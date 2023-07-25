
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data,unsigned int count)
    : m_count(count)
{
    
    GCE glGenBuffers(1, &m_RendererID); GCE
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); GCE
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(unsigned int), data, GL_STATIC_DRAW); GCE
}

IndexBuffer::~IndexBuffer() 
{
    GCE glDeleteBuffers(1,&m_RendererID); GCE
}

void IndexBuffer::Bind() const
{
    GCE glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID); GCE
}

void IndexBuffer::Unbind() const
{
    GCE glBindBuffer(GL_ARRAY_BUFFER,0); GCE
}