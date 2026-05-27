#pragma once

#include "../common.hpp"
#include "../types.hpp"

#include "BasePage.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../UI/MiiBar.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@Menu_UpBarController/SIZE@0x328/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~Menu_UpBarController();
        virtual void onPagePreStep();
        virtual void onPageEnter();
        virtual void initControl();

        void leaveSetting(s32);
        s32 setupSetting(bool);
        void leavePlayerName(s32);
        s32 setupCourseVote();
        void leaveKartSelected(s32);
        s32 setupSingleBattle();
        s32 setupKartSelectedBar();
        UI::MiiBar *getBar(s32);
        bool isNoReq();
        void startIn(bool);
        void startOut(bool);
        void addAIBar_();
        void setEnable(s32, bool);
        bool isBarFinished();
        void endIn();
        void setTex(s32, RaceSys::EDriverID, s32);
        
        /M/sead::FixedPtrArray<UI::MiiGroupBar, KART_MAX> m_menu_name_group/0x2c/0x26C/
        /M/sead::FixedPtrArray<UI::MiiStrBar, KART_MAX> m_menu_name_course/0x2c/0x298/
        /M/sead::FixedPtrArray<UI::MiiCheckBar, KART_MAX> m_menu_name_check/0x2c/0x2c4/
        /M/BaseMenuPage *m_menu_page/0x4/0x2f0/
        /U/s32/0x4/0x2f4/
        /U/s32/0x4/0x2f8/
        /U/s32/0x4/0x2fc/
        /U/s32/0x4/0x300/
        /U/s32/0x4/0x304/
        /U/bool/0x1/0x308/
        /U/u8/0x1/0x309/
        /M/sead::Delegate1<Menu_UpBarController, s32> m_leave_selected_delegate/0x10/0x30c/
        /M/UI::UIMenuMiiBarController *m_menu_name_group_controller/0x4/0x31c/
        /M/UI::UIMenuMiiBarController *m_menu_name_course_controller/0x4/0x320/
        /M/UI::UIMenuMiiBarController *m_menu_name_check_controller/0x4/0x324/
    /END/
}