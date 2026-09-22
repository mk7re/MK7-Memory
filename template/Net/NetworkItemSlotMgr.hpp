#pragma once

#include "../common.hpp"
#include "../types.hpp"

#include "NetworkDataManager.hpp"

#include "../Item/eItemSlot.hpp"
#include "../Item/eItemType.hpp"

#include "../Object/Actor.hpp"

#include <container/seadTList.h>

BEGIN_NAMESPACE(Net)
{
    /START_CLASS/NAME@NetworkItemSlotMgr/SIZE@0x264/BASE@Object::Actor/BSIZE@0x8/
    public:
        enum class EEquipItemState : u32
        {
            
        };

        enum class EStockItemState : u32
        {
            
        };

        /START_CLASS/NAME@Node/SIZE@0x24/
        public:
            Node()
            {
                m_player_bit = {};
            }

            /START_STRUCT/NAME@Takeover/SIZE@0x12/
                /M/u8 m_frame[TAKEOVER_MAX]/0x3/0x0/
                /M/Item::eItemSlot m_stock_item[TAKEOVER_MAX]/0x3/0x3/
                /M/Item::eItemSlot m_equip_item[TAKEOVER_MAX]/0x3/0x6/
                /M/u8 m_stock_item_state[TAKEOVER_MAX]/0x3/0x9/
                /M/u8 m_equip_item_state[TAKEOVER_MAX]/0x3/0xC/
                /M/u8 m_equip_items_used[TAKEOVER_MAX]/0x3/0xF/
            /END/

            /M/u8 m_frame/0x1/0x0/
            /M/Item::eItemSlot m_stock_item/0x1/0x1/
            /M/Item::eItemSlot m_equip_item/0x1/0x2/
            /M/u8 m_stock_item_state/0x1/0x3/
            /M/u8 m_equip_item_state/0x1/0x4/
            /M/u8 m_player_bit/0x1/0x5/
            /M/u8 m_equip_items_used/0x1/0x6/
            /M/u8 m_0x7[KART_MAX]/0x8/0x7/ // takeover frames?
            /M/s8 m_0xF[TAKEOVER_MAX]/0x3/0xF/ // amount or takeover player IDs?
            /M/Takeover m_takeover/0x12/0x12/
        /END/

        /START_STRUCT/NAME@Buffer/SIZE@0x254/BASE@NetworkDataManager<Node>/BSIZE@0x71/
            /START_STRUCT/NAME@NodeIdPair/SIZE@0x8/
                /M/Node *node/0x4/0x0/
                /M/s32 id/0x4/0x4/
            /END/

            /M/Node m_nodes[KART_MAX]/0x120/0x71/
            /M/sead::TListNode<NodeIdPair> m_node_id_pairs[KART_MAX]/0xA0/0x194/
        /END/

        /M/Buffer m_buffer/0x254/0x8/
    /END/
}