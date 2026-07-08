#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "EngineCreatorBase.hpp"

#include <container/seadPtrArray.h>
#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@EngineCreatorManager/SIZE@0x10/VTABLE@True/
    public:
        virtual void vf_0x00();
        virtual void vf_0x04();
        virtual void defineEngineCreatorList(sead::PtrArray<EngineCreatorBase> *) const = 0;

        EngineCreatorManager();
        void createEngines(System::GameScene *, const SceneSequence *);
        static bool compareEngineCreator(const EngineCreatorBase *, const sead::SafeString *);
        static bool compareEngineCreator(const EngineCreatorBase *, const EngineCreatorBase *);
        void create();

        /M/sead::PtrArray<EngineCreatorBase> m_engine_creator_array/0xC/0x4/
    /END/
}