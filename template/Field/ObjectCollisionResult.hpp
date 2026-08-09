#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@ObjectCollisionResult/SIZE@0x1C/
        /M/sead::Vector3f m_normal/0xc/0x0/
        // If negative, the entities are not colliding.
        // If 0, they're touching, and if positive, they're intersecting.
        /M/f32 m_penetration_depth/0x4/0xc/
        // The exact point where one entity intersects another one.
        /M/sead::Vector3f m_intersection_point/0xc/0x10/
    /END/
}