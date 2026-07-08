#pragma once

#include "DashEngineCreatorBase.hpp"
#include "../Object/CharacterEngine.hpp"
#include "../Object/EEngineType.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@CharacterEngineCreator/SIZE@0x14/SIZEOF@DashEngineCreatorBase<void *, void *, Object::EEngineType::Character>/BASE@DashEngineCreatorBase<Object::CharacterEngine, Object::CharacterEngine::Argument, Object::EEngineType::Character>/BSIZE@0x14/VTABLE@True/
    public:
        virtual const char *getClassName() const;
        virtual s32 convertMode(const sead::SafeString &) const;
        virtual s32 onInitArgumentInner(s32, Object::CharacterEngine::Argument *, s16 *, s16 *);
    /END/
}