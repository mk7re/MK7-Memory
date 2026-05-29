#pragma once

#include "../common.hpp"
#include "../types.hpp"
#include "../RaceSys/RankingOneData.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../versions.h"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@TimeAttackChart/SIZE@0x4CC/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~TimeAttackChart();
        virtual void onPagePreStep();
        virtual bool canFinishFadein();
        virtual bool canFinishFadeout();
        virtual void initControl();

        TimeAttackChart();
        void selectGhost(s32*);
        void setCourseName(RaceSys::ECourseID);
        void onPageFromGhost();
        void onPageCourseEnter();
        void changeOut();
        void onPageToGhost();
        void protGhost();
        void changeIn(RaceSys::ECourseID);
        void onPageOut();
#if GAME_VERSION != ALL_DLP
        void FUN_00495bc4();        // 0x00495bc4 (VERSION_USA_REV1)
        void FUN_00496018();        // 0x00496018 (VERSION_USA_REV1)
#endif

        /M/UI::ChartMeter *m_chart_meter/0x4/0x26C/
        /M/sead::FixedPtrArray<UI::ChartDot, 40> m_chart_dots/0xac/0x270/
        /M/UI::ChartGhost *m_chart_ghost_mii/0x4/0x31c/
        /M/UI::ChartGhostSelect *m_chart_ghost_select_mii/0x4/0x320/
        /M/sead::FixedPtrArray<UI::ChartGhost, GHOST_LIST_MAX> m_chart_ghosts/0x68/0x324/
        /M/sead::FixedPtrArray<UI::ChartGhostSelect, KART_MAX - 1> m_chart_ghosts_select/0x28/0x38c/
        /M/UI::MenuCourseName *m_menu_course_name/0x4/0x3b4/
        /U/bool/0x1/0x3b8/
        /M/RaceSys::RankingOneData m_ranking_datas[NUM_SCROLL_LIST_VISIBLE_ENTRIES]/0xb4/0x3bc/
        /M/RaceSys::ECourseID m_course/0x4/0x494/
        /M/s32 m_selected_ghosts[KART_MAX - 1]/0x1c/0x498/
        /M/s32 m_num_chart_dots/0x4/0x4b4/
        /M/s32 m_num_ghosts/0x4/0x4b8/
        /M/bool m_chart_ghost_select_already_anim_out/0x1/0x4bd/
    /END/
}