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
        ROAD    = ENUM_BIT(ECollisionTypes::ROAD),
        ROAD2   = ENUM_BIT(ECollisionTypes::ROAD2),
        ROAD3   = ENUM_BIT(ECollisionTypes::ROAD3),
        SAND    = ENUM_BIT(ECollisionTypes::SAND),
        LDIRT   = ENUM_BIT(ECollisionTypes::LDIRT),
        DIRT    = ENUM_BIT(ECollisionTypes::DIRT),
        HDIRT   = ENUM_BIT(ECollisionTypes::HDIRT),
        ICE     = ENUM_BIT(ECollisionTypes::ICE),
        DASH    = ENUM_BIT(ECollisionTypes::DASH),
        GLIDE   = ENUM_BIT(ECollisionTypes::GLIDE),
        ITROAD  = ENUM_BIT(ECollisionTypes::ITROAD),
        RESQ    = ENUM_BIT(ECollisionTypes::RESQ),
        PULL    = ENUM_BIT(ECollisionTypes::PULL),
        LAROAD  = ENUM_BIT(ECollisionTypes::LAROAD),
        BELT    = ENUM_BIT(ECollisionTypes::BELT),
        DUMMY0  = ENUM_BIT(ECollisionTypes::DUMMY0),
        WALL    = ENUM_BIT(ECollisionTypes::WALL),
        WALL2   = ENUM_BIT(ECollisionTypes::WALL2),
        OUTF    = ENUM_BIT(ECollisionTypes::OUTF),
        ITWALL  = ENUM_BIT(ECollisionTypes::ITWALL),
        LWALL   = ENUM_BIT(ECollisionTypes::LWALL),
        BWALL   = ENUM_BIT(ECollisionTypes::BWALL),
        OUTMH   = ENUM_BIT(ECollisionTypes::OUTMH),
        DUMMY1  = ENUM_BIT(ECollisionTypes::DUMMY1),
        DUMMY2  = ENUM_BIT(ECollisionTypes::DUMMY2),
        VALLEY  = ENUM_BIT(ECollisionTypes::VALLEY),
        TRIGGER = ENUM_BIT(ECollisionTypes::TRIGGER),
        SOUND   = ENUM_BIT(ECollisionTypes::SOUND),
        CANNON  = ENUM_BIT(ECollisionTypes::CANNON),
        VALLEY2 = ENUM_BIT(ECollisionTypes::VALLEY2),
        DUMMY3  = ENUM_BIT(ECollisionTypes::DUMMY3),
        ZONE    = ENUM_BIT(ECollisionTypes::ZONE)
    };

    enum ECollisionResult : u32
    {
        COLLIDING_WITH_WALL = 1,
        FLAG_2 = 2
    };
}