#pragma once

#include <container/seadPtrArray.h>

#include "../../forward.hpp"
#include "../../types.hpp"

#include "base.hpp"
#include "../ObjectBase.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@MapdataEnemyPathData/SIZE@0x48/
        /M/u16 m_start_point/0x2/0x0/
        /M/u16 m_point_num/0x2/0x2/
        /M/u16 m_previous_points[16]/0x20/0x4/ // path indices
        /M/u16 m_next_points[16]/0x20/0x24/ // path indices
        /M/u32 m_link_end_flags/0x4/0x44/ // bit n: previous path n is joined at its first point, bit 16 + n: next path n is joined at its last point
    /END/

    /START_CLASS/NAME@MapdataEnemyPath/SIZE@0x40/BASE@MapdataDataBase<MapdataEnemyPathData>/BSIZE@0x4/
    public:
        void createDepth_(s32, MapdataEnemyPathAccessor *);

        /M/s8 m_find_type/0x1/0x4/ // -2 by default, -3/-4 when a point of the path has that path_find_options
        /M/s32 m_start_adjust/0x4/0x8/ // added to m_start_point
        /M/s32 m_count_adjust/0x4/0xC/ // added to m_point_num
        /M/s32 m_depth/0x4/0x10/ // -1 when not reachable from path 0
        /M/sead::FixedPtrArray<ObjectBase, 8> m_obj_link_array/0x2C/0x14/
    /END/
}
