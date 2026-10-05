#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../RaceSys/EBodyID.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndDriverVoice/SIZE@0x30/
    public:
        // Note: The name is made up
        enum class EDriverID : s32
        {
            Bowser,
            Daisy,
            DonkeyKong,
            HoneyQueen,
            KoopaTroopa,
            Lakitu,
            Luigi,
            Mario,
            MetalMario,
            Mim,            // Male Mii (Red, Orange, Pink)
            Mif,            // Female Mii (Red, Orange, Pink)
            Peach,
            Rosalina,
            ShyGuy,
            Toad,
            Wario,
            Wiggler,
            Yoshi,
            Mim2,           // Male Mii (Yelow, Yellow-green, Sky-blue)
            Mim3,           // Male Mii (Green, Blue, Purple)
            Mim4,           // Male Mii (Brown, White, Black)
            Mif2,           // Female Mii (Yelow, Yellow-green, Sky-blue)
            Mif3,           // Female Mii (Green, Blue, Purple)
            Mif4            // Female Mii (Brown, White, Black)
        };

        // Note: The name is made up
        enum class EVoiceType : s32
        {
            USE_ITEM,             // ITM_TRW
            DROP_ITEM,            // ITM_PUT
            ITEM_HIT_SUCCESS,     // ITM_SCES
            OVERTAKE,             // OVTAK
            MUTEKI_HIT,           // 
            DASH,                 // DSH
            DASH_GLIDER,          // START_GLIDE
            TRICK,                // JP_ACT_S
            GLIDER_TRICK,         // JP_ACT
            STAR,                 // ITM_PWUP
            CANNON,               // CAN
            START_DASH_MISS,      // STR_FAIL
            DAMAGE_SMALL,         // DMG_S
            DAMAGE_LARGE,         // DMG_L
            DAMAGE_SPIN,          // DMG_SPN
            VOICE_RESTART,        // 
            AWARDS_FIRST,         // WINNING_RUN_1ST
            AWARDS_SECOND,        // WINNING_RUN_2ND
            AWARDS_THIRD,         // WINNING_RUN_3RD
            GOAL_TOP,             // GOL_TOP
            GOAL_GOOD,            // GOL_GOOD
            GOAL_BAD              // GOL_BAD
        };

        SndDriverVoice();
        void calcGoalVoice(s32);
        void playGoalVoice(s32);
        void playGoalVoice();
        void calcOvertakeVoice();
        void requestDelayVoice(s32);
        void requestOvettakeVoice(s32);
        void requestStartDashVoice(bool);
        void cancelRequestOvettakeVoice();
        void calc();
        void init(SndActorKart *, SndHandle *);
        void playVoice(s32);
        void stopAll(s32);
        void stopVoice(s32);
        
        /M/SndActorKart *m_snd_actor_kart/0x4/0x0/
        /M/SndHandle *m_snd_handle/0x4/0x4/
        /M/SndRndID *m_snd_rnd_id/0x4/0x8/
        /M/EVoiceType m_voice_type/0x4/0xc/
        /M/EDriverID m_driver_id/0x4/0x10/
        /M/s32 m_overtake_voice_timer_delay/0x4/0x14/
        /M/s32 m_overtake_voice_timer/0x4/0x18/
        /M/s32 m_delay/0x4/0x1c/
        /M/s32 m_voice_type_delay/0x4/0x20/
        /M/bool m_is_master/0x1/0x24/
        /M/bool m_disable_voice/0x1/0x25/
        /U/u8/0x1/0x26/
        /M/bool m_is_initialized/0x1/0x27/
        /M/bool m_is_playing_voice/0x1/0x28/
        /M/bool m_awards_voice_played/0x1/0x29/
        /M/RaceSys::EBodyID m_body_id/0x4/0x2c/
    /END/
}