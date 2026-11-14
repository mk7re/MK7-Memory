#pragma once

#include "../../types.hpp"

#include "base.hpp"

#include <math/seadMatrix.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // Entry of the MSPT section. Empty in every original course, and not used by the game
    /START_STRUCT/NAME@MapdataMissionPointData/SIZE@0x1C/
        /M/sead::Vector3f position/0xC/0x0/
        /M/sead::Vector3f rotation/0xC/0xC/ // radians
    /END/
    
    /START_CLASS/NAME@MapdataMissionPoint/SIZE@0x28/BASE@MapdataDataBase<MapdataMissionPointData>/BSIZE@0x4/
    public:
        /M/sead::Matrix33f m_posture/0x24/0x4/ // rotation matrix of rotation
    /END/
}