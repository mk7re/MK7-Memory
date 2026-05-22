#pragma once

#include "VehicleControlAI.hpp"

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@VehicleMove/SIZE@0x1214/BASE@VehicleControlAI/BSIZE@0xC28/
	public:
		struct StatusFlags
		{
			u32
				jump 						: 1, // 0x1
				ollie_pitch 				: 1, // 0x2
			 	land 						: 1, // 0x4
			    stand_still 				: 1, // 0x8
			    sticky_road 				: 1, // 0x10
			    jugem_recover 				: 1, // 0x20
			    jugem_recover_ai_oob 		: 1, // 0x40
			    wing_open 					: 1, // 0x80
			    glider_pad 					: 1, // 0x100
			    unk_glider 					: 1, // 0x200
			    wing_force_close 			: 1, // 0x400
			    wing_tricked 				: 1, // 0x800
			    in_water 					: 1, // 0x1000
			    in_moon 					: 1, // 0x2000
			    sliding_turn 				: 1, // 0x4000
			    in_slope 					: 1, // 0x8000
			    accident_1 					: 1, // 0x10000
			    accident_2 					: 1, // 0x20000
			    mushroom_bounce 			: 1, // 0x40000
			    in_pullback 				: 1, // 0x80000
			    in_pullback_extreme 		: 1, // 0x100000
			    tricked 					: 1, // 0x200000
			    killer 						: 1, // 0x400000
			    hang 						: 1, // 0x800000
			    tail 						: 1, // 0x1000000
			    battle_restart 				: 1, // 0x2000000
			    ground_camera 				: 1, // 0x4000000
			    vanish_start 				: 1, // 0x8000000
			    vanish_end 					: 1, // 0x10000000
			    _0x20000000 				: 1, // 0x20000000
			    _0x40000000 				: 1, // 0x40000000
			    camera_roll_unlock 			: 1; // 0x80000000
		};
		static_assert(sizeof(StatusFlags) == 0x4);

		struct BoostFlags
		{
			u32
				mushroom 					: 1, // 0x1
				boost_pad 					: 1, // 0x2
			 	jugem_recovery 				: 1, // 0x4
			    miniturbo 					: 1, // 0x8
			    super_miniturbo 			: 1, // 0x10
			    start_lv1 					: 1, // 0x20
			    start_lv2 					: 1, // 0x40
			    start_lv3 					: 1, // 0x80
			    start_lv4 					: 1, // 0x100
			    start_lv5 					: 1, // 0x200
			    trick 						: 1, // 0x400
			    trick_water_dive 			: 1, // 0x800
			    trick_water 				: 1, // 0x1000
			    star_ring 					: 1, // 0x2000
			    coin 						: 1, // 0x4000
			    water 						: 1, // 0x8000
			    _0x10000 					: 1, // 0x10000
			    _0x20000 					: 1, // 0x20000
			    _0x40000 					: 1, // 0x40000
			    tail_jump 					: 1, // 0x80000
			    wall_stuck 					: 1, // 0x100000
			    wing_closed 				: 1, // 0x200000
			    _0x400000 					: 1, // 0x400000
			    _0x800000 					: 1, // 0x800000
			    _0x1000000 					: 1, // 0x1000000
			    _0x2000000 					: 1, // 0x2000000
			    _0x4000000 					: 1, // 0x4000000
			    _0x8000000 					: 1, // 0x8000000
			    _0x10000000 				: 1, // 0x10000000
			    _0x20000000 				: 1, // 0x20000000
			    _0x40000000 				: 1, // 0x40000000
			    _0x80000000 				: 1; // 0x80000000
		};
		static_assert(sizeof(BoostFlags) == 0x4);

		enum class DashType: u32 {
			COIN_OR_SLIPSTREAM,
			MINITURBO_OR_TRICK,
			START_OR_RESPAWN_BOOST,
			WATER_NOSEDIVE,
			STAR_RING,
			TRICK_WATER_DIVE,
			DASH_PANEL,
			MUSHROOM,
			NO_DASH
		};

		/M/BoostFlags m_boost_flags/0x4/0xC28/
		/M/BoostFlags m_boost_flags_previous_frame/0x4/0xC2C/
		/M/StatusFlags m_status_flags/0x4/0xC30/
		/M/StatusFlags m_status_flags_previous_frame/0x4/0xC34/
		/M/sead::Vector3f m_xyz_speed_vec/0xC/0xC60/
		/M/sead::Vector3f m_prev_xyz_speed_vec/0xC/0xC6C/
		// The speed of the vehicle that also includes the effect of other external forces. Capped to 30.0f
		/M/f32 m_xyz_speed/0x4/0xC78/
		/M/f32 m_xyz_speed_ratio/0x4/0xC7C/
		/M/s32 m_air_frames/0x4/0xD48/
		/M/s32 m_ground_frames/0x4/0xD50/
		/M/sead::Vector3f m_front_pitch/0xC/0xD6C/
		/M/s32 m_dokan_warp/0x4/0xDA8/
		/U/bool/0x1/0xE81/
		/M/f32 m_miniturbo_charge/0x4/0xF08/
		/M/f32 m_yaw_strength/0x4/0xF24/
		/M/f32 m_forward_speed/0x4/0xF2C/
		// The current max speed of the vehicle, including the current coin amount.
		// Doesn't count the max speed when in offroad, etc.
		/M/f32 m_current_max_speed_base/0x4/0xF80/
		/M/f32 m_current_max_speed_2/0x4/0xF84/
		// The actual, true current max speed, taking into account other speed limiters,
		// such as the lightning or star. Also includes CPU rubberbanding
		/M/f32 m_current_max_speed/0x4/0xF88/
		/M/DashType m_current_boost_type/0x4/0xF98/
		/M/s32 m_boost_frames/0x4/0xF9C/
		/M/s32 m_boost_duration_per_type[8]/0x20/0xFA0/
		/M/f32 m_boost_speed/0x4/0xFC0/	// Maximum speed when the boost is applied
		/M/f32 m_boost_accel/0x4/0xFC4/
		/M/s32 m_draft_frames/0x4/0xFD8/
		/M/s32 m_trick_frames/0x4/0xFF0/
		/M/s32 m_star_frames/0x4/0xFF4/
		/M/s32 m_ink_frames/0x4/0xFF8/
		/M/s32 m_stun_frames/0x4/0xFFC/
		/M/s32 m_thunder_frames/0x4/0x1000/
		/M/s32 m_press_frames/0x4/0x1004/
		/M/f32 m_press_size/0x4/0x1014/
		/M/s32 m_invincibility_frames/0x4/0x102C/
		/M/s32 m_jugem_frames/0x4/0x103C/
		/M/f32 m_speed_max_forward_land_base/0x4/0x1054/
		/M/f32 m_Dash_FrmMiniT_Lv1/0x4/0x1128/
		/M/f32 m_Dash_FrmMiniT_Lv2/0x4/0x112c/
	/END/
}