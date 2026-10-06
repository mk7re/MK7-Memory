#pragma once

#include <math/seadVector.h>

#include "../forward.hpp"
#include "../types.hpp"

#include "../Util/TStateObserver.hpp"

BEGIN_NAMESPACE(Enemy)
{
    // Watches a CPU's progress along the enemy route: backs it up, asks for re-routes, hands it to Lakitu
    /START_CLASS/NAME@AIStuck/SIZE@0x70/VTABLE@True/
    public:
        // State of m_observer
        enum class EState : u8 {
            IDLE = 0,
            CHECK_STUCK = 1,            // watching for progress
            BACK_PATH_POINT = 2,        // backing up
            START_OUT_OF_BOUNDS = 3,    // handing the kart to Lakitu
        };

        // Phase of the back-up (state BACK_PATH_POINT)
        enum class EBackPhase : s32 {
            REVERSE = 0,
            DRIVE_BACK = 1,             // driving to the aim point behind
            TURN_TO_ROUTE = 2,          // turning back toward the route
        };

        virtual void stateInitIdle();
        virtual void stateIdle();
        virtual void stateInitCheckStuck();
        virtual void stateCheckStuck();
        virtual void stateInitBackPathPoint();
        virtual void stateBackPathPoint();
        virtual void stateExitBackPathPoint();
        virtual void stateInitStartOutOfBounds();
        virtual void stateStartOutOfBounds();

        void init();
        void update();
        void onAIFall();
        void onOutOfBoundsInner();

        /M/Util::TStateObserverEx<AIStuck> m_observer/0x20/0x4/
        /M/AIInfo *m_ai_info/0x4/0x24/
        /M/AIPathHandler *m_ai_path_handler/0x4/0x28/
        /M/AIPathPoint *m_ai_path_point/0x4/0x2C/
        /M/AI *m_ai/0x4/0x30/
        /M/AISpeedRaceBase *m_ai_speed/0x4/0x34/
        /M/AIAutoSteer *m_ai_auto_steer/0x4/0x38/
        /M/sead::Vector3f m_fall_pos/0xC/0x3C/ // kart position at the last relocation onto the enemy route
        // Frames below 10 % of the top speed, +3 per frame while the kart touches a wall. Above 600 the CPU backs up
        /M/s32 m_slow_frames/0x4/0x48/
        /M/s32 m_no_advance_frames/0x4/0x4C/ // frames without reaching a new point: re-route at 450, Lakitu at 901
        /M/s32 m_fall_count/0x4/0x50/ // relocations in a row within 10 units of m_fall_pos; the fifth calls Lakitu
        /U/s32/0x4/0x54/
        /M/EBackPhase m_back_phase/0x4/0x58/
        /M/u32 m_back_frames/0x4/0x5C/
        /M/f32 m_back_rate/0x4/0x60/ // how far back along the route the back-up aims (AIPathPoint::m_move_back_rate)
        /M/f32 m_back_rate_max/0x4/0x64/ // 4.0 in race, 2.0 in battle
        /M/bool m_reroute_request/0x1/0x69/ // set for one frame to ask for a re-route to the nearest point
        /M/bool m_is_battle/0x1/0x6A/
        /M/bool m_is_multiplayer/0x1/0x6B/
        /M/bool m_is_race_started/0x1/0x6C/
    /END/
}
