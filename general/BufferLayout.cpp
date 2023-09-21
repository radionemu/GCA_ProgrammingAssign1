#include "BufferLayout.hpp"
#include <GL/glew.h>


BufferLayout::BufferLayout()
{
}

void BufferLayout::Clear()
{
    VertElement.clear();
    stride = 0;
}
