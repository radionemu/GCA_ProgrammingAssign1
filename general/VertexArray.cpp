#include "VertexArray.hpp"
#include <GL/glut.h>
#include <GL/glew.h>

VertexArray::VertexArray()
{
    init();
}

VertexArray::~VertexArray()
{
    //glDeleteVertexArrays(1, &vaoID);
}


void VertexArray::init()
{
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
}

void VertexArray::destroy()
{
    glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::Bind()
{
    glBindVertexArray(vaoID);
    //printf("vao bind done\n");
}

void VertexArray::AttribBuffer(VertexBuffer &vb, BufferLayout &layout)
{
    vb.Bind();
    const auto& element = layout.getElement();
    for(int i=0; i<element.size(); i++){
        glVertexAttribPointer(element[i].LayoutID, element[i].count, element[i].vptype, element[i].normalize, layout.Getstride(), (void *)(element[i].offset));
        glEnableVertexAttribArray(element[i].LayoutID);
    }
}
