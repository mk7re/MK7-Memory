#pragma once

#include "BaseFastControl.hpp"

#include <nw/lyt/TextBox.hpp>
#include <prim/seadSafeString.h>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@StaffRoll/SIZE@0x8EC/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~StaffRoll();
        virtual void onCreate(const Control::CreateArg *);
        virtual void onReset();

        void startAnim(f32);

        /M/nw::lyt::TextBox *unk_0x7c[4]/0x10/0x7c/
        /M/sead::WFixedSafeString<256> unk_0xa8[4]/0x830/0xa8/
        /M/nw::lyt::TextBox *unk_0x8d8[4]/0x10/0x8d8/
        /U/u8/0x1/0x8e8/
    /END/
}