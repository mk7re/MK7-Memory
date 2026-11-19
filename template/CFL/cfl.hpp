#pragma once

#include "../types.hpp"

#include <3ds/mii.h> // CFLStoreData

BEGIN_GLOBAL_NAMESPACE

enum class CFLFavoriteColor : u32 {
    RED,
    ORANGE,
    YELLOW,
    YELLOW_GREEN,
    GREEN,
    BLUE,
    SKY_BLUE,
    PINK,
    PURPLE,
    BROWN,
    WHITE,
    BLACK,

    MAX
};

/START_STRUCT/NAME@CFLAdditionalInfo/SIZE@0x40/
    /M/u32 skin_color_or_gender/0x4/0x38/
/END/

s32 CFL_GetAdditionalInfo(CFLAdditionalInfo *, s32, void *, u16, bool);

END_GLOBAL_NAMESPACE