#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "ObjectParameter.hpp"

#include <math/seadMatrix.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // Name is made up
    enum ELodState : u32 {
        HIGH,
        MEDIUM,
        LOW,
        CULLED,
    };

    /START_STRUCT/NAME@EObjectClipArg/SIZE@0x4/
    /END/

    /START_CLASS/NAME@ObjectBase/SIZE@0xA0/VTABLE@True/
    public:
        virtual void calcView(); // 0

        /M/u32 m_need_flag/0x4/0x4/
        /M/MapdataGeoObj *m_mapdata_geo_obj/0x4/0x8/
        /M/ObjectParameter::Parameter *m_parameter/0x4/0xC/
        /M/ObjectPathBase *m_path/0x4/0x10/
        /M/ObjectCollisionBase *m_object_collision/0x4/0x14/
        /M/sead::Matrix34f m_collision_posture/0x30/0x18/
        /U/sead::Vector3f/0xC/0x48/ // default pos?
        /U/sead::Vector3f/0xC/0x54/
        /U/sead::Vector3f/0xC/0x60/
        /U/u32/0x4/0x6C/ // flags
        /M/EObjectClipArg m_arg/0x4/0x70/
        /M/ELodState m_lod_state/0x4/0x74/
        /M/bool m_update_culling/0x1/0x7A/
        /M/bool m_is_culled/0x1/0x7B/
        /M/bool m_enable_culling/0x1/0x7C/
        /M/bool m_is_visible/0x1/0x7D/
        /M/Sound::SndActorBase *m_snd_actor/0x4/0x80/
        /M/BoxCol::Unit *m_unit/0x4/0x84/
        /U/f32/0x4/0x88/ // area?
        /U/sead::Vector3f/0xC/0x8C/
        /M/bool m_is_net_object/0x1/0x98/
        /M/bool m_is_time_trials/0x1/0x99/
        /M/bool m_is_race_preview/0x1/0x9A/
        /U/f32/0x4/0x9C/
    /END/
}