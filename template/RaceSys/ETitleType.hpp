#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    enum class ETitleType : u32
    {
        DEFAULT,
        ShellShark,
        BananaBlitzer,
        BobombAce,
        ProDefender,
        RowdyRacer,
        BoostJumper,
        Aviator,
        Dolphin,
        DriftWizard,
        QuickStarter,
        ComebackKid,
        StarRacer,
        ModelDriver,
        MajorSwerver,
        SafeDriver,
        Rookie,
        MAX,
    };

    enum ETitleTypeFlags : u32
    {
        ITEM_THROWER  = 0x0001,  // Either the Shell Shark, Banana Blitzer or Bob-Omb Ace titles.
        PRO_DEFENDER  = 0x0002,
        BOOST_JUMPER  = 0x0004,
        ROWDY_RACER   = 0x0008,
        MAJOR_SWERVER = 0x0010,
        DRIFT_WIZARD  = 0x0020,
        AVIATOR       = 0x0040,
        DOLPHIN       = 0x0080,
        SAFE_DRIVER   = 0x0100,
        QUICK_STARTER = 0x0200,
        COMEBACK_KID  = 0x0400,
        STAR_RACER    = 0x0800,
        ROOKIE        = 0x1000,
        MODEL_DRIVER  = 0x2000,  // The default case
    };
}