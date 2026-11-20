#pragma once

#include "../types.hpp"

#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EEngineLevel.hpp"
#include "../RaceSys/EGrandPrixID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/ETitleType.hpp"
#include "../RaceSys/EWingID.hpp"

#include "../LMS_MessageID.hpp"

#include "../System/RootSystem.hpp"

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@MessageIDConverter/SIZE@0x228/
    public:
        /M/LMS_MessageID m_driver_short_message_ids[std::to_underlying(RaceSys::EDriverID::MAX)]/0x48/0x0/
        /M/LMS_MessageID m_driver_message_ids[std::to_underlying(RaceSys::EDriverID::MAX)]/0x48/0x48/
        /M/LMS_MessageID m_body_message_ids[std::to_underlying(RaceSys::EBodyID::MAX)]/0x44/0x90/
        /M/LMS_MessageID m_tire_message_ids[std::to_underlying(RaceSys::ETireID::MAX)]/0x28/0xD4/
        /M/LMS_MessageID m_wing_message_ids[std::to_underlying(RaceSys::EWingID::MAX)]/0x1C/0xFC/
        /M/LMS_MessageID m_course_message_ids[std::to_underlying(RaceSys::ECourseID::MAX)]/0xA0/0x118/
        /M/LMS_MessageID m_engine_level_message_ids[std::to_underlying(RaceSys::EEngineLevel::MAX)]/0xC/0x1B8/
        /M/LMS_MessageID m_grand_prix_message_ids[std::to_underlying(RaceSys::EGrandPrixID::MAX)]/0x20/0x1C4/
        /M/LMS_MessageID m_title_type_message_ids[std::to_underlying(RaceSys::ETitleType::MAX)]/0x44/0x1E4/
    /END/
}

BEGIN_NAMESPACE(Sequence)
{
    inline auto GetMessageIDConverter()
    {
        return System::g_root_system->get_message_id_converter();
    }
}