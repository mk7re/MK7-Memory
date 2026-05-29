#pragma once

#include "AppletLauncher.hpp"

#include <nn/swkbd/CTR/swkbd.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KeyboardAppletLauncher/SIZE@0x44/BASE@AppletLauncher/BSIZE@0x44/VTABLE@True/
    public:

        void launch(const nn::swkbd::CTR::Parameter *, const wchar_t *);
    /END/
}