/*
 * File:   VertexArrayObject.hpp
 * Author: JoPe
 *
 * Created on 3 de abril de 2015, 22:04
 */

#ifndef VERTEXARRAY_HPP
#define	VERTEXARRAY_HPP

#include "GL/glew.h"
#include "TLS/Handle.hpp"
#include "Model.hpp"

namespace glt
{
  void DeleteVertexArray(GLuint vertexArray);
  using VertexArrayHandle = tls::Handle<GLuint, DeleteVertexArray>;

  void DeleteBuffer(GLuint buffer);
  using BufferHandle = tls::Handle<GLuint, DeleteBuffer>;

  class VertexArray
  {
    VertexArrayHandle m_vertexArray;
    BufferHandle m_vertexBuffer;
    BufferHandle m_indexBuffer;

    public:
      VertexArray() noexcept = default;
      VertexArray(Model const& i_model);
      VertexArray(VertexArray&& that) noexcept;
      VertexArray& operator=(VertexArray&& that) noexcept;
      GLuint VerArr() const {return m_vertexArray;}
  };
}
#endif	/* VERTEXARRAY_HPP */
