/*
 * File:   Shader.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de septiembre de 2013, 13:09
 */

#include <cassert>
#include <vector>
#include "Shader.hpp"

#ifndef NDEBUG
#include <iostream>
#endif //NDEBUG

namespace glt
{
  Shader::Shader( GLuint shaderID, GLuint mvpLoc ) noexcept
    : m_shaderID { shaderID }
    , m_mvpLocation { mvpLoc }
  {}
    
  Shader::Shader( Shader && i_src ) noexcept
    : m_shaderID { i_src.m_shaderID }
    , m_mvpLocation { i_src.m_mvpLocation }
  {
    i_src.m_shaderID = 0;
  }
    
  Shader& Shader::operator=( Shader && i_src ) noexcept
  {
    m_shaderID = i_src.m_shaderID;
    m_mvpLocation = i_src.m_mvpLocation;
    i_src.m_shaderID = 0;
    return *this;
  }
  
  Shader::~Shader() noexcept
  {
    glDeleteProgram(m_shaderID);
  }
    
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
      std::vector< char > compilerLog;
      compilerLog.resize( (long long unsigned int)lengthLog, 0 );
      glGetShaderInfoLog( vertexShader, lengthLog, NULL, compilerLog.data() );
      std::cout << compilerLog.data() << std::endl;
    }
    assert( checkCompile != GL_FALSE );

    glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &checkCompile );
    if ( checkCompile == GL_FALSE )
    {
      GLint lengthLog ( 0 );
      glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &lengthLog );
      std::vector< char > compilerLog;
      compilerLog.resize( (long long unsigned int)lengthLog, 0 );
      glGetShaderInfoLog( fragmentShader, lengthLog, NULL, compilerLog.data() );
      std::cout << compilerLog.data() << std::endl;
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
      std::vector< char > linkerLog;
      linkerLog.resize( (long long unsigned int)lengthLog, 0 );
      glGetProgramInfoLog( programID, lengthLog, NULL, linkerLog.data() );
      std::cout << linkerLog.data() << std::endl;
    }
    assert( checkLink != GL_FALSE );
#endif //NDEBUG

    glDetachShader( programID, vertexShader );
    glDetachShader( programID, fragmentShader );
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );

    return { programID, (GLuint)glGetUniformLocation( programID, "mvpMatrix" ) };
  }
}

