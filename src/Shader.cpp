/* 
 * File:   Shader.cpp
 * Author: juan.garibotti
 * 
 * Created on 16 de septiembre de 2013, 13:09
 */

#include <cassert>
#include "GLT/Shader.hpp"

namespace glt
{
    Shader LoadShaderCode( char const* i_vertexProgram, char const* i_fragmentProgram )
    {
        GLuint const vertexProgram ( glCreateShader( GL_VERTEX_SHADER ) );
        GLuint const fragmentProgram ( glCreateShader( GL_FRAGMENT_SHADER ) );
        
        GLchar const* vertexCodeArray[1] = { i_vertexProgram };
        GLchar const* fragmentCodeArray[1] = { i_fragmentProgram };
        
        glShaderSource( vertexProgram, 1, vertexCodeArray, NULL );
        glShaderSource( fragmentProgram, 1, fragmentCodeArray, NULL );
        
        glCompileShader( vertexProgram );
        glCompileShader( fragmentProgram );
        
#ifndef NDEBUG
        GLint checkCompile;
        glGetShaderiv( vertexProgram, GL_COMPILE_STATUS, &checkCompile );
        glGetShaderiv( fragmentProgram, GL_COMPILE_STATUS, &checkCompile );
        assert( checkCompile != GL_FALSE );
#endif //NDEBUG
        
        GLuint const shaderID ( glCreateProgram() );
        glAttachShader( shaderID, vertexProgram );
        glAttachShader( shaderID, fragmentProgram );
        glLinkProgram( shaderID );
        
#ifndef NDEBUG
        GLint checkLink;
        glGetProgramiv( shaderID, GL_LINK_STATUS, &checkLink );
        assert( checkLink != GL_FALSE );
#endif //NDEBUG
        
        Shader const shader = { shaderID };
        
        return shader;
    }
}

