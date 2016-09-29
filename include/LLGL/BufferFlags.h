/*
 * BufferFlags.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_BUFFER_FLAG_H__
#define __LLGL_BUFFER_FLAG_H__


#include "Export.h"
#include "VertexFormat.h"
#include "IndexFormat.h"
#include "RenderSystemFlags.h"
#include <string>


namespace LLGL
{


//! Hardware buffer type enumeration.
enum class BufferType
{
    Vertex,         //!< Vertex buffer type.
    Index,          //!< Index buffer type.
    Constant,       //!< Constant buffer type (also called "Uniform Buffer Object").
    Storage,        //!< Storage buffer type (also called "Shader Storage Buffer Object" or "Read/Write Buffer").
    StreamOutput,   //!< Stream output buffer type (also called "Transform Feedback Buffer").
};

/**
\brief Storage buffer type enumeration.
\note Only supported with: Direct3D 11, Direct3D 12.
*/
enum class StorageBufferType
{
    Buffer,                     //!< Typed buffer.
    StructuredBuffer,           //!< Structured buffer.
    ByteAddressBuffer,          //!< Byte-address buffer.
    RWBuffer,                   //!< Typed read/write buffer.
    RWStructuredBuffer,         //!< Structured read/write buffer.
    RWByteAddressBuffer,        //!< Byte-address read/write buffer.
    AppendStructuredBuffer,     //!< Append structured buffer.
    ConsumeStructuredBuffer,    //!< Consume structured buffer.
};


//! Hardware buffer descriptor structure.
struct BufferDescriptor
{
    //! Vertex buffer descriptor structure.
    struct VertexBufferDescriptor
    {
        /**
        \brief Specifies the vertex format layout.
        \remarks This is required to tell the renderer how the vertex attributes are stored inside the vertex buffer and
        it must be the same vertex format which is used for the respective graphics pipeline shader program.
        */
        VertexFormat vertexFormat;
    };

    struct IndexBufferDescriptor
    {
        /**
        \brief Specifies the index format layout, which is basically only the data type of each index.
        \remarks The only valid format types for an index buffer are: DataType::UByte, DataType::UShort, and DataType::UInt.
        \see DataType
        */
        IndexFormat indexFormat;
    };

    struct StorageBufferDescriptor
    {
        /**
        \brief Specifies the storage buffer type.
        \remarks In OpenGL there are only generic storage buffers (or rather "Shader Storage Buffer Objects").
        \note Only supported with: Direct3D 11, Direct3D 12.
        */
        StorageBufferType type = StorageBufferType::Buffer;
    };

    //! Hardware buffer type. By default BufferType::Vertex.
    BufferType              type    = BufferType::Vertex;

    //! Buffer size (in bytes). By default 0.
    unsigned int            size    = 0;

    //! Buffer usage. By default BufferUsage::Static.
    BufferUsage             usage   = BufferUsage::Static;

    //! Vertex buffer type descriptor appendix.
    VertexBufferDescriptor  vertexBufferDesc;

    //! Index buffer type descriptor appendix.
    IndexBufferDescriptor   indexBufferDesc;

    //! Storage buffer type descriptor appendix.
    StorageBufferDescriptor storageBufferDesc;
};

/**
\brief Constant buffer shader-view descriptor structure.
\remarks This structure is used to describe the view of a constant buffer within a shader.
*/
struct ConstantBufferViewDescriptor
{
    std::string     name;           //!< Constant buffer name.
    unsigned int    index   = 0;    //!< Index of the constant buffer within the respective shader.
    unsigned int    size    = 0;    //!< Buffer size (in bytes).
};

/**
\brief Storage buffer shader-view descriptor structure.
\remarks This structure is used to describe the view of a storage buffer within a shader.
*/
struct StorageBufferViewDescriptor
{
    std::string         name;           //!< Storage buffer name.
    unsigned int        index   = 0;    //!< Index of the storage buffer within the respective shader.

    /**
    \brief Storage buffer type.
    \remarks For the OpenGL render system, this type is always 'StorageBufferType::Buffer',
    since GLSL only supports generic shader storage buffers. Here is an example:
    \code
    layout(std430, binding=0) buffer myBuffer
    {
        vec4 myBufferArray[];
    };
    \endcode
    \note Only supported with: Direct3D 11, Direct3D 12
    */
    StorageBufferType   type    = StorageBufferType::Buffer;
};


} // /namespace LLGL


#endif



// ================================================================================