#pragma once

#include "../types.hpp"

#include "SoundID.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_STRUCT/NAME@SndRndID/SIZE@0x10/
        SndRndID();
        SndRndID(u32, u8);
        u32 getFreeRandID();
        void setBeforeUseID(u32, bool);
        u32 getRandID_Allow2Times();
        void setBeforeUseID_Allow2Times(u32, bool);

        /M/ESoundID m_sound_id/0x4/0x0/
        /M/u8 m_num_random_sounds/0x1/0xa/
    /END/
}