#ifndef MTLLOADER_HPP
#define MTLLOADER_HPP

#include <vector>
#include <string.h>

typedef struct mtl{
    public:
    const char *mtlname; //every .mtl file must have at least one mtlname
    const char *texturepath = ""; //contain the relative path of texture
    const char *textureformat; //contain extension of texture image (e.g. .png .bmp .tga)
    mtl(){}
    mtl(const char *name) : mtlname(name){}
}mtl;

//path : mtl location
bool mtl_opener(const char* path, std::vector<mtl> & mtllib);

#endif