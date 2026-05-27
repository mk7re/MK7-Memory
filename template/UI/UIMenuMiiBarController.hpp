#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@UIMenuMiiBarController/SIZE@0x138/
    public:
        enum class EState : s32 {
            STATE_0,
            STATE_1,
            STATE_DELETE,
            STATE_ADD,
            STATE_4
        };

        UIMenuMiiBarController();
        MiiBar *getEmptyBar();
        void setBarEnable(bool);
        void calcAddState_();
        void calcDeleteState_();
        bool isBarSlideFinished();
        void endIn();
        u32 update();
        void startOut(bool);
        void startIn(bool);
        void addBar(MiiBar *);

        /M/sead::FixedPtrArray<MiiBar, KART_MAX> m_mii_bar_array/0x2C/0x0/
        /M/EState m_state/0x4/0xb8/
        /M/sead::Vector3f m_positions[KART_MAX]/0x60/0xd8/
    /END/
}