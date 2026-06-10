#pragma once

#include <math/seadVector.hpp>

#include "../Item/eItemType.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkItemEventDataMgr/SIZE@0x1/
    public:
        enum class EEventType : u8
        {
            InitBurst,
            SevenFrame,
            SelfMove,
            SevenInitUse,
            UpdateKartItem_DestroyOther,
            UpdateKartItem_DestroySelf,
            InitSpin,
            Action,
            Seven,
            InitUse,
            UseExpire,
            MAX
        };

        /START_STRUCT/NAME@SSelfMove/SIZE@0x24/
            /M/u8 player_id/0x1/
            /M/u8 sequence_id/0x1/
            /M/bool is_dropped/0x1/
            /M/bool is_deflected/0x1/
            /M/float cpad_y/0x4/
            /M/sead::Vector3f position/0xC/
            /M/sead::Vector3f velocity/0xC/
            /M/float gravity/0x4/
        /END/

        // Below is the most likely pattern for SlotData,
        // with an array of indeterminate size. The game
        // reinterpret_casts the data member to one of
        // the structs avobe.

        struct SlotData {
            u32 frame_count;                // (O:0x4,S:0x4)
            Item::eItemType item_type;      // (O:0x4,S:0x1)
            EEventType event_type;          // (O:0x5,S:0x1)
            u8 unk_0x6;                     // (O:0x6,S:0x1) maybe player ID?
            u8 data_size;                   // (O:0x7,S:0x1)
            u8 data[];                      // (O:0x8,S:Variable)
        };
    /END/
}