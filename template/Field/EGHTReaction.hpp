#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    // See `Field::ObjectBase::doReaction_againstKart` for usage.
    // On the right is the associated eAcdType + some comments.
    enum class EGHTReaction : u32
    {
        EGHTREACT_NONE=0 /* Item clips through the object  */,
        EGHTREACT_BOUNCE=1 /* Item bounces on object like if it was a wall */,
        EGHTREACT_BREAK=2 /* Item breaks/vanishes on contact with the object. */,
        EGHTREACT_WALL=8 /* Calls `Field::ObjectBase::doReact_Wall` with collision flag: 0x10000 (WALL) */,
        EGHTREACT_LWALL=9 /* Calls `Field::ObjectBase::doReact_Wall` with collision flag: 0x100000 (LWALL) */,
        EGHTREACT_SPIN=10 /* SPIN_1_NORMAL */,
        EGHTREACT_SPEED_SPIN=11 /* SPIN_2_NORMAL */,
        EGHTREACT_MUD_SPIN=12 /* SPIN_2_NORMAL */,
        EGHTREACT_FIRE_SPIN=13 /* SPIN_2_FIRE */,
        EGHTREACT_WATER_SPIN=14 /* SPIN_2_NORMAL */,
        EGHTREACT_CRASH_DIR=15 /* CRASH_DIR */,
        EGHTREACT_CRASH_DIR_FORWARDS=16 /* CRASH_DIR. The direction always points forwards. */,
        EGHTREACT_CRASH_LR=17 /* CRASH_LR */,
        EGHTREACT_CRASH_LR_BIG=18 /* CRASH_LR_BIG */,
        EGHTREACT_CRASH_DIR_BIG=19 /* CRASH_DIR_BIG */,
        EGHTREACT_THWOMP=20 /* FREEZE */,
        EGHTREACT_THWOMP_SHORTER=21 /* FREEZE. Squish lasts shorter. The "note" object (TempoKun) uses the exact same parameters when getting squished, but they're not set using this enum. */,
        EGHTREACT_WALL_CONSTANT_HIT=22,
        EGHTREACT_WALL_STOP=23 /* Calls `Kart::VehicleReact::reactStop` to stop the kart */,
        EGHTREACT_WALL_REJECT=24 /* Calls `Kart::VehicleReact::reactReject` */,
        EGHTREACT_WALL_CONSTANT_HIT_2=25,
        EGHTREACT_WALL_FLIPPER=26
    };
}