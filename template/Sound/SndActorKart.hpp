#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "SndActorBase.hpp"
#include "SndHandle.hpp"
#include "SoundID.hpp"
#include "../RaceSys/EBodyID.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndActorKart/BASE@SndActorBase/SIZE@0x204/BSIZE@0xD8/
    public:
        // Note: The name is made up.
        /START_STRUCT/NAME@BodySoundInfo/SIZE@0x1C/
            /M/ESoundID m_sound/0x4/0x0/
            /M/f32 m_pitch/0x4/0x4/
            /U/f32/0x4/0x8/
            /U/f32/0x4/0xc/
            /U/f32/0x4/0x10/
            /U/f32/0x4/0x14/
            /U/f32/0x4/0x18/
        /END/

        virtual void startSound(u32, Sound::SndHandle*);
        virtual void holdSound(u32, Sound::SndHandle*);
        
        /M/BodySoundInfo *m_sound_info/0x4/0x120/
        /M/s8 m_horn_timer/0x1/0x181/
        /M/s8 m_horn_counter/0x1/0x182/
        /M/Sound::SndHandle m_0x1c4/0x4/0x1c4/
        /M/Sound::SndHandle m_driver_voice_snd_handle/0x4/0x1dc/
        /M/Kart::Vehicle* m_vehicle/0x4/0x1E0/
        /M/s32 m_player_id/0x4/0x1E4/
        /U/bool/0x1/0x1F1/
        /M/s32 m_race_rank/0x4/0x1F4/
        /M/s8 m_miniturbo_level/0x1/0x1FC/
        /M/bool m_killer_state/0x1/0x1FE/
        /M/bool m_star_state/0x1/0x1FF/

        static BodySoundInfo s_body_sound_info_list[static_cast<u32>(RaceSys::EBodyID::MAX)];    // 0x005e48b8 (VERSION_EUR_DLP)
    /END/
}