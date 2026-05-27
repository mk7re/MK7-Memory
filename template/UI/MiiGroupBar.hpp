#pragma once

#include "../forward.hpp"

#include "BaseFastControl.hpp"
#include "MiiBar.hpp"

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@MiiGroupBar/SIZE@0xC8/BASE@MiiBar/BSIZE@0xBC/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MiiGroupBar();
        virtual void onReset();
        virtual void startOut();

        void setPosL();
        void setPosR();
        void moveLtoR();
        void moveRtoL();

        /M/nw::lyt::TextBox *m_T_name2/0x4/0xbc/
        /M/BaseFastControl::TextScale m_text_scale/0x8/0xc0/
    /END/
}