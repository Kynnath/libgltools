/*
 * File:   Texture.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de junio de 2014, 14:51
 */

#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include "GL/glew.h"

namespace tga
{
    class Image;
}

namespace glt
{
    class Image;

    struct TextureSettings
    {
        GLint m_mipMapLevel;
        GLint m_wrapMode;
        GLint m_filterQuality;
        bool m_generateMipMap;

        TextureSettings( GLint const& i_mipMapLevel     = 0,
                         GLint const& i_wrapMode        = GL_CLAMP_TO_EDGE,
                         GLint const& i_filterQuality   = GL_LINEAR,
                         bool i_generateMipMap          = false );
    };

    class Texture
    {
        static GLenum const sk_target;
        static GLint const sk_border;
        GLuint m_name;

        Texture( Texture const& i_texture ) = delete;
        Texture & operator=( Texture const& i_texture ) = delete;

        public:
            Texture();
            Texture( Image const& i_image, TextureSettings const& i_settings = TextureSettings() );
            Texture( tga::Image c_image, TextureSettings const& i_settings = TextureSettings() );
            Texture( Texture && io_texture );
            Texture & operator=( Texture && io_texture );
            ~Texture();

            GLuint const& Name() const;
    };
}
#endif	/* TEXTURE_HPP */

