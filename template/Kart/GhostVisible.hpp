#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@GhostVisible/SIZE@0x104/
    public:
        // NOTE: guessed name
        /START_STRUCT/NAME@SInfo/SIZE@0x14/
            /M/s32 m_player_id/0x4/0x0/
            /M/InfoProxy *m_info_proxy/0x4/0x4/
            /U/f32/0x4/0x8/ // distance related
            /U/f32/0x4/0xC/
            /U/u8/0x1/0x10/
        /END/

        /M/InfoProxy *m_info_proxy/0x4/0x0/
        /M/Camera *m_camera/0x4/0x4/
        /M/sead::PtrArray<void> m_entries/0xC/0x8/ // same type as 0xBC field
        /M/s32 m_last_player_id/0x4/0x14/
        /M/SInfo *m_info_pointer/0x4/0x18/
        /M/SInfo m_info_value[KART_MAX]/0xA0/0x1C/
        /M/void *unk_0xBC[KART_MAX]/0x20/0xBC/
        /M/s32 unk_0xDC[KART_MAX]/0x20/0xDC/ // player IDs?
        /U/s32/0x4/0xFC/ // sort of counter
        /M/RaceSys::LapRankChecker *m_lap_rank_checker/0x4/0x100/
    /END/
}