#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "BasePage.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@EndingPage/SIZE@0x2B4/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
        virtual ~EndingPage();
        virtual void onPagePreStep();
        virtual void onPageEnter();
        virtual void onPageComplete();
        virtual void onPageExit();
        virtual void initControl();

        /M/UI::EndingMovieView *m_ending_movie_view/0x4/0x26c/
        /M/System::MobiClipThread *m_mobiclip_thread/0x4/0x270/
        /M/UI::StaffRoll *m_staff_roll_array[10]/0x28/0x274/
        /M/s32 m_staff_roll_array_num/0x4/0x29c/
        /U/s32/0x4/0x2a0/
        /U/s32/0x4/0x2a4/
        /M/s32 m_is_credits_true/0x4/0x2a8/
        /U/s32/0x4/0x2ac/
        /U/u8/0x1/0x2b0/
        /U/bool/0x1/0x2b1/
    /END/

    extern sead::SafeString g_ending_movie_names[2]; // 0x00692a54 (VERSION_USA_REV1)
}