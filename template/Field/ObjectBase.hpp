#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "ObjectParameter.hpp"
#include "ObjectCreateArgument.hpp"
#include "EGHTReaction.hpp"
#include "eObjectReactType.hpp"
#include "eMapdataGeoObjIDIndex.hpp"

#include <math/seadMatrix.h>
#include <prim/seadSafeString.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // Name is made up
    enum class ELodState : u32 {
        HIGH,
        MEDIUM,
        LOW,
        CULLED,
    };

    enum class EObjectClipArg : u32
    {
        CLIP_ARG_1 = 1,
        CLIP_ARG_2,
        CLIP_ARG_5 = 5
    };

    // Name is made up
    enum class EObjectSoundActorType : u32
    {
        DEFAULT,
        POINT,      // SndActorPoint
        ITEM,       // SndActorItem
        ENEMY,      // SndActorEnemy
        OBJECT,     // SndActorObj
        CLUSTER,    // SndActorCluster
        TEMPOKUN    // SndActorTempokun
    };

    // Name is made up
    enum ObjectDefaultNeedFlag : u32 {
        HAS_GROUND_COLLISION = 0x00000001,
        // See ClipContext / ClipParam related code
        CAN_CLIP = 0x00000002,
        USES_3D_SOUNDS = 0x00000004,
        FLAG_0x0008 = 0x00000008,
        HAS_GROUND_SHADOW = 0x00000010,
        UPDATE_COLLISION_POSTURE = 0x00000020,
        CALC_WHEN_INVISIBLE = 0x00000040,
        // See `ObjectSimpleModelBase::calcVisibility`
        FORCE_SKELETAL_MODEL_INVISIBLE = 0x00000080,
        HAS_SPECIAL_LIGHTSET = 0x00000100,
        FLAG_0x0200 = 0x00000200,
        // If set, coins will despawn upon contact with the object
        DESPAWN_COIN_ON_CONTACT = 0x00000400,
    };

    // Name is made up
    enum ObjectFlags : u32 {
        UPDATE_POSITION = 0x00000001,
        UPDATE_ROTATION = 0x00000002,
        UPDATE_SCALE    = 0x00000004,
    };

    /START_CLASS/NAME@ObjectBase/SIZE@0xA0/VTABLE@True/
    public:
        virtual void calcView();
        virtual void updateScaleChange();
        virtual void vf_0x8();
        virtual Util::CollisionResult *getCollisionResult();
        virtual ObjectCollisionBase *getCollisionBase() const;
        virtual bool checkCollision(const sead::Vector3f &, f32, s32);
        virtual EObjectSoundActorType getSoundActorType();
        virtual void add_IndividualArgs(ObjectCreateArgument &);
        virtual void add_IndividualArgs_forLOD(Render::DrawMdlCreateArgs &, s32);
        virtual void createObjectDefault(ObjectCreateArgument &) = 0;
        virtual void createObjectAnim(const ObjectCreateArgument &) = 0;
        virtual void createObjectShadow(const ObjectCreateArgument &);
        virtual void createObjectExtend(const ObjectCreateArgument &) = 0;
        virtual void createObjectAnimExtend(const ObjectCreateArgument &) = 0;
        virtual void createDefaultMaterialAnim(const ObjectCreateArgument &) = 0;
        virtual void createMaterialAnimLeader(const ObjectCreateArgument &);
        virtual void initObjectAnim(const ObjectCreateArgument &) = 0;
        virtual void beginRegistAnimation(s32) = 0;
        virtual void endRegistAnimation() = 0;
        virtual void createPath(const ObjectCreateArgument &);
        virtual void createSoundActor(const ObjectCreateArgument &);
        virtual void initObj();
        virtual void calcObj();
        virtual void calcPath();
        virtual void calcPathPosture();
        virtual void calcEnd();
        virtual f32 getGroundCollisionRadius();
        virtual void createCollision(SObjectCollisionSet *);
        virtual void createNoCollision(SObjectCollisionSet *);
        virtual void createSphereCollision(SObjectCollisionSet *);
        virtual void createCylinderCollision(SObjectCollisionSet *);
        virtual void createBoxCollision(SObjectCollisionSet *);
        virtual void createGroundCollision(SObjectCollisionSet *);
        virtual void createCapsuleCollision(SObjectCollisionSet *);
        virtual void createOriginalCollision(SObjectCollisionSet *);
        virtual EGHTReaction setReaction_fromKart(EGHTReaction, eObjectReactType, Kart::VehicleReact *);
        virtual EGHTReaction setReaction_fromItem(EGHTReaction, eObjectReactType, Item::ItemReactProxy *);
        virtual void doReaction_againstKart(EGHTReaction, Kart::VehicleReact *, ObjectCollisionResult *, bool);
        virtual void doReaction_againstItem(EGHTReaction, Item::ItemReactProxy *);
        virtual void updateObjectCollisionPos();
        virtual sead::Matrix34f *getObjectCollisionPosture();
        virtual void onCollisionHit(ObjectCollisionResult *);
        virtual const char *getResourceName();
        virtual const char *getModelName();
        virtual s32 getRenderPriorityOpa_Start();
        virtual s32 getRenderPriorityOpa_End();
        virtual s32 getAnimNum();
        virtual s32 getDefaultPlayAnimIndex();
        virtual s32 getDefaultPlayMaterialAnimIndex();
        virtual eMapdataGeoObjIDIndex getObjectEnumIndex();
        virtual void setupBoxCol();
        virtual void setDefaultNeedFlag();
        virtual bool isCreateHitEffect() const;

        ObjectBase(const ObjectCreateArgument &);
        void createObject(ObjectCreateArgument &);
        void doReact_Wall(Kart::VehicleReact *, ObjectCollisionResult *, u32);
        void doReact_Reject(Kart::VehicleReact *, ObjectCollisionResult *);
        void doReact_CrashLR(Kart::VehicleReact *, ObjectCollisionResult *, bool);
        void setupParameter(ObjectCreateArgument &);
        f32 getFixedRandomF32(f32);
        u32 getFixedRandomU32(u32);
        f32 getUnfixedRandomF32(f32);
        u32 getUnfixedRandomU32(u32);
        static void createResourcePath(sead::FixedSafeString<128> *, const char *, const char *);
        bool checkGroundCollision(KDGndCol::CheckIF *, const sead::Vector3f &, f32, u32, u32, sead::Vector3f *);
        void updateGroundCollision(const sead::Vector3f &, f32, u32, u32);
        void checkDetail_ItemHitObj(Item::ItemReactProxy *);
        void checkDetail_KartHitObj(Kart::VehicleReact *);
        void followPosture_PathMove();
        void calc();
        void init();
        
        /M/u32 m_need_flag/0x4/0x4/     // See the `ObjectDefaultNeedFlag` enum
        /M/MapdataGeoObj *m_mapdata_geo_obj/0x4/0x8/
        /M/ObjectParameter::Parameter *m_parameter/0x4/0xC/
        /M/ObjectPathBase *m_path/0x4/0x10/
        /M/ObjectCollisionBase *m_object_collision/0x4/0x14/
        /M/sead::Matrix34f m_collision_posture/0x30/0x18/
        /M/sead::Vector3f m_pos/0xC/0x48/
        /M/sead::Vector3f m_previous_pos/0xC/0x54/
        // TODO: Is this used only for collision-related operations?
        /M/sead::Vector3f m_collision_size_multiplier/0xC/0x60/
        /M/u32 m_flags/0x4/0x6C/    // See the `ObjectFlags` enum
        /M/EObjectClipArg m_arg/0x4/0x70/
        /M/ELodState m_lod_state/0x4/0x74/
        /M/bool m_cpu_should_avoid_object/0x1/0x78/
        /M/bool m_is_active/0x1/0x79/
        /M/bool m_update_culling/0x1/0x7A/
        /M/bool m_is_culled/0x1/0x7B/
        /M/bool m_enable_culling/0x1/0x7C/
        /M/bool m_is_visible/0x1/0x7D/
        /U/s16/0x2/0x7E/
        /M/Sound::SndActorBase *m_snd_actor/0x4/0x80/
        /M/BoxCol::Unit *m_unit/0x4/0x84/
        /M/f32 m_unit_size/0x4/0x88/    // Aka `m_area`
        /U/sead::Vector3f/0xC/0x8C/
        /M/bool m_is_net_object/0x1/0x98/
        /M/bool m_is_time_trials/0x1/0x99/
        /M/bool m_is_race_preview/0x1/0x9A/
        // Used by EGHTReaction's `EGHTREACT_SPEED_SPIN`.
        // See `ObjectBase::doReaction_againstKart`
        /M/f32 m_eght_react_speed_spin_min_speed/0x4/0x9C/
    /END/

    ELodState getLodState(const ClipContext *, const sead::Vector3f &, const ObjectParameter::Parameter *, const EObjectClipArg &);
}