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
        /*M3DVector3f x, z;

			// Make rotation matrix
			// Z vector is reversed
			z[0] = -vForward[0];
			z[1] = -vForward[1];
			z[2] = -vForward[2];*/
        vec::Vector3 const zVec ( vec::Scale( i_forward, -1.0 ) );
        vec::Vector3 const xVec ( vec::CrossProduct( i_up, zVec ) );
/*
			// X vector = Y cross Z
			m3dCrossProduct3(x, vUp, z);

			// Matrix has no translation information and is
			// transposed.... (rows instead of columns)
			#define M(row,col)  m[col*4+row]
			   M(0, 0) = x[0];
			   M(0, 1) = x[1];
			   M(0, 2) = x[2];
			   M(0, 3) = 0.0;
			   M(1, 0) = vUp[0];
			   M(1, 1) = vUp[1];
			   M(1, 2) = vUp[2];
			   M(1, 3) = 0.0;
			   M(2, 0) = z[0];
			   M(2, 1) = z[1];
			   M(2, 2) = z[2];
			   M(2, 3) = 0.0;
			   M(3, 0) = 0.0;
			   M(3, 1) = 0.0;
			   M(3, 2) = 0.0;
			   M(3, 3) = 1.0;
			#undef M


            if(bRotationOnly)
                return;

            // Apply translation too
            M3DMatrix44f trans, M;
            m3dTranslationMatrix44(trans, -vOrigin[0], -vOrigin[1], -vOrigin[2]);

            m3dMatrixMultiply44(M, m, trans);

            // Copy result back into m
            memcpy(m, M, sizeof(float)*16);
            }*/

    }

    GLMatrix MVPMatrix::BuildMVPMatrix() const
    {
        mat::Matrix4 ModelViewProjection ( ProjectionMatrix );
        ModelViewProjection.Multiply( ViewMatrix );
        ModelViewProjection.Multiply( ModelMatrix );

        GLMatrix MVPMatrixGL;

        for ( int i = 0; i < 16; ++i )
        {
            MVPMatrixGL.data[ i ] = (float)ModelViewProjection.data[ i ];
        }

        return MVPMatrixGL;
    }
}
