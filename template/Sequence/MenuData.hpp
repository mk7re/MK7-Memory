#pragma once

#include "../types.hpp"
#include "Common_SystemDialog.hpp"
#include "FaderPage.hpp"
#include "../RaceSys/RaceInfo/CRaceInfo.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../Utility/Random.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuData/SIZE@0x978/
    public:
        // NOTE: guessed name
        /START_STRUCT/NAME@CourseVote/SIZE@0x8/
            /M/s32 station_id/0x4/0x0/
            /M/RaceSys::ECourseID course_id/0x4/0x4/
        /END/

        /M/Utility::Random m_random/0x18/0x0/
        /M/FaderPage *m_fader_page/0x4/0x18/
        /M/Common_SystemDialog *m_common_system_dialog/0x4/0x1c/
        /M/TimerPage *m_timer_page/0x4/0x20/
        /M/MenuSingle_Ghost *m_menu_single_ghost/0x4/0x2c/
        /M/BaseRacePage *m_base_race_page/0x4/0x30/
        /M/RaceSys::CRaceInfo m_race_info/0x190/0x74/
        /M/sead::PtrArray<CourseVote> m_course_votes/0xc/0x72c/
    /END/

    Utility::Random *GetRandom();
}