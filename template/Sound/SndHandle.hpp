#pragma once

#include "../types.hpp"

#include <sound/seadSoundHandle.hpp>

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndHandle/SIZE@0x4/
    public:
        SndHandle();
        ~SndHandle();
        bool writeSeqVarLocal(s32, s16);

        /M/sead::SoundHandle m_sound_handle/0x4/0x0/
    /END/
};