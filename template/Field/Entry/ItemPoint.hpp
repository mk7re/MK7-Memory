#pragma once

#include <math/seadVector.h>

#include "../../types.hpp"

#include "base.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@MapdataItemPointData/SIZE@0x14/
        /M/sead::Vector3f position/0xC/0x0/
    /END/

    /START_CLASS/NAME@MapdataItemPoint/SIZE@0x2C/BASE@MapdataDataBase<MapdataItemPointData>/BSIZE@0x4/
    public:
        /M/u8 m_previous_count/0x1/0x4/
        /M/u8 m_next_count/0x1/0x5/
        /M/u16 m_previous_ids[6]/0xC/0x6/
        /M/u16 m_next_ids[6]/0xC/0x12/
        /M/u32 m_checkpoint_index/0x4/0x20/
        /M/u32 m_point_path_index/0x4/0x24/
    /END/
}