/*
 * File:   Image.hpp
 * Author: juan.garibotti
 *
 * Created on 26 de junio de 2014, 14:05
 */

#ifndef IMAGE_HPP
#define	IMAGE_HPP

#include <memory>
#include "GL/glew.h"

namespace glt
{
    struct ImageDescription
    {
        GLsizei m_width;
        GLsizei m_height;
        GLenum m_format;
        GLenum m_type;

        ImageDescription(GLsizei const& i_width, GLsizei const& i_height, GLenum const& i_format = GL_RED, GLenum const& i_type = GL_UNSIGNED_BYTE);
    };

    class Image
    {
        ImageDescription m_description;
        std::unique_ptr<unsigned char[]> m_data;

        public:
            Image(ImageDescription const& i_description, std::unique_ptr<unsigned char[]> data);
            ImageDescription const& Description() const;
            unsigned char const* Data() const;
    };
}
#endif	/* IMAGE_HPP */

