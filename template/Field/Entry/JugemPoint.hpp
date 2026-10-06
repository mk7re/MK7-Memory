#pragma once

#include <math/seadVector.h>

#include "../../types.hpp"

#include "base.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@MapdataJugemPointData/SIZE@0x1C/
        /M/sead::Vector3f position/0xC/0x0/
        /M/s16 check_point_index/0x2/0x1A/ // used as MapdataJugemPoint::m_check_point_index when > 0
    /END/

    /START_CLASS/NAME@MapdataJugemPoint/SIZE@0x50/BASE@MapdataDataBase<MapdataJugemPointData>/BSIZE@0x4/
    public:
        /M/u8 m_check_point_index/0x1/0x28/ // checkpoint the kart is placed in after respawning here
        /M/s32 m_nearest_enemy_point/0x4/0x2C/ // route point a CPU resumes from after respawning here, -1 when none
    /END/
}