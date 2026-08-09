#pragma once

#include "../Field/ObjectCollisionResult.hpp"

BEGIN_NAMESPACE(Util)
{
    /START_STRUCT/NAME@CollisionResult/SIZE@0x20/
        enum CollisionResultFlags : u16 {
            // If set to `true`, forcefully pass the collision checks
            // so that it always collides no matter what.
            FORCE_COLLISION = 0x0001
        };

        void Reverse();

        /M/u16 m_flags/0x2/0x1e/    // See the `CollisionResultFlags` enum.
    /END/
}