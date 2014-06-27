/*
 * File:   Image.cpp
 * Author: juan.garibotti
 *
 * Created on 26 de junio de 2014, 14:05
 */

#include "Image.hpp"

namespace glt
{
    ImageDescription::ImageDescription( GLsizei const& i_width, GLsizei const& i_height, GLenum const& i_format, GLenum const& i_type )
        : m_width { i_width }
        , m_height { i_height }
        , m_format { i_format }
        , m_type { i_type }
    {}

    Image::Image( ImageDescription const& i_description, std::unique_ptr<unsigned char[]> c_data )
        : m_description { i_description }
        , m_data { std::move( c_data ) }
    {}

    ImageDescription const& Image::Description() const
    {
        return m_description;
    }

    unsigned char const* Image::Data() const
    {
        return m_data.get();
    }


}