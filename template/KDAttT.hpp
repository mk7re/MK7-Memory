#pragma once

#include "types.hpp"

#include <math/seadVector.hpp>

BEGIN_GLOBAL_NAMESPACE

/START_CLASS/NAME@KDAttT/SIZE@0x24/
public:
    KDAttT() {};

    inline void reset()
    {
        m_right = sead::Vector3f::zero;
        m_forward = sead::Vector3f::zero;
        m_up = sead::Vector3f::zero;
    }

    inline void init()
    {
        m_right = sead::Vector3f::ex;
        m_forward = sead::Vector3f::ez;
        m_up = sead::Vector3f::ey;
    }

    /M/sead::Vector3f m_right/0xC/0x0/ // X axis
    /M/sead::Vector3f m_forward/0xC/0xC/ // Z axis
    /M/sead::Vector3f m_up/0xC/0x18/ // Y axis
/END/

END_GLOBAL_NAMESPACE
