#pragma once

#include "../types.hpp"
#include "Actor.hpp"

#include "../System/SceneID.hpp"

BEGIN_NAMESPACE(Object)
{
    /START_CLASS/NAME@ActorEngine/SIZE@0x8/BASE@Actor/BSIZE@0x8/
    public:
        virtual void sceneEnter(System::SceneID) {}; // 18
        virtual void sceneExit(System::SceneID) {}; // 19

        virtual void _0x50() = 0; // 20

        ActorEngine();
    /END/
}