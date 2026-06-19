#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../versions.h"

#include <controller/ctr/seadCtrController.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(System)
{
#if GAME_VERSION == VERSION_E3_2010
    // NOTE: The size actually appears to be 0x124, probably due to some missing fields
    // in `sead::ControllerBase`
    /START_CLASS/NAME@ControllerBase/SIZE@0x6C/
    public:
        /M/sead::ControllerBase m_base/0x68/0x4/
    /END/
#endif
}
