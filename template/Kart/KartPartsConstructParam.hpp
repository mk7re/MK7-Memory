#pragma once

#include "../types.hpp"

#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EScrewID.hpp"

BEGIN_NAMESPACE(Kart)
{
    /START_STRUCT/NAME@KartPartsConstructParam/SIZE@0x14/
        KartPartsConstructParam()
        {
            m_tire_id = RaceSys::ETireID::Standard;
            m_wing_id = RaceSys::EWingID::SuperGlider;
            m_screw_id = RaceSys::EScrewID::Standard;
            m_driver_id = RaceSys::EDriverID::Mario;
            m_body_id = RaceSys::EBodyID::Standard;
        }

        /M/RaceSys::EBodyID m_body_id/0x4/0x0/
        /M/RaceSys::EDriverID m_driver_id/0x4/0x4/
        /M/RaceSys::ETireID m_tire_id/0x4/0x8/
        /M/RaceSys::EWingID m_wing_id/0x4/0xC/
        /M/RaceSys::EScrewID m_screw_id/0x4/0x10/
    /END/
}