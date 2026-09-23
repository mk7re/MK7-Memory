#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(KDGndCol)
{
    // Note: The names of the enums are made up.
    enum class ECollisionTypes : u32
    {
        ROAD    = 0,
        ROAD2   = 1,
        ROAD3   = 2,
        SAND    = 3,
        LDIRT   = 4,  /* Aka DirtL */
        DIRT    = 5,  /* Aka DirtM */
        HDIRT   = 6,  /* Aka DirtH */
        ICE     = 7,
        DASH    = 8,
        GLIDE   = 9,
        ITROAD  = 10,
        RESQ    = 11,
        PULL    = 12,
        LAROAD  = 13,
        BELT    = 14,
        DUMMY0  = 15,
        WALL    = 16,
        WALL2   = 17,
        OUTF    = 18,
        ITWALL  = 19,
        LWALL   = 20,
        BWALL   = 21,
        OUTMH   = 22,
        DUMMY1  = 23,
        DUMMY2  = 24,
        VALLEY  = 25,
        TRIGGER = 26,
        SOUND   = 27,
        CANNON  = 28,
        VALLEY2 = 29,
        DUMMY3  = 30,
        ZONE    = 31,

        MAX
    };

    enum class ECollisionFlags : u32
    {
        ROAD    = 1 << static_cast<u32>(ECollisionTypes::ROAD),
        ROAD2   = 1 << static_cast<u32>(ECollisionTypes::ROAD2),
        ROAD3   = 1 << static_cast<u32>(ECollisionTypes::ROAD3),
        SAND    = 1 << static_cast<u32>(ECollisionTypes::SAND),
        LDIRT   = 1 << static_cast<u32>(ECollisionTypes::LDIRT),
        DIRT    = 1 << static_cast<u32>(ECollisionTypes::DIRT),
        HDIRT   = 1 << static_cast<u32>(ECollisionTypes::HDIRT),
        ICE     = 1 << static_cast<u32>(ECollisionTypes::ICE),
        DASH    = 1 << static_cast<u32>(ECollisionTypes::DASH),
        GLIDE   = 1 << static_cast<u32>(ECollisionTypes::GLIDE),
        ITROAD  = 1 << static_cast<u32>(ECollisionTypes::ITROAD),
        RESQ    = 1 << static_cast<u32>(ECollisionTypes::RESQ),
        PULL    = 1 << static_cast<u32>(ECollisionTypes::PULL),
        LAROAD  = 1 << static_cast<u32>(ECollisionTypes::LAROAD),
        BELT    = 1 << static_cast<u32>(ECollisionTypes::BELT),
        DUMMY0  = 1 << static_cast<u32>(ECollisionTypes::DUMMY0),
        WALL    = 1 << static_cast<u32>(ECollisionTypes::WALL),
        WALL2   = 1 << static_cast<u32>(ECollisionTypes::WALL2),
        OUTF    = 1 << static_cast<u32>(ECollisionTypes::OUTF),
        ITWALL  = 1 << static_cast<u32>(ECollisionTypes::ITWALL),
        LWALL   = 1 << static_cast<u32>(ECollisionTypes::LWALL),
        BWALL   = 1 << static_cast<u32>(ECollisionTypes::BWALL),
        OUTMH   = 1 << static_cast<u32>(ECollisionTypes::OUTMH),
        DUMMY1  = 1 << static_cast<u32>(ECollisionTypes::DUMMY1),
        DUMMY2  = 1 << static_cast<u32>(ECollisionTypes::DUMMY2),
        VALLEY  = 1 << static_cast<u32>(ECollisionTypes::VALLEY),
        TRIGGER = 1 << static_cast<u32>(ECollisionTypes::TRIGGER),
        SOUND   = 1 << static_cast<u32>(ECollisionTypes::SOUND),
        CANNON  = 1 << static_cast<u32>(ECollisionTypes::CANNON),
        VALLEY2 = 1 << static_cast<u32>(ECollisionTypes::VALLEY2),
        DUMMY3  = 1 << static_cast<u32>(ECollisionTypes::DUMMY3),
        ZONE    = 1 << static_cast<u32>(ECollisionTypes::ZONE)
    };

    enum ECollisionResult : u32
    {
        COLLIDING_WITH_WALL = 1,
        FLAG_2 = 2
    };
}