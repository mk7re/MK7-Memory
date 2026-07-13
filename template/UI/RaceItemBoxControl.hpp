#pragma once

#include "../types.hpp"
#include "BaseFastControl.hpp"
#include "../Item/eItemSlot.hpp"

#include <nw/lyt/TexMap.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@RaceItemBoxControl/SIZE@0x350/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        // Each animation in the animation family with ID = 2
        enum Animation : s32
        {
            Animation_None,     // sc         (AnimationType::STOP_BY_RATE)
            Animation_Receive,  // sc         (AnimationType::DEFAULT)
            Animation_Use,      // item_flash (AnimationType::DEFAULT)
        };

        // NOTE: Name is made up
        enum class BoxIconName : u8 {
            MUSHROOM,           // kinoko
            DOUBLE_MUSHROOM,    // kinoko_2
            TRIPLE_MUSHROOM,    // kinoko_3
            STAR,               // star
            LIGHTNING,          // thunder
            BANANA,             // banana
            TRIPLE_BANANA,      // banana_3
            BOB_OMB,            // bomb_hei
            BLOOPER,            // gesso
            GREEN_SHELL,        // kame_green
            TRIPLE_GREEN_SHELL, // kame_green_3
            RED_SHELL,          // kame_red
            TRIPLE_RED_SHELL,   // kame_red_3
            BLUE_SHELL,         // kame_wing
            BULLET_BILL,        // killer
            GOLDEN_MUSHROOM,    // GKinoko
            FIRE_FLOWER,        // flower
            TANOOKI_LEAF,       // leaf
            LUCKY_SEVEN,        // sp_seven
            TEST3,              // star
            TEST4,              // star

            MAX
        };

        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~RaceItemBoxControl();
        virtual void onCreate(const Control::CreateArg *);
        virtual void onReset();
        virtual void onCalc();

        RaceItemBoxControl();
        void changeAnim(s32);
        void setTexture(s32, Item::eItemSlot);
        void setPauseVisible(bool);
        void changeItemTexture(s32);
        void animUse();
        void setColor(s32);

        /M/BoxIconName m_texmap_box_icon_indices[static_cast<u32>(Item::eItemSlot::MAX)]/0x14/0x7c/
        /M/bool m_is_pause_visible/0x1/0x90/
        /M/bool m_is_item_decided/0x1/0x91/
        /M/bool m_stop_roulette/0x1/0x92/
        /M/f32 m_ratio_slot/0x4/0x94/
        /M/Item::eItemSlot m_received_item/0x1/0x98/
        // Set to 0x14 in `UI::RaceItemBoxControl::onCreate` alongside `m_received_item`
        // Perhaps its type is also `Item::eItemSlot`?
        /U/u8/0x1/0x99/
        /M/Item::KartItemProxy *m_item_proxy/0x4/0x9c/
        // [0] -> N_itembox (nw::lyt::Pane *)
        // [1] -> P_item-00 (nw::lyt::Pane *). Current item in the roulette
        // [2] -> P_item-01 (nw::lyt::Pane *). Next item in the roulette
        /M/ControlSight::ElementHandle m_element_handles[3]/0xc/0xa0/
        /M/nw::lyt::TexMap m_texmap_box_icon[static_cast<u32>(BoxIconName::MAX)]/0x2a0/0xb0/

        // 0x005e11c8 (VERSION_EUR_DLP)
        static const char *boxIconNames[static_cast<u32>(BoxIconName::MAX)];
    /END/
}