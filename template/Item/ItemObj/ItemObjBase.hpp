#pragma once

#include "../../forward.hpp"
#include "../../types.hpp"

#include "../../KDGndCol/CheckIF_EX.hpp"

#include "../../Object/Actor3DMdl.hpp"
#include "../../Object/ArgumentObj.hpp"

#include "../../Util/TStateObserver.hpp"

#include "../eItemType.hpp"

#include <math/seadVectorFwd.h>

BEGIN_NAMESPACE(Item)
{
    /START_CLASS/NAME@ItemObjBase/SIZE@0x1F8/BASE@Object::Actor3DMdl/BSIZE@0x58/VTABLE@True/
    public:
        enum class eColMode : u8
        {
            None,
            Equip,
            SelfMove,
            Stand,
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const { return {}; }; // 0
		virtual Object::DTIClassInfo *getDTIClass() const { return {}; }; // 1

		virtual void create(Object::ArgumentObj const *) {}; // 4
		virtual void init() = 0; // 5
		virtual void calc() = 0; // 6

        virtual bool isEquip() const { return {}; }; // 18
        virtual bool isEquip_Hang() const { return {}; }; // 19
        virtual bool isEquip_Multi() const { return {}; }; // 20

        virtual s32 getMultiID() const { return {}; }; // 21
        virtual float *getColRadius() const { return {}; }; // 22
        virtual float *getBoxColRadius() const { return {}; }; // 23
        virtual void *getColScale() const { return {}; }; // 24
        virtual u32 getSoundActorType() const { return {}; }; // 25

        virtual void calc_HitGnd(void const *) {}; // 26
        virtual void calc_HitWall(void const *) {}; // 27

        virtual void exit_Lava() {}; // 28
        virtual void setStateStand() {}; // 29

        virtual void _0x78() = 0; // 30

        virtual void initEntryInner_Before() {}; // 31

        virtual void _0x80() = 0; // 32
        virtual void _0x84() = 0; // 33

        virtual void exit_VanishInner() {}; // 34
        virtual void exit_BreakInner() {}; // 35
        virtual void exitInner() {}; // 36

        virtual void react_BreakInner() {}; // 37
        virtual void react_VanishInner() {}; // 38
        virtual void react_ReflectInner(sead::Vector3f const &, sead::Vector3f const &, bool) {}; // 39

        //virtual void _0xA0() = 0; // 40 | Stripped

        virtual void stateInitSelfMoveImpl() {}; // 41

        virtual bool hasCollision_InUseState() const { return {}; }; // 42
        virtual float *getShadowScale() const { return {}; }; // 43
        virtual float *getPressOffsetY_Shadow() const { return {}; }; // 44
        virtual bool hasLight() const { return {}; }; // 45
        virtual float *getOffset_Hang_Y() const { return {}; }; // 46
        virtual float *getOffset_Multi_Y() const { return {}; }; // 47
        virtual float *getOffset_Multi_Z() const { return {}; }; // 48
        virtual float *getRotVelRatio_Multi() const { return {}; }; // 49
        virtual float *getRadius_Multi() const { return {}; }; // 50
        virtual char const *getVanishEffectName() const { return {}; }; // 51

        virtual void stateInitWait() {}; // 52
        virtual void stateWait() {}; // 53
        virtual void stateInitEquip_Hang() {}; // 54
        virtual void stateEquip_Hang() {}; // 55
        virtual void stateInitEquip_Multi() {}; // 56
        virtual void stateEquip_Multi() {}; // 57
        virtual void stateInitSelfMove() {}; // 58
        virtual void stateSelfMove() {}; // 59
        virtual void stateInitDrop() {}; // 60
        virtual void stateDrop() {}; // 61
        virtual void stateInitStand() {}; // 62
        virtual void stateStand() {}; // 63
        virtual void stateInitUse() {}; // 64
        virtual void stateUse() {}; // 65
        virtual void stateInitAttacked() {}; // 66
        virtual void stateAttacked() {}; // 67

        virtual void _0x110() = 0; // 68
        virtual void _0x114() = 0; // 69

        /M/Util::TStateObserver<ItemObjBase> m_state_observer_base/0x20/0x58/ // some ItemObjs also have a specialized Observer
        /M/sead::Matrix34f m_draw_mtx/0x30/0x78/
        /M/sead::Vector3f m_position/0xC/0xA8/
        /M/sead::Vector3f m_starting_velocity/0xC/0xB4/
        /M/f32 m_equip_scale/0x4/0xC0/
        /M/sead::Vector3f m_velocity/0xC/0xC4/
        /M/f32 m_gravity/0x4/0xD0/
        /U/sead::Vector3f/0xC/0xD4/
        /M/s32 m_multi_id/0x4/0xE0/
        /M/sead::Vector2f m_multi_position/0x8/0xE4/
        /M/s32 m_multi_amount/0x4/0xEC/
        /M/Render::ShadowVolume *m_shadow_volume/0x4/0xF0/
        /M/bool m_is_thrown_backwards/0x1/0xF4/
        /M/sead::Vector2f m_stick/0x8/0xF8/
        /U/u8/0x1/0x100/
        /U/sead::Vector3f/0xC/0x104/
        /M/Effect::GameParticle *m_game_particle_1/0x4/0x110/
        /M/ItemReactProxy *m_item_react_proxy/0x4/0x114/
        /M/KDGndCol::CheckIF_EX m_check_if_ex/0x10/0x118/
        /U/u32/0x4/0x128/ // ground flags 1
        /U/u32/0x4/0x12C/ // ground flags 2
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0x130/
        /M/RaceSys::CRaceInfo *m_race_info/0x4/0x134/
        /M/RaceSys::LogRecorder *m_log_recorder/0x4/0x138/
        /U/sead::Vector3f/0xC/0x13C/
        /U/bool/0x1/0x148/
        /M/bool m_has_vanish_effect/0x1/0x149/
        /M/bool m_has_shadow/0x1/0x14A/
        /M/bool m_is_tc_board_area/0x1/0x14B/
        /U/bool/0x1/0x14C/
        /M/bool m_is_multi_trail/0x1/0x14D/
        /U/u8/0x1/0x14E/
        /M/s32 m_serial/0x4/0x150/
        /U/u8/0x1/0x154/
        /U/u8/0x1/0x155/ // state init circle related?
        /M/eItemType m_item_type/0x1/0x156/
        /M/Kart::InfoProxy *m_info_proxy/0x4/0x158/
        /M/f32 m_compare/0x4/0x15C/
        /M/s32 m_item_id/0x4/0x160/
        /M/s32 m_owner_player_id/0x4/0x164/
        /M/s32 m_current_life/0x4/0x168/
        /U/s32/0x4/0x16C/ // collisionless num?
        /M/eColMode m_col_mode/0x1/0x170/
        /M/u32 m_exit_frame/0x4/0x174/
        /M/u32 m_exit_director_frame/0x4/0x178/
        /M/Render::RaceLight::LightObj *m_light_obj/0x4/0x17C/
        /M/sead::Vector3f m_position_previous/0xC/0x180/
        /M/sead::Vector3f m_move/0xC/0x18C/
        /M/bool m_is_draw/0x1/0x198/
        /M/bool m_is_clip_context_visible/0x1/0x199/
        /M/Field::QuadTree *m_quad_tree/0x4/0x19C/
        /M/Field::ClipContext *m_clip_context/0x4/0x1A0/
        /M/bool m_is_state_init_equip_hang/0x1/0x1A4/
        /M/Sound::SndActorItem *m_snd_actor_item/0x4/0x1A8/
        /M/bool m_is_immediate_throw/0x1/0x1AC/
        /M/bool m_is_collisionless/0x1/0x1AD/
        /M/bool m_is_dropped/0x1/0x1AE/
        /M/bool m_is_awaiting_delete/0x1/0x1AF/
        /M/bool m_is_dropped_disable_logrecord/0x1/0x1B0/ // Always set along m_is_dropped, disables logging the InitSelfMove event (LogRecorder::addValue)
        /M/f32 m_water_box/0x4/0x1B4/
        /U/void */0x4/0x1B8/ // Field::ObjectWaterBox?
        /M/f32 m_moon_box/0x4/0x1BC/
        /U/s32/0x4/0x1C0/
        /U/sead::Vector3f/0xC/0x1C4/ // scale anim?
        /U/sead::Vector3f/0xC/0x1D0/ // angular velocity?
        /M/bool m_is_exiting/0x1/0x1DC/
        /U/s32/0x4/0x1E0/ // player ID equipped?
        /U/s32/0x4/0x1E4/ // player ID unequipped?
        /U/bool/0x1/0x1E8/
        /M/u32 m_delay_frame/0x4/0x1EC/
        /M/f32 m_speed/0x4/0x1F0/
        /M/bool m_is_doing_recovery/0x1/0x1F4/
        /U/u8/0x1/0x1F5/
    /END/
}