#pragma once
#include "pch.h"
#include <guiddef.h>
#include <cstdint>
#include <functional>
#include <cstddef>

struct GUIDHash
{
    size_t operator()(const GUID& g) const noexcept
    {
        const uint64_t* p = reinterpret_cast<const uint64_t*>(&g);
        return std::hash<uint64_t>()(p[0]) ^ std::hash<uint64_t>()(p[1]);
    }
};
