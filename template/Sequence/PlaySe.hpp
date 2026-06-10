#pragma once

#include "../types.hpp"
#include "../Sound/SndSeEvent.hpp"

BEGIN_NAMESPACE(Sequence)
{
    void PlaySe(Sound::SndSeEvent::EEvent);
    void PlaySe(Sound::SndSeEvent::EEvent, s32);
}