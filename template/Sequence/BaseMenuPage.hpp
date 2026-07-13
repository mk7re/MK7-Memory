#pragma once

#include "../types.hpp"

#include "BasePage.hpp"
#include "ControlSlider.hpp"
#include "../Sound/EMenuPage.hpp"
#include "../RaceSys/EDriverID.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@BaseMenuPage/SIZE@0x294/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:
        struct ControlDisplayFlags
		{
			u8
				DISPLAY_BACK_BUTTON 				: 1, // 0x1
				_0x2 				                : 1, // 0x2
			 	ENABLE_SLIDE_ENTER 				    : 1, // 0x4. Allows the control slider to work when entering the menu
			    ENABLE_SLIDE_COMPLETE 			    : 1, // 0x8. Allows the control slider to work when exiting the menu
			    FORCE_SLIDE_ON_PAGE_EXIT 			: 1, // 0x10. See `Sequence::BaseMenuPage::step`
			    DISPLAY_WIFI_COUNTDOWN_TIMER 	    : 1, // 0x20. When in the Wifi character selection screen
			    ERASE_TIMER 		                : 1; // 0x40. Used in `Sequence::BaseMenuPage::complete`
		};
		static_assert(sizeof(ControlDisplayFlags) == 0x1);

        struct BaseMenuPageFlags
		{
			u8
				ON_TIME_UP_COMPLETE_DONE 				: 1; // 0x1
		};
		static_assert(sizeof(BaseMenuPageFlags) == 0x1);

        // TODO
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~BaseMenuPage();
        virtual void step();
        virtual void enter(Section::EFadeKind, u32);
        virtual void complete();
        virtual void exit();
        virtual bool canFinishFadein();
        virtual bool canFinishFadeout();
        virtual void onSliderSetting(bool, bool);
        virtual bool canStartSlideIn();
        virtual bool canStartSlideOut();
        virtual void onTimeUp(s32);
        virtual void onTimeUpComplete(s32);
        virtual void onTimeUpCompleteStep(s32);
        virtual s32 getBackEnterCode();
        virtual s32 getBackReturnCode();

        BaseMenuPage();
        void initSlider(s32);
        void applySetting_GP();
        void applySetting_CPU_(s32, s32, RaceSys::EDriverID);
        void applySetting_Battle();
        void applySetting_MasterCPU_();
        void applySetting_WinningRun();
        void applySetting_TimeAttackPre();
        void applySetting_TitleDemo_Race();
        void applySetting_TitleDemo_BattleCoin();
        void applySetting_TitleDemo_BattleBalloon();
        void onSliderSettingImpl(bool, bool, s32);
        
        /M/sead::FixedPtrArray<ControlSlider, 3> m_control_slider_array/0x18/0x26C/
        /M/ControlDisplayFlags m_control_display_flags/0x1/0x284/
        /M/s32 m_wifi_course_vote_timer/0x4/0x288/
        /M/BaseMenuPageFlags m_flags/0x1/0x28c/
        /M/Sound::EMenuPage m_id/0x4/0x290/
    /END/
}