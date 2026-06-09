#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndDriverVoice/SIZE@0x30/
    public:
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
        /M/s32 m_voice_type/0x4/0xc/
        /M/s32 m_mii_voice_type/0x4/0x10/
        /M/s32 m_overtake_voice_timer_delay/0x4/0x14/
        /M/s32 m_overtake_voice_timer/0x4/0x18/
        /M/s32 m_delay/0x4/0x1c/
        /M/s32 m_voice_type_delay/0x4/0x20/
        /M/bool m_is_master/0x1/0x24/
        /M/bool m_disable_voice/0x1/0x25/
        /M/bool m_is_playing_voice/0x1/0x28/
        /M/bool m_awards_voice_played/0x1/0x29/
    /END/
}