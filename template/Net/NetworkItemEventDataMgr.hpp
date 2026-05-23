#pragma once

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

        /START_STRUCT/NAME@SlotData/SIZE@0x9/
            /M/Item::eItemType item_type/0x1/0x4/
            /M/EEventType event_type/0x1/0x5/
            /M/u8 player_id/0x1/0x8/
        /END/
    /END/
}