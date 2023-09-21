#pragma once
#ifndef BUFFER_LAYOUT_HPP
#define BUFFER_LAYOUT_HPP

#include <GL/glew.h>
#include <vector>
#include <stdio.h>

typedef struct VertexPointer{
    GLuint count;
    GLuint vptype;
    GLuint normalize;
    GLuint LayoutID;
    GLuint offset;
}VertexPointer;

//store the Information about glEnableVertexAttribArray() + glVertexAttribPointer()
class BufferLayout{
    private:
        std::vector<VertexPointer> VertElement;
        GLuint stride = 0;
    public:
        BufferLayout();

        std::vector<VertexPointer> getElement(){return VertElement;}
        //test
        void Push(int programID, const char *Layout, GLuint gltype, unsigned int pcount){
            GLuint tLID = glGetAttribLocation(programID, Layout);
            VertexPointer temp = {pcount, gltype, GL_FALSE, tLID, stride};
            VertElement.push_back(temp);
            stride += sizeof(float)*pcount;
            printf("layout push done\n");
        }

        GLuint Getstride(){
            return stride;
        }

        void Clear();
};



#endif