#pragma once

#include "EngineCreatorBase.hpp"
#include "../Object/EEngineType.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@EngineCreator/TEMPLATE@template <class TEngine, class TArgument, Object::EEngineType Type>/SIZE@0x14/SIZEOF@EngineCreator<void *, void *, Object::EEngineType::Character>/BASE@EngineCreatorBase/BSIZE@0x14/VTABLE@True/
    public:
        virtual void createEngine(System::GameScene *, const SceneSequence *, const sead::SafeString &);
    /END/
}