#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EWingID.hpp"

BEGIN_NAMESPACE(Kart){
    /START_CLASS/NAME@Driver/SIZE@0xE8/
    public:
        // NOTE: guessed name
        enum class EGoalMotionState : u8
        {
            Win,
            Lose,
            Idle // default
        };

        /START_CLASS/NAME@FacePat/SIZE@0x14/
        public:
        /END/

        /M/InfoProxy *m_info_proxy/0x4/0x0/
        /M/Vehicle *m_vehicle/0x4/0x4/
        /M/RaceSys::EDriverID m_driver_id/0x4/0x8/
        /M/RaceSys::EWingID m_wing_id/0x4/0xC/
        /M/bool m_is_driver_mii/0x1/0x14/
        /M/Mii::Face *m_mii_face/0x4/0x18/
        /M/Object::Actor3DMdl *m_model/0x4/0x1C/
        /M/Render::DrawMdl *m_draw_mdl/0x4/0x20/
        /M/bool m_is_high_detail/0x1/0x24/
        /M/DriverCallback *m_driver_callback/0x4/0x28/
        /M/DriverHop *m_driver_hop/0x4/0x2C/
        /M/EGoalMotionState m_goal_motion_state/0x4/0x54/
        /M/FacePat *m_face_pat/0x4/0x74/
    /END/
}