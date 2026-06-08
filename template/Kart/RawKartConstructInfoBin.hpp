#pragma once

#include "../types.hpp"

#include "../RaceSys/EDriverID.hpp"

BEGIN_NAMESPACE(Kart)
{
    // Representation of the raw `Common.szs/Kart/KartConstructInfo.bin` file
	/START_STRUCT/NAME@RawKartConstructInfoBin/SIZE@0x10494/
	public:
        /START_STRUCT/NAME@CharacterInfo/SIZE@0x18/
            inline char getWeightClass() const {
                return m_weight_class[0];
            }

            /M/f32 m_inverse_scale/0x4/0x0/
            /M/char m_short_name[4]/0x4/0x4/
            /M/char m_weight_class[4]/0x4/0x8/
            /M/char m_long_name[12]/0xc/0xc/
        /END/

        /U/u32/0x4/0x0/
        /U/u32/0x4/0x4/
        /M/CharacterInfo m_character_info[static_cast<u32>(RaceSys::EDriverID::MAX)]/0x1b0/0x518/
	/END/
}