#pragma once

#include "forward.hpp"
#include "types.hpp"

#include "KDMtxT.hpp"

#include <math/seadVector.h>

BEGIN_GLOBAL_NAMESPACE

/START_CLASS/NAME@KDRigid/SIZE@0xD0/
public:
    KDRigid();
    void reset();

    /M/KDMtxT m_kd_mtx/0x30/0x0/ // inherited?
    /U/sead::Vector4f/0x10/0x30/
    /M/KDAttT *m_rotation/0x4/0x40/
    /M/sead::Vector3f *m_position/0x4/0x44/
/END/

END_GLOBAL_NAMESPACE
