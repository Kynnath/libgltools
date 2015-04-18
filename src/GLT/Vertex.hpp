/*
 * File:   Vertex.hpp
 * Author: JoPe
 *
 * Created on 1 de septiembre de 2013, 20:19
 */

#ifndef GLT_VERTEX_HPP
#define	GLT_VERTEX_HPP

#include <array>
#include "GL/glew.h"

namespace glt
{
  struct Vertex
  {
    enum Attribute
    {
      Position = 0,
      Color,
      Texture,
      Attributes
    };
    enum Offset
    {
      PositionOffset = 0,
      ColorOffset = sizeof(GLfloat)*3,
      TextureOffset = ColorOffset + sizeof(GLfloat)*4
    };
    std::array<GLfloat,3> m_position;
    std::array<GLfloat,4> m_color;
    std::array<GLfloat,2> m_texture;
  };

  bool operator==( Vertex const& lhs, Vertex const& rhs );
  bool operator!=( Vertex const& lhs, Vertex const& rhs );
}

#endif	/* VERTEX_HPP */
