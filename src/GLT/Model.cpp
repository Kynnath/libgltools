/*
 * File:   Model.cpp
 * Author: JoPe
 *
 * Created on 1 de septiembre de 2013, 20:47
 */

#include "Model.hpp"

#include <algorithm>
#include <cstring>

namespace glt
{
    Model::Model( obj::Object const& i_object )
    {
        // Convert obj file to OGL ready model
        // Build vertices from obj vertex data, collect indices into index list
        // For each vertex in the object face list:
        // - find vertex in vertex list (keep in mind 1/1/1 is a different vertex to 1/2/1)
        //  - if not added, add it to vertex list
        // - record the index number in the index list

        for ( auto const& face : i_object.m_faceList )
        {
            for ( int vertexIndex ( 0 ); vertexIndex < 3; ++vertexIndex )
            {
                Vertex vertex;
                memcpy( &vertex.m_position, &i_object.m_coordinatesList[ (unsigned int)face.m_coordinates[(unsigned int)vertexIndex]-1 ].m_data, sizeof(vertex.m_position) );
                if ( face.m_texture[ (unsigned int)vertexIndex ] != 0 )
                {
                    memcpy( &vertex.m_texture, &i_object.m_textureList[ (unsigned int)face.m_texture[(unsigned int)vertexIndex]-1 ].m_data, sizeof(vertex.m_texture) );
                }

                std::vector<Vertex>::const_iterator searchResult ( std::find( m_vertexList.begin(), m_vertexList.end(), vertex ) );
                if ( searchResult != m_vertexList.end() )
                {
                    m_indexList.push_back( GLuint( searchResult - m_vertexList.begin() ) );
                }
                else
                {
                    m_vertexList.push_back( vertex );
                    m_indexList.push_back( GLuint( m_vertexList.size() - 1 ) );
                }
            }
        }
    }
}