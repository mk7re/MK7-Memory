#pragma once

#include "../forward.hpp"

#include "MiiBar.hpp"

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@MiiCheckBar/SIZE@0xBC/BASE@MiiBar/BSIZE@0xBC/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MiiCheckBar();
        virtual void onReset();
        virtual void startOut();

        bool setCheck(bool);
    /END/
}