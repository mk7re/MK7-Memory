#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../KDMtxT.hpp"
#include "../KDRigid.hpp"
#include "../KDGndCol/CheckIF_EX.hpp"

#include <math/seadMatrix.hpp>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@Camera/SIZE@0x290/
    public:
        // NOTE: Name is made up
        enum class DepthLevelMode : u32 {
            MODE_THIRD_PERSON,
            MODE_ZOOMING_INTO_FIRST_PERSON,
            MODE_FIRST_PERSON_CHARACTER_MODEL_VISIBLE,
            MODE_FIRST_PERSON_CHARACTER_MODEL_INVISIBLE
        };

        /START_STRUCT/NAME@ParamSet_View/SIZE@0x14/
            /U/f32/0x4/0x0/
            /U/f32/0x4/0x4/
            /U/f32/0x4/0x8/
            /U/f32/0x4/0xC/
            /U/f32/0x4/0x10/
        /END/

        Camera(const Vehicle *, GLOBAL_NAMESPACE::Camera::CameraBase *);
        void calcGndEvade(sead::Vector3f *);
        void calcParamSet(f32);
        void startGndEvading(const sead::Vector3f &, const sead::Vector3f &, sead::Vector3f *);
        void calcMtxTwistRoll(f32, sead::Vector3f &, KDMtxT &);
        void calcYawPitchFilter(sead::Vector3f *, sead::Vector3f *, const sead::Vector3f &, const sead::Vector3f &, bool);
        void initParamSet_Target(const ParamSet_View &);
        void init();
        void calcDraw(const sead::Matrix34f &, f32);
        void calcApply(f32, bool, f32, f32);

        /M/KDRigid m_rigid/0xd0/0x0/ // inherited?
        /M/GLOBAL_NAMESPACE::Camera::CameraBase *m_camera_base/0x4/0xd0/
        /M/bool m_is_focused_player/0x1/0xd4/
        /M/bool m_is_master_player/0x1/0xd5/
        /M/InfoProxy *m_info_proxy/0x4/0xd8/
        /M/Vehicle *m_vehicle/0x4/0xdc/
        /M/sead::Vector3f m_target_vehicle_position/0xc/0x130/
        /M/sead::Vector3f m_target_position/0xc/0x13c/
        /M/f32 m_fovy/0x4/0x170/
        /M/f32 m_depth_level/0x4/0x17c/
        /M/KDGndCol::CheckIF_EX m_check_if_ex/0x10/0x1c0/
        /U/ParamSet_View/0x14/0x244/
        /U/ParamSet_View/0x14/0x258/
        /M/DepthLevelMode m_depth_level_mode/0x4/0x270/
        /M/sead::Vector3f m_position_first_person/0xc/0x280/
    /END/
}