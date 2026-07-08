#pragma once

#include "DashEngineCreatorBase.hpp"
#include "../Camera/CameraEngine.hpp"
#include "../Object/EEngineType.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@CameraEngineCreator/SIZE@0x14/SIZEOF@DashEngineCreatorBase<void *, void *, Object::EEngineType::Camera>/BASE@DashEngineCreatorBase<Camera::CameraEngine, Camera::CameraEngine::Argument, Object::EEngineType::Camera>/BSIZE@0x14/VTABLE@True/
    public:
        virtual const char *getClassName() const;
        virtual s32 convertMode(const sead::SafeString &) const;
        virtual s32 onInitArgumentInner(s32, Camera::CameraEngine::Argument *, s16 *, s16 *);
    /END/
}