#pragma once

#include "../types.hpp"
#include "../versions.h"

BEGIN_NAMESPACE(Object)
{
    enum class EEngineType : u32
    {
        Character,
        Camera,
        Render,
        System,
        Sequence,
#if GAME_VERSION == VERSION_E3_2010
        _5,
        Sound,
        Debug,
#else
        Mii,
        Sound,
        Network,
        Effect,
        _9,
#endif
        MAX
    };
}