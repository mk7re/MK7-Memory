#pragma once

#include "../forward.hpp"

#include "eInvalidFlag.hpp"
#include "eItemSlot.hpp"
#include "eItemType.hpp"

#include "ItemObjDirector/all.hpp"

#include "../Net/NetworkItemEventDataMgr.hpp"

#include "../Object/Actor.hpp"
#include "../Object/TDirectorArray.hpp"
#include "../Object/TLinkSocket.hpp"

#include "../RaceSys/ModeManager/ModeManagerBase.hpp"

#include "../System/RootSystem.hpp"

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(Item)
{
    /START_CLASS/NAME@ItemDirector/SIZE@0x12C/BASE@Object::TDirectorArray<Object::Actor, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
    public:
        s16 getDetailKartID()
        {
            return m_mode_manager->m_race_info.m_detail_kart_id;
        }

        ItemObjDirectorBase *getDirector_FromItemSlot(eItemSlot item)
        {
            switch (item)
            {
            case eItemSlot::Banana:
            case eItemSlot::Banana3:
                return m_banana_director;
            case eItemSlot::KouraG:
            case eItemSlot::KouraG3:
                return m_kourag_director;
            case eItemSlot::KouraR:
            case eItemSlot::KouraR3:
                return m_kourar_director;
            case eItemSlot::Kinoko:
            case eItemSlot::Kinoko3:
            case eItemSlot::KinokoP:
                return m_kinoko_director;
            case eItemSlot::Bomhei:
                return m_bomhei_director;
            case eItemSlot::Gesso:
                return m_gesso_director;
            case eItemSlot::KouraB:
                return m_kourab_director;
            case eItemSlot::Star:
                return m_star_director;
            case eItemSlot::Killer:
                return m_killer_director;
            case eItemSlot::Thunder:
                return m_thunder_director;
            case eItemSlot::Flower:
                return m_flower_director;
            case eItemSlot::Tail:
                return m_tail_director;
            case eItemSlot::Seven:
                return m_seven_director;
            default:
                return nullptr;
            }
        }

        ItemObjDirectorBase *getDirector_FromItemType(eItemType item)
        {
            switch (item)
            {
            case eItemType::KouraG:
                return m_kourag_director;
            case eItemType::KouraR:
                return m_kourar_director;
            case eItemType::Banana:
                return m_banana_director;
            case eItemType::Kinoko:
                return m_kinoko_director;
            case eItemType::Star:
                return m_star_director;
            case eItemType::KouraB:
                return m_kourab_director;
            case eItemType::Thunder:
                return m_thunder_director;
            case eItemType::Bomhei:
                return m_bomhei_director;
            case eItemType::Gesso:
                return m_gesso_director;
            case eItemType::Killer:
                return m_killer_director;
            case eItemType::Flower:
                return m_flower_director;
            case eItemType::Tail:
                return m_tail_director;
            case eItemType::Seven:
                return m_seven_director;
            default:
                return nullptr;
            }
        }

        // NOTE: not part of symbols. Extracted from Item::ItemDirector::_calcInvalidFlag.
        inline static eItemType getItemType_FromItemSlot(eItemSlot item)
        {
            switch (item)
            {
                case eItemSlot::Banana:
                case eItemSlot::Banana3:
                    return eItemType::Banana;
                case eItemSlot::KouraG:
                case eItemSlot::KouraG3:
                    return eItemType::KouraG;
                case eItemSlot::KouraR:
                case eItemSlot::KouraR3:
                    return eItemType::KouraR;
                case eItemSlot::Kinoko:
                case eItemSlot::Kinoko3:
                    return eItemType::Kinoko;
                case eItemSlot::Bomhei:
                    return eItemType::Bomhei;
                case eItemSlot::Gesso:
                    return eItemType::Gesso;
                case eItemSlot::KouraB:
                    return eItemType::KouraB;
                case eItemSlot::Star:
                case eItemSlot::Test3:
                case eItemSlot::Test4:
                    return eItemType::Star;
                case eItemSlot::Killer:
                    return eItemType::Killer;
                case eItemSlot::Thunder:
                    return eItemType::Thunder;
                case eItemSlot::KinokoP:
                    return eItemType::KinokoP;
                case eItemSlot::Flower:
                    return eItemType::Flower;
                case eItemSlot::Tail:
                    return eItemType::Tail;
                case eItemSlot::Seven:
                    return eItemType::Seven;
                default:
                    return eItemType::INVALID;
            }
        }

        /M/ItemObjBananaDirector *m_banana_director/0x4/0x28/
        /M/ItemObjKouraGDirector *m_kourag_director/0x4/0x2C/
        /M/ItemObjKouraRDirector *m_kourar_director/0x4/0x30/
        /M/ItemObjBomheiDirector *m_bomhei_director/0x4/0x34/
        /M/ItemObjGessoDirector *m_gesso_director/0x4/0x38/
        /M/ItemObjStarDirector *m_star_director/0x4/0x3C/
        /M/ItemObjThunderDirector *m_thunder_director/0x4/0x40/
        /M/ItemObjKillerDirector *m_killer_director/0x4/0x44/
        /M/ItemObjKouraBDirector *m_kourab_director/0x4/0x48/
        /M/ItemObjFlowerDirector *m_flower_director/0x4/0x4C/
        /M/ItemObjTailDirector *m_tail_director/0x4/0x50/
        /M/ItemObjKinokoDirector *m_kinoko_director/0x4/0x54/
        /M/ItemObjSevenDirector *m_seven_director/0x4/0x58/
        /M/s32 m_gesso_time/0x4/0x5C/
        /M/s32 m_thunder_time/0x4/0x60/
        /M/s32 m_kourab_time/0x4/0x64/
        /M/s32 m_killer_time/0x4/0x68/
        /M/s32 m_seven_time/0x4/0x6C/
        /M/s32 m_kinokop_time/0x4/0x70/
        /M/bool m_special_items_threshold_passed/0x4/0x74/
        /M/eInvalidFlag m_invalid_flag/0x4/0x78/
        /M/sead::Delegate1R<ItemDirector, Net::NetworkItemEventDataMgr::SlotData const &, bool> m_item_event_recv_handler_delegate/0x10/0x7C/
        /M/ItemSlotTable *m_item_slot_table/0x4/0x8C/
        /M/sead::PtrArray<ItemObjBase> m_equip_item_objs/0xC/0x90/
        /M/sead::PtrArray<ItemObjBase> m_selfmove_item_objs/0xC/0x9C/
        /M/sead::PtrArray<ItemObjBase> m_stand_item_objs/0xC/0xA8/
        /M/sead::PtrArray<ItemObjBase> m_delwait_item_objs/0xC/0xB4/
        /M/sead::PtrArray<KartItem> m_kart_items/0xC/0xC0/
        /M/s32 m_director_frame/0x4/0xCC/
        /M/sead::Buffer<bool> m_current_presses/0x8/0xD0/
        /M/sead::Buffer<bool> m_previous_presses/0x8/0xD8/
        /M/sead::Buffer<ItemSlot> m_item_usages/0x8/0xE0/
        /M/sead::Buffer<s32> m_kinoko_frames/0x8/0xE8/
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0xF0/
        /M/CSVUtil::CSVParam *m_csv_param/0x4/0xF4/
        /M/bool m_is_lava_course/0x1/0xF8/
        /M/Field::MapdataCheckPointAccessor *m_check_point_accessor/0x4/0x100/
        /M/Net::NetworkItemEventDataMgr::SlotData *m_slot_datas/0x4/0x11C/
    /END/

    inline static auto GetDirector()
    {
        return System::g_root_system->get_item_director();
    }
}