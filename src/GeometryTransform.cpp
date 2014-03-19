/*
 * File:   GeometryTransform.cpp
 * Author: JoPe
 *
 * Created on 28 de septiembre de 2013, 15:26
 */

#include "GLT/GeometryTransform.hpp"

#include <cmath>

namespace glt
{
    void GeometryTransform::Reset()
    {
        m_viewFrame.m_forward =  { { 0.0,  0.0, -1.0 } };
        m_viewFrame.m_position = { { 0.0,  0.0,  0.0 } };
        m_viewFrame.m_up =       { { 0.0,  1.0,  0.0 } };

        m_projectionMatrix.SetIdentity();

        m_vpMatrix.SetIdentity();
    }

    void GeometryTransform::DefineOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax)
    {
        m_projectionMatrix.SetIdentity();

        m_projectionMatrix[ 0 ] = 2.0 / ( i_xMax - i_xMin );
        m_projectionMatrix[ 5 ] = 2.0 / ( i_yMax - i_yMin );
        m_projectionMatrix[ 10 ] = - 2.0 / ( i_zMax - i_zMin );
        m_projectionMatrix[ 12 ] = - ( ( i_xMax + i_xMin ) / ( i_xMax - i_xMin ) );
        m_projectionMatrix[ 13 ] = - ( ( i_yMax + i_yMin ) / ( i_yMax - i_yMin ) );
        m_projectionMatrix[ 14 ] = - ( ( i_zMax + i_zMin ) / ( i_zMax - i_zMin ) );

        BuildVPMatrix();
    }

    void GeometryTransform::DefinePerspectiveProjection( double const& i_fieldOfView, double const& i_aspectRatio, double const& i_zMin, double const& i_zMax )
    {
        m_projectionMatrix.SetIdentity();

        double const yMax = i_zMin * tan( i_fieldOfView * 0.5 );
        double const yMin = - yMax;
        double const xMin = yMin * i_aspectRatio;
        double const xMax = - xMin;

        m_projectionMatrix[ 0 ] = ( 2.0 * i_zMin ) / ( xMax - xMin );
        m_projectionMatrix[ 5 ] = ( 2.0 * i_zMin ) / ( yMax - yMin );
        m_projectionMatrix[ 8 ] = ( xMax + xMin ) / ( xMax - xMin );
        m_projectionMatrix[ 9 ] = ( yMax + yMin ) / ( yMax - yMin );
        m_projectionMatrix[ 10 ] = - ( ( i_zMax + i_zMin ) / ( i_zMax - i_zMin ) );
        m_projectionMatrix[ 11 ] = - 1.0;
        m_projectionMatrix[ 14 ] = -( ( 2.0 * ( i_zMax * i_zMin ) ) / ( i_zMax - i_zMin ) );
        m_projectionMatrix[ 15 ] = 0.0;

        BuildVPMatrix();
    }

    void GeometryTransform::BuildVPMatrix() const
    {
        m_vpMatrix = mat::Multiply( m_viewFrame.BuildViewMatrix(), m_projectionMatrix );
    }

    GLMatrix GeometryTransform::BuildMVPMatrix( Frame const& i_model ) const
    {
        return GLMatrix ( mat::Multiply( i_model.BuildMatrix(), m_vpMatrix ) );
    }
}