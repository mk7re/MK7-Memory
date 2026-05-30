#pragma once

#include "../types.hpp"

#include "../UI/VisualControl.hpp"
#include "../Sound/SndSeEvent.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@ControlSlider/SIZE@0x1CF4/
    public:
        enum class AnimationDirection : u8 {
            // Doesn't move, just vanishes on the spot
            DIRECTION_NONE,
            // e.g. swipe left
            DIRECTION_FORWARDS,
            // e.g. swipe right
            DIRECTION_BACKWARDS
        };

        /START_CLASS/NAME@ItemH/SIZE@0x28/
        /END/

        /START_CLASS/NAME@ItemV/SIZE@0x34/
        /END/

        ControlSlider();
        void setDelayH(u32);
        void setSlideH(UI::VisualControl *);
        void setSlideV(UI::VisualControl *, UI::VisualControl *);
        void startH();
        void startV();
        void stepH();
        void stepV();
        void updatePosDefH(u32);
        void stepMoveV(ItemV &, bool);

        // ControlSliders that are currently sliding in or out
        /M/s32 m_num_active_sliders/0x4/0x0/
        /M/sead::PtrArray<ItemH> m_item_h_array/0xC/0x14/
        /M/AnimationDirection m_anim_direction/0x1/0x1838/
        // Set to `true` when going back to a previous menu
        /M/bool m_is_going_backwards/0x1/0x1858/
        /U/Sound::SndSeEvent::EEvent/0x1/0x1861/
        /U/Sound::SndSeEvent::EEvent/0x1/0x1864/
        /U/Sound::SndSeEvent::EEvent/0x1/0x1865/
        /M/sead::PtrArray<ItemV> m_item_v_array/0xC/0x1868/
        /M/ItemV *m_item_v_array_buffer[20]/0x50/0x1c88/
    /END/
}