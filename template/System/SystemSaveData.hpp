#pragma once

#include "../types.hpp"

#include "OpponentList.hpp"
#include "PlayerFlagSaveData.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@SystemSaveData/SIZE@0x50D0/
    public:
        bool goldHandleIsAvailable() const;

        /M/OpponentList m_opponent_list/0x41A0/0x730/
        /M/PlayerFlagSaveData m_player_flag_save_data/0x800/0x48D0/
    /END/
}