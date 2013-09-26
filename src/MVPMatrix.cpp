/*
 * File:   MVPMatrix.cpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 17:43
 */

#include "GLT/MVPMatrix.hpp"



namespace glt
{
    void MVPMatrix::Reset()
    {
        ModelMatrix = mat::k_identity;
        ViewMatrix = mat::k_identity;
        ProjectionMatrix = mat::k_identity;
    }

    /*void m3dMakePerspectiveMatrix(M3DMatrix44f mProjection, float fFov, float fAspect, float zMin, float zMax)
	{
	m3dLoadIdentity44(mProjection); // Fastest way to get most valid values already in place

    float yMax = zMin * tanf(fFov * 0.5f);
    float yMin = -yMax;
	float xMin = yMin * fAspect;
    float xMax = -xMin;

	mProjection[0] = (2.0f * zMin) / (xMax - xMin);
	mProjection[5] = (2.0f * zMin) / (yMax - yMin);
	mProjection[8] = (xMax + xMin) / (xMax - xMin);
	mProjection[9] = (yMax + yMin) / (yMax - yMin);
	mProjection[10] = -((zMax + zMin) / (zMax - zMin));
	mProjection[11] = -1.0f;
	mProjection[14] = -((2.0f * (zMax*zMin))/(zMax - zMin));
	mProjection[15] = 0.0f;
	}

*/
    void MVPMatrix::SetOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax)
    {
        ProjectionMatrix.SetIdentity();

        ProjectionMatrix[ 0 ] = 2.0 / ( i_xMax - i_xMin );
        ProjectionMatrix[ 5 ] = 2.0 / ( i_yMax - i_yMin );
        ProjectionMatrix[ 10 ] = -2.0 / ( i_zMax - i_zMin );
        ProjectionMatrix[ 12 ] = -( ( i_xMax + i_xMin ) / ( i_xMax - i_xMin ) );
        ProjectionMatrix[ 13 ] = -( ( i_yMax + i_yMin ) / ( i_yMax - i_yMin ) );
        ProjectionMatrix[ 14 ] = -( ( i_zMax + i_zMin ) / ( i_zMax - i_zMin ) );
    }

    void MVPMatrix::SetPerspectiveProjection( double const& i_fieldOfView, double const& i_aspectRatio, double const& i_zMin, double const& i_zMax )
    {}

    void MVPMatrix::SetView( vec::Vector3 const& i_position, vec::Vector3 const& i_direction, vec::Vector3 const& i_up )
    {}

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
