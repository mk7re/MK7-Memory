#pragma once

#include "forward.hpp"
#include "types.hpp"

#include "KDMtxT.hpp"
#include "KDMinMax.hpp"

#include <math/seadQuat.h>
#include <math/seadVector.h>

BEGIN_GLOBAL_NAMESPACE

/START_CLASS/NAME@KDRigid/SIZE@0xD0/
public:
    KDRigid();
    void reset();

    /M/KDMtxT m_kd_mtx/0x30/0x0/ // inherited?
    /M/sead::Quatf m_quat/0x10/0x30/
    /M/KDAttT *m_angle/0x4/0x40/
    /M/sead::Vector3f *m_position/0x4/0x44/
    /M/sead::Vector3f m_velocity/0xC/0x48/
    /M/sead::Vector3f m_rotation/0xC/0x54/
    /U/f32/0x4/0x60/
    /U/f32/0x4/0x64/
    /M/sead::Vector3f m_inertia/0xC/0x68/
    /M/sead::Vector3f m_inertia_ratio/0xC/0x74/  // 1 / m_inertia
    /M/KDMinMax m_velocity_min_max/0x18/0x80/
    /M/KDMinMax m_rotation_min_max/0x18/0x98/
    /M/KDMinMax m_reject/0x18/0xb0/
    /M/f32 m_time_scale/0x4/0xc8/
    /M/f32 m_time_scale_ratio/0x4/0xcc/  // 1 / m_time_scale
/END/

END_GLOBAL_NAMESPACE
