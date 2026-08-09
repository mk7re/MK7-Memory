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
        /M/u16 m_previous_points[16]/0x20/0x4/
        /M/u16 m_next_points[16]/0x20/0x24/
        /U/u32/0x4/0x44/
    /END/

    /START_CLASS/NAME@MapdataEnemyPath/SIZE@0x40/BASE@MapdataDataBase<MapdataEnemyPathData>/BSIZE@0x4/
    public:
        void createDepth_(s32, MapdataEnemyPathAccessor *);

        /M/sead::FixedPtrArray<ObjectBase, 8> m_obj_link_array/0x2C/0x14/
    /END/
}