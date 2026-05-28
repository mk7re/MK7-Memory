#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "FaderPage.hpp"
#include "ECup.hpp"
#include "../RaceSys/EGrandPrixRecord.hpp"
#include "../RaceSys/RaceInfo/CRaceInfo.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../Utility/Random.hpp"

#include <container/seadPtrArray.h>
#include <heap/seadExpHeap.h>
#include <prim/seadSafeString.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuData/SIZE@0x978/
    public:
        enum EndingType {
            ENDING_NORMAL,
            ENDING_TRUE
        };

        // NOTE: guessed name
        /START_STRUCT/NAME@CourseVote/SIZE@0x8/
            /M/s32 station_id/0x4/0x0/
            /M/RaceSys::ECourseID course_id/0x4/0x4/
        /END/

        /START_STRUCT/NAME@FriendApproach/SIZE@0x10/
            FriendApproach();

            /U/s32/0x4/0x0/
            /M/u64 m_friend_code/0x8/0x8/
        /END/

        sead::ExpHeap *getFlagHeap();
        void createFlagHeap();
        void clearData();

        /M/Utility::Random m_random/0x18/0x0/
        /M/FaderPage *m_fader_page/0x4/0x18/
        /M/Common_SystemDialog *m_common_system_dialog/0x4/0x1c/
        /M/TimerPage *m_timer_page/0x4/0x20/
        /M/Menu_UpBarController *m_menu_up_bar_controller/0x4/0x24/
        /M/TimeAttackChart *m_time_attack_chart/0x4/0x28/
        /M/MenuSingle_Ghost *m_menu_single_ghost/0x4/0x2c/
        /M/BaseRacePage *m_base_race_page/0x4/0x30/
        /M/MenuWifi_Confirm *m_menuwifi_confirm/0x4/0x34/
        /M/MenuSingle_Chara *m_menuwifi_chara/0x4/0x38/
        /M/s32 m_flag_heap_idx/0x4/0x3c/
        /M/sead::ExpHeap *m_flag_heaps[8]/0x20/0x40/
        /M/u8 m_boot_task_enter_code/0x1/0x61/
        /U/u8/0x1/0x62/
        /M/Fader::EFaderType m_fader_type_top_screen/0x1/0x63/
        /M/Fader::EFaderType m_fader_type_bottom_screen/0x1/0x64/
        /M/s32 m_fade_frames_top_screen/0x4/0x68/
        /M/s32 m_fade_frames_bottom_screen/0x4/0x6c/
        /M/u8 m_current_title_demo_mode/0x1/0x70/
        /M/bool m_request_save/0x1/0x71/
        /M/u8 m_ending_type/0x1/0x72/                        // See the `EndingType` enum
        /M/RaceSys::CRaceInfo m_race_info/0x190/0x74/
        /M/RaceSys::CRaceInfo m_demo_race_info/0x190/0x204/  // Used by Demo and WinningRun
        /M/RaceSys::CRaceInfo::CKartInfo m_kart_info/0x2c/0x394/
        // The name of each player as shown in the race rank board and results screen
        // TODO: Total size should be 0x4C * 8 = 0x160, but for some reason the size calculated is incorrect, leading to a size static assert
        // /M/sead::WFixedSafeString<32> m_player_names/0x160/0x3c0/
        /M/ECup m_race_cup/0x1/0x620/
        /M/bool m_is_ch_gp/0x1/0x621/       // Is GP started from Mario Kart Channel (i.e. StreetPass Mii GP)
        /M/RaceSys::EGrandPrixRecord m_gp_record/0x4/0x624/
        /M/s32 m_gp_hidden_score_per_course[NUM_COURSES_PER_CUP]/0x10/0x628/
        /M/bool m_played_using_wheel[KART_MAX]/0x8/0x638/
        /M/bool m_gold_wheel_unlocked[KART_MAX]/0x8/0x640/
        /M/RaceSys::EGrandPrixRecord m_gp_record_per_player[KART_MAX]/0x20/0x648/
        /M/u8 m_ai_level/0x1/0x668/
        /M/u8 m_selected_option/0x1/0x669/
        /M/s32 m_num_races/0x4/0x66c/   // Total number of races
        /M/s32 m_race_no/0x4/0x670/     // Current race number
        /M/RaceSys::ECourseID m_course_id[NUM_COURSES]/0xA0/0x674/
        /M/RaceSys::ECourseID unk_0x718[NUM_COURSES_PER_CUP]/0x10/0x718/
        /M/sead::PtrArray<CourseVote> m_course_votes/0xc/0x72c/
        /M/Net::NetworkSelectMenuProcess *m_network_select_menu_process/0x4/0x7a0/
        /M/sead::WSafeString m_mii_name/0x8/0x7bc/
        /M/FriendApproach m_friend_approach[KART_MAX]/0x80/0x7e0/
        /M/RaceSys::CRaceInfo::CKartInfo m_cpu_kart_infos[KART_MAX - 2]/0x108/0x860/
        // Set to `true` if CPUs are enabled in the VS / Battle settings
        /M/bool m_is_cpu_enabled/0x1/0x968/
        /M/u32 m_num_free_player_slots/0x4/0x96c/
    /END/

    Utility::Random *GetRandom();
}