#pragma once

#include "../types.hpp"

#include "PlayerDataNoMii.hpp"

#include <3ds/services/act.h>
#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@PlayerData/SIZE@0xA0/BASE@PlayerDataNoMii/BSIZE@0x3C/
    public:
        PlayerData();
        sead::BufferedSafeString getName() const;

        /M/CFLStoreData m_store_data/0x60/0x3C/
        /M/bool m_loaded/0x1/0x9C/
    /END/
}