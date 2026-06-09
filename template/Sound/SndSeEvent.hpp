#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Utility/Random.hpp"

#include <sound/seadSoundHandle.hpp>

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
            CHARA_DECIDE_VOICE = 0x48,
            CHARA_PRESENT_VOICE = 0x49,
            SE_SYS_DECIDE_M = 0x5A,
            SE_SYS_BUTTON_INVALID = 0x5B,
            READY_TO_GO_VOICE = 0x6A,
            SE_SYS_NAME_APPEAR = 0x71,
            SE_SYS_NAME_DISAPPEAR = 0x72,
            SE_SYS_FRIEND_BTN_TURN_ON = 0x76,
            SE_SYS_FRIEND_BTN_TURN_OFF = 0x77,
            SE_SYS_DECIDE_M_8A = 0x8A
        };

        enum class ETitleCallType : s32
        {
            DEFAULT_TITLE,
            MARIO_GLIDER,
            MARIO_UNDERWATER,
            PEACH,
            DK,
            YOSHI
        };

        SndSeEvent();
        void initialize();
        void initScene();
        void playTitleCall();
        void stopTitleCall();
        void setTitleCallType(s32);
        void playReadyToGoVoice(s32);
        void playCharaDecideVoice(s32);
        void playCharaPresentVoice(s32);
        void exec(EEvent, s32);

        /M/bool m_enable_se/0x1/0x0/
        /M/Utility::Random m_random/0x18/0x4/
        /M/SndEngine *m_snd_engine/0x4/0x1c/
        /M/ETitleCallType m_title_call_type/0x4/0x20/
        /M/bool m_title_call_played/0x1/0x24/
        /M/bool m_alt_title_screen_unlocked/0x1/0x25/
        /M/sead::SoundHandle *m_snd_handle/0x4/0x28/
    /END/
}