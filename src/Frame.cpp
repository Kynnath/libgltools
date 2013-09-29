/*
 * File:   Frame.cpp
 * Author: JoPe
 *
 * Created on 28 de septiembre de 2013, 11:02
 */

#include "GLT/Frame.hpp"

namespace glt
{

    mat::Matrix4 Frame::BuildRotationMatrix() const
    {
        vec::Vector3 const right ( vec::CrossProduct( m_up, m_forward ) );

        mat::Matrix4 const rotationMat =
        {
            {
                    right[ 0 ],     right[ 1 ],     right[ 2 ], 0.0,
                     m_up[ 0 ],      m_up[ 1 ],      m_up[ 2 ], 0.0,
                m_forward[ 0 ], m_forward[ 1 ], m_forward[ 2 ], 0.0,
                           0.0,            0.0,            0.0, 1.0
            }
        };

        return rotationMat;
    }

    mat::Matrix4 Frame::BuildTranslationMatrix() const
    {
        mat::Matrix4 translationMat ( mat::k_identity );

        translationMat( 3, 0 ) = m_position[ 0 ];
        translationMat( 3, 1 ) = m_position[ 1 ];
        translationMat( 3, 2 ) = m_position[ 2 ];

        return translationMat;
    }

    mat::Matrix4 Frame::BuildViewRotationMatrix() const
    {
        vec::Vector3 const zVec ( vec::Scale( m_forward, -1.0 ) );
        vec::Vector3 const xVec ( vec::CrossProduct( m_up, zVec ) );

        mat::Matrix4 const rotationMat =
        {
            {
                xVec[ 0 ], xVec[ 1 ], xVec[ 2 ], 0.0,
                m_up[ 0 ], m_up[ 1 ], m_up[ 2 ], 0.0,
                zVec[ 0 ], zVec[ 1 ], zVec[ 2 ], 0.0,
                      0.0,       0.0,       0.0, 1.0
            }
        };

        return rotationMat;
    }

    mat::Matrix4 Frame::BuildViewTranslationMatrix() const
    {
        mat::Matrix4 translationMat ( mat::k_identity );

        translationMat( 3, 0 ) = - m_position[ 0 ];
        translationMat( 3, 1 ) = - m_position[ 1 ];
        translationMat( 3, 2 ) = - m_position[ 2 ];

        return translationMat;
    }

    mat::Matrix4 Frame::BuildMatrix() const
    {
        mat::Matrix4 const rotationMatrix ( BuildRotationMatrix() );
        mat::Matrix4 const translationMatrix ( BuildTranslationMatrix() );

        return ( mat::Multiply( rotationMatrix, translationMatrix ) );
    }

    mat::Matrix4 Frame::BuildViewMatrix() const
    {
        mat::Matrix4 const rotationMatrix ( BuildViewRotationMatrix() );
        mat::Matrix4 const translationMatrix ( BuildViewTranslationMatrix() );

        return ( mat::Multiply( rotationMatrix, translationMatrix ) );
    }
}