#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../versions.h"

#include "BaseMenuViewControl.hpp"

BEGIN_NAMESPACE(UI)
{
#if GAME_VERSION != ALL_DLP
    // NOTE: The name is made up
    /START_CLASS/NAME@ScrollListBarBase/SIZE@0xB0/BASE@BaseMenuViewControl/BSIZE@0xA8/VTABLE@True/
    public:
        /START_STRUCT/NAME@MiiInfoListEntry/SIZE@0x10/
            /M/Mii::Face *m_face/0x4/0x0/
            /M/Mii::Icon *m_icon/0x4/0x4/
            /M/s32 m_idx/0x4/0x8/
            /M/u8 m_mii_storage_array_pos/0x1/0xc/      // Index in the array `MiiManager->faceManager->faceArray`
            /M/u8 m_player_id/0x1/0xd/
        /END/

        /START_STRUCT/NAME@MiiInfoList/SIZE@0x54/
            /M/MiiInfoListEntry m_entries[5]/0x50/0x0/  // One per visible entry in the scroll list
            /M/s32 m_current_entry_idx/0x4/0x50/
        /END/

        virtual void onScrollUpdate(s32);

        /M/ScrollListFrame *m_frame/0x4/0xa8/
        /M/s32 m_option = -1/0x4/0xac/
    /END/
#endif
}