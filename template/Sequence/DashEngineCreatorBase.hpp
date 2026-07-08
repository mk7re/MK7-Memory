#pragma once

#include "EngineCreator.hpp"
#include "../Object/EEngineType.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@DashEngineCreatorBase/TEMPLATE@template <class TEngine, class TArgument, Object::EEngineType Type>/SIZE@0x14/SIZEOF@DashEngineCreatorBase<void *, void *, Object::EEngineType::Character>/BASE@EngineCreator<TEngine, TArgument, Type>/BSIZE@0x14/VTABLE@True/
    public:
        virtual s32 onInitArgument(s32, TArgument *, s16 *, s16 *);
        virtual s32 onInitArgumentInner(s32, TArgument *, s16 *, s16 *);
    /END/
}