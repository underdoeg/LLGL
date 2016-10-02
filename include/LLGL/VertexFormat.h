/*
 * VertexFormat.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_VERTEX_FORMAT_H__
#define __LLGL_VERTEX_FORMAT_H__


#include "Export.h"
#include "Image.h"
#include "VertexAttribute.h"
#include <vector>


namespace LLGL
{


/**
\brief Vertex format descriptor class.
\remarks A vertex format is required to describe how the vertex attributes are supported inside a vertex buffer.
\see VertexBuffer
*/
class LLGL_EXPORT VertexFormat
{

    public:

        /**
        \brief Adds a new vertex attribute to this vertex format with a specified name (used for GLSL).
        \param[in] name Specifies the attribute name.
        \param[in] dataType Specifies the data type of the attribute components.
        \param[in] components Specifies the number of attribute components. This must be 1, 2, 3, or 4.
        \param[in] conversion Specifies whether to convert integral vertex attributes to normalized floating-point types. By default false.
        \param[in] perInstance Specifies whether this is per-instance data. If false, this is per-vertex data. By default false.
        \remarks This is equivalent to:
        \code
        AddAttribute(name, 0, dataType, components, conversion);
        \endcode
        \throws std::invalid_argument If 'components' is neither 1, 2, 3, nor 4.
        \see AddAttribute(const std::string&, unsigned int, const DataType, unsigned int, bool, bool)
        */
        void AddAttribute(
            const std::string& name,
            const DataType dataType,
            unsigned int components,
            bool conversion = false,
            bool perInstance = false
        );

        /**
        \brief Adds a new vertex attribute to this vertex format with a specified semantic (used for HLSL).
        \param[in] semanticName Specifies the semantic name (For Direct3D).
        \param[in] semanticIndex Specifies the semantic index (For Direct3D).
        \param[in] dataType Specifies the data type of the attribute components.
        \param[in] components Specifies the number of attribute components. This must be 1, 2, 3, or 4.
        \param[in] conversion Specifies whether to convert integral vertex attributes to normalized floating-point types. By default false.
        \param[in] perInstance Specifies whether this is per-instance data. If false, this is per-vertex data. By default false.
        \throws std::invalid_argument If 'components' is neither 1, 2, 3, nor 4.
        */
        void AddAttribute(
            const std::string& semanticName,
            unsigned int semanticIndex,
            const DataType dataType,
            unsigned int components,
            bool conversion = false,
            bool perInstance = false
        );

        /**
        \brief Append all attributes of the specified vertex format.
        \remarks This can be used to build a vertex format for vertex buffer arrays.
        */
        void AppendAttributes(const VertexFormat& vertexFormat);

        /**
        \brief Returns the list of all vertex attributes.
        \see AddAttribute
        */
        inline const std::vector<VertexAttribute>& GetAttributes() const
        {
            return attributes_;
        }

        //! Returns the size of this vertex format (in bytes).
        inline unsigned int GetFormatSize() const
        {
            return formatSize_;
        }

    private:
        
        std::vector<VertexAttribute>    attributes_;
        unsigned int                    formatSize_ = 0;

};


} // /namespace LLGL


#endif



// ================================================================================
