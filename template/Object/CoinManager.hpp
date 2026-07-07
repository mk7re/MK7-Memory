#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../Field/ObjectDirector.hpp"

BEGIN_NAMESPACE(Object)
{
    /START_CLASS/NAME@CoinManager/SIZE@0x6D04/
    public:
    /END/

    inline static CoinManager *GetCoinManager()
    {
        return System::g_root_system->get_object_director()->m_coin_manager;
    }
}