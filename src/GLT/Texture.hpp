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
    struct TextureSettings
    {
        GLint m_mipMapLevel;
        GLint m_wrapMode;
        GLint m_filterQuality;
        bool m_generateMipMap;

        TextureSettings();
    };

    class Texture
    {
        static GLenum const sk_target;
        static GLint const sk_border;
        GLuint m_name;
        GLsizei m_width;
        GLsizei m_height;

        public:
            Texture( tga::Image c_image, TextureSettings const& i_settings = TextureSettings() );
            Texture( Texture && io_texture );
            ~Texture();

            GLuint const& Name() const;

        private:
            Texture( Texture const& i_texture );
            Texture & operator=( Texture c_texture );
    };
}
#endif	/* TEXTURE_HPP */

