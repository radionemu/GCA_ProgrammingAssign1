#include <stdio.h>
#include <string.h>

#include <glm/glm.hpp>
#include <vector>
#include <iostream>

#include "objloader.hpp"

bool submeshflush(
    std::vector<obj> & collector,
    unsigned int * submv
){
    collector.back().sMesh.back().vStart = *submv;
    collector.back().sMesh.back().vsize = (collector.back().facesize)*3 - *submv;
        
    //update submesh pos to temp pos
    *submv = collector.back().facesize*3;
    return true;
}

    bool objflush(
    std::vector<obj> & collector,
    std::vector<glm::vec3> & Tvertex,
    std::vector<glm::vec2> & TUV,
    std::vector<glm::vec3> & Tnormal,

    std::vector<unsigned int> & Ivertf,
    std::vector<unsigned int> & Iuvf,
    std::vector<unsigned int> & Inormf
    ){
        //malloc sizeof Faces
        collector.back().pv = ::operator new(sizeof(float)*Ivertf.size()*8);
        //collector.back().pvt = ::operator new(sizeof(float)*Ivertf.size()*2);
        //collector.back().pvn = ::operator new(sizeof(float)*Ivertf.size()*3);

        for(int i=0; i<Ivertf.size(); i++){
                //printf("%0x%p %f\n", ((float *)(collector.back().pvn)+i*3), Tnormal[Inormf[i]-1].x);
                *((float *)(collector.back().pv)+i*8) = Tvertex[Ivertf[i]-1].x;
                *((float *)(collector.back().pv)+i*8+1) = Tvertex[Ivertf[i]-1].y;
                *((float *)(collector.back().pv)+i*8+2) = Tvertex[Ivertf[i]-1].z;

                *((float *)(collector.back().pv)+i*8+3) = TUV[Iuvf[i]-1].x;
                *((float *)(collector.back().pv)+i*8+4) = TUV[Iuvf[i]-1].y;

                *((float *)(collector.back().pv)+i*8+5) = Tnormal[Inormf[i]-1].x;
                *((float *)(collector.back().pv)+i*8+6) = Tnormal[Inormf[i]-1].y;
                *((float *)(collector.back().pv)+i*8+7) = Tnormal[Inormf[i]-1].z;
                //printf("uvx : %f || uvy : %f\n", *((float *)(collector.back().pvt)+i*2), *((float *)(collector.back().pvt)+i*2+1));
        }
        //clear vectors
        Tvertex.clear();
        TUV.clear();
        Tnormal.clear();
        Ivertf.clear();
        Iuvf.clear();
        Inormf.clear();

        return true;
    }


bool obj_opener(const char *path, std::vector<obj> & collector, const char *mtlpath){
    //temp f indices vector
    std::vector<unsigned int> Ivertf;
    std::vector<unsigned int> Iuvf;
    std::vector<unsigned int> Inormf;
    //temp vector
    std::vector<glm::vec3> Tvertex;
    std::vector<glm::vec2> TUV;
    std::vector<glm::vec3> Tnormal;
    
    printf("open obj file : %s\n", path);

    FILE * file = fopen(path, "r");
    if(file == NULL){
        printf("obj open failed.\n");
        getchar();
        return false;
    }
    printf("obj open success.\n");
    char obj_current[1024] = "NULL";
    obj *obj_recent;
    unsigned int globalv = 0;
    unsigned int globalvt = 0;
    unsigned int globalvn = 0;

    unsigned int tempv =0;
    unsigned int tempvt =0;
    unsigned int tempvn =0;

    unsigned int submv = 0;

    while(true){
        char obj_command[128];
        int res = fscanf(file, "%s", obj_command);
        if(res == EOF) break;
        
        //mtllib [filename]
        if(strcmp(obj_command, "mtllib") == 0){
            fscanf(file, "%s\n", mtlpath);
        }
        // o [Object Name]
        else if(strcmp(obj_command, "o") == 0){
            //new object will take place
            //flush recent vertices
            if(collector.size() != 0){
                //submeshflush(collector, &submv);
                //vectorflush(collector, Tvertex, TUV, Tnormal, Ivertf, Iuvf, Inormf);
            }
            char *obj_name = (char *)malloc((sizeof(char))*1024);
            fscanf(file, "%s\n", obj_name);
            if(collector.size() == 0){
                collector.emplace_back(obj(obj_name));
            }
            //for debug
            printf("%s %s\t\t", obj_command, collector.back().objName);
        
        }
        // v (x y z [w?])
        else if(strcmp(obj_command, "v") == 0){
            //no object
            if(collector.size() == 0){
                collector.emplace_back(obj(path));
            }

            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            Tvertex.emplace_back(vertex);     

            collector.back().vertexsize++;       
            tempv++;
        }
        // vn (x y z [w?])
        else if(strcmp(obj_command, "vn") == 0){
            glm::vec3 vertNormal;
            fscanf(file, "%f %f %f\n", &vertNormal.x, &vertNormal.y, &vertNormal.z);
            Tnormal.emplace_back(vertNormal);
            tempvn++;
        }
        // vt (u v [w?])
        // on png uv coordinate is reversed
        else if(strcmp(obj_command, "vt") == 0){
            glm::vec2 vertTex;
            fscanf(file, "%f %f\n", &vertTex.x, &vertTex.y);
            vertTex.y = -vertTex.y; //LodePNG uses a pixel order where it goes in rows from top to bottom.
            TUV.emplace_back(vertTex);
            tempvt++;
        }
        // usemtl (mtl name)
        else if(strcmp(obj_command, "usemtl") == 0){
            //flush old submeshes
            if(collector.back().sMesh.size() != 0){
                submeshflush(collector, &submv);
            }

            //new subMesh
            char *sMesh_name = (char *)malloc((sizeof(char))*1024);
            fscanf(file, "%s\n", sMesh_name);
            collector.back().sMesh.emplace_back(subMesh(sMesh_name));
        }

        // f (v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3)
        else if(strcmp(obj_command, "f") == 0){
            if(collector.back().sMesh.size() == 0){
                collector.back().sMesh.emplace_back(subMesh("Temp"));                
            }

            unsigned int vertIndex[3];
            unsigned int UVIndex[3];
            unsigned int normIndex[3];
            fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertIndex[0], &UVIndex[0], &normIndex[0], &vertIndex[1], &UVIndex[1], &normIndex[1], &vertIndex[2], &UVIndex[2], &normIndex[2]);
            for(int i=0; i<3; i++){
                //printf("%d %d %d\n", normIndex[0], normIndex[1], normIndex[2]);
                //f indices start with 1
                //each parameter means individual vertex (not x y z)
                Ivertf.emplace_back(vertIndex[i]);
                Iuvf.emplace_back(UVIndex[i]);
                Inormf.emplace_back(normIndex[i]);
            }
            collector.back().facesize++;
        }else{
            char Buffer[1000];
			fgets(Buffer, 1000, file);
        }
    }
    submeshflush(collector, &submv);
    objflush(collector, Tvertex, TUV, Tnormal, Ivertf, Iuvf, Inormf);
    return 0;
}