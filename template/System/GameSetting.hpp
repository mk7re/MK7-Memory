#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ELanguageType.hpp"

#include <nn/cfg/CTR/cfg.h>
#include <nn/friends/CTR/friends.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GameSetting/SIZE@0x1050/
    public:
        /START_STRUCT/NAME@Location/SIZE@0x8/
            /U/u8/0x1/0x2/
            /M/nn::cfg::CTR::CfgCountryCode m_country/0x1/0x3/
            /M/s16 m_latitude/0x2/0x4/
            /M/s16 m_longitude/0x2/0x6/
        /END/

        GameSetting();
        void init();
        Location &getDefaultAddress();
        void getSimpleAddress(PlayerData *, bool) const;

        /U/void */0x4/0x0/
        /M/ELanguageType m_language_type/0x1/0x4/
        /M/nn::cfg::CTR::CfgRegionCode m_region_code/0x1/0x5/
        /M/nn::cfg::CTR::SimpleAddress m_simple_address/0x1008/0x8/
        /M/u16 m_country_id/0x2/0x1010/
        /M/nn::cfg::CTR::UserName m_user_name/0x1c/0x1014/
        /M/u64 m_transferable_id/0x8/0x1030/
        /M/bool m_is_from_friend_list/0x1/0x1038/
        /M/nnfriendsFriendKey m_friend_key/0x10/0x1040/

        inline u8 getRegionId() {
            return static_cast<u8>(m_simple_address.id >> 0x10);
        }

        // 0x0057f1e0 (VERSION_EUR_DLP)
        // 0x005ed1d8 (VERSION_USA_REV1)
        static Location Locations[static_cast<u32>(nn::cfg::CTR::CfgRegionCode::CFG_REGION_MAX)];
    /END/
}