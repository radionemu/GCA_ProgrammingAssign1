#pragma once
#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <GL/glew.h>

class VertexBuffer
{
    private:
        GLuint BufferID;//VBO needs Buffer's ID to Bind and Buffer Data
    public:
        VertexBuffer();
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind();
        void Unbind();
        void FillData(const void* data, unsigned int size);
};

#endif