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

namespace glt
{
    struct Model
    {
        std::vector< Vertex > m_vertexList;
        std::vector< GLuint > m_indexList;
    };
}

#endif	/* MODEL_HPP */

