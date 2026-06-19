#pragma once

#include "../forward.hpp"
#include "../types.hpp"


BEGIN_NAMESPACE(Field)
{
    // Name is made up
    enum ELodState : u32 {
        HIGH,
        MEDIUM,
        LOW,
        CULLED,
    };

    /START_CLASS/NAME@ObjectBase/SIZE@0xA0/VTABLE@True/
    public:
        virtual void calcView(); // 0

        /M/ELodState m_lod_state/0x4/0x74/
        /M/bool m_update_culling/0x1/0x7A/
        /M/bool m_is_culled/0x1/0x7B/
        /M/bool m_enable_culling/0x1/0x7C/
        /M/bool m_is_visible/0x1/0x7D/
        /M/bool m_is_net_object/0x1/0x98/
        /M/bool m_is_time_trials/0x1/0x99/
        /M/bool m_is_race_preview/0x1/0x9A/
    /END/
}