#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    enum class eMapdataAreaType : u8
    {
        CAMERA,
        ENVIRONMENT_EFFECT,
        TYPE_2,
        MOVING_ROAD,  // Used by `Kart::PullPath`
        TYPE_4,
        TYPE_5,
        TYPE_6,
        TYPE_7,
        TYPE_8,
        TYPE_9,
        TYPE_10,
        SOUND_AREA,
        COURSE        // Used by MapdataAreaCourse. See `Field::MapdataCourseAccessor::constructLocal`
    };
}