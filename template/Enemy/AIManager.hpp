#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include "EAILevel.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AIManager/SIZE@0xA8/
    public:
        AIManager();
        f32 getRandF32(f32);
        u32 getRandU32(u32);
        void registerAI(AI *);
        AI *getPlayerAI(s32);
        u32 calcAILevel_();
        AI *getAIByPlayerID(s32);
        AI *getRandamPlayerAI();
        void initTeamMemberAndOrder();
        void init(bool);
        void update();
        AI *getAIOrder(s32) const;
        AI *findNearest(const AI *) const;

        /M/AIRankManager *m_ai_rank_manager/0x4/0x0/
        /M/AIPathManager *m_ai_path_manager/0x4/0x4/
        /M/AIParamLoader *m_ai_param_loader/0x4/0x8/
        /M/AIObjectManager *m_ai_object_manager/0x4/0xC/
        /M/AIBattleManager *m_ai_battle_manager/0x4/0x10/
        /M/Utility::Random *m_utility_random/0x4/0x14/
        /M/s32 m_kart_num/0x4/0x18/
        /M/s32 m_player_kart_num/0x4/0x1C/
        /M/s32 m_red_team_members_num/0x4/0x20/
        /M/s32 m_blue_team_members_num/0x4/0x24/
        /M/s32 m_remote_player_num/0x4/0x28/
        /M/EAILevel m_ai_level/0x4/0x2C/
        // The player ID of the CPU the game is currently updating
        /M/u32 m_update_player_id/0x4/0x30/
        // Semi-random value, set in Enemy::AIManager::init. Set to `AISpeedRaceBase->m_max_speed_top_rand_bonus` in `Enemy::AI::initAfterManager`
        /M/f32 m_max_speed_top_rank_bonus/0x4/0x34/
        /M/AI *m_ais[KART_MAX]/0x20/0x38/
        /M/AI *m_ai_order[KART_MAX]/0x20/0x58/
        /M/AI *m_player_ais[KART_MAX]/0x20/0x78/
        /M/AI *m_streetpass_cpu/0x4/0x98/
        // Is online or local multiplayer CPU. Affects the CPU's speed. See `Enemy::AISpeedRaceBase::update`
        /M/bool m_is_remote_cpu[KART_MAX]/0x8/0x9c/
        /M/bool m_team_mode/0x1/0xA4/
	/END/

    AIManager *GetAIManager();
}