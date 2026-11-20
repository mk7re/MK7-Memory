#pragma once

#include "../types.hpp"

#include "GrandPrixCupData.hpp"

#include "../RaceSys/EGrandPrixID.hpp"
#include "../RaceSys/EGrandPrixTrophy.hpp"

BEGIN_NAMESPACE(System)
{
    // More info: https://mk3ds.com/index.php?title=Save_File#GrandPrixData
    /START_CLASS/NAME@GrandPrixData/SIZE@0x20/
    public:
        bool set(const GrandPrixData &);
        void init();

        /*
        inline u8 getTrophyType(u32 cup, u32 engine_class) const {
            return (m_data[cup][engine_class] >> 5) & 0x7;
        }

        inline void setTrophyType(u32 cup, u32 engine_class, RaceSys::EGrandPrixTrophy trophy) {
            m_data[cup][engine_class] = (m_data[cup][engine_class] & 0x1F) | ((std::to_underlying(trophy) & 0x7) << 5);
        }

        inline u32 getRank(u32 cup, u32 engine_class) const {
            return (m_data[cup][engine_class] >> 1) & 0xF;
        }

        inline void setRank(u32 cup, u32 engine_class, u32 rank) {
            m_data[cup][engine_class] = (m_data[cup][engine_class] & 0xE1) | ((static_cast<u8>(rank) & 0xF) << 1);
        }

        inline bool isCompleted(u32 cup, u32 engine_class) const {
            return m_data[cup][engine_class] & 0x1;
        }

        inline void setCompleted(u32 cup, u32 engine_class, bool completed) {
            if (completed)
                m_data[cup][engine_class] |= 0x1;
            else
                m_data[cup][engine_class] &= ~0x1;
        }

        //u8 m_data[NUM_CUPS][NUM_ENGINE_CLASSES]/0x20/0x0/
        */

        /M/GrandPrixCupData m_grand_prix_cup_data[std::to_underlying(RaceSys::EGrandPrixID::MAX)]/0x20/0x0/
    /END/
}