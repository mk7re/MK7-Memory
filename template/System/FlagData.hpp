#pragma once

#include "../types.hpp"

#include "../RaceSys/ETitleType.hpp"

BEGIN_NAMESPACE(System)
{
    /START_STRUCT/NAME@FlagData/SIZE@0x5F4/
        // NOTE: made up name
        /START_STRUCT/NAME@ProfileData/SIZE@0x4/
            /M/u32 vr : 17, title : 5, _unk0 : 2, gp : 6, _unk1 : 2/0x4/0x0/

            auto get_vr() { return static_cast<u32>(vr); }
            void set_vr(u32 value) { vr = value; }

            auto get_gp() { return static_cast<u32>(gp); }
            void set_gp(u32 value) { gp = value; }

            auto get_title() { return static_cast<RaceSys::ETitleType>(title); }
            void set_title(RaceSys::ETitleType value) { title = std::to_underlying(value); }
        /END/

        /M/u32 coins/0x4/0x358/
        /M/u32 streetpass_tags/0x4/0x554/
        /M/u32 wins/0x4/0x564/
        /M/u32 losses/0x4/0x568/
        /M/ProfileData profile_data/0x4/0x56C/
    /END/
}