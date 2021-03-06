/*
 * File:   MVPMatrix.hpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 17:43
 */

#ifndef MVPMATRIX_HPP
#define	MVPMATRIX_HPP

#include "MAT/Matrix4.hpp"
#include "GLMatrix.hpp"

namespace vec
{
    struct Vector3;
}

namespace glt
{
    class MVPMatrix
    {
        public:
            MVPMatrix () = default;
            void Reset();
            void SetOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax);
            void SetPerspectiveProjection( double const& i_fieldOfView, double const& i_aspectRatio, double const& i_zMin, double const& i_zMax );
            void SetView( vec::Vector3 const& i_position, vec::Vector3 const& i_forward, vec::Vector3 const& i_up );
            GLMatrix BuildMVPMatrix() const;

        protected:
            mat::Matrix4 m_modelMatrix;
            mat::Matrix4 m_viewMatrix;
            mat::Matrix4 m_projectionMatrix;
    };

    mat::Matrix4 BuildViewRotationMatrix( vec::Vector3 const& i_forward, vec::Vector3 const& i_up );
    mat::Matrix4 BuildViewTranslationMatrix( vec::Vector3 const& i_position );
}

#endif	/* MVPMATRIX_HPP */

