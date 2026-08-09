#pragma once

#include <math/seadVector.h>
#include <math/seadMatrix.h>

#include "../../forward.hpp"
#include "../../types.hpp"

#include "base.hpp"
#include "../SMapdataPosture.hpp"
#include "../eMapdataGeoObjID.hpp"
#include "../eMapdataGeoObjIDIndex.hpp"

BEGIN_NAMESPACE(Field)
{
    enum ObjPresenceFlags : u16 {
        SINGLE_PLAYER = 1,
        MULTIPLAYER = 2,
        ONLINE = 4
    };

    /START_STRUCT/NAME@MapdataGeoObjData/SIZE@0x40/
        /M/eMapdataGeoObjID m_id/0x2/0x0/
        /M/eMapdataGeoObjIDIndex m_id_index/0x2/0x2/
        /M/sead::Vector3f position/0xC/0x4/
        /M/sead::Vector3f rotation/0xC/0x10/
        /M/sead::Vector3f scale/0xC/0x1C/
        /M/s16 m_route_id/0x2/0x28/
        /M/u16 m_settings[8]/0x10/0x2a/
        /M/u16 m_presence_flags/0x2/0x3a/   // See the `ObjPresenceFlags` enum
        /M/s16 m_enemy_route/0x2/0x3c/
        /U/s16/0x2/0x3e/
    /END/
    
    /START_CLASS/NAME@MapdataGeoObj/SIZE@0x60/BASE@MapdataDataBase<MapdataGeoObjData>/BSIZE@0x4/
    public:
        static void forge_MapdataGeoObj(eMapdataGeoObjID, MapdataGeoObj::SData *);

        /M/MapdataPath *m_mapdata_path/0x4/0x4/
        /M/SMapdataPosture m_posture/0x24/0x8/
        /U/sead::Matrix34f/0x30/0x2C/
        /M/u32 m_special_light_set_index/0x4/0x5C/
    /END/
}