#pragma once

#include "NarrowIF.hpp"
#include "CollisionFlags.hpp"

BEGIN_NAMESPACE(KDGndCol)
{
    /START_CLASS/NAME@CheckIF/SIZE@0x10/BASE@NarrowIF/BSIZE@0x4/
    public:
        CheckIF();

        // The value put here is what's returned from `KDGndCol::Manager::checkSphere`
        // See the `KDGndCol::ECollisionResult` enum
        /M/u32 m_collision_result/0x4/0x4/
        /M/HitInfo *m_hit_info/0x4/0x8/
        /M/KColDataBlockCache *m_block_cache/0x4/0xC/
    /END/
}