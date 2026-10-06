#pragma once

#include "AIControlBase.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AIControlRace/SIZE@0x94/BASE@AIControlBase/BSIZE@0x50/
    public:
        void watchPlayerAndSwitchCollision();

        /M/AI *m_watched_ai/0x4/0x60/ // AI of the kart RaceSys::CRaceInfo::m_detail_kart_id
        // Frames in a row of a Bullet Bill's ending phase on Field::ENEMY_POINT_KILLER_NO_END points without reaching a
        // new point. Above 420 the Bullet Bill ends
        /M/u16 m_killer_hold_frames/0x2/0x7C/
        /M/bool m_skip_watch/0x1/0x91/ // while set, watchPlayerAndSwitchCollision is not run
	/END/
}