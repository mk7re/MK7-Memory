#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    enum class ERacePlayMode : u32
    {
        SinglePlayer,
        MultiPlayer,
        Online,
        Demo,       // Title demo, awards and course preview
        Replay,
        MAX,
    };
}