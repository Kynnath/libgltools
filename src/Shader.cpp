/*
 * File:   Shader.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de septiembre de 2013, 13:09
 */

#include <cassert>
#include <vector>
#include "GLT/Shader.hpp"

#ifndef NDEBUG
#include <iostream>
#endif //NDEBUG

namespace glt
{
    Shader LoadShaderCode( char const* i_vertexShader, char const* i_fragmentShader )
    {
        GLuint const vertexShader ( glCreateShader( GL_VERTEX_SHADER ) );
        GLuint const fragmentShader ( glCreateShader( GL_FRAGMENT_SHADER ) );

        GLchar const* vertexCodeArray[1] = { i_vertexShader };
        GLchar const* fragmentCodeArray[1] = { i_fragmentShader };

        glShaderSource( vertexShader, 1, vertexCodeArray, NULL );
        glShaderSource( fragmentShader, 1, fragmentCodeArray, NULL );

        glCompileShader( vertexShader );
        glCompileShader( fragmentShader );

#ifndef NDEBUG
        GLint checkCompile;
        glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &checkCompile );
        if ( checkCompile == GL_FALSE )
        {
            GLint lengthLog ( 0 );
            glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &lengthLog );
            char * compilerLog = new char[lengthLog];
            //compilerLog.resize( lengthLog, 0 );
            glGetShaderInfoLog( vertexShader, lengthLog, NULL, compilerLog );
            std::cout << compilerLog << std::endl;
            delete[] compilerLog;
        }
        assert( checkCompile != GL_FALSE );
        
        glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &checkCompile );
        if ( checkCompile == GL_FALSE )
        {
            GLint lengthLog ( 0 );
            glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &lengthLog );
            char * compilerLog = new char[lengthLog];
            //compilerLog.resize( lengthLog, 0 );
            glGetShaderInfoLog( fragmentShader, lengthLog, NULL, compilerLog );
            std::cout << compilerLog << std::endl;
            delete[] compilerLog;
        }
        assert( checkCompile != GL_FALSE );
#endif //NDEBUG

        GLuint const programID ( glCreateProgram() );
        glAttachShader( programID, vertexShader );
        glAttachShader( programID, fragmentShader );
        glLinkProgram( programID );

#ifndef NDEBUG
        GLint checkLink;
        glGetProgramiv( programID, GL_LINK_STATUS, &checkLink );
        if ( checkLink == GL_FALSE )
        {
            GLint lengthLog ( 0 );
            glGetProgramiv( programID, GL_INFO_LOG_LENGTH, &lengthLog );
            char * linkerLog = new char[lengthLog];
            //compilerLog.resize( lengthLog, 0 );
            GLsizei lengthWritten;
            glGetProgramInfoLog( programID, lengthLog, &lengthWritten, linkerLog );
            std::cout << linkerLog << std::endl;
            delete[] linkerLog;
        }
        assert( checkLink != GL_FALSE );
#endif //NDEBUG

        Shader const shader = { programID };

        return shader;
    }
}

