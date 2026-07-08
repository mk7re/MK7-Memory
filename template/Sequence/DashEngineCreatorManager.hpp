#pragma once

#include "EngineCreatorManager.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@DashEngineCreatorManager/SIZE@0x10/BASE@EngineCreatorManager/BSIZE@0x10/VTABLE@True/
    public:
        virtual void defineEngineCreatorList(sead::PtrArray<EngineCreatorBase> *) const;

        DashEngineCreatorManager();
    /END/
}