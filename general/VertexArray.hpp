#pragma once
#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP


#include <GL/glew.h>
#include "general/VertexBuffer.hpp"
#include "general/BufferLayout.hpp"

class VertexArray{
    private:
    GLuint vaoID;
    public:
    VertexArray();
    ~VertexArray();

    void init();
    void destroy();
    void Bind();
    void AttribBuffer(VertexBuffer &vb, BufferLayout &layout);//Needs AttribLocation (a.k.a. Layout)
};

#endif