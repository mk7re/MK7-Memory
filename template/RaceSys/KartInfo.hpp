#pragma once

#include "CTime.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    /START_CLASS/NAME@KartInfo/SIZE@0x74/
    public:
        struct EFlags
		{
			u32
				real_goal_1 : 1, // 0x1
				real_goal_2 : 1, // 0x2
				is_vanished : 1, // 0x4
                fake_goal   : 1; // 0x8
		};
		static_assert(sizeof(EFlags) == 0x4);

        bool calcFromRank(LapRankChecker *, bool);
        void allGoal(LapRankChecker *);

        /M/EFlags m_flags/0x4/0x40/
        /M/u16 m_player_id/0x2/0x44/
        /M/u16 m_coins/0x2/0x46/
        /M/u16 m_coins_max/0x2/0x48/
        /M/s16 m_balloon_points/0x2/0x54/
        /M/s16 m_balloon_count/0x2/0x56/
        /M/u8 m_lap_num/0x1/0x58/
        /M/CTime m_time/0xC/0x5C/
        /M/s32 m_times_num/0x4/0x68/
        /M/CTime *m_times/0x4/0x6C/
    /END/
}