/*
 * File:   VertexArrayObject.cpp
 * Author: JoPe
 *
 * Created on 3 de abril de 2015, 22:04
 */

#include "VertexArray.hpp"

#include <array>

namespace glt
{
  void DeleteVertexArray(GLuint vertexArray)
  {
    glDeleteVertexArrays(1, &vertexArray);
  }

  void DeleteBuffer(GLuint buffer)
  {
    glDeleteBuffers(1, &buffer);
  }

  class BindVertexArray
  {
    public:
      BindVertexArray(GLuint vertexArray)
      {
        glBindVertexArray(vertexArray);
      }
      ~BindVertexArray()
      {
        glBindVertexArray(0);
      }
  };

  struct VertexAttribute
  {
    bool enabled;
    GLint size;  // number of components
    GLenum type;  // type of components, GL_BYTE, _SHORT, _INT, etc
    GLboolean normalized;  // are the values normalized
    GLsizei stride;  // offset between consecutive values. sizeof(Vertex)
    GLvoid* offset;  // offset to first value
  };

  VertexArray::VertexArray(Model const& i_model)
    : m_vertexArray {}
    , m_vertexBuffer {}
    , m_indexBuffer {}
  {
    {
      GLuint vertexArray;
      glGenVertexArrays(1, &vertexArray);
      m_vertexArray = vertexArray;
    }
    auto vertexArrayBinding = BindVertexArray(m_vertexArray);

    {
      GLuint vertexBuffer;
      glGenBuffers(1, &vertexBuffer);
      m_vertexBuffer = vertexBuffer;
    }
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER,
        GLsizeiptr(sizeof(Vertex)*i_model.m_vertexList.size()),
        i_model.m_vertexList.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(Vertex::Position);
    glVertexAttribPointer(Vertex::Position, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (GLvoid const*)Vertex::PositionOffset);

    glEnableVertexAttribArray(glt::Vertex::Texture);
    glVertexAttribPointer(glt::Vertex::Texture, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (GLvoid const*)Vertex::TextureOffset);

    {
      GLuint indexBuffer;
      glGenBuffers(1, &indexBuffer);
      m_indexBuffer = indexBuffer;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        GLsizeiptr(sizeof(GLuint)*i_model.m_indexList.size()),
        i_model.m_indexList.data(), GL_STATIC_DRAW);
  }

  VertexArray::VertexArray(VertexArray&& that) noexcept
    : m_vertexArray(std::move(that.m_vertexArray))
    , m_vertexBuffer(std::move(that.m_vertexBuffer))
    , m_indexBuffer(std::move(that.m_indexBuffer))
  {}

  VertexArray& VertexArray::operator=(VertexArray&& that) noexcept
  {
    m_indexBuffer = std::move(that.m_indexBuffer);
    m_vertexBuffer = std::move(that.m_vertexBuffer);
    m_vertexArray = std::move(that.m_vertexArray);

    return *this;
  }
}
