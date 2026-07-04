#pragma once

#include "../common.hpp"
#include "../types.hpp"
#include "../RaceSys/ECourseID.hpp"

#include <prim/seadSafeString.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@SequenceIDTable/SIZE@0x270/
    public:
        /START_STRUCT/NAME@CupInfo/SIZE@0x8/
            CupInfo();

            /M/s32 m_cup_id/0x4/0x0/
            /M/s32 m_cup_course_number/0x4/0x4/
        /END/

        void initialize();

        /M/CupInfo m_cup_info_list[NUM_RACE_COURSES + 10]/0x150/0x0/    // One entry per `ECourseID`, up to 0x2A
        /M/bool m_is_cec_gp/0x1/0x150/      // i.e. is StreetPass GP
        /M/sead::WSafeString m_cec_gp_name/0x8/0x154/
        /M/RaceSys::ECourseID m_cec_gp_courses[NUM_COURSES_PER_CUP]/0x10/0x260/
    /END/

    extern RaceSys::ECourseID RaceCourseIds[NUM_CUPS][NUM_COURSES_PER_CUP];     // 0x00611ca0 (VERSION_EUR_DLP)
    extern RaceSys::ECourseID BattleCourseIds[NUM_BATTLE_COURSES];              // 0x00611d20 (VERSION_EUR_DLP)

    bool IsCecGP();
    const sead::WSafeString &GetCecGPName();
    RaceSys::ECourseID GetCecGPCourse(s32);
    s32 GetCupCourseNo(RaceSys::ECourseID);
    s32 GetCup(RaceSys::ECourseID);
    void SetCecGPName(const sead::WSafeString &);
    void SetCecGPCourse(RaceSys::ECourseID, RaceSys::ECourseID, RaceSys::ECourseID, RaceSys::ECourseID);
    void SetCecGP(bool);
}