#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include "OpponentList.hpp"
#include "PlayerFlagSaveData.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EEngineLevel.hpp"
#include "../RaceSys/EGrandPrixID.hpp"
#include "../RaceSys/GrandPrixData.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@SystemSaveData/SIZE@0x50D4/
    public:
        // NOTE: Name is made up
        /START_CLASS/NAME@Data/SIZE@0x50D0/
        public:
            /M/OpponentList m_opponent_list/0x41A0/0x730/
            /M/PlayerFlagSaveData m_player_flag_save_data/0x800/0x48D0/
        /END/

        void getPlayerData(PlayerData *);
        bool getGhostUpdate(RaceSys::ECourseID);
        void initCecComment();
        void setGhostUpdate(RaceSys::ECourseID, bool);
        void setGrandPrixData(const RaceSys::GrandPrixData &, RaceSys::EGrandPrixID, RaceSys::EEngineLevel, bool);
        void getLastMenuSetting(RaceSys::EDriverID *, RaceSys::EBodyID *, RaceSys::ETireID *, RaceSys::EWingID *);
        RaceSys::EGrandPrixRecord getMinimumGPRecord();
        bool isAbleToUploadPlayerLog();
        void updatePlayerLogUploadDate();
        bool set(const void *);
        void init();
        void getGrandPrixData(RaceSys::GrandPrixData *, RaceSys::EGrandPrixID, RaceSys::EEngineLevel, bool) const;
        bool goldHandleIsAvailable() const;

        /M/Data m_data/0x50d0/0x0/
        /M/u32 m_crc32/0x4/0x50d0/     // CRC-32 of `m_data`
    /END/
}