#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "BaseFastControl.hpp"
#include "../Item/eItemType.hpp"

#include <nw/lyt/Pane.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@RaceItemEquipControl/SIZE@0xA0/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~RaceItemEquipControl();
        virtual void onCreate(const Control::CreateArg *);
        virtual void onReset();
        virtual void onCalc();

        RaceItemEquipControl();
        void equipMulti(Item::eItemType);
        void setTexture(s32, Item::eItemType);
        void use(Item::eItemType);
        void drop(Item::eItemType);
        void equip(Item::eItemType);
        void setFPS(bool);
        void animUse();

        /M/RaceItemBoxControl *m_race_itembox_control/0x4/0x7c/
        /M/nw::lyt::Pane *m_R_center/0x4/0x80/
        // [0] -> P_item_l (nw::lyt::Pane *). Item on the left
        // [1] -> P_item_c (nw::lyt::Pane *). Item on the center
        // [2] -> P_item_r (nw::lyt::Pane *). Item on the right
        /M/ControlSight::ElementHandle m_element_handles[3]/0xc/0x84/
        /M/f32 m_item_height/0x4/0x90/  // Y pos of `P_item_l`
        /M/bool m_is_first_person/0x1/0x94/
        /M/s32 m_item_count/0x4/0x98/
        /M/Item::eItemType m_item_type/0x1/0x9c/
    /END/
}