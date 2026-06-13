#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "CursorMove.hpp"
#include "KeyItem.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@Manipulator/SIZE@0x11C/
    public:
        s32 getCurrent();
        void manipulate();
        void setCapture(TouchItem *);
        void setKeyItem(KeyItem *, bool);
        void setCursorOn(bool);
        void setCursorOff(bool);
        void setTouchItem(TouchItem *);
        void setCursorItem(CursorItem *);
        void releaseCapture();
        void init();
        void reset();
        void isSelect(const CursorItem *);
        void savePrev();
        void setCursor(const UI::CursorItem *);
        void setCursor(s32);
        Manipulator(Sequence::BasePage *, s32);

        /M/u8 m_state/0x1/0x0/
        /M/TouchItem *m_capture/0x4/0x4/
        /M/sead::FixedPtrArray<KeyItem, 6> m_key_items/0x24/0x8/
        /M/sead::FixedPtrArray<TouchItem, 18> m_touch_items/0x54/0x2c/
        /M/sead::FixedPtrArray<CursorItem, 18> m_cursor_items/0x54/0x80/
        /M/Sequence::BasePage *m_page/0x4/0xd4/
        /U/s32/0x4/0xd8/
        /M/CursorMove m_cursor_move/0x24/0xdc/
        /M/s32 m_current_cursor_item_idx/0x4/0x100/   // Aka "optionIdx" or "selectedOptionIdx"
        /M/s32 m_previous_cursor_item_idx/0x4/0x104/   // Aka "optionIdx" or "selectedOptionIdx"
        /M/s32 m_selection_delay_timer/0x4/0x108/
        /M/s32 m_max_selection_delay_time/0x4/0x10c/
        /U/s32/0x4/0x110/
        /M/s32 m_selected_option/0x4/0x114/
        // Index in DashSequenceEngine's `m_selected_cursor_item_idx_array`
        /M/u8 m_selected_cursor_item_idx_array_id/0x1/0x118/
        /U/bool/0x1/0x119/
        /U/bool/0x1/0x11a/
    /END/
}