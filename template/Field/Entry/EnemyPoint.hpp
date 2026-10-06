#pragma once

#include <math/seadVector.h>

#include "../../forward.hpp"
#include "../../types.hpp"

#include "base.hpp"

BEGIN_NAMESPACE(Field)
{
    enum EnemyPointFlags : u8 {
        ENEMY_POINT_CORNERING               = 0x01, // Race: drifting CPUs shift their line through the corner
        ENEMY_POINT_HEIGHT_REROUTE          = 0x02, // Re-route check when the target is steeply above/below
        ENEMY_POINT_PRECISE                 = 0x04, // Reach radius 140 (+ ENEMY_POINT_CORNERING in race)
        ENEMY_POINT_NO_TRICK                = 0x08, // No trick hops
        ENEMY_POINT_HOLD_DRIFT              = 0x10, // Race: longer, gentler drifts
        ENEMY_POINT_KILLER_FOLLOW_HEIGHT    = 0x20, // Race: Bullet Bill is pulled to the route height
        ENEMY_POINT_KILLER_NO_END           = 0x40, // Race: Bullet Bill ending is paused
        ENEMY_POINT_FORCE_BASE_SPEED        = 0x80, // Base speed ratio. Battle: also aim at the centre and trick hop
    };

    /START_STRUCT/NAME@MapdataEnemyPointData/SIZE@0x18/
        enum class EMushroomSetting : u16 {
            USE = 0,                    // CPUs may use a Mushroom
            SHORTCUT_START = 1,         // race: first point of a mushroom shortcut branch; no Mushroom use
            NO_USE = 2,                 // no Mushroom use; any other value acts the same
        };

        enum class EDriftSetting : u8 {
            ALLOW = 0,                  // a drift may start toward the point and continue
            END = 1,                    // no drift starts toward the point; a drift ends on reaching it
            END_NO_MINI_TURBO = 2,      // as END, and the mini-turbo of the drift is thrown away
            BY_CORNER = 3,              // a drift may start; it ends where the road straightens or bends the other way
        };

        /M/sead::Vector3f position/0xC/0x0/
        /M/float scale/0x4/0xC/ // lateral half-width = scale * 50.f
        /M/EMushroomSetting mushroom_setting/0x2/0x10/
        /M/EDriftSetting drift_setting/0x1/0x12/ // values above 3 act as BY_CORNER
        /M/u8 flags/0x1/0x13/ // See the `EnemyPointFlags` enum
        /M/s16 path_find_options/0x2/0x14/ // 0 -> normal, -1/-2 -> excluded from some nearest point searches, -3/-4 -> Mii title path, > 0 -> award kart number
        /M/s16 max_search_y_offset/0x2/0x16/ // nearest point search: 0 -> no height limit, < 0 -> 75 units, > 0 -> value in units
    /END/

    /START_CLASS/NAME@MapdataEnemyPoint/SIZE@0x54/BASE@MapdataDataBase<MapdataEnemyPointData>/BSIZE@0x4/
    public:
        void setup(s32, MapdataEnemyPathAccessor *);
        void setupNrm();

        /M/MapdataEnemyPath *m_path/0x4/0x4/
        /M/s32 *m_prev_points/0x4/0x8/
        /M/s32 *m_next_points/0x4/0xC/
        /M/s32 m_prev_count/0x4/0x10/
        /M/s32 m_next_count/0x4/0x14/
        /M/s32 m_sector/0x4/0x18/ // 0xFF when not set
        /M/s32 m_index/0x4/0x1C/
        /M/s32 m_path_index/0x4/0x20/
        /M/f32 m_corner/0x4/0x24/ // signed cosine of the horizontal turn, race only
        /M/f32 m_width/0x4/0x28/ // scale * 50.f
        /M/sead::Vector3f m_normal/0xC/0x2C/
        /M/sead::Vector3f m_side_axis/0xC/0x38/
        /M/sead::Vector3f m_direction/0xC/0x44/ // (0, 0, 1) in game
        /M/u32 m_internal_flags/0x4/0x50/ // 1 -> m_side_axis is valid, 0xA -> award start path
    /END/
}
