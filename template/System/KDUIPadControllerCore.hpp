#pragma once

#include "../types.hpp"

#include "KDPadControllerCore.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KDUIPadControllerCore/SIZE@0x160/BASE@KDPadControllerCore/BSIZE@0x160/
    public:
        virtual ~KDUIPadControllerCore();
        virtual void calcImpl_();
        virtual void updateDerivativeParamsSp_(u32, bool);
    /END/
}
