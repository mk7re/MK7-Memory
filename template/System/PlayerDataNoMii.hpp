#pragma once

#include "../types.hpp"

#include "PlayerID.hpp"
#include "../RaceSys/Rate.hpp"

BEGIN_NAMESPACE(System)
{
    /START_STRUCT/NAME@PlayerDataNoMii/SIZE@0x3C/
        enum EFlags : u8 {
            COUNTRY_FLAG_VISIBLE = 0x01,
            ONLINE_STATUS_VISIBLE = 0x02,
            GOLD_WHEEL_UNLOCKED = 0x04,
            RANK_3_STARS = 0x08,
            RANK_2_STARS = 0x10,
            RANK_1_STARS = 0x20,
        };

        /M/RaceSys::Rate rate/0x4/0x0/
        /M/u32 wins/0x4/0x4/
        /M/u32 losses/0x4/0x8/
        /U/s32/0x4/0xc/
        /U/s32/0x4/0x10/
        /M/u16 driver/0x2/0x14/
        /M/u16 body/0x2/0x16/
        /M/u16 tire/0x2/0x18/
        /M/u16 wing/0x2/0x1a/
        /U/u32/0x4/0x1c/
        /M/PlayerID playerId/0x10/0x20/
        /M/u32 myPrincipalId/0x4/0x30/
        /M/s16 country/0x2/0x34/
        /M/s16 latitude/0x2/0x36/
        /M/s16 longitude/0x2/0x38/
        /M/u8 region/0x1/0x3a/
        /M/u8 flags/0x1/0x3b/
    /END/
}