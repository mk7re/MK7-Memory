#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "BasePage.hpp"
#include "NetworkErrorChecker.hpp"
#include "../UI/BaseMenuViewControl.hpp"
#include "../UI/Control.hpp"
#include "../UI/HomeDisableIcon.hpp"
#include "../Sound/SndSeEvent.hpp"

#include <prim/seadSafeString.hpp>
#include <container/seadPtrArray.h>
#include <math/seadVector.hpp>
#include <nw/lyt/Pane.hpp>
#include <nw/lyt/Drawer.hpp>
#include <nw/lyt/DrawInfo.hpp>

BEGIN_NAMESPACE(Sequence)
{
    // TODO: Fill this
    enum class SystemDialogOwner : u32
    {
        OWNER_0
    };

    enum class EDialogType : u32
    {
        // One button (OK)
        TYPE_OK,
        // Two options selection (Yes / No)
        TYPE_YES_NO,
        // Shows the wait icon. No buttons
        TYPE_WAIT,
        // No buttons
        TYPE_NO_BUTTONS,
        // Can display the back (B) button
        TYPE_BACK_BUTTON,

        TYPE_MAX
    };

    /START_CLASS/NAME@Common_SystemDialog/SIZE@0x6C8/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:
        // Seemingly the same as `Sequence::EDialogType`
        enum class SystemDialogType : u32
        {
            // One button (OK)
            TYPE_OK,
            // Two options selection (Yes / No)
            TYPE_YES_NO,
            // Shows the wait icon. No buttons
            TYPE_WAIT,
            // No buttons
            TYPE_NO_BUTTONS,
            // Can display the back (B) button
            TYPE_BACK_BUTTON,

            TYPE_MAX
        };

        enum class SystemDialogResult : u32
        {
            RESULT_NO,
            RESULT_YES,
            RESULT_NONE,
            RESULT_ERROR
        };

        enum class EnterCode : s32
        {
            SINGLE,
            MULTI,
            WIFI
        };

        enum class ReturnCode : s32
        {
            NORMAL,
            ERROR,
            SIMPLE_ERROR
        };

        /START_CLASS/NAME@SystemDialogData/SIZE@0x1C/
            SystemDialogData();

            /M/s32 m_manipulator_idx/0x4/0x0/
            /M/UI::MenuDialogBody *m_body/0x4/0x4/
            /M/UI::MenuDialogHalfBody *m_half_body/0x4/0x8/
            /M/UI::SystemDialogButton *m_button_next/0x4/0xc/
            /M/UI::SystemDialogButton *m_button_2_yes/0x4/0x10/
            /M/UI::SystemDialogButton *m_button_2_no/0x4/0x14/
            /M/UI::MenuWaitMark *m_wait_mark/0x4/0x18/
        /END/

        /START_CLASS/NAME@SystemDialogState/SIZE@0x140/
            void set(SystemDialogType, s32, const UI::DashMessageArg *, bool, bool, s32, s32, s32);

            /M/s32 m_message_id/0x4/0x0/
            /M/s32 m_ok_option_message_id/0x4/0x4/
            /M/s32 m_yes_option_message_id/0x4/0x8/
            /M/s32 m_no_option_message_id/0x4/0xc/
            /M/SystemDialogType m_type/0x4/0x10/
            /M/UI::DashMessageArg m_message_arg/0x128/0x14/
            /M/bool m_0x13c/0x1/0x13c/
            /M/bool m_0x13d/0x1/0x13d/
        /END/

        // TODO
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        ~Common_SystemDialog();
        void onPagePreStep();
        void onPageEnter();
        bool canFinishFadein();
        void initControl();
        void enterCursor(s32);
        void buttonHandler_OK(s32);
        void procOpenMenu();
        void onMenuEnter();
        void onMenuComplete();
        void onMenuExit();
        
        void fadeInWindow_(Sequence::Common_SystemDialog::SystemDialogState &, bool);
        void fadeOutWindow_(Sequence::Common_SystemDialog::SystemDialogState &, bool);
        void closeSystemDialog_();
        UI::MenuDialogBody *createSystemDialogBody_(s32);
        UI::SystemDialogButton *createSystemDialogButton_(s32);
        UI::MenuDialogHalfBody *createSystemDialogHalfBody_(s32);
        UI::MenuWaitMark *createSystemDialogWaitMark_(s32, s32);
        UI::SystemDialogButton *createSystemDialogButton2_No_(s32);
        UI::SystemDialogButton *createSystemDialogButton2_Yes_(s32);
        void setupSystemDialog_(s32);
        void setupSystemDialogMessage_(s32, s32, const UI::DashMessageArg *, s32, s32, s32);
        void closeSystemWindow(bool);
        void noHomeDisableIcon();
        void startSystemWindow(SystemDialogType, s32, const UI::DashMessageArg *, bool, bool, s32, s32, s32);
        void changeSystemWindow(SystemDialogType, s32, const UI::DashMessageArg *, bool, s32, s32, s32, bool);
        void drawHomeDisableIcon(nw::lyt::Drawer *, nw::lyt::DrawInfo &);
        void setOKSound_YesButton(Sound::SndSeEvent::EEvent);
        void setOKSound_NoButton(Sound::SndSeEvent::EEvent);
        void setOKSound_OKButton(Sound::SndSeEvent::EEvent);
        void showHomeDisableIcon();
        bool isSystemWindowClosed(SystemDialogOwner);
        bool isSystemWindowOpened(SystemDialogOwner);
        bool isSystemWindowStable(SystemDialogOwner);
        bool isSystemWindowDecided(SystemDialogOwner);
        void setupHomeDisableIcon();
        void vanishHomeDisableIcon();
        void setDisableSystemWindow();
        void draw(UI::Control::EDrawScreen, nw::lyt::Drawer *, nw::lyt::DrawInfo &);
        Common_SystemDialog();

        static ReturnCode convertEnterCodeImpl(const sead::SafeString &);
        static char const *convertReturnCodeImpl(s32);

        /M/UI::HomeDisableIcon *m_home_disable_icon/0x4/0x26C/
        /M/SystemDialogData m_dialog_data_array[7]/0xc4/0x270/
        /M/s32 m_0x334/0x4/0x334/
        /M/s32 m_0x338/0x4/0x338/
        /M/bool m_0x33c/0x1/0x33c/
        /M/s32 m_0x340/0x4/0x340/
        /M/s32 m_default_option/0x4/0x344/  // 1: Yes, 2: No
        /M/Sound::SndSeEvent::EEvent m_on_menu_enter_sound/0x1/0x348/
        /M/bool m_show_home_disabled_icon/0x1/0x349/
        /M/SystemDialogOwner m_dialog_owner/0x4/0x34c/
        /M/bool m_check_network_errors/0x1/0x350/
        /M/NetworkErrorChecker m_network_error_checker/0x24/0x354/
        /M/SystemDialogType m_type/0x4/0x378/
        /M/s32 m_time_before_fadein/0x4/0x380/
        /M/SystemDialogState m_system_dialog_state/0x140/0x384/
        /M/SystemDialogState m_system_dialog_state_2/0x140/0x4c4/
        /M/bool m_is_system_window_decided/0x1/0x604/
        /M/sead::Vector2f m_0x608/0x8/0x608/
        // Here goes the controls associated exclusively to UI::Control::EDrawScreen's DRAW_SCREEN_4
        /M/sead::PtrArray<UI::Control> m_0x610/0xC/0x610/
        // List of controls set up in `Sequence::Common_SystemDialog::setupSystemDialog_`
        /M/sead::PtrArray<UI::BaseMenuViewControl> m_controls/0xC/0x66c/
    /END/

    void CloseDialog();
    void CloseWatchDialogRequest();
    void SetDialogDefaultButton(Common_SystemDialog::SystemDialogResult);
    void SetDialogOKSound_YesButton(Sound::SndSeEvent::EEvent);
    void SetDialogOKSound_NoButton(Sound::SndSeEvent::EEvent);
    void OpenWatchDialog();
    void OpenDialog(EDialogType, s32, const UI::DashMessageArg *);
    bool IsCloseDialog();
    bool IsDialogNo();
    bool IsDialogYes();
    bool IsOpenDialog();
    void FadeOverDialog();
    void FadeUnderDialog();
}
