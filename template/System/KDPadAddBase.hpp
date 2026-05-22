#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "KDPadData.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KDPadAddBase/SIZE@0x24/VTABLE@True/
    public:
        /START_STRUCT/NAME@KDPadDataOnFrame/SIZE@0x1c/
            /M/u16 m_buttons/0x2/0x0/
            /M/s8 m_stick_x/0x1/0x2/
            /M/s8 m_stick_y/0x1/0x3/
            /M/bool m_update_inputs/0x1/0x4/
            /M/sead::Vector2f m_raw_stick/0x8/0x8/
            /M/u32 m_raw_buttons/0x4/0x10/
            /M/bool m_holding_start_or_select/0x1/0x14/
            /M/bool m_touch_screen_held/0x1/0x15/
            /M/sead::Vector2s m_touch_input/0x4/0x16/
        /END/

        virtual ~KDPadAddBase() = default;
        virtual void reset();
        virtual void calc();
        virtual void calcState() {};
        virtual void resetCore() {};
        virtual void initInner() {};

        KDPadAddBase(KDPad *, KDPadDataOnFrame &);
        void init();
        void start();

        /M/s32 m_0x4/0x4/0x4/
        /M/s32 m_0x8/0x4/0x8/
        /M/KDPadAddBase *m_prev_pad_add_base/0x4/0xc/
        // [0] -> TKDPadDataBase<System::KDPadButtonFormat>
        // [1] -> TKDPadDataBase<System::KDPadStickFormat>
        /M/sead::PtrArray<KDPadDataBase> m_pad_data_array/0xc/0x10/
        /M/KDPadDataOnFrame *m_data_on_frame/0x4/0x1c/
        /M/KDPad *m_pad/0x4/0x20/
    /END/
}