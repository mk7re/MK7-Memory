#pragma once

#include "Control.hpp"
#include "BaseMenuViewControl.hpp"
#include "../Object/ArgumentObj.hpp"

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@EndingMovieView/SIZE@0xAC/BASE@BaseMenuViewControl/BSIZE@0xA8/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~EndingMovieView();
        void create(const Object::ArgumentObj *);
        void draw(Control::EDrawScreen);

        /M/System::MobiClipThreadProxy *m_mobiclip_thread/0x4/0xa8/
    /END/
}