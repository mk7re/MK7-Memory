#pragma once

#include "../types.hpp"
#include "EDriverID.hpp"

#include <prim/seadSafeString.h>

BEGIN_NAMESPACE(RaceSys)
{
    enum class EShyGuyColor : u8
    {
        Red,
        Blue,
        Yellow,
        Green,
        LightBlue,
        Pink,
        Black,
        White,
        MAX,
    };

    sead::SafeString GetShyGuyColorString(EDriverID, EShyGuyColor);
}