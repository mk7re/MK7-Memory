#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

#include "Page.hpp"
#include "ECup.hpp"
#include "../RaceSys/CRaceMode.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EScrewID.hpp"
#include "../RaceSys/EEngineLevel.hpp"
#include "../RaceSys/EItemPattern.hpp"
#include "../RaceSys/EPlayerType.hpp"
#include "../RaceSys/ETeamType.hpp"
#include "../RaceSys/Rate.hpp"
#include "../UI/BaseFastControl.hpp"
#include "../UI/ControlInitializer.hpp"
#include "../UI/CursorItem.hpp"
#include "../UI/KeyItem.hpp"
#include "../UI/Manipulator.hpp"

#include <prim/seadSafeString.hpp>
#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@BasePage/SIZE@0x26C/BASE@Page/BSIZE@0x5C/VTABLE@True/
    public:
        enum class EnterCode : s32
        {
            NEXT,
            BACK
        };

        enum class ReturnCode : s32
        {
            NEXT_00,
            NEXT_01,
            NEXT_02,
            NEXT_03,
            NEXT_04,
            NEXT_05,
            NEXT_06,
            NEXT_07,
            BACK
        };

        enum class Mode : s32
        {
            DEFAULT
        };

        // TODO
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~BasePage();
        virtual void step();
        virtual void enter(Section::EFadeKind, u32);
        virtual void start();
        virtual void complete();
        virtual void cancel(Section::EFadeKind, u32);
        virtual void exit();
        virtual void pageStep(bool);
        virtual void onGenerateControl(UI::ControlInitializer *);
        virtual bool canFinishFadein();
        virtual bool canFinishFadeout();
        virtual void initControl();
        virtual void calcItemIcon();
        virtual void onPageFadein();
        virtual void onPageFadeout();
        virtual void enterCursor(s32);
        virtual void buttonHandler_SelectOn(s32);
        virtual void buttonHandler_OK(s32);
        virtual void inputHandler(s32, s32);
        virtual void procOpenMenu();
        virtual void procCloseMenu();
        virtual void procExitMenu();
        virtual void onMenuEnter();
        virtual void onMenuStart();
        virtual void onMenuComplete();
        virtual void onMenuExit();

        BasePage();
        void setKeyItem(UI::KeyItem *);
        void setCursorItem(UI::CursorItem *);
        void setTouchItem(UI::TouchItem *);
        void enterPost();
        void clearEnemy(s32);
        void initRaceNo();
        void loadCourse();
        void setCourseID(ECup, s32);
        void setDemoMode();
        void setRaceMode(RaceSys::CRaceMode);
        void setRaceRank(s32, u16);
        void setTeamMode(bool);
        void setTeamType(s32, RaceSys::ETeamType);
        void setWiFiRate(s32, const RaceSys::Rate &);
        void completeNext(s32);
        void copyRaceInfo();
        void setRacePoint(s32, u16);
        void setTotalRank(s32, u16);
        void clearRaceInfo();
        void completeScene(s32);
        void setPlayerType(s32, RaceSys::EPlayerType);
        void setReplayMode(bool);
        void clearAllPlayer();
        void clearRacePoint();
        void loadNextCourse(bool);
        void saveRandomSeed(RaceSys::RaceDirector *);
        void setItemPattern(RaceSys::EItemPattern);
        void setRawCourseID(RaceSys::ECourseID);
        void updateRaceInfo();
        void restoreRaceInfo();
        void updateMenuState();
        void setUniqTotalRank(s32, u16);
        void calcNormalControl();
        void setMasterPlayerID(s32);
        u32 getFixedRandomSeed();
        void setFixedRandomSeed(u32);
        void setHalfFixedRandomSeed(u32);
        void setCameraTargetPlayerID(s32);
        void setCC(RaceSys::EEngineLevel);
        void setCup(ECup);
        void setBody(s32, RaceSys::EBodyID);
        void setTire(s32, RaceSys::ETireID);
        void setWing(s32, RaceSys::EWingID);
        void enterPre(Section::EFadeKind, u32);
        void initMenu(s32);
        void openMenu(u32);
        void setParts(s32, RaceSys::EBodyID, RaceSys::ETireID, RaceSys::EWingID, RaceSys::EScrewID);
        void setScrew(s32, RaceSys::EScrewID);
        void closeMenu();
        void setDriver(s32, RaceSys::EDriverID, RaceSys::EPlayerType);
        void setMirror(bool);
        void setRaceNo(s32);
#if GAME_VERSION != ALL_DLP
        void FUN_004d337c();    // 0x004d337c (VERSION_USA_REV1)
#endif

        static void convertEnterCodeImpl(const sead::SafeString &);
        static void convertReturnCodeImpl(s32);
        static void convertModeImpl(const sead::SafeString &);

        enum BasePageState {
            STATE_CLOSED,   // Menu is already closed
            STATE_OPEN,
            STATE_ENTER,    // Calls onMenuEnter()
            STATE_START,    // Or `STATE_CALC`. Calls onMenuStart()
            STATE_EXIT,     // Calls onMenuExit()
            STATE_COMPLETE  // Calls onMenuComplete()
        }; 

        template <typename T>
        T* setupControl(const sead::SafeString &, const sead::SafeString &);

        template <typename T>
        T* setupBothControl(const sead::SafeString &, const sead::SafeString &);

        template <typename T>
        T* setupMenuControl(const sead::SafeString &, const sead::SafeString &, u32);

        /M/s32 m_on_back_return_code/0x4/0x5C/
        /M/u32 m_timer/0x4/0x60/
        /M/UI::Manipulator *m_manipulator/0x4/0x64/
        /M/bool m_set_item_to_all_manipulators/0x1/0x68/ // See `Sequence::BasePage::setCursorItem`
        /M/UI::ControlInitializer *m_control_initializer/0x4/0x6C/
        /M/u32 m_0x70/0x4/0x70/
        /M/u32 m_0x74/0x4/0x74/
        /M/s32 m_0x78/0x4/0x78/
        /M/s32 m_0x7C/0x4/0x7C/
        /M/bool m_allow_attaching_manipulators/0x1/0x80/
        /M/u32 m_num_manipulators/0x4/0x84/
        /M/UI::Manipulator **m_manipulators/0x4/0x88/
        /M/bool m_has_manipulators/0x1/0x8C/
        /M/bool m_0x8D/0x1/0x8D/
        /M/u8 m_0x8E/0x1/0x8E/
        /M/u8 m_menu_state/0x1/0x8F/    // See the `BasePageState` enum
        /M/s32 m_0x90/0x4/0x90/
        /M/s32 m_0x94/0x4/0x94/
        /M/s32 m_0x98/0x4/0x98/
        /M/s32 m_0x9C/0x4/0x9C/
        /M/s32 m_0xA0/0x4/0xA0/
        /M/s32 m_0xA4/0x4/0xA4/
        /M/s32 m_0xA8/0x4/0xA8/
        // Controls created in the `Sequence::BasePage::setupControl_*` functions are appended to this array
        /M/sead::FixedPtrArray<UI::BaseFastControl, 100> m_controls/0x19C/0xAC/
        // Controls that are common to most menus, such as the B button and others.
        // These controls are updated when `m_menu_state` == STATE_OPEN or STATE_CLOSED (`see pageStep`)
        // Controls created in the `Sequence::BasePage::setupMenuControl_*` functions are appended to this array
        /M/s32 m_num_menu_controls/0x4/0x248/
        /M/sead::FixedPtrArray<UI::BaseFastControl, 15> *m_menu_controls/0x4/0x24C/
        // Controls created in the `Sequence::BasePage::setupBothControl_*` functions are appended to this array
        // These controls are always updated, no matter the current `m_menu_state` we're currently in.
        /M/sead::FixedPtrArray<UI::BaseFastControl, 3> m_both_controls/0x18/0x250/
        /M/u8 m_0x268/0x1/0x268/
        /M/bool m_in_MMenCheckPage/0x1/0x269/
    /END/
}