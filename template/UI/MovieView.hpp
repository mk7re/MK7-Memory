#pragma once

#include "../forward.hpp"
#include "../Object/ArgumentObj.hpp"
#include "BaseFastControl.hpp"

#include <nw/lyt/TextBox.hpp>
#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@MovieView/SIZE@0xC4/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        /START_STRUCT/NAME@AnimationDefine/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            virtual void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            virtual const ControlAnimator::AnimationDefine *getAnimationDefine() const; // 3
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MovieView();
        virtual void create(const Object::ArgumentObj *);
        virtual void onCreate(const Control::CreateArg *);
        virtual void draw(Control::EDrawScreen);
        virtual void onReset();
        virtual void onCalc();

        void changeText(u32);
        void setMoviePane(const sead::SafeString &);
        void setMovieVisible(bool);
        void animOut();

        /M/nw::lyt::TextBox *m_T_mode/0x4/0x7c/
        /M/u32 m_message_idx/0x4/0xa8/
        /M/bool m_hide_movie/0x1/0xac/
        /U/bool/0x1/0xad/
        /M/System::MobiClipThreadProxy *m_mobiclip_thread/0x4/0xb0/
    /END/
}