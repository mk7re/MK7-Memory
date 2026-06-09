#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EScrewID.hpp"

BEGIN_NAMESPACE(Kart)
{
    // NOTE: Name is made up
    /START_STRUCT/NAME@PartsDriveParamGroup/SIZE@0x14/
        /M/s32 m_total_count/0x4/0x0/
        /M/s32 m_driver/0x4/0x4/
        /M/s32 m_body/0x4/0x8/
        /M/s32 m_tire/0x4/0xc/
        /M/s32 m_wing/0x4/0x10/
    /END/

    /START_STRUCT/NAME@PartsDriveParam/SIZE@0x130/
        PartsDriveParam();
        void resetPoint();
        void applyToKart(Kart::Vehicle*);
        void updatePoint(RaceSys::EDriverID, RaceSys::EBodyID, RaceSys::ETireID, RaceSys::EWingID);

        /M/PartsDriveParamGroup m_weight/0x14/0x0/
        /M/PartsDriveParamGroup m_speed_land/0x14/0x14/
        /M/PartsDriveParamGroup m_speed_sea/0x14/0x28/
        /M/PartsDriveParamGroup m_speed_air/0x14/0x3c/
        /M/PartsDriveParamGroup m_accel/0x14/0x50/
        /M/PartsDriveParamGroup m_turn_land/0x14/0x64/
        /M/PartsDriveParamGroup m_turn_sea/0x14/0x78/
        /M/PartsDriveParamGroup m_turn_air/0x14/0x8c/
        /M/PartsDriveParamGroup m_offroad/0x14/0xa0/
        /M/PartsDriveParamGroup m_miniturbo/0x14/0xb4/
        /M/PartsDriveParamGroup m_tire_feeling/0x14/0xc8/
        /M/PartsDriveParamGroup m_drift_start/0x14/0xdc/
        /M/CSVUtil::CSVParam *m_points_driver/0x4/0xf0/
        /M/CSVUtil::CSVParam *m_points_body/0x4/0xf4/
        /M/CSVUtil::CSVParam *m_points_tire/0x4/0xf8/
        /M/CSVUtil::CSVParam *m_points_wing/0x4/0xfc/
        /M/CSVUtil::CSVParam *m_param_weight/0x4/0x100/
        /M/CSVUtil::CSVParam *m_param_speed_land/0x4/0x104/
        /M/CSVUtil::CSVParam *m_param_speed_sea/0x4/0x108/
        /M/CSVUtil::CSVParam *m_param_speed_air/0x4/0x10c/
        /M/CSVUtil::CSVParam *m_param_accel/0x4/0x110/
        /M/CSVUtil::CSVParam *m_param_turn_land/0x4/0x114/
        /M/CSVUtil::CSVParam *m_param_turn_sea/0x4/0x118/
        /M/CSVUtil::CSVParam *m_param_turn_air/0x4/0x11c/
        /M/CSVUtil::CSVParam *m_param_offroad/0x4/0x120/
        /M/CSVUtil::CSVParam *m_param_miniturbo/0x4/0x124/
        /M/CSVUtil::CSVParam *m_param_tire_feeling/0x4/0x128/
        /M/CSVUtil::CSVParam *m_param_drift_start/0x4/0x12c/
    /END/
}