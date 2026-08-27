#pragma once

#include "../forward.hpp"

#include "../Item/eItemType.hpp"
#include "BaseFastControl.hpp"

#include <nw/lyt/Pane.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@BgRaceMapItemControl/SIZE@0xA4/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~BgRaceMapItemControl();
        virtual void onCreate(const Control::CreateArg *);
        virtual void onReset();
        virtual void onCalc();

        void calcEquipBanana();
        void setTex(Item::eItemType);
        void calcMove();
        void calcEquipKoura();
        void calcEquip(f32);

        /M/nw::lyt::Pane *m_P_item/0x4/0x7c/
        /M/Item::ItemObjBase *m_item_obj/0x4/0x80/
        /M/UI::BgRaceMapControl **m_current_bg_race_map_control/0x4/0x84/
        /U/void */0x4/0x88/
        /U/void */0x4/0x8c/
        /U/f32/0x4/0x90/
        /U/f32/0x4/0x94/
        /M/Kart::Vehicle *m_vehicle/0x4/0x98/
        /M/void (BgRaceMapItemControl::*m_calc_func)()/0x8/0x9c/
    /END/
}