#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "DispPart.hpp"

#include <math/seadMatrix.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@DispKiller/SIZE@0x54/BASE@DispPart/BSIZE@0x8/
    public:
        DispKiller(const DispPart::ConstructArgsBase &);
        void updatePoseMtx(const sead::Matrix34f &, const sead::Vector3f &, f32, f32, bool);
        
        /M/sead::Matrix34f m_pose_mtx/0x30/0x8/
        /M/sead::Vector3f m_right/0xc/0x38/
        /M/Render::ShadowVolume *m_shadow/0x4/0x50/
    /END/
}