#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(System)
{
    /START_STRUCT/NAME@PlayerID/SIZE@0x10/
        void init();

        /M/u64 m_transferable_id/0x8/0x0/
        /U/u64/0x8/0x8/     // Current time? `nn::fnd::DateTime::GetNow()` is called shortly before this gets set in `init()`
    /END/
}