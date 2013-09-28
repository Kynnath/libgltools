/*
 * File:   Frame.hpp
 * Author: JoPe
 *
 * Created on 28 de septiembre de 2013, 11:02
 */

#ifndef FRAME_HPP
#define	FRAME_HPP

#include "MAT/Matrix4.hpp"
#include "VEC/Vector3.hpp"

namespace glt
{
    struct Frame
    {
        vec::Vector3 m_position;
        vec::Vector3 m_forward;
        vec::Vector3 m_up;

        mat::Matrix4 BuildRotationMatrix() const;
        mat::Matrix4 BuildTranslationMatrix() const;
        mat::Matrix4 BuildViewRotationMatrix() const;
        mat::Matrix4 BuildViewTranslationMatrix() const;
        mat::Matrix4 BuildMatrix() const;
        mat::Matrix4 BuildViewMatrix() const;
    };
}

#endif	/* FRAME_HPP */

