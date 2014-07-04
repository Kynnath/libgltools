/*
 * File:   Model.hpp
 * Author: JoPe
 *
 * Created on 1 de septiembre de 2013, 20:47
 */

#ifndef MODEL_HPP
#define	MODEL_HPP

#include <vector>
#include "GL/glew.h"
#include "Vertex.hpp"

namespace obj
{
    class Object;
}
namespace glt
{
    struct Model
    {
        std::vector< Vertex > m_vertexList;
        std::vector< GLuint > m_indexList;

        Model() = default;
        Model( obj::Object const& i_object );
    };
}

#endif	/* MODEL_HPP */

