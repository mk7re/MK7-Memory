#pragma once

#include "../types.hpp"

#include "EGrandPrixRecord.hpp"
#include "EGrandPrixTrophy.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    /START_STRUCT/NAME@GrandPrixData/SIZE@0xC/
        /M/bool valid/0x1/0x0/
        /M/EGrandPrixRecord record/0x4/0x4/
        /M/EGrandPrixTrophy trophy/0x4/0x8/
    /END/
}