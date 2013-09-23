/*
 * File:   MVPMatrix.cpp
 * Author: JoPe
 *
 * Created on 22 de septiembre de 2013, 17:43
 */

#include "GLT/MVPMatrix.hpp"



namespace glt
{
//    MVPMatrix::MVPMatrix()
//    : ModelMatrix ( mat::k_identity )
//    , ViewMatrix ( mat::k_identity )
//    , ProjectionMatrix( mat::k_identity )
//    {}

    void MVPMatrix::Reset()
    {
        ModelMatrix = mat::k_identity;
        ViewMatrix = mat::k_identity;
        ProjectionMatrix = mat::k_identity;
    }

    void MVPMatrix::SetOrthographicProjection( double const& i_xMin, double const& i_xMax, double const& i_yMin, double const& i_yMax, double const& i_zMin, double const& i_zMax)
    {}

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
