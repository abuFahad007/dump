#include "VertexArray.h"
#include "Error.h"

VertexArray::VertexArray()
{
    GCE glGenVertexArrays(1,&m_RendererID); GCE
}

VertexArray::~VertexArray()
{
    GCE glDeleteVertexArrays(1,&m_RendererID); GCE
}

void VertexArray::AddBuffer(const VertexBuffer& vb,const VertexBufferLayout& layout) 
{
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0;i<elements.size();i++)
    {
        const auto& element = elements[i];
        GCE glEnableVertexAttribArray(i); GCE
        glVertexAttribPointer(i,element.count,element.type,element.normalized,layout.GetStride(),(const void*)offset); GCE
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    GCE glBindVertexArray(m_RendererID); GCE
}

void VertexArray::Unbind() const
{
    GCE glBindVertexArray(0); GCE
}
