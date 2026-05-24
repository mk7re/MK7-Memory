#pragma once

#include "../types.hpp"

//#include <thread/seadThread.h>

BEGIN_NAMESPACE(System)
{
    // TODO: Inherits from sead::Thread
    // Size 0xAC in VERSION_USA_REV1
    /START_CLASS/NAME@KDThread/SIZE@0xA4/VTABLE@True/
    public:
        virtual ~KDThread();
        virtual void destroy();
        virtual void sendMessage();
        virtual void vf_0x10();
        virtual bool start();
        virtual void quit();
        virtual void waitDone();
        virtual void vf_0x20();
        virtual void quitAndWaitDoneSingleThread();
        virtual void setPriority(s32);
        virtual void vf_0x2c();
        virtual void vf_0x30();
        virtual void vf_0x34();
        virtual void vf_0x38();
        virtual void calc_(s32);
        virtual void calcInner_(s32) = 0;

        void waitForRetrace();
    /END/
}
