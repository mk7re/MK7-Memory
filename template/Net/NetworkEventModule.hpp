#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkEventModule/SIZE@0xB4/
    public:
        /START_STRUCT/NAME@EventHandleArg/SIZE@0x8/
            /M/u32 player_id/0x4/0x0/
            /M/u16 tick/0x2/0x6/
        /END/

        /START_STRUCT/NAME@Slot/SIZE@0x24/
            /M/u32 frame/0x4/0x4/
        /END/
    /END/
}