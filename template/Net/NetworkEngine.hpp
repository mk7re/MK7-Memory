#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../RaceSys/EShyGuyColor.hpp"

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkEngine/SIZE@0x598/
    public:
        RaceSys::EShyGuyColor getShyGuyColor(s32);

        /M/NetworkStationBufferManager *m_network_station_buffer_manager/0x4/0x25C/
        /M/s32 m_local_station_id/0x4/0x264/
        /M/s32 m_local_player_id/0x4/0x268/
        /M/s32 m_master_station_id/0x4/0x26C/
        /M/s32 m_master_player_id/0x4/0x270/
        /M/NetworkErrorHandler *m_network_error_handler/0x4/0x290/
        /U/bool/0x1/0x294/
        /M/NetworkSystemInfoManager *m_network_system_info_manager/0x4/0x298/
        /M/NetworkGameMgr *m_network_game_mgr/0x4/0x29C/
        /M/NetworkGameEventMgr *m_network_game_event_mgr/0x4/0x2A0/
        /M/NetworkItemEventMgr *m_network_item_event_mgr/0x4/0x2A4/
        /M/NetworkWbtMgr *m_network_wbt_mgr/0x4/0x2A8/
        /M/NetworkFriendsManager *m_network_friends_manager/0x4/0x2AC/
        /M/NetworkMiiManager *m_network_mii_manager/0x4/0x2B0/
        /M/NetworkSupplyInfoManager *m_network_supply_info_manager/0x4/0x2B4/
        /M/NetworkPlayerDataManager *m_network_player_data_manager/0x4/0x2B8/
        /M/NetworkGhostUploadManager *m_network_ghost_upload_manager/0x4/0x2BC/
        /M/EventLogger *m_event_logger/0x4/0x2C0/
    /END/
}