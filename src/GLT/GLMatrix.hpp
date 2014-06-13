/*
 * File:   GLMatrix.hpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 18:43
 */

#ifndef GLMATRIX_HPP
#define	GLMATRIX_HPP

#include <array>
#include "GL/glew.h"

namespace mat
{
    struct Matrix4;
}

namespace glt
{
    struct GLMatrix
    {
        std::array<GLfloat,16> m_data;

        GLMatrix() = default;
        GLMatrix( mat::Matrix4 const& i_matrix );
    };
}

#endif	/* GLMATRIX_HPP */

