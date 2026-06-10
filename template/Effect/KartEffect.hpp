#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include "../Object/Actor.hpp"
#include "../Object/ArgumentObj.hpp"

#include "GameParticle.hpp"
#include "EKartEffectID.hpp"
#include "../Kart/Vehicle/VehicleReact.hpp"
#include "../Field/EGHTReaction.hpp"

#include <container/seadPtrArray.h>
#include <prim/seadSafeString.h>
#include <math/seadMatrix.hpp>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Effect)
{
    /START_CLASS/NAME@KartEffect/SIZE@0x834/BASE@Object::Actor/BSIZE@0x8/
    public:
        enum class eGndEffFlag : u32 {
            HDIRT=1,
            DIRT_UNDERWATER=2 /* HDIRT OR LDIRT */,
            SAND=4,
            ROAD3_OR_SAND_UNDERWATER=8,
            ZONE_PETALS=16 /* ZONE - Variant 1 */,
            HDIRT_VARIANT_4=32,
            ROAD_VARIANT_1=64,
            ICE_VARIANT_1=128,
            HDIRT_VARIANT_5=256,
            DIRT_VARIANT_5=512,
            SAND_VARIANT_5=1024,
            LDIRT_VARIANT_6=2048,
            LDIRT_VARIANT_6_UNDERWATER=4096,
            ICE=8192,
            ICE_VARIANT_2=16384,
            LDIRT_VARIANT_3=32768,
            MOVING_WATER=65536,
            FLAG_0x20000=131072,
            BELT=262144,
            HDIRT_VARIANT_1=524288,
            DIRT_VARIANT_2=1048576,
            DIRT_VARIANT_2_UNDERWATER=2097152,
            LDIRT_VARIANT_5=4194304
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1

        virtual void create(Object::ArgumentObj const *); // 4
		virtual void init(); // 5
		virtual void calc(); // 6

        KartEffect(s32);
        void _calcParam();
        void _resetParam();
        void createMaple();
        void setDrawTrig(bool);
        void createObjHit(Field::ObjectBase *, Field::EGHTReaction, const sead::Vector3f &);
        void _calcTireInfo(const KDGndCol::CheckIF_EX &);
        void calcItemThrow(const sead::Matrix34f &);
        void createKartHit(const sead::Vector3f &, s32);
        void createWallHit(Field::ObjectBase *, const sead::Vector3f &);
        void _calcAllPlayer();
        void _calcEnvEffect();
        void _calcMtx_YAxis(sead::Matrix34f *);
        void createSpinTrig(Kart::VehicleReact::EAcdType, Kart::VehicleReact::ESpinType);
        void createTailTrig();
        void _calcBodyEffect();
        void _calcMufflerMtx();
        void createCrashTrig(Kart::VehicleReact::EAcdType);
        void createGessoTrig();
        void _calcCameraParam();
        void _calcMtxTireLand();
        void calcWaterOutPota(const sead::Matrix34f &);
        void callBackHeadNode(const sead::Matrix34f &);
        void createKillerTrig();
        void createKinokoJump();
        void createCoinHitTrig(const sead::Vector3f &);
        void createThunderTrig();
        void createWaterInTrig(bool);
        void createWaterObjHit();
        void killAllEffectImpl();
        void _emit_Valley_Model(Render::DrawMdl *, const sead::Vector3f &);
        void createJugemWaterTrig();
        void _init_Valley_Model(Render::DrawMdl *);
        void createWaterOutTrig();
        void setGndEff_ZonePetal();
        void _calcBodyEffect_Star();
        void _create_Valley_Model(Render::DrawMdl **, const sead::SafeString &, const sead::SafeString &);
        void createJumpActionTrig();
        void _calcCameraEffectImpl();
        void _createObjHitTrigImpl(Field::ObjectBase *, Field::EGHTReaction, const sead::Vector3f &, bool);
        void createValleyEffectCalc(s32, const sead::Vector3f &, f32);
        void _createValleyLavaTrig(const sead::Vector3f &, f32, bool);
        void calcAfterCameraUpdate();
        void createMufflerFireTrig();
        void _calcBodyEffect_Killer();
        void _calcCameraEffect_Impl(LibEffect::Particle *, bool, f32, bool);
        void _calcMufflerEffect_Gas();
        void _calcPartsEffect_Screw();
        void createItemBoxBreakTrig(const sead::Vector3f &);
        void _calcBodyEffect_Thunder();
        void createStartDashMissTrig();
        void _calcTireEffect_Gnd();
        void _calcImpl_TireEffect_Gnd(EKartEffectID, eGndEffFlag);
        void createFireBallDamegeTrig();
        void createTailSpinAttackTrig();
        void _calcBodyEffect_LandSmoke();
        void _calcTireEffect_WheelSpin();
        void _calcBodyEffect_SlipStream();
        void _calcTireEffect_WaterSpray();
        void _calcBodyEffect_RippleInWater();
        void _calcTireEffect_Drift();
        void _calcImpl_TireEffect_DriftSpark(EKartEffectID);
        void createMufflerFireCalc_DashPanel();
        void _calcProxyEffect_InCharacterEngine();
        bool isDetail() const;

        /M/sead::FixedPtrArray<GameParticle, 116> m_particles/0x1DC/0x14/
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0x1f0/
        /M/RaceSys::CRaceInfo *m_race_info/0x4/0x1f4/
        /M/s32 m_player_id/0x4/0x1f8/
        /M/Kart::InfoProxy *m_info_proxy/0x4/0x1fc/
        /M/Item::KartItemProxy *m_item_proxy/0x4/0x200/
        /M/bool m_was_drifting/0x1/0x204/
        /M/bool m_stop_drift/0x1/0x205/
        /M/bool m_is_drifting/0x1/0x206/
        /M/bool m_was_miniturbo_over_lvl_1/0x1/0x207/
        /M/bool m_was_miniturbo_over_lvl_2/0x1/0x208/
        /M/bool m_display_miniturbo_lvl_1/0x1/0x209/
        /M/bool m_display_miniturbo_lvl_2/0x1/0x20a/
        /M/bool m_is_miniturbo_over_lvl_1/0x1/0x20b/
        /M/bool m_is_miniturbo_over_lvl_2/0x1/0x20c/
        /M/bool m_is_first_person/0x1/0x6d4/
        /M/bool m_was_first_person/0x1/0x6d5/
        /M/f32 m_waterbox_height/0x4/0x754/
        /M/s32 m_above_water_time/0x4/0x758/
        /M/s32 m_calc_timer/0x4/0x75c/
        /M/bool m_is_item_throw/0x1/0x760/
        /M/bool m_is_detail/0x1/0x775/
        // If `true`, then, when in 1st person, when drifting,
        // only the road drift smoke will be visible in the tire of the side the player is drifting to
        /M/bool m_only_display_drift_sparks_in_one_side_fp/0x1/0x830/
        /M/bool m_is_visible/0x1/0x831/
    /END/
}