#pragma once

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

#include "../forward.hpp"
#include "../types.hpp"

#include "../Util/TStateObserver.hpp"
#include "EAILevel.hpp"

BEGIN_NAMESPACE(Enemy)
{
    class AIObjectSearcher;

    // Steering a CPU does outside the enemy route: avoiding objects, waiting at crossings, fleeing boards, gathering coins
    /START_CLASS/NAME@AIAutoSteer/SIZE@0x100/VTABLE@True/
    public:
        // State of m_observer
        enum class EState : u8 {
            IDLE = 0,
            AVOID = 1,
            REACT = 2,
            GOTO = 3,
            ZIG_ZAG = 4,
            RUN_AWAY = 5,               // battle: driving away from a board
            WAIT = 6,                   // waiting before a train crossing
            SIDE_ATTACK = 7,
            GENERATE = 8,
            GATHER = 9,                 // coin battle: driving to nearby coins
            GO_MASTER = 10,
        };

        virtual void stateInitIdle();
        virtual void stateIdle();
        virtual void stateInitAvoid();
        virtual void stateAvoid();
        virtual void stateInitReact();
        virtual void stateReact();
        virtual void stateInitGoto();
        virtual void stateGoto();
        virtual void stateInitZigZag();
        virtual void stateZigZag();
        virtual void stateInitRunAway();
        virtual void stateRunAway();
        virtual void stateInitWait();
        virtual void stateWait();
        virtual void stateInitSideAttack();
        virtual void stateSideAttack();
        virtual void stateInitGenerate();
        virtual void stateGenerate();
        virtual void stateInitGather();
        virtual void stateGather();
        virtual void stateExitGather();
        virtual void stateInitGoMaster();
        virtual void stateGoMaster();

        void init();
        void onAIFall();
        bool isNeedWait_();
        bool isNeedRunAway_();

        /M/Util::TStateObserverEx<AIAutoSteer> m_observer/0x20/0x4/
        /M/AIInfo *m_ai_info/0x4/0x24/
        /M/AI *m_ai/0x4/0x28/
        /M/AIPathHandler *m_ai_path_handler/0x4/0x30/
        /M/AIProbabilityBase *m_ai_probability/0x4/0x34/
        /M/AIStuck *m_ai_stuck/0x4/0x38/
        /M/AIManager *m_ai_manager/0x4/0x3C/
        /M/Item::KartItemProxy *m_kart_item_proxy/0x4/0x40/
        /M/AIObjectSearcher *m_ai_object_searcher/0x4/0x44/
        /M/Field::MapdataEnemyPointAccessor *m_enemy_point_accessor/0x4/0x48/
        /M/Field::ObjectDirector *m_object_director/0x4/0x4C/
        /M/Field::ObjectBase *m_wait_object/0x4/0x50/ // the crossing the CPU waits for in state WAIT
        /M/DriveInfo *m_drive_info/0x4/0x54/
        /M/Object::CoinManager *m_coin_manager/0x4/0x58/
        /M/Object::Coin *m_gather_target/0x4/0x5C/ // the coin the CPU drives to in state GATHER
        /M/u32 m_state_frames/0x4/0x6C/ // frames in the current state, for the states that time themselves
        /M/u32 m_state_frames_max/0x4/0x78/
        /M/s32 m_bd_board_num/0x4/0x84/ // size of Field::ObjectDirector::m_bd_board_objects in battle, 0 otherwise
        /M/EAILevel m_ai_level/0x4/0x88/
        /M/f32 m_gather_radius/0x4/0x90/ // XZ radius in which state GATHER looks for coins
        // Behind AIControlRace::m_watched_ai in race progress and more than 1500 units from it
        /M/bool m_is_far_behind/0x1/0x94/
        /M/bool m_wait_brake/0x1/0x95/ // state WAIT: let go of the accelerator instead of driving on
        /M/bool m_wait_any_direction/0x1/0x96/ // state WAIT: the wait does not end when the crossing is behind the kart
        /M/bool m_is_battle/0x1/0x97/
        /M/bool m_gather_target_found/0x1/0x98/ // state GATHER found a coin to drive to
        /M/bool m_is_team_mode/0x1/0x99/
        /M/sead::Vector3f m_run_away_target/0xC/0x9C/ // state RUN_AWAY: the spot the CPU flees to, 400 units from the board
        // The N64Crossing objects whose MapdataGeoObjData::m_enemy_route is 0 or more
        /M/sead::FixedPtrArray<Field::ObjectBase, 8> m_crossings/0x2C/0xA8/
        /M/sead::FixedPtrArray<Object::Coin, 8> m_gather_coins/0x2C/0xD4/ // the coins still to visit in state GATHER
    /END/
}
