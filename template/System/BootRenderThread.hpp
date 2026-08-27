#pragma once

#include "BootPictureIcon.hpp"
#include "KDThread.hpp"
//#include "versions.h"

#include <heap/seadHeap.h>

BEGIN_NAMESPACE(System)
{
    // Size is 0xF0 in `ALL_DLP`
    // Size is 0xF4 in `ALL_KIOSK`
    /START_CLASS/NAME@BootRenderThread/SIZE@0xF8/BASE@KDThread/BSIZE@0xA4/VTABLE@True/
    public:
        virtual ~BootRenderThread();
        virtual void calcInner_(s32);

        BootRenderThread();
        void setup();
        void calcFunc();

        /M/sead::Heap *m_heap/0x4/0xc4/
        // [0] -> Game logo (left)
        // [1] -> Game logo (right)
        // [2] -> Spinning tire icon
        /M/BootPictureBase *m_boot_pictures[3]/0xc/0xd0/
//#if GAME_VERSION == ALL_KIOSK
//        // Set to `true` when the BootRenderThread finished,
//        // in order to allow transitioning from the MK7 logo to the ratings screen
//        /M/bool m_boot_render_thread_completed/0x1/0xf0/
//#elif GAME_VERSION != ALL_DLP
//        /U/void */0x4/0xf0/
//        /U/void */0x4/0xf4/
//#endif
    /END/
}