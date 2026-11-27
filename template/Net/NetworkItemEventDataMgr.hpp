#pragma once

#include "../types.hpp"

#include "../Item/eItemType.hpp"

#include "NetworkDataManager.hpp"
#include "NetworkEventModule.hpp"
#include "NetworkItemEventDataFormatDummy.hpp"

#include <math/seadVector.hpp>
#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkItemEventDataMgr/SIZE@0x118/BASE@NetworkDataManager<NetworkItemEventDataFormatDummy>/BSIZE@0x50/
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
            /M/u8 serial/0x1/
            /M/bool is_dropped/0x1/
            /M/bool is_deflected/0x1/
            /M/f32 cpad_y/0x4/
            /M/sead::Vector3f position/0xC/
            /M/sead::Vector3f velocity/0xC/
            /M/f32 gravity/0x4/
        /END/

        // Below is the most likely pattern for SlotData,
        // with an array of indeterminate size. The game
        // reinterpret_casts the data member to one of
        // the structs above.
        /START_STRUCT/NAME@SlotData/SIZE@0x8/
            /M/u32 frame/0x4/0x0/
            /M/Item::eItemType item_type/0x1/0x4/
            /M/EEventType event_type/0x1/0x5/
            /U/u8/0x1/0x6/ // player ID? unused?
            /M/u8 data_size/0x1/0x7/
            /M/u8 data[]/0x0/0x8/
        /END/

        /M/NetworkEventModule m_network_event_module/0xB4/0x50/
        /M/sead::Delegate2R<NetworkItemEventDataMgr, NetworkEventModule::EventHandleArg const &, u8 const *, bool> m_event_handler_delegate/0x10/0x104/
        /U/void */0x4/0x114/ // itemEventRecvHandler delegate ptr?
    /END/
}