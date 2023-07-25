
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data,unsigned int size)
{
    GCE
    glGenBuffers(1, &m_RendererID); GCE
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID); GCE
    glBufferData(GL_ARRAY_BUFFER,size, data, GL_STATIC_DRAW); GCE
}

VertexBuffer::~VertexBuffer()
{
    GCE
    glDeleteBuffers(1,&m_RendererID); GCE
}

void VertexBuffer::Bind() const
{
    GCE
    glBindBuffer(GL_ARRAY_BUFFER,m_RendererID); GCE
}

void VertexBuffer::Unbind() const
{
    GCE
    glBindBuffer(GL_ARRAY_BUFFER,0); GCE
}