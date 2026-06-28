#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/Actor.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Item)
{
    // unused TDirectorBase?
	/START_CLASS/NAME@ItemSlotTable/SIZE@0xA8/BASE@Object::Actor/BSIZE@0x8/
	public:
        // NOTE: invented name
        enum ItemSlotTableIndex
        {
            ItemSlotTable_GrandPrix,
            ItemSlotTable_GrandPrix_AI,
            ItemSlotTable_VS,
            ItemSlotTable_VS_AI,
            ItemSlotTable_WiFi,
            ItemSlotTable_WiFi_AI,
            ItemSlotTable_Coin,
            ItemSlotTable_Coin_AI,
            ItemSlotTable_Balloon,
            ItemSlotTable_Balloon_AI,
            ItemSlotTable_Coin_WiFi,
            ItemSlotTable_Coin_WiFi_AI,
            ItemSlotTable_Balloon_WiFi,
            ItemSlotTable_Balloon_WiFi_AI,
            ItemSlotTable_Kinoko,
            ItemSlotTable_Koura,
            ItemSlotTable_Banana,
            ItemSlotTable_Bomb,
            ItemSlotTable_Coin_Kinoko,
            ItemSlotTable_Coin_Koura,
            ItemSlotTable_Coin_Banana,
            ItemSlotTable_Coin_Bomhei,
            ItemSlotTable_Balloon_Kinoko,
            ItemSlotTable_Balloon_Koura,
            ItemSlotTable_Balloon_Banana,
            ItemSlotTable_Balloon_Bomhei,
            ItemSlotTable_Decided,
            ItemSlotTable_Title,
            ItemSlotTable_MAX,
        };

        /M/sead::FixedPtrArray<CSVUtil::CSVParam, ItemSlotTable_MAX> m_param_array/0x7C/0x28/
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0xA4/
	/END/
}