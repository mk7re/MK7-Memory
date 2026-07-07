#pragma once

#include "../types.hpp"

#include "../CFL/cfl.hpp"
#include "DispPart.hpp"

#include <container/seadPtrArray.h>
#include <math/seadMatrix.h>
#include <heap/seadHeap.h>
#include <math/seadVector.h>
#include <nw/gfx/res/ResBlend.hpp>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@DispWing/SIZE@0x114/BASE@DispPart/BSIZE@0x8/
    public:
        /START_STRUCT/NAME@ConstructArgs/SIZE@0x24/BASE@DispPart::ConstructArgsBase/BSIZE@0x24/
        /END/

        DispWing(const ConstructArgs &);
        void applyMiiFavoriteColor(const CFLFavoriteColor &);
        void applyColor(s32);
        void boneFuncWorld(s32, sead::Matrix34f *);
        void calcOpenScale();
        void calcWaveScale();
        void initWaveScale();
        void setGhostAlpha(f32);
        void calcOffsetView1st(sead::Matrix34f *, f32, const sead::Vector3f &);
        void initWaveParameter();
        void prepareColorTable();
        void switchMeshVisible(bool);
        void setupResModelForGhost_(void * /* nw::gfx::res::ResModel */, void * /* nw::gfx::res::ResGraphicsFile */, sead::Heap *);
        void init();
        f32 getCameraOfstY() const;
        f32 getDriverGShock() const;
        void replaceVariationTexture_(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResModel */, s32, s32, bool) const;

        /M/f32 m_camera_ofst_y/0x4/0x30/
        /M/f32 m_ghost_alpha/0x4/0x8c/
        /M/sead::PtrArray<nw::gfx::res::ResBlendOperation> m_res_blend_op_data/0xC/0x90/
    /END/
}