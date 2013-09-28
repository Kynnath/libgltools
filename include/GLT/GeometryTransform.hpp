/*
 * File:   GeometryTransform.hpp
 * Author: JoPe
 *
 * Created on 28 de septiembre de 2013, 15:26
 */

#ifndef GEOMETRYTRANSFORM_HPP
#define	GEOMETRYTRANSFORM_HPP

#include "GLT/Frame.hpp"
#include "GLT/GLMatrix.hpp"
#include "MAT/Matrix4.hpp"

namespace glt
{
    struct GeometryTransform
    {
        Frame m_viewFrame;
        mat::Matrix4 m_projectionMatrix;
        mutable mat::Matrix4 m_vpMatrix;

        void Reset();
        void DefineOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax);
        void DefinePerspectiveProjection( double const& i_fieldOfView, double const& i_aspectRatio, double const& i_zMin, double const& i_zMax );
        void BuildVPMatrix() const;
        GLMatrix BuildMVPMatrix( Frame const& i_model ) const;
    };
}

#endif	/* GEOMETRYTRANSFORM_HPP */

