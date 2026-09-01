#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "Vehicle/VehicleReact.hpp"

#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Kart)
{
    /START_STRUCT/NAME@NetData/SIZE@0x48/
        NetData();

        void clear(s8 player_id)
        {
            m_frame = 0;
            m_accident_type = VehicleReact::EAcdType::Dummy;
            m_sender_player_id = player_id;
            m_kart_data = {};
            m_dokan_warp = -1;
        }

        bool read(Net::NetworkBuffer *, NetData **, NetData **);
        void send(s32);

        struct KartData
        {
            u32
                // VehicleControl::Controls
                accelerate_forwards     : 1, // 0x1
                accelerate_backwards    : 1, // 0x2
                hop                     : 1, // 0x4

                _0x8                    : 1,
                _0x10                   : 1,
                _0x20                   : 1,
                _0x40                   : 1,
                _0x80                   : 1,
                _0x100                  : 1,
                _0x200                  : 1,
                _0x400                  : 1,
                _0x800                  : 1,
                _0x1000                 : 1,
                _0x2000                 : 1,
                _0x4000                 : 1,
                _0x8000                 : 1,
                _0x10000                : 1,
                warp                    : 1; // 0x20000
        };
        static_assert(sizeof(KartData) == 0x4);

        /M/s32 m_frame/0x4/0x0/
        /M/KartData m_kart_data/0x4/0x4/
        /M/VehicleMove::StatusFlags m_status_flags/0x4/0x8/
        /M/s8 m_sender_player_id/0x1/0xC/
        /M/u8 m_coins/0x1/0xD/
        /M/u8 m_balloon_points/0x1/0xE/
        /M/u8 m_balloon_count/0x1/0xF/
        /M/sead::Vector3<s16> m_position/0x6/0x10/
        /M/sead::Vector3<s16> m_velocity/0x6/0x16/
        /M/sead::Vector3<s16> m_angular_velocity/0x6/0x1C/
        /M/s16 m_turning_speed/0x2/0x22/
        /M/s16 m_forward_speed/0x2/0x24/
        /M/s16 m_drift_steering/0x2/0x26/
        /M/s16 m_directional_speed/0x2/0x28/
        /M/u8 m_drift_type/0x1/0x2A/
        /M/u8 m_wing_path_id/0x1/0x2B/
        /M/u8 m_dokan_warp/0x1/0x2C/
        /M/u8 m_boost_type/0x1/0x2D/
        /M/s16 m_boost_speed/0x2/0x2E/
        /M/u8 m_boost_frames/0x1/0x30/
        /M/u8 m_star_timer/0x1/0x31/
        /M/u8 m_ink_timer/0x1/0x32/
        /M/u8 m_shrink_timer/0x1/0x33/
        /M/u8 m_squish_timer/0x1/0x34/
        /M/u8 m_blink_timer/0x1/0x35/
        /M/s8 m_respawn_point_id/0x1/0x36/
        /M/u8 m_hit_item_type_id/0x1/0x37/
        /M/u8 m_hit_player_id/0x1/0x38/
        /M/VehicleReact::EAcdType m_accident_type/0x1/0x39/
        /M/sead::Vector3<s16> m_hit_direction_1/0x6/0x3A/
        /M/sead::Vector3<s16> m_hit_direction_2/0x6/0x40/
    /END/
}