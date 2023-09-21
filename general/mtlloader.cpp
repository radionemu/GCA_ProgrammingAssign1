#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

#include "mtlloader.hpp"

bool mtl_opener(const char* path, std::vector<mtl> & mtllib){
    printf("open mtl file : %s\n", path);

    FILE * file = fopen(path, "r");
    if(file == NULL){
        printf("mtl open failed.\n");
        getchar();
        return false;
    }
    printf("mtl open success.\n");
    
    while(true){
        char mtl_command[128];
        int res = fscanf(file, "%s", mtl_command);
        if(res == EOF) break;

        //newmtl [material name]
        if(strcmp(mtl_command, "newmtl") == 0){
            char *mtl_name = (char *)malloc((sizeof(char))*1024);
            fscanf(file, "%s\n", mtl_name);
            mtllib.push_back(mtl(mtl_name));
        }
        //map_Kd [Texture map] : Diffuse Map
        else if(strcmp(mtl_command, "map_Kd") == 0){
            mtllib.back().texturepath = (const char *)malloc(sizeof(char) * 4096);
            fscanf(file, "%s\n", mtllib.back().texturepath);//고쳐야함
        }
    }
    
    return true;
}