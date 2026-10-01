#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../RaceSys/ETitleType.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AI/SIZE@0x2c/
    public:
        // NOTE: Name is made up.
        enum class ETargetPlayerType : u16
        {
            PLAYER,
            SELF,

            MAX
        };

        AI(s32);
        void onOutOfBounds(const Field::MapdataJugemPoint *);
        void setRotateRadAI(f32);
        void initAfterManager();
        void setMaxSpeedRatio(f32);
        void init();
        void awake();
        void sleep();
        void startKiller();
        void update();
        void onAIFall();

        /M/Kart::InfoProxy *m_info_proxy/0x4/0x0/
        /M/Kart::Vehicle *m_vehicle/0x4/0x4/
        /M/AIEngine *m_engine/0x4/0x8/
        /M/u32 m_team/0x4/0xc/                      // `RaceSys::ETeamType`?
        /M/u32 m_title_type_flags/0x4/0x10/         // See the `RaceSys::ETitleTypeFlags` enum
        /M/s32 m_team_member_id/0x4/0x14/
        /M/f32 m_max_speed_ratio/0x4/0x18/
        /M/s16 m_kart_grid_rank/0x2/0x1c/
        /M/ETargetPlayerType m_target_player_type/0x2/0x1e/       // Only used in battles? See `Enemy::AIItemBattle::initAfterManager` and `Enemy::AIManager::initTeamMemberAndOrder`
        /M/f32 m_rotate_rad_ai/0x4/0x20/
        /M/bool m_is_human_controlled_player/0x1/0x24/
        /M/bool m_force_default_speed/0x1/0x25/
        /M/bool m_is_back_path_point/0x1/0x26/                    // Is the CPU going backwards (holding B)
        /U/u8/0x1/0x27/
        /M/bool m_is_cutscene_mode/0x1/0x28/
        /M/bool m_is_on_same_team_as_player/0x1/0x29/
    /END/
}