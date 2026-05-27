#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include "BaseRacePage.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@RacePage/SIZE@0x3320/BASE@BaseRacePage/BSIZE@0x31FC/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
        virtual ~RacePage();
        virtual void initControl();

        RacePage();
        void genRaceBTCoin();
        void genPauseTA();
        void resEnterTA();
        void genResultBT();
        void genResultTA();
        void resPointFix();
        void resSortTeam();
        void genNextDebug();
        void genPauseRpGP();
        void genPauseRpTA();
        bool resBarInTeam(s32);
        void genResultTeam();
        void genResultWiFi();
        void genResultCommu();
        void initResultName();
        void getResultBarPos(s32);
        void setDrawPriority(s32, UI::BaseResultBar *);
        void genNextCommunity();
        void genRaceBTBalloon();
        void initControl_WiFiVS();
        void initControl_MultiGP();
        void initControl_MultiVS();
        void initControl_SingleGP();
        void initControl_WiFiBattle();
        void initControl_MultiBattle();
        void initControl_SingleBattle();
        void initControl_SingleTimeAttack();
        void genNext();
        void resSort();
        void genPause();
        bool resBarIn(s32);
        void resEnter();
        u32 resPoint(s32);
        void genNextGP();
        void genNextTA();
        void genRaceGP();
        void genResult();
        bool resBarOut(s32);
        void resInitTA();

        /M/UI::ResultBgTA *m_result_bg_TA/0x4/0x31fc/
        /M/UI::ResultBattlePoint *m_result_battle_point/0x4/0x3200/
        /M/sead::FixedPtrArray<UI::ResultBar, KART_MAX> m_result_bar_array/0x2C/0x3204/
        /M/sead::FixedPtrArray<UI::ResultBarTeam, KART_MAX> m_result_bar_team_array/0x2C/0x3230/
        /M/sead::Vector3f m_result_bar_pos[KART_MAX]/0x60/0x325c/
    /END/
}