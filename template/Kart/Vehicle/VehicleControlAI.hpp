#pragma once

#include "VehicleControlNet.hpp"

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@VehicleControlAI/SIZE@0xC28/BASE@VehicleControlNet/BSIZE@0xBE8/
	public:
		/M/f32 m_max_speed_ratio/0x4/0xBE8/ // share of the top speed the AI asks for
		/M/bool m_award_flag/0x1/0xBF8/ // award ceremony: the target point has max_search_y_offset 1
		/M/bool m_collision_switch/0x1/0xC25/
	/END/
}