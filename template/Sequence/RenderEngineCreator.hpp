#pragma once

#include "DashEngineCreatorBase.hpp"
#include "../Render/RenderEngine.hpp"
#include "../Object/EEngineType.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@RenderEngineCreator/SIZE@0x14/SIZEOF@DashEngineCreatorBase<void *, void *, Object::EEngineType::Render>/BASE@DashEngineCreatorBase<Render::RenderEngine, Render::RenderEngine::Argument, Object::EEngineType::Render>/BSIZE@0x14/VTABLE@True/
    public:
        virtual const char *getClassName() const;
        virtual s32 convertMode(const sead::SafeString &) const;
        virtual s32 onInitArgumentInner(s32, Render::RenderEngine::Argument *, s16 *, s16 *);
    /END/
}