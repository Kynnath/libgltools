/* 
 * File:   Shader.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de septiembre de 2013, 13:09
 */

#ifndef SHADER_HPP
#define	SHADER_HPP

#include "GL/glew.h"

namespace glt
{
    struct Shader 
    {
        GLuint m_shaderID;        
    };
    
    Shader LoadShaderCode( char const* i_vertexProgram, char const* i_fragmentProgram );
}

#endif	/* SHADER_HPP */

