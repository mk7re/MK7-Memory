#pragma once

#include "AIControlBase.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AIControlBattle/SIZE@0xB8/BASE@AIControlBase/BSIZE@0x50/
    public:
        /M/s32 *m_search_weights/0x4/0x60/ // weights, out of 100, of the random choice of AIControlBase::m_search_mode
        /M/s32 m_battle_type/0x4/0x90/ // coin battle: 1 or 2, given to each CPU of a team; 0 by default
        // Keep AIPathHandler::m_do_not_select_backward when locking on to a target, instead of clearing it
        /M/bool m_do_not_select_backward/0x1/0x95/
	/END/
}