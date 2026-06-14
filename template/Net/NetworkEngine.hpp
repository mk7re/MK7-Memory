#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../RaceSys/EShyGuyColor.hpp"

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkEngine/SIZE@0x598/
    public:
        RaceSys::EShyGuyColor getShyGuyColor(s32);

        /M/NetworkStationBufferManager* m_network_station_buffer_manager/0x4/0x25C/
        /M/s32 m_local_station_id/0x4/0x264/
        /M/s32 m_local_player_id/0x4/0x268/
        /M/s32 m_master_station_id/0x4/0x26C/
        /M/s32 m_master_player_id/0x4/0x270/
        /M/NetworkErrorHandler *m_network_error_handler/0x4/0x290/
        /M/NetworkPlayerDataManager *m_network_player_data_manager/0x4/0x2B8/
    /END/
}