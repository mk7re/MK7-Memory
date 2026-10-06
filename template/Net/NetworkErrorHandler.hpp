#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkErrorHandler/SIZE@0x4C/
    public:
        enum class EErrorKind : s32 {
            NONE = 0,
            STAND_ALONE = 5,    // every other player left the session
        };

        /M/u32 m_error_code/0x4/0x38/
        /M/EErrorKind m_error_kind/0x4/0x40/ // kind of the pending error
    /END/
}