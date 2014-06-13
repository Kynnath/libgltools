/*
 * File:   GLMatrix.cpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 18:43
 */

#include "GLMatrix.hpp"

#include "MAT/Matrix4.hpp"

namespace glt
{
    GLMatrix::GLMatrix( mat::Matrix4 const& i_matrix )
    {
        for ( int index = 0; index < 16; ++index )
        {
            m_data[ (long long unsigned int)index ] = (float) i_matrix[ index ];
        }
    }
}