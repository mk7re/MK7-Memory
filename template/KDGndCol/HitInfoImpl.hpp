#pragma once

#include "CollisionFlags.hpp"
#include "KDAttT.hpp"
#include "KDMinMax.hpp"

#include <math/seadVector.h>

BEGIN_NAMESPACE(KDGndCol)
{
    /START_CLASS/NAME@HitInfoImpl/SIZE@0xB0/
        public:
            void entryAttrW(u32, u16, u32, f32);
            void entryGeomL(const sead::Vector3f &, const sead::Vector3f &, const sead::Vector3f &, f32, u32);
            u32 convToWorld(const f32 *, const KDAttT *, const sead::Vector3f *, HitInfoImpl *) const;
            bool searchProperty(u32) const;
            const sead::Vector3f &getNrmGnd() const;
            const sead::Vector3f &getReject() const;

            /U/u32/0x4/0x0/ // Interaction flags?
            /M/KDMinMax m_reject_min_max/0x18/0x4/
            /M/sead::Vector3f m_reject/0xc/0x1c/
            /M/sead::Vector3f m_nrm_gnd/0xc/0x28/
            /U/sead::Vector3f/0xc/0x34/
            /U/sead::Vector3f/0xc/0x40/
            /U/f32/0x4/0x4c/
            /U/sead::Vector3f/0xc/0x50/
            /U/f32/0x4/0x5c/
            /U/sead::Vector3f/0xc/0x60/
            /U/sead::Vector3f/0xc/0x6c/
            /U/f32/0x4/0x78/
            /U/sead::Vector3f/0xc/0x7c/
            /U/sead::Vector3f/0xc/0x88/
            /U/sead::Vector3f/0xc/0x94/
            /U/f32/0x4/0xa0/
            /M/u32 m_collision_flags/0x4/0xa4/
            /M/u32 m_collision_result/0x4/0xa8/
            /U/u32/0x4/0xac/
    /END/
}