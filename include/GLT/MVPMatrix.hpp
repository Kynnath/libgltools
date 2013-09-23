/*
 * File:   MVPMatrix.hpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 17:43
 */

#ifndef MVPMATRIX_HPP
#define	MVPMATRIX_HPP

#include "GLT/GLMatrix.hpp"
#include "MAT/Matrix4.hpp"

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
            void SetView( vec::Vector3 const& i_position, vec::Vector3 const& i_direction, vec::Vector3 const& i_up );
            GLMatrix BuildMVPMatrix() const;

        protected:
            mat::Matrix4 ModelMatrix;
            mat::Matrix4 ViewMatrix;
            mat::Matrix4 ProjectionMatrix;
    };
}

#endif	/* MVPMATRIX_HPP */

