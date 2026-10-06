#pragma once

#include <container/seadPtrArray.h>

#include "../forward.hpp"
#include "../types.hpp"
#include "../System/RootSystem.hpp"
#include "../Field/ObjectDirector.hpp"

BEGIN_NAMESPACE(Object)
{
    /START_CLASS/NAME@CoinManager/SIZE@0x6D04/
    public:
        /M/sead::PtrArray<Coin> m_coins/0xC/0x48E8/ // the coins of the course
    /END/

    inline static CoinManager *GetCoinManager()
    {
        return System::g_root_system->get_object_director()->m_coin_manager;
    }
}
