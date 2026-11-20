#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    enum class EGrandPrixRecord : u32
    {
        NO_RECORD,
        RECORD_1,   // Unused. Maybe unused rank "C"?
        RECORD_2,   // Unused. Maybe unused rank "B"?
        RECORD_3,   // Unused. Maybe unused rank "A"?
        RECORD_1_STAR,
        RECORD_2_STAR,
        RECORD_3_STAR
    };
}