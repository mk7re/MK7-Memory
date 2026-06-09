#pragma once

#include "../types.hpp"

BEGIN_GLOBAL_NAMESPACE

/START_STRUCT/NAME@CFLStoreData/SIZE@0x60/
    /M/u8 height/0x1/0x2e/
    /M/u8 weight/0x1/0x2f/
/END/

/START_STRUCT/NAME@CFLAdditionalInfo/SIZE@0x40/
    /M/u32 skin_color_or_gender/0x4/0x38/
/END/

s32 CFL_GetAdditionalInfo(CFLAdditionalInfo *, s32, void *, u16, bool);

END_GLOBAL_NAMESPACE