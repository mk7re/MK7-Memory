#pragma once

#include "../types.hpp"
#include "../versions.h"

BEGIN_NAMESPACE(Sound)
{
    enum class EMenuPage : s32
    {
        MenuTitle = 1,
#if GAME_VERSION == ALL_KIOSK
        TrialManual,
        TrialTitle,
#endif
        MenuSingle_Mode,
        MenuSingle_Class,
        MenuSingle_Chara,
        MenuSingle_Kart,
        MenuSingle_Cup,
        MenuSingle_Course,
        MenuSingle_CourseBattle,
        MenuSingle_Setting,
        MenuSingle_Ghost,
        MenuSingle_GhostLoad,
        MenuMulti_Group,
        MenuMulti_Waiting,
        MenuMulti_DlplaySequence,
        MenuMulti_Mode,
        MenuMulti_Class,
        MenuMulti_Chara,
        MenuMulti_Kart,
        MenuMulti_VSSetting,
        MenuMulti_Cup,
        MenuMulti_Course,
        MenuMulti_CourseBattle,
        MenuMulti_CourseVote,
        MenuMulti_CourseDL,
        MenuWiFi_Connect,
        MenuWiFi_ModeOpponent,
        MenuWiFi_Mode,
        MenuWifi_Chara,
        MenuWiFi_Kart,
        MenuWiFi_Waiting,
        MenuWiFi_WaitingDecide,
        MenuWiFi_Confirm,
        MenuWiFi_Cup,
        MenuWiFi_Course,
        MenuWiFi_CourseBattle,
        MenuWiFi_CourseVote,
        MenuWiFi_Friend,
        MenuWiFi_Community, // Unused?
        MenuCommunity_Top,
        MenuCommunity_Enter,
        MenuCommunity_Lobby,
        PAGE_2A, // Unused?
        MenuCommunity_Search,
        MenuCommunity_SearchConfirm,
        MenuCommunity_CreateMark,
        MenuCommunity_CreateName,
        MenuCommunity_CreateRule,
        MenuCommunity_CreateComment,
        MenuCommunity_CreateFinish,
        MenuCommunity_Chara,
        MenuChannel_Top,
        MenuChannel_ShowMii,
        MenuChannel_CecMii,
        MenuChannel_CecList,
        MenuChannel_SetupTop,
        MenuChannel_SetupMii,
        MenuChannel_SetupComment,
        MenuChannel_SetupMachine,
        MenuChannel_SetupGP,
        MenuChannel_SetupSetting
    };

}