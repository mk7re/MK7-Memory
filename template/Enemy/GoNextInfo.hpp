#pragma once

#include <math/seadVector.h>

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@GoNextInfo/SIZE@0x30/
    public:
        /M/bool m_is_relocate/0x1/0x0/
        /M/sead::Vector3f m_kart_pos/0xC/0x4/
        /M/s32 m_base_point_index/0x4/0x10/ // point whose next points are chosen from, or the point to relocate to
        /M/s32 m_target_point_index/0x4/0x14/
        /M/s32 m_branch_num/0x4/0x18/
        /M/s32 m_branch_index/0x4/0x1C/
        /M/u32 m_search_mode/0x4/0x20/
        /M/bool m_do_select_shortcut/0x1/0x24/
        /M/bool m_do_not_select_backward/0x1/0x25/
        /M/bool m_do_select_root_branch/0x1/0x26/
        /M/bool m_is_killer/0x1/0x27/
        /M/f32 m_corner_line_shift/0x4/0x2C/
    /END/
}
