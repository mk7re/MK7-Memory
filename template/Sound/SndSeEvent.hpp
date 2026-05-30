#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndSeEvent/SIZE@0x2c/
    public:
        enum class EEvent : u8
        {
            SE_SYS_CURSOR_1 = 0x01,
            SE_SYS_CURSOR_OUT_2 = 0x02,
            SE_SYS_CURSOR_3 = 0x03,
            SE_SYS_CANCEL_L = 0x09,
            SE_RC_PAUSE_TO_RETRY = 0x28,
            SE_RC_PAUSE_TO_RESELECT = 0x29,
            SE_PAUSE_TO_REPLAY= 0x2B,
            SE_RC_PAUSE_EXIT_GAME = 0x2C,
            SE_SYS_DECIDE_M = 0x5A,
            SE_SYS_BUTTON_INVALID = 0x5B,
            SE_SYS_NAME_APPEAR = 0x71,
            SE_SYS_NAME_DISAPPEAR = 0x72,
            SE_SYS_FRIEND_BTN_TURN_ON = 0x76,
            SE_SYS_FRIEND_BTN_TURN_OFF = 0x77,
            SE_SYS_DECIDE_M_8A = 0x8A
        };
    /END/
}