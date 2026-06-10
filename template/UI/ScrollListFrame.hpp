#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../versions.h"

#include "BaseMenuInputControl.hpp"
#include "KeyItem.hpp"
#include "ScrollListBarBase.hpp"

#include <prim/seadDelegate.h>
#include <container/seadPtrArray.h>
#include <nw/lyt/Pane.hpp>
#include <nw/lyt/Bounding.hpp>

BEGIN_NAMESPACE(UI)
{
#if GAME_VERSION != ALL_DLP
    /START_CLASS/NAME@ScrollListFrame/SIZE@0x5F0/BASE@BaseMenuInputControl/BSIZE@0x40C/VTABLE@True/
    public:
        enum class EMoveState : u8 {
            NOT_MOVING,
            MOVING_WITH_TOUCH,              // Scrolling by touching the entries themselves
            MOVING_WITH_TOUCH_THEN_PAD,     // Scrolling by touching the entries themselves, then using the D-Pad or Circle Pad to move while the scroll hasn't stopped moving
            MOVING_WITH_PAD,                // Using the D-Pad or Circle Pad to move
            MOVING_WITH_CURSOR              // Scrolling by touching the up / down arrow on the right
        };

        enum class EMovingDirection : s32 {
            NOT_MOVING,
            MOVING_UP,          // i.e. backwards
            MOVING_DOWN         // i.e. forwards
        };

        // NOTE: Name is made up
        /START_STRUCT/NAME@ControlInfo/SIZE@0x18/
            /U/void */0x4/0x0/
            /U/s32/0x4/0x4/
            /U/s32/0x4/0x8/
            /U/f32/0x4/0xc/
            /M/f32 m_height/0x4/0x10/
            /M/VisualControl *m_attached_control/0x4/0x14/
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~ScrollListFrame();
        virtual void onCreate(const Control::CreateArg *);
        virtual void keyHandler(s32, EKeyID);
        virtual void touchHandlerSlideOut(s32, const sead::Vector2f &);
        virtual void touchHandlerSlideIn(s32, const sead::Vector2f &);
        virtual void touchHandlerCaptureOut(s32, const sead::Vector2f &);

        ScrollListFrame();                                      // 0x00162f84 (VERSION_USA_REV1)
        void update();                                          // 0x0016175c (VERSION_USA_REV1)
        void attachControl(s32, const VisualControl &, f32);    // 0x00161514 (VERSION_USA_REV1)
        void onScroll(s32);                                     // 0x00161b08 (VERSION_USA_REV1)
        void FUN_00161010();                                    // 0x00161010 (VERSION_USA_REV1)
        ScrollListBarBase *getSelectedBar(EMovingDirection, bool);  // 0x001615f4 (VERSION_USA_REV1)
        static void calcMoving(float, ScrollListFrame *);       // TODO. Double check if this prototype is correct. 0x00161d1c (VERSION_USA_REV1)
        void FUN_00161f64(bool);                                // 0x00161f64 (VERSION_USA_REV1)
        void FUN_00162ba8();                                    // 0x00162ba8 (VERSION_USA_REV1)
        void FUN_00162c7c();                                    // 0x00162c7c (VERSION_USA_REV1)
        void triggerMoveWithPad(EMovingDirection);              // 0x00162d08 (VERSION_USA_REV1)
        void FUN_00162dac(s32);                                 // 0x00162dac (VERSION_USA_REV1)
        void calcMovingWithTouch();                             // 0x00162ef4 (VERSION_USA_REV1)

        /M/s32 m_option/0x4/0x410/
        /M/s32 m_num_items/0x4/0x430/
        /M/sead::PtrArray<ControlInfo> m_control_info_array/0xc/0x444/
        /M/ControlInfo *m_control_info_array_buffer[6]/0x18/0x4e8/
        /M/sead::PtrArray<ScrollListBarBase> *m_bars/0x4/0x500/
        /M/nw::lyt::Pane *m_P_scroll_bar_00/0x4/0x504/
        /M/nw::lyt::Bounding *m_B_scroll/0x4/0x508/
        /M/nw::lyt::Pane *m_P_scroll_btn/0x4/0x50c/
        /M/nw::lyt::Pane *m_B_btn/0x4/0x510/
        /M/KeyItem m_on_scroll_up_key_item/0x1c/0x514/
        /M/KeyItem m_on_scroll_down_key_item/0x1c/0x530/
        /M/sead::Delegate1<ScrollListFrame, s32> m_on_scroll_delegate/0x10/0x54c/
        /M/EMoveState m_moving_state/0x1/0x55c/
        // Set to the next option while the list is moving towards the next option
        // Once it reaches the next option, it's set back to -1
        /M/s32 m_next_option/0x4/0x560/
        /M/f32 m_scrolling_speed/0x4/0x584/
        /M/f32 m_pad_default_scrolling_speed/0x4/0x598/
    /END/
#endif
}