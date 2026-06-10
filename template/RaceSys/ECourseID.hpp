#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    // https://tcrf.net/Notes:Mario_Kart_7#Course
    enum class ECourseID : u32
    {
        Gctr_MarioCircuit,      // Mario Circuit
        Gctr_RallyCourse,       // Rock Rock Mountain
        Gctr_MarineRoad,        // Cheep Cheep Lagoon
        Gctr_GlideLake,         // Daisy Hills
        Gctr_ToadCircuit,       // Toad Circuit
        Gctr_SandTown,          // Shy Guy Bazaar
        Gctr_AdvancedCircuit,   // Neo Bowser City
        Gctr_DKJungle,          // DK Jungle
        Gctr_WuhuIsland1,       // Wuhu Loop
        Gctr_WuhuIsland2,       // Maka Wuhu
        Gctr_IceSlider,         // Rosalina's Ice World
        Gctr_BowserCastle,      // Bowser's Castle
        Gctr_UnderGround,       // Piranha Plant Slide
        Gctr_RainbowRoad,       // Rainbow Road
        Gctr_WarioShip,         // Wario Shipyard
        Gctr_MusicPark,         // Music Park
        Gwii_CoconutMall,       // Wii Coconut Mall
        Gwii_KoopaCape,         // Wii Koopa Cape
        Gwii_MapleTreeway,      // Wii Maple Treeway
        Gwii_MushroomGorge,     // Wii Mushroom Gorge
        Gds_LuigisMansion,      // DS Luigi's Mansion
        Gds_AirshipFortress,    // DS Airship Fortress
        Gds_DKPass,             // DS DK Pass
        Gds_WaluigiPinball,     // DS Waluigi Pinball
        Ggc_DinoDinoJungle,     // GCN Dino Dino Jungle
        Ggc_DaisyCruiser,       // GCN Daisy Cruiser
        Gn64_LuigiCircuit,      // N64 Luigi Raceway
        Gn64_KalimariDesert,    // N64 Kalimari Desert
        Gn64_KoopaTroopaBeach,  // N64 Koopa Beach
        Gagb_BowserCastle1,     // GBA Bowser Castle 1
        Gsfc_MarioCircuit2,     // SNES Mario Circuit 2
        Gsfc_RainbowRoad,       // SNES Rainbow Road
        Bctr_WuhuIsland3,       // Wuhu Town
        Bctr_HoneyStage,        // Honeybee Hive
        Bctr_IceRink,           // Sherbet Rink
        Bds_PalmShore,          // DS Palm Shore
        Bn64_BigDonut,          // N64 Big Donut
        Bagb_BattleCourse1,     // GBA Battle Course 1
        Gctr_WinningRun,        // Toad Circuit (Grand Prix winning cutscene)
        _39,
        MAX,
        INVALID,
    };
}