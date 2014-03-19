/*
 * File:   Vertex.cpp
 * Author: JoPe
 *
 * Created on 1 de septiembre de 2013, 20:19
 */

#include "GLT/Vertex.hpp"

#include <cstring>

namespace glt
{
    bool operator==( Vertex const& lhs, Vertex const& rhs )
    {
        return !memcmp( &lhs, &rhs, sizeof(Vertex) );
    }

    bool operator!=( Vertex const& lhs, Vertex const& rhs )
    {
        return !operator==(lhs,rhs);
    }
}