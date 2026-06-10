#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Kart)
{
    /START_STRUCT/NAME@PartsDriveParamSet/SIZE@0xB4/
        /M/float m_mass_stopped/0x4/0x0/                      // KartBound_MassL
        /M/float m_mass/0x4/0x4/                              // KartBound_MassH
        /M/float m_mass_dash/0x4/0x8/                         // KartBound_MassD
        /M/float m_speed_max_forward_land/0x4/0xC/            // Drive_SpdMaxFwd_L
        /M/float m_speed_max_forward_land_max_coins/0x4/0x10/ // Drive_SpdMaxFwd_H
        /M/float m_speed_max_forward_sea/0x4/0x14/            // Float_SpdMaxFwd_L
        /M/float m_speed_max_forward_sea_max_coins/0x4/0x18/  // Float_SpdMaxFwd_H
        /M/float m_speed_max_forward_air_neutral/0x4/0x1C/    // Wing_SpdMaxFwd_N
        /M/float m_speed_max_forward_air_downward/0x4/0x20/   // Wing_SpdMaxFwd_D
        /M/float m_ground_lift_air/0x4/0x24/                  // Wing_GndLift
        /M/float m_acceleration_limit_forward_land/0x4/0x28/  // Drive_AccLmtFwd
        /M/float m_speed_kf_forward_land/0x4/0x2C/            // Drive_SpdKfFwd
        /M/float m_handling_drive_land/0x4/0x30/              // Drive_DirRotH
        /M/float m_handling_drift_land/0x4/0x34/              // Drift_DirRotH
        /M/float m_handling_auto_drift_land/0x4/0x38/         // AutoDrift_ChargeRt
        /M/float m_handling_drive_sea/0x4/0x3C/               // Float_Drive_DirRotH
        /M/float m_handling_drift_sea/0x4/0x40/               // Float_Drift_DirRotH
        /M/float m_handling_auto_drift_sea/0x4/0x44/          // Float_AutoDrift_ChargeRt
        /M/float m_handling_slide_sea/0x4/0x48/               // Float_SlideK
        /M/float m_handling_roll_air/0x4/0x4C/                // Wing_StickLR_Roll
        /M/float m_handling_move_air/0x4/0x50/                // Wing_StickLR_Move
        /M/float m_brake_dirt_light/0x4/0x54/                 // BrakeRt_DIRT_L
        /M/float m_brake_dirt_medium/0x4/0x58/                // BrakeRt_DIRT_M
        /M/float m_brake_dirt_heavy/0x4/0x5C/                 // BrakeRt_DIRT_H
        /M/float m_brake_sand_light/0x4/0x60/                 // BrakeRt_SAND_L
        /M/float m_brake_sand_medium/0x4/0x64/                // BrakeRt_SAND_M
        /M/float m_brake_sand_heavy/0x4/0x68/                 // BrakeRt_SAND_H
        /M/float m_brake_ice_light/0x4/0x6C/                  // BrakeRt_ICE_L
        /M/float m_brake_ice_medium/0x4/0x70/                 // BrakeRt_ICE_M
        /M/float m_brake_ice_heavy/0x4/0x74/                  // BrakeRt_ICE_H
        /M/float m_slip_dirt_light/0x4/0x78/                  // SlipRt_DIRT_L
        /M/float m_slip_dirt_medium/0x4/0x7C/                 // SlipRt_DIRT_M
        /M/float m_slip_dirt_heavy/0x4/0x80/                  // SlipRt_DIRT_H
        /M/float m_slip_sand_light/0x4/0x84/                  // SlipRt_SAND_L
        /M/float m_slip_sand_medium/0x4/0x88/                 // SlipRt_SAND_M
        /M/float m_slip_sand_heavy/0x4/0x8C/                  // SlipRt_SAND_H
        /M/float m_slip_ice_light/0x4/0x90/                   // SlipRt_ICE_L
        /M/float m_slip_ice_medium/0x4/0x94/                  // SlipRt_ICE_M
        /M/float m_slip_ice_heavy/0x4/0x98/                   // SlipRt_ICE_H
        /M/float m_miniturbo_boost_amount_level1/0x4/0x9C/    // Dash_FrmMiniT_Lv1
        /M/float m_miniturbo_boost_amount_level2/0x4/0xA0/    // Dash_FrmMiniT_Lv2
        /M/float m_tire_feeling_1/0x4/0xA4/                   // Float_Roll
        /M/float m_tire_feeling_2/0x4/0xA8/                   // Float_Roll_Dr
        /M/float m_tire_feeling_3/0x4/0xAC/                   // Attach_LowRt
        /M/float m_drift_start/0x4/0xB0/                      // OuterSlip
    /END/
}