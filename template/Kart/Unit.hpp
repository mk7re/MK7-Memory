#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "Vehicle/Vehicle.hpp"

#include "../Object/Actor3DMdl.hpp"
#include "../Object/TDirectorList.hpp"
#include "../Object/TLinkSocket.hpp"

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@Unit/SIZE@0x400/BASE@Object::TDirectorList<Object::Actor3DMdl, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
	public:
		void changeToNetStop()
		{
			m_vehicle->m_is_net_send = false;
			m_vehicle->m_is_net_recv = false;
		}

		/M/s32 m_player_id/0x4/0x28/
		/M/Vehicle *m_vehicle/0x4/0x2C/
		/M/ReplayInfo *m_replay_info/0x4/0x30/
		/M/InfoProxy *m_info_proxy/0x4/0x34/
		/M/Mii::Face *m_mii_face/0x4/0x38/
		/M/bool m_is_master/0x1/0x3C/
		/M/bool m_is_high_detail/0x1/0x3D/
		/M/bool m_is_driver_mii/0x1/0x3E/
		/M/bool m_is_ghost/0x1/0x3F/
		/M/u8 m_flags/0x1/0x40/
		/M/KartPartsCustomedParam *m_kart_parts_customed_param/0x4/0x44/
		/M/PartsDriveParam *m_parts_drive_param/0x4/0x48/
		/M/System::ControllerBase *m_0x4C_kd_pad_controller/0x4/0x4C/
		/M/Driver *m_driver/0x4/0x50/
		/M/DispBody *m_disp_body/0x4/0x5c/
		/M/DispWing *m_disp_wing/0x4/0x1E8/
		/M/Render::DrawMdl *m_kart_shadow/0x4/0x1F4/
		/M/GhostVisible *m_ghost_visible/0x4/0x200/
		/M/DispKiller *m_disp_killer/0x4/0x204/
		/M/Camera *m_camera/0x4/0x214/
		/M/bool m_is_body_model_visible/0x1/0x3cc/
	/END/
}