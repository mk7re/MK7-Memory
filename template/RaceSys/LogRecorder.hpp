#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include <container/seadBuffer.h>
#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(RaceSys)
{
    /START_CLASS/NAME@LogRecorder/SIZE@0x130/
    public:
        // The Japanese comments come from the file `content/record/RaceLogData.exbin` in MK8
        enum class EValueType : u32
        {
            OBTAIN_ITEM,                  // アイテム取得
            USED_ITEM_FROM_SLOT,          // アイテムをスロットから使った. When the item slot becomes inactive after using an item.
            USED_ITEM_AND_HIT_SOMEONE,    // 使ったアイテムが他人に当たった
            THROW_ITEM,                   // アイテムを投げた
            HOLD_ITEM,                    // アイテムをホールドしている. Time while equipping / holding the item on the back of the kart.
            BUMP_INTO_ENEMY,              // 敵車と当たった. Bumping into another vehicle above a certain speed.
            TRICK,                        // ジャンプアクションをした
            START_DRIFT_JUMP,             // ドリフトジャンプをした
            RACETIME,                     // 走行時間
            RACETIME_IN_FIRST_PERSON,     // 主観視点時間
            DRIFT_START,                  // ドリフトした
            DRIFT_TIME,                   // ドリフト時間
            MINITURBO_LEVEL_1,            // ミニターボLv1を出した
            MINITURBO_LEVEL_2,            // ミニターボLv2を出した
            UNDERWATER,                   // 水中を走っている
            RANK_UP_WHILE_UNDERWATER,     // 水中を走り中にランクアップした
            FLYING,                       // 滑空している
            RANK_UP_WHILE_FLYING,         // 滑空中にランクアップした
            RESPAWN,                      // ジュゲムに救出された. Respawned by Lakitu.
            POP_BALLOON,                  // 他人の風船を壊した. Pop somebody else's balloon. Only used in Balloon Battle.
            LOSE_BALLOON,                 // 風船を失った. Only used in Balloon Battle.
            STOLE_BALLOON,                // 風船を奪った. Only used in Balloon Battle.
            OBTAIN_COIN,                  // コインを num 枚取得. Total number of coins obtained. Only used in Coin Runners.
            DROPPED_COIN,                 // コインを num 枚失った. Total number of coins dropped. Only used in Coin Runners.
            TOTAL_COINS,                  // コイン合計. Number of coins at the end of the race.
            RACETIME_IN_FIRST_PLACE,      // 1位の時間
            ROCKET_START,                 // ロケットスタート

            MAX
        };

        // NOTE: The name is made up.
        /START_STRUCT/NAME@BufferParams/SIZE@0x8/
            /U/u32/0x4/0x0/
            /M/u32 m_buffer_size/0x4/0x4/
        /END/

        LogRecorder(s32);
        void makeRaceLog(Net::RaceLogResult *);
        void createBuffer();
        void addValueNum(EValueType, u8, s32);
        void addValue(EValueType, s32);
        void addValueNoCheck(EValueType, s32);
        void calc();
        void calcAfterStructure();
        void raceEnd();
        void raceStart();
        void determineTitleType(s32);       // 0x0045ceb8 (VERSION_USA_REV1)
        bool saveRaceStats(s32 *);          // 0x0045d484 (VERSION_USA_REV1)

        // Each index corresponds to its entry in the `EValueType` enum.
        /M/sead::Buffer<u32> m_logs[static_cast<u32>(EValueType::MAX)]/0xd8/0x0/
        /M/sead::Delegate<LogRecorder> m_race_start/0x10/0xd8/
        /M/sead::Delegate<LogRecorder> m_race_end/0x10/0xe8/
        // This is a log of 24 entries that saves the value of `m_current_rank_timer` every 10 seconds.
        // TODO: Verify if the data type is correct.
        /M/sead::Buffer<f32 *> m_current_rank_timer_log/0x8/0xf8/
        // The lower your rank is, the larger this number will be. See 0x00418908 (VERSION_EUR_DLP).
        /M/s32 m_current_rank_timer/0x4/0x100/
        // Wait time before updating `m_current_rank_timer_log`.
        /M/s32 m_current_rank_timer_log_update_delay_time/0x4/0x104/
        // Current index within the `m_current_rank_timer_log` log.
        /M/s32 m_current_rank_timer_log_idx/0x4/0x108/
        // This timer runs when using gyro controls in first person.
        // If you use the stick while in first person, it will stop until you let go of the stick.
        /M/s32 m_time_using_gyro/0x4/0x10c/
        // Set to `true` when LogRecorder is actually performing logging work.
        /M/bool m_is_active/0x1/0x110/
        // Racer has played the match using gyro controls at least 80% of the time.
        /M/bool m_played_using_the_wheel/0x1/0x111/
        /M/s32 m_master_player_id/0x4/0x114/
        // A delay timer before updating the array below
        /M/s16 m_is_player_rank_higher_than_master_update_delay_time[KART_MAX]/0x10/0x118/
        // If `true`, the player in question is ahead of the master player.
        /M/bool m_is_player_rank_higher_than_master[KART_MAX]/0x8/0x128/

        // 0x0057f668 (VERSION_EUR_DLP)
        static const BufferParams m_buffer_params_list[static_cast<u32>(EValueType::MAX)];
    /END/
}