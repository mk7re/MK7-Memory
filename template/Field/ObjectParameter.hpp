#pragma once

#include "../types.hpp"

#include "eMapdataGeoObjID.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@SObjectCollisionSet/SIZE@0x8/
    /END/

    /START_CLASS/NAME@ObjectParameter/SIZE@0x10/
    public:
        /START_STRUCT/NAME@Parameter/SIZE@0x84/
            // NOTE: guessed name
            /START_STRUCT/NAME@Info/SIZE@0xA0/
                /M/eMapdataGeoObjID m_mapdata_geo_obj_id/0x2/0x0/
                /M/u16 m_flags/0x2/0x2/
                /M/u32 unk_0x4[3]/0xC/0x8/ // LOD distances?
                /M/SObjectCollisionSet m_collision_set/0x8/0x14/
                /M/char m_name[128]/0x80/0x1C/
            /END/

            /M/Info *m_info/0x4/0x0/
        /END/

        /M/sead::PtrArray<Parameter> m_parameters/0xC/0x0/
        /U/int/0x4/0xC/
    /END/
}