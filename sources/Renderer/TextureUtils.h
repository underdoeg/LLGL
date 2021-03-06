/*
 * TextureUtils.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2019 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_TEXTURE_UTILS_H
#define LLGL_TEXTURE_UTILS_H


#include <LLGL/TextureFlags.h>


namespace LLGL
{

//TODO: merge this header and source iwth "DescriptorHelper.cpp/h"

/* ----- Structures ----- */

// Subresource data size structure with stride per row, stride per array layer, and whole data size.
struct SubresourceLayout
{
    std::uint32_t rowStride     = 0; // Bytes per row
    std::uint32_t layerStride   = 0; // Bytes per layer
    std::uint32_t dataSize      = 0; // Bytes per resource
};


/* ----- Functions ----- */

// Calculates the actual 3D offset for the specified texture type.
LLGL_EXPORT Offset3D CalcTextureOffset(const TextureType type, const Offset3D& offset, std::uint32_t baseArrayLayer);

// Calculates the actual 3D extent for the specified texture and range of array layers.
LLGL_EXPORT Extent3D CalcTextureExtent(const TextureType type, const Extent3D& extent, std::uint32_t numArrayLayers);

// Calculates the size and strides for a subresource of the specified format and extent.
LLGL_EXPORT SubresourceLayout CalcSubresourceLayout(const Format format, const Extent3D& extent);

// Returns true if the specified flags for texture creation require MIP-map generation at creation time.
LLGL_EXPORT bool MustGenerateMipsOnCreate(const TextureDescriptor& textureDesc);

// Returns the samples clamped to the range [1, LLGL_MAX_NUM_SAMPLES].
LLGL_EXPORT std::uint32_t GetClampedSamples(std::uint32_t samples);


} // /namespace LLGL


#endif



// ================================================================================
