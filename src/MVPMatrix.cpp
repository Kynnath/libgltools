/*
 * File:   MVPMatrix.cpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 17:43
 */

#include "GLT/MVPMatrix.hpp"

#include <cmath>
#include "VEC/Vector3.hpp"

namespace glt
{
    void MVPMatrix::Reset()
    {
        ModelMatrix = mat::k_identity;
        ViewMatrix = mat::k_identity;
        ProjectionMatrix = mat::k_identity;
    }

    void MVPMatrix::SetOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax)
    {
        ProjectionMatrix.SetIdentity();

        ProjectionMatrix[ 0 ] = 2.0 / ( i_xMax - i_xMin );
        ProjectionMatrix[ 5 ] = 2.0 / ( i_yMax - i_yMin );
        ProjectionMatrix[ 10 ] = - 2.0 / ( i_zMax - i_zMin );
        ProjectionMatrix[ 12 ] = - ( ( i_xMax + i_xMin ) / ( i_xMax - i_xMin ) );
        ProjectionMatrix[ 13 ] = - ( ( i_yMax + i_yMin ) / ( i_yMax - i_yMin ) );
        ProjectionMatrix[ 14 ] = - ( ( i_zMax + i_zMin ) / ( i_zMax - i_zMin ) );
    }

    void MVPMatrix::SetPerspectiveProjection( double const& i_fieldOfView, double const& i_aspectRatio, double const& i_zMin, double const& i_zMax )
    {
        ProjectionMatrix.SetIdentity();

        double const yMax = i_zMin * tanf( i_fieldOfView * 0.5 );
        double const yMin = - yMax;
        double const xMin = yMin * i_aspectRatio;
        double const xMax = - xMin;

        ProjectionMatrix[ 0 ] = ( 2.0 * i_zMin ) / ( xMax - xMin );
        ProjectionMatrix[ 5 ] = ( 2.0 * i_zMin ) / ( yMax - yMin );
        ProjectionMatrix[ 8 ] = ( xMax + xMin ) / ( xMax - xMin );
        ProjectionMatrix[ 9 ] = ( yMax + yMin ) / ( yMax - yMin );
        ProjectionMatrix[ 10 ] = - ( ( i_zMax + i_zMin ) / ( i_zMax - i_zMin ) );
        ProjectionMatrix[ 11 ] = - 1.0;
        ProjectionMatrix[ 14 ] = -( ( 2.0 * ( i_zMax * i_zMin ) ) / ( i_zMax - i_zMin ) );
        ProjectionMatrix[ 15 ] = 0.0;
    }

    void MVPMatrix::SetView( vec::Vector3 const& i_position, vec::Vector3 const& i_forward, vec::Vector3 const& i_up )
    {
        mat::Matrix4 const rotationMat ( BuildViewRotationMatrix( i_forward, i_up ) );
        mat::Matrix4 const translationMat ( BuildViewTranslationMatrix( i_position ) );

        ViewMatrix = mat::Multiply( rotationMat, translationMat );
    }

    GLMatrix MVPMatrix::BuildMVPMatrix() const
    {
        mat::Matrix4 ModelViewProjection ( ProjectionMatrix );
        ModelViewProjection.Multiply( ViewMatrix );
        ModelViewProjection.Multiply( ModelMatrix );

        GLMatrix MVPMatrixGL;

        for ( int i = 0; i < 16; ++i )
        {
            MVPMatrixGL.m_data[ i ] = (float)ModelViewProjection.m_data[ i ];
        }

        return MVPMatrixGL;
    }

    mat::Matrix4 BuildViewRotationMatrix( vec::Vector3 const& i_forward, vec::Vector3 const& i_up )
    {
        vec::Vector3 const zVec ( vec::Scale( i_forward, -1.0 ) );
        vec::Vector3 const xVec ( vec::CrossProduct( i_up, zVec ) );

        mat::Matrix4 const rotationMat =
        {
            {
                xVec[ 0 ], xVec[ 1 ], xVec[ 2 ], 0.0,
                i_up[ 0 ], i_up[ 1 ], i_up[ 2 ], 0.0,
                zVec[ 0 ], zVec[ 1 ], zVec[ 2 ], 0.0,
                      0.0,       0.0,       0.0, 1.0
            }
        };

        return rotationMat;
    }

    mat::Matrix4 BuildViewTranslationMatrix( vec::Vector3 const& i_position )
    {
        mat::Matrix4 translationMat ( mat::k_identity );
        translationMat( 3, 0 ) = - i_position[ 0 ];
        translationMat( 3, 1 ) = - i_position[ 1 ];
        translationMat( 3, 2 ) = - i_position[ 2 ];

        return translationMat;
    }

}
