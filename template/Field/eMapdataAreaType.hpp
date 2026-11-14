#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    enum class eMapdataAreaType : u8
    {
        CAMERA,             // replay and after-finish camera, see m_came_index
        ENVIRONMENT_EFFECT, // m_setting1: what it switches on (0-3, usually that effect slot), m_setting2: seconds after the countdown before it shows
        TYPE_2,
        MOVING_ROAD,  // pushes karts on PULL collision along route m_route_id
        TYPE_4,
        TYPE_5,
        TYPE_6,
        TYPE_7,
        TYPE_8,
        TYPE_9,
        TYPE_10,
        SOUND_AREA,   // ambient sound (m_route_id < 1) or a sound placed along route m_route_id
        COURSE        // given by the game to the entries of the CORS section (Field::MapdataCourse), not used in AREA, no effect
    };
}