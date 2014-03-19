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
        enum
        {
            Position = 0,
            Color
        };
        std::array<GLfloat,3> m_position;
        std::array<GLfloat,3> m_color;
    };

    bool operator==( Vertex const& lhs, Vertex const& rhs );
    bool operator!=( Vertex const& lhs, Vertex const& rhs );
}

#endif	/* VERTEX_HPP */

