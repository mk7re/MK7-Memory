#pragma once

#include "common.hpp"
#include "../types.hpp"
#include "../forward.hpp"

#include "EGrandPrixRecord.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    // More info: https://mk3ds.com/index.php?title=Save_File#GrandPrixData
    /START_STRUCT/NAME@GrandPrixData/SIZE@0x50D4/
        // Name is made up
        enum TrophyType : u8
        {
            TROPHY_NONE   = 0x0,
            TROPHY_BRONZE = 0x1,
            TROPHY_SILVER = 0x2,
            TROPHY_GOLD   = 0x3
        };

        bool set(const GrandPrixData &);
        void init();

        inline u8 getTrophyType(u32 cup, u32 engine_class) const {
            return (m_data[cup][engine_class] >> 5) & 0x7;
        }

        inline void setTrophyType(u32 cup, u32 engine_class, TrophyType trophy) {
            m_data[cup][engine_class] = (m_data[cup][engine_class] & 0x1F) | ((static_cast<u8>(trophy) & 0x7) << 5);
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

        /M/u8 m_data[NUM_CUPS][NUM_ENGINE_CLASSES]/0x20/0x0/
    /END/
}