#pragma once

#include "../forward.hpp"
#include "../Object/Actor.hpp"
#include "../Render/Renderer.hpp"
#include "math/seadVector.h"

BEGIN_NAMESPACE(Camera)
{
    /START_CLASS/NAME@FinalOutputCamera/SIZE@0xA4/
    public:
        virtual void update(CameraBase *, CameraBase *);

        FinalOutputCamera();
        void calcStereoCamera(const nw::gfx::Camera *, nn::math::MTX34 *, nn::math::MTX44 *);
        void setCurrentViewAndProjMtx(Render::Renderer::ERenderLocale);

        // This might be an array ? //
        /U/u32/0x4/0x4/
        /M/nn::math::MTX44 *m_proj_L/0x4/0x8/
        /U/u32/0x4/0xc/
        /M/nn::math::MTX44 *m_inverted_proj_L/0x4/0x10/
        /U/u32/0x4/0x14/
        /M/nn::math::MTX44 *m_view_L/0x4/0x18/
        /U/u32/0x4/0x1c/
        /M/nn::math::MTX44 *m_inverted_view_L/0x4/0x20/
        /////////////////////////////////////////
        /U/u32/0x4/0x24/
        /U/nw::gfx::Camera */0x4/0x28/
        /U/nw::gfx::Camera */0x4/0x2c/
        /M/nn::ulcd::CTR::StereoCamera m_stereo_camera/0x60/0x34/
        /M/Render::Renderer::ERenderLocale m_render_locale/0x1/0x94/
        /M/f32 m_depth_level/0x4/0x98/
        /M/f32 m_depth_range/0x4/0x9c/
        /M/bool m_real_switch/0x1/0xa0/
    /END/
}