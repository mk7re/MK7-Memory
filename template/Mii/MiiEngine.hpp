#pragma once

#include "../types.hpp"
#include "../CFL/cfl.hpp"

BEGIN_NAMESPACE(Mii)
{
    /START_CLASS/NAME@MiiEngine/SIZE@0x271B4/
    public:
        static bool getAdditionalInfo(CFLAdditionalInfo *, const CFLStoreData &, bool);
        f32 getMiiFaceScale();
    /END/
}