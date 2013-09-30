/*
 * File:   Vertex.hpp
 * Author: JoPe
 *
 * Created on 1 de septiembre de 2013, 20:19
 */

#ifndef VERTEX_HPP
#define	VERTEX_HPP

#include "GL/glew.h"

namespace glt
{
    struct Vertex
    {
        enum
        {
            Position = 0,
            Color,
            Count,
        };
        GLfloat m_position[ 3 ];
        GLfloat m_color[ 3 ];
    };
}

#endif	/* VERTEX_HPP */

