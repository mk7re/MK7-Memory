#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@EngineCreatorBase/SIZE@0x14/VTABLE@True/
    public:
        virtual void vf_0x00();
        virtual void vf_0x04();
        virtual const char *getClassName() const = 0;
        virtual void createEngine(System::GameScene *, const SceneSequence *, const sead::SafeString &) = 0;
        virtual s32 convertMode(const sead::SafeString &) const = 0;

        EngineCreatorBase();

        /U/s32/0x4/0x4/
        /U/s32/0x4/0x8/
        /U/s32/0x4/0xc/
        /M/SceneSequenceProxy *m_scene_sequence_proxy/0x4/0x10/
    /END/
}