#pragma once

#include "../forward.hpp"
#include "../versions.h"
#include "MenuListSeparator.hpp"
#include "ScrollListBarBase.hpp"
#include "../Sequence/BasePage.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(UI)
{
#if GAME_VERSION != ALL_DLP
    // NOTE: Name is made up
    /START_CLASS/NAME@ScrollList/SIZE@0x74/
    public:
        // NOTE: Name is made up
        enum class EType : u32 {
            GHOST_LIST,
            FRIEND_LIST,
            COMMUNITY_LIST,
            COMMUNITY_CREATE_MARK_LIST,
            STREETPASS_LIST,
            COMMUNITY_LOBBY_MESSAGE_LIST
        };

        s32 getSelectedOption() const;                       // 0x004e18dc (VERSION_USA_REV1)
        void init(EType, s32, Sequence::BasePage *);         // 0x001462fc (VERSION_USA_REV1)
        void initFrame(s32);                                 // 0x00161430 (VERSION_USA_REV1)
        void setSelectedOption(s32);                         // 0x001478d0 (VERSION_USA_REV1)
        void setupControlSlider(Sequence::ControlSlider *);  // 0x001478dc (VERSION_USA_REV1)
        void setupMenuCommunity_CreateMark();                // 0x001460e0 (VERSION_USA_REV1)
        void clearEntries();                                 // 0x00147830 (VERSION_USA_REV1)
        Mii::Icon *getMiiIcon(s32) const;                    // 0x00145894 (VERSION_USA_REV1)
        s32 getMiiStorageArrayPos(s32) const;                // 0x001458ec (VERSION_USA_REV1)
        void setCurrentMiiInfoListEntryIdx(s32);             // 0x001459f8 (VERSION_USA_REV1)
        void FUN_00145df0();                                 // 0x00145df0 (VERSION_USA_REV1)
        void FUN_00145ab8(s32);                              // 0x00145ab8 (VERSION_USA_REV1)
        void setVisibility(bool);                            // 0x001457c0 (VERSION_USA_REV1)
        void FUN_00145a04();                                 // 0x00145a04 (VERSION_USA_REV1)
        void FUN_00145b7c();                                 // 0x00145b7c (VERSION_USA_REV1)
        void FUN_00145e34();                                 // 0x00145e34 (VERSION_USA_REV1)
        void FUN_00145f30();                                 // 0x00145f30 (VERSION_USA_REV1)
        bool FUN_004e18f0() const;                           // 0x004e18f0 (VERSION_USA_REV1)

        /M/ScrollListBg *m_bg/0x4/0x0/
        /M/sead::FixedPtrArray<MenuListSeparator, 6> m_separators/0x24/0x4/
        /M/sead::FixedPtrArray<ScrollListBarBase, 5> m_bars/0x20/0x28/
        /M/ScrollListFrame *m_frame/0x4/0x48/
        /M/s32 m_num_items/0x4/0x58/
    /END/
#endif
}