#pragma once

#include "VehicleBase.hpp"
#include "../../System/KDPad.hpp"



BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@VehicleControl/SIZE@0x11C/BASE@VehicleBase/BSIZE@0xE0/
	public:
		struct Controls
		{
			u32
				accelerate_forwards 	: 1, // 0x1
				accelerate_backwards 	: 1, // 0x2
				hop 					: 1; // 0x4
		};
		static_assert(sizeof(Controls) == 0x4);

		enum class ViewMode : s32
		{
			
		};

		void setPad(System::KDPad *);

		/M/System::KDPlayerPad *m_player_pad/0x4/0xE0/
		/M/System::ControllerBase *m_controller_base/0x4/0xE4/
		/M/u32 m_is_first_person/0x4/0xE8/
		/M/ViewMode m_active_view_mode/0x4/0xEC/
		/M/ViewMode m_current_view_mode/0x4/0xF0/
		/M/bool m_force_switch_first_person_view/0x1/0xF4/
		/M/bool m_is_gyro_controls_enabled/0x1/0xF5/
		/M/GLOBAL_NAMESPACE::Camera::KartCameraDirector *m_kart_camera_director/0x4/0xF8/
		/M/Controls m_controls/0x4/0xFC/
		/M/f32 m_stick_x/0x4/0x100/
		/M/f32 m_gyro_x/0x4/0x104/
		/M/f32 m_stick_y/0x4/0x108/
		/M/f32 m_gyro_y/0x4/0x10C/
		/M/f32 m_first_person_view_camera_distance/0x4/0x110/
		/M/bool m_is_first_person_view_offroad/0x1/0x114/
		/M/u32 m_first_person_view_offroad_frames/0x4/0x118/
	/END/
}