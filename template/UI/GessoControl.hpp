#pragma once

#include "../forward.hpp"

#include "BaseFastControl.hpp"
#include "UnitTextPane.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EGrandPrixRecord.hpp"

#include <math/seadVector.hpp>
#include <nw/lyt/Pane.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@GessoControl/SIZE@0x9C/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~GessoControl();
        virtual void onCreate(const Control::CreateArg *);
        virtual void onReset();
        virtual void onCalc();

        GessoControl();
        void changeVisible(bool);
        void animIn(s32);
        void animScale();

        /M/nw::lyt::Pane *m_R_center/0x4/0x7c/
        /M/bool m_is_anim_finished/0x1/0x80/
        /M/s32 m_active_timer/0x4/0x84/
        /M/s32 m_wait/0x4/0x88/
        /M/f32 m_speed/0x4/0x8c/
        /M/f32 m_color_element/0x4/0x90/    // Transparency?
        /M/sead::Vector2f m_scale/0x8/0x94/
    /END/
}