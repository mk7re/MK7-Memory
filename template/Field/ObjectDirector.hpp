#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ObjectBase.hpp"
#include "ObjectParameter.hpp"
#include "Entry/GeoObj.hpp"
#include "eObjectReactType.hpp"
#include "eObjectModelType.hpp"
#include "EGHTItemKind.hpp"
#include "EGHTKartState.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectDirector/SIZE@0x1D0/BASE@Object::TDirectorArray<Object::Actor, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
		virtual void calc(); // 6
        virtual void createBeforeStructure(const Object::ArgumentObj *);
        virtual void initAfterStructure();
        virtual void calcBeforeStructure();
        virtual void calcAfterStructure();

        ObjectDirector();
        ObjectBase *findObject(eMapdataGeoObjID, s32) const;
        bool isNetObject() const;
        bool checkTcBoardArea(const sead::Vector3f &, float) const;
        void entryObjEx(s32, Object::Actor *, eObjectModelType);
        bool isNCObject_(MapdataGeoObj *, ObjectParameter *, const RaceSys::CRaceInfo &);
        void reactThunder();
        bool checkItemHitObj(Item::ItemReactProxy *);
        bool checkKartHitObj(Kart::VehicleReact *);
        void create_ObjReactTable(const Object::ArgumentObj *);
        eObjectReactType getObjReact_fromItem(eMapdataGeoObjID, EGHTItemKind);
        eObjectReactType getObjReact_fromKart(eMapdataGeoObjID, EGHTKartState);
        void forceExtraObjectsInto(s32, const Object::ArgumentObj *);
        void invalidate_FarLodDistance();
        static bool append(eMapdataGeoObjID, eMapdataGeoObjIDIndex, Object::Actor*(*)(ObjectCreateArgument &), const Object::DTIClassInfo *);

        /M/ObjectParameter m_object_parameter/0x10/0x28/
        /U/s32/0x4/0x38/
        /U/s32/0x4/0x3c/
        /U/s32/0x4/0x40/
        /M/sead::PtrArray<ObjectBase> m_objects/0xc/0x44/
        // The objects that go into this array are those whose field 0x3C in their KMP setting is set to 0 or higher.
        // See 0x0033d8d4 (VERSION_EUR_DLP). Checked by AIAutoSteer::init in order to get the N64Crossing objects,
        // which the CPU use to know where to stop for the train to pass.
        /M/sead::PtrArray<ObjectBase> m_obj_link_array/0xc/0x50/
        // Objects that go here are those whose `ObjFlowBinEntryFlags` have `IS_SKYBOX` set
        /M/sead::FixedPtrArray<ObjectVRDefault, 20> m_vr_objects/0x5c/0x5c/
        /M/Object::CoinManager *m_coin_manager/0x4/0xb8/
        /M/Object::GrObjManager *m_gr_obj_manager/0x4/0xbc/
        /M/ObjectCmnMiiManager *m_obj_cmn_mii_manager/0x4/0xc0/
        /M/ObjectHsAirCurrent *m_obj_hs_air_current/0x4/0xc4/
        /M/sead::FixedPtrArray<ObjectBdBoard, 10> m_bd_board_objects/0x34/0xc8/
        /M/sead::FixedPtrArray<ObjectTcBoard, 4> m_tc_board_objects/0x1c/0xfc/
        /M/ObjectWiiEscalator *m_wii_escalator/0x4/0x118/
        /U/s32/0x4/0x11c/
        /U/s32/0x4/0x120/
        /U/s32/0x4/0x124/
        // ObjectBase. Only objects with ObjectReactType equal to 1 or 2 go here
        /U/sead::PtrArray<ObjectBase>/0xc/0x130/
        /U/s32/0x4/0x13c/
        /U/s32/0x4/0x140/
        /U/s32/0x4/0x144/
        /U/s32/0x4/0x148/
        /U/s32/0x4/0x14c/
        /M/MapdataGeoObj *m_cmn_start_grid_geo_obj/0x4/0x150/
        /M/MapdataGeoObjData m_cmn_start_grid_sdata/0x40/0x154/
        /M/f32 m_water_height/0x4/0x194/
        /U/s32/0x4/0x198/
        /U/s32/0x4/0x19c/
        /U/s32/0x4/0x1a0/
        /M/GeoHitTable *m_geo_hit_table_item/0x4/0x1a4/
        /M/GeoHitTable *m_geo_hit_table_item_obj/0x4/0x1a8/
        /M/GeoHitTable *m_geo_hit_table_kart/0x4/0x1ac/
        /M/GeoHitTable *m_geo_hit_table_kart_obj/0x4/0x1b0/
        /M/s32 m_geo_hit_table_kart_obj_num_rows/0x4/0x1b4/
        /M/s32 m_geo_hit_table_kart_obj_num_columns/0x4/0x1b8/
        /M/eObjectReactType *m_geo_hit_table_kart_obj_entries/0x4/0x1bc/
        /M/s32 m_geo_hit_table_item_obj_num_rows/0x4/0x1c0/
        /M/s32 m_geo_hit_table_item_obj_num_columns/0x4/0x1c4/
        /M/eObjectReactType *m_geo_hit_table_item_obj_entries/0x4/0x1c8/
        /M/eObjectModelType m_object_model_type/0x1/0x1cc/
        // If `true`, objects will be updated.
        // Set to `true` when the countdown starts, so that objects can start moving
        /M/bool m_calc_moving_objects/0x1/0x1cd/
    /END/
}