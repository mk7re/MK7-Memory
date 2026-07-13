#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "MenuMoviePageBase.hpp"
#include "../RaceSys/ERacePlayMode.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuSingle_Mode/SIZE@0x2E8/BASE@MenuMoviePageBase/BSIZE@0x2BC/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MenuSingle_Mode();
        virtual void onPagePreStep();
        virtual void onPageEnter();
        virtual void onPageExit();
        virtual void initControl();
        virtual void onPageFadeout();
        virtual void buttonHandler_SelectOn(s32);
        virtual void buttonHandler_OK(s32);

        MenuSingle_Mode();
#if GAME_VERSION != ALL_DLP
        void setupMovie();      // 0x004a3f78 (VERSION_USA_REV1)
#endif
        
        /M/RaceSys::ERacePlayMode m_play_mode/0x4/0x2bc/
        /M/sead::FixedPtrArray<UI::MenuButton, 4> m_menu_buttons/0x1c/0x2c0/
        /M/UI::MenuCaption *m_caption/0x4/0x2dc/
        /M/UI::BackButtonB *m_back_button/0x4/0x2e0/
        /M/UI::MovieView *m_movie_view/0x4/0x2e4/
    /END/
}