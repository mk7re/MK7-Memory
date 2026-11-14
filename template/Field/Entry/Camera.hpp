#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "../../types.hpp"

#include "base.hpp"

BEGIN_NAMESPACE(Field)
{    
    /START_CLASS/NAME@MapdataCamera/SIZE@0x2C/
    public:
        // How the camera moves and where it looks
        enum class EType : u8 {
            GOAL = 0,                   // meant for the view after the finish; behaves as FOLLOW, but the game never makes it current
            FIXED = 1,                  // fixed position, looks at the kart
            PATH = 2,                   // moves along m_route_id, looks at the kart
            FOLLOW = 3,                 // orbits the kart at the angles and distance in m_viewpoint_begin
            FIXED_MOVE_AT = 4,          // fixed position, look-at point moves from m_viewpoint_begin to m_viewpoint_end
            PATH_MOVE_AT = 5,           // moves along m_route_id, look-at point moves as in FIXED_MOVE_AT
            FOLLOW_PATH = 6,            // follows the watched kart along m_route_id, whose points are offsets from it
            FOLLOW_PATH_KART_1 = 7,     // FOLLOW_PATH, following kart 1 (second place in the award ceremony)
            FOLLOW_PATH_KART_2 = 8,     // FOLLOW_PATH, following kart 2 (third place in the award ceremony)
        };

        /START_STRUCT/NAME@SData/SIZE@0x48/
            /M/EType m_type/0x1/0x0/
            /M/s8 m_next/0x1/0x1/ // next camera of the course intro, -1 none; -2 makes follow cameras keep the world Y axis as up
            /M/u8 m_video_next/0x1/0x2/ // non-zero: no area camera is built from it, and the intro chain search does not start from it
            /M/s8 m_route_id/0x1/0x3/ // POTI route, -1 none
            /M/u16 m_point_speed/0x2/0x4/ // not read by the game
            /M/u16 m_fov_speed/0x2/0x6/ // hundredths of a degree per frame, from m_fov_begin toward m_fov_end
            /M/u16 m_viewpoint_speed/0x2/0x8/ // hundredths of a unit per frame, from m_viewpoint_begin toward m_viewpoint_end
            /M/u8 m_start_flag/0x1/0xA/ // not read by the game
            /M/u8 m_video_flag/0x1/0xB/ // not read by the game
            /M/sead::Vector3f m_position/0xC/0xC/
            /M/sead::Vector3f m_rotation/0xC/0x18/ // radians
            /M/f32 m_fov_begin/0x4/0x24/ // degrees
            /M/f32 m_fov_end/0x4/0x28/ // degrees
            // Look-at point (FIXED_MOVE_AT, PATH_MOVE_AT); for FOLLOW: yaw and pitch in degrees, then distance
            /M/sead::Vector3f m_viewpoint_begin/0xC/0x2C/
            // Look-at point (FIXED_MOVE_AT, PATH_MOVE_AT); for follow cameras: yaw, pitch and roll of the view in degrees
            /M/sead::Vector3f m_viewpoint_end/0xC/0x38/
            /M/f32 m_duration/0x4/0x44/ // frames
        /END/

        /M/MapdataPath *m_path/0x4/0x0/
        /M/SData *m_data/0x4/0x4/
        /M/sead::Matrix33f m_posture/0x24/0x8/ // rotation matrix of m_rotation
    /END/
}
