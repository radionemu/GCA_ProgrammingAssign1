#ifndef OBJLOADER_HPP
#define OBJLOADER_HPP

#include<vector>
#include<string.h>
#include<glm/glm.hpp>
#include<general/mtlloader.hpp>

//submesh
typedef struct subMesh{
    public:
        unsigned int vStart = 0;//start point of vertices
        unsigned int vsize = 0;//size of submesh
        const char * mtlname;
        subMesh(){}
        subMesh(const char * name) : mtlname(name){}
}subMesh;

typedef struct obj{
    public:
        const char *objName;
        unsigned int vertexsize = 0;
        unsigned int facesize = 0;
        void * pv;
        void * pvt;
        void * pvn;
        std::vector<glm::vec3> v;
        std::vector<glm::vec2> vt;
        std::vector<glm::vec3> vn;
        std::vector<subMesh> sMesh;
        obj(){}
        obj(const char *name) : objName(name){
        }
}obj;

bool obj_opener(const char *path, std::vector<obj> & collector, const char *mtlpath);

#endif