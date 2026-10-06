#pragma once

#include <math/seadVector.h>

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Enemy)
{
    class AIBattleSearcher;

    /START_CLASS/NAME@AIPathPoint/SIZE@0x58/VTABLE@True/
    public:
        virtual void init(f32) {}; // 0
        virtual void update() {}; // 1
        virtual void calcNextTargetTrans(f32, bool) {}; // 2
        virtual void onAIFall(s32) {}; // 3
        virtual s32 selectNextPointHandle_(GoNextInfo &) { return {}; }; // 4
        virtual s32 selectNextPointHandleIndex_(GoNextInfo &) { return {}; }; // 5

        void goNextPoint(GoNextInfo &);
        s32 selectNextPointHandleIndexWithShortcut_(GoNextInfo &);

        /M/AIPathManager *m_ai_path_manager/0x4/0x4/
        /M/AIManager *m_ai_manager/0x4/0x8/
        /M/AI *m_ai/0x4/0xC/
        /M/Field::MapdataEnemyPointAccessor *m_enemy_point_accessor/0x4/0x10/
        /M/Field::MapdataEnemyPoint *m_next_point/0x4/0x14/ // the point after the target
        /M/Field::MapdataEnemyPoint *m_target_point/0x4/0x18/
        /M/Field::MapdataEnemyPoint *m_prev_point/0x4/0x1C/
        /M/Field::MapdataEnemyPoint *m_history_points[3]/0xC/0x20/
        /M/s32 m_start_point_index/0x4/0x2C/
        /M/s32 m_branch_index/0x4/0x30/
        /M/u32 m_obj_check_rate/0x4/0x34/
        /M/f32 m_corner/0x4/0x38/
        /M/f32 m_width/0x4/0x3C/
        /M/f32 m_offset/0x4/0x40/
        /M/f32 m_offset_rate/0x4/0x44/
        /M/f32 m_move_back_rate/0x4/0x48/
        /M/sead::Vector3f m_target_trans/0xC/0x4C/
    /END/

    /START_CLASS/NAME@AIPathPointAward/SIZE@0x58/BASE@AIPathPoint/BSIZE@0x58/
    /END/

    /START_CLASS/NAME@AIPathPointBattle/SIZE@0x70/BASE@AIPathPoint/BSIZE@0x58/
    public:
        virtual void setTargetForBranchTrans(sead::Vector3f) {}; // 6

        /M/AIBattleSearcher *m_battle_searcher/0x4/0x58/
        /M/sead::Vector3f m_target_for_branch_trans/0xC/0x5C/
        /M/Field::MapdataEnemyPath *m_current_path/0x4/0x68/
        /M/s32 m_path_entry_point/0x4/0x6C/ // end of m_current_path it was entered from
    /END/

    /START_CLASS/NAME@AIPathPointBattleCoin/SIZE@0x70/BASE@AIPathPointBattle/BSIZE@0x70/
    /END/
}
