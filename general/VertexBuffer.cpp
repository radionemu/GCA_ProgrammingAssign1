#include "VertexBuffer.hpp"
#include <stdio.h>
// generate Buffer and Bind buffer.
// This Constructor does not alloc Data
VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &BufferID);
    glBindBuffer(GL_ARRAY_BUFFER, BufferID);
}

// generate Buffer, Bind Buffer, and Data Buffer
// size must be calculated as byte, not sizeof elements
VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    VertexBuffer();
    FillData(data, size);
}

VertexBuffer::~VertexBuffer()
{
    Unbind();
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, BufferID);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);//0 == unbind
}

void VertexBuffer::FillData(const void* data, unsigned int size)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
