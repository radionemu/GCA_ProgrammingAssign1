#include <GL/glew.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

#include <lodepng.h>

#define FILEHEADER 0x89504E470D0A1A0A

GLuint LoadPNG(const char * PNGpath){
    //wait what
    std::vector<unsigned char> PNGimage;
    unsigned int width, height;
    unsigned int res = lodepng::decode(PNGimage, width, height, PNGpath);

    if(res != 0){
        printf("PNG open failed.\n");
        return 1;
    }

    printf("PNG file [%s] opened.\n", PNGpath);
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &PNGimage[0]);

    //check it later
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
	glGenerateMipmap(GL_TEXTURE_2D);

    return textureID;
}