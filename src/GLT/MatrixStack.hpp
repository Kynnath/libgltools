/*
 * File:   MatrixStack.hpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 22:35
 */

#ifndef MATRIXSTACK_HPP
#define	MATRIXSTACK_HPP

#include <vector>
#include "MAT/Matrix4.hpp"

namespace glt
{
    class MatrixStack
    {
        public:
            MatrixStack() = default;
            void Reset();
            void PushMatrix( mat::Matrix4 const& i_matrix );
            void PopMatrix();
            mat::Matrix4 const& GetMatrix() const;

        protected:
            std::vector< mat::Matrix4 > m_matrixStack;
    };
}

#endif	/* MATRIXSTACK_HPP */

