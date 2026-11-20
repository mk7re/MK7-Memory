#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "GrandPrixData.hpp"
#include "OpponentList.hpp"
#include "PlayerFlagSaveData.hpp"

#include "../RaceSys/ECourseID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EEngineLevel.hpp"
#include "../RaceSys/EGrandPrixID.hpp"
#include "../RaceSys/EGrandPrixRecord.hpp"

BEGIN_NAMESPACE(System)
{
    // https://mk3ds.com/index.php?title=Save_File#File_Format
    /START_CLASS/NAME@SystemSaveData/SIZE@0x50D4/
    public:
        // NOTE: Name is made up
        /START_CLASS/NAME@Data/SIZE@0x50D0/
        public:
            // /M/RankingSaveData m_ranking_save_data/0x600/0x10C/
            /M/GrandPrixData m_grand_prix_data/0x20/0x70C/
            /M/OpponentList m_opponent_list/0x41A0/0x730/
            /M/PlayerFlagSaveData m_player_flag_save_data/0x800/0x48D0/
        /END/

        void getGrandPrixData(RaceSys::GrandPrixData *grand_prix_data, RaceSys::EGrandPrixID *grand_prix_id, RaceSys::EEngineLevel *engine_level, bool mirror)
        {
            RaceSys::EEngineLevel engine;
            int index;
            GrandPrixOneData data;

            engine = *engine_level;
            index = 0;

            if ( engine != RaceSys::EEngineLevel::_50cc )
            {
                if ( engine == RaceSys::EEngineLevel::_100cc )
                {
                    index = 1;
                }
                else if ( engine == RaceSys::EEngineLevel::_150cc )
                {
                    if ( mirror )
                        index = 3;
                    else
                        index = 2;
                }
            }

            data = m_data.m_grand_prix_data.m_grand_prix_cup_data[std::to_underlying(*grand_prix_id)].m_grand_prix_one_data[index];
            if ( data.completed )
            {
                grand_prix_data->record = static_cast<RaceSys::EGrandPrixRecord>(data.rank);
                grand_prix_data->trophy = static_cast<RaceSys::EGrandPrixTrophy>(data.trophy);
                grand_prix_data->valid = true;
            }
            else
            {
                grand_prix_data->valid = false;
                grand_prix_data->record = RaceSys::EGrandPrixRecord::NO_RECORD;
                grand_prix_data->trophy = RaceSys::EGrandPrixTrophy::None;
            }
        }

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
        bool goldHandleIsAvailable() const;

        /M/Data m_data/0x50d0/0x0/
        /M/u32 m_crc32/0x4/0x50d0/     // CRC-32 of `m_data`
    /END/
}