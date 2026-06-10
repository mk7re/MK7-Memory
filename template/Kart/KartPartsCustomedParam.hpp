#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "KartPartsConstructParam.hpp"

#include <math/seadVector.h>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@KartPartsCustomedParam/SIZE@0x1CC/
    public:
        KartPartsCustomedParam();
        void convert_Result();
        void calc_ShaftWheel();
        void updateParam_forKart(RaceSys::EDriverID, RaceSys::EBodyID, RaceSys::ETireID, RaceSys::EWingID);
        void calc_All();

        /M/KartConstructInfoAccessor *m_construct_info_accessor/0x4/0x0/
        /M/KartPartsConstructParam m_construct_param/0x14/0x4/
        /M/sead::Vector3f unk_0x18[2]/0x18/0x18/
        /M/sead::Vector3f m_body_scale/0xC/0x30/
        /U/sead::Vector3f/0xC/0x3C/ // body scale related
        /U/sead::Vector3f/0xC/0x48/ // body scale related
        /U/sead::Vector3f/0xC/0x54/
        /U/sead::Vector3f/0xC/0x60/
        /U/sead::Vector3f/0xC/0x6C/
        /U/sead::Vector3f/0xC/0x78/
        /U/sead::Vector3f/0xC/0x84/
        /U/sead::Vector3f/0xC/0x90/
        /U/sead::Vector3f/0xC/0x9C/
        /M/sead::Vector3f m_body_offset/0xC/0xA8/
        /M/sead::Vector3f m_wing_offset/0xC/0xB4/
        /M/sead::Vector3f m_screw_offset/0xC/0xC0/
        /M/sead::Vector3f m_character_offset/0xC/0xCC/
        /M/sead::Vector3f unk_0xD8[4]/0x30/0xD8/
        /M/sead::Vector3f unk_0x108[4]/0x30/0x108/
        /M/sead::Vector3f unk_0x138[4]/0x30/0x138/
        /M/sead::Vector3f m_ground_offset/0xC/0x168/
        /M/f32 m_tire_rotation_range/0x4/0x174/
        /U/f32/0x4/0x178/
        /U/f32/0x4/0x17C/
        /U/f32/0x4/0x180/
        /U/sead::Vector3f/0xC/0x184/ // front shaft offset?
        /U/sead::Vector3f/0xC/0x190/ // back shaft offset?
        /U/sead::Vector3f/0xC/0x19C/ // front wheel offset?
        /U/sead::Vector3f/0xC/0x1A8/ // back wheel offset?
        /M/sead::Vector3f m_tire_offset/0xC/0x1B4/
        /U/sead::Vector3f/0xC/0x1C0/
    /END/
}