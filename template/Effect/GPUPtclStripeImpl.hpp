#pragma once

#include "../types.hpp"

#include <gfx/seadColor.h>

BEGIN_NAMESPACE(Effect)
{
    /START_CLASS/NAME@GPUPtclStripeImpl/SIZE@0x8EC/VTABLE@True/
    public:
        virtual ~GPUPtclStripeImpl() = default;

        /M/f32 m_width/0x4/0x8A0/
        /M/f32 m_frame_alpha_max/0x4/0x8A4/
        /M/f32 m_frame_alpha_min/0x4/0x8A8/
        /M/f32 m_frame_scale_max/0x4/0x8AC/
        /M/f32 m_frame_scale_min/0x4/0x8B0/
        /M/f32 m_scale_ini/0x4/0x8B4/
        /M/f32 m_scale_max/0x4/0x8B8/
        /M/f32 m_scale_min/0x4/0x8BC/
        /M/f32 m_alpha_near/0x4/0x8C0/
        /M/f32 m_alpha_dist/0x4/0x8C4/
        /M/sead::Color4f m_color/0x10/0x8C8/
        /U/bool/0x1/0x8E4/
    /END/
}