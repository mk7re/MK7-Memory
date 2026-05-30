#pragma once

#include "../types.hpp"
#include "EDriverID.hpp"
#include "EBodyID.hpp"
#include "ETireID.hpp"
#include "EWingID.hpp"
#include "EScrewID.hpp"
#include "../versions.h"
#include "CTime.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    /START_STRUCT/NAME@RankingOneData/SIZE@0x24/
        RankingOneData();
#if GAME_VERSION != ALL_DLP
        void set(const CTime &, EDriverID, EBodyID, ETireID, EWingID, EScrewID);        // 0x00462ad8 (VERSION_USA_REV1)
#endif

        /M/bool m_is_finished/0x1/0x0/
        /M/CTime m_time/0xc/0x4/
        /M/EDriverID m_driver/0x4/0x10/
        /M/EBodyID m_body/0x4/0x14/
        /M/ETireID m_tire/0x4/0x18/
        /M/EWingID m_wing/0x4/0x1c/
        /M/EScrewID m_screw/0x4/0x20/
    /END/
}
