/*
 * File:   MatrixStack.cpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 22:35
 */

#include "MatrixStack.hpp"

namespace glt
{
    void MatrixStack::Reset()
    {
        m_matrixStack.clear();
        m_matrixStack.push_back( mat::k_identity );
    }

    void MatrixStack::PushMatrix( mat::Matrix4 const& i_matrix )
    {
        m_matrixStack.push_back( i_matrix );
    }

    void MatrixStack::PopMatrix()
    {
        m_matrixStack.pop_back();
    }

    mat::Matrix4 const& MatrixStack::GetMatrix() const
    {
        return m_matrixStack.back();
    }
}