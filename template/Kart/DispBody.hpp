#pragma once

#include "../types.hpp"

#include "../CFL/cfl.hpp"
#include "../RaceSys/EShyGuyColor.hpp"
#include "DispPart.hpp"

#include <container/seadPtrArray.h>
#include <heap/seadHeap.h>
#include <nw/gfx/res/ResBlend.hpp>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@DispBody/SIZE@0x8C/BASE@DispPart/BSIZE@0x8/
    public:
        /START_STRUCT/NAME@ConstructArgs/SIZE@0x28/BASE@DispPart::ConstructArgsBase/BSIZE@0x24/
            /M/CFLFavoriteColor m_mii_favorite_color/0x4/0x24/
        /END/

        DispBody(const ConstructArgs &);
        void constructNormal_(const ConstructArgs &);
        void constructLod_(const ConstructArgs &);
        void setGhostAlpha(f32);
        void InitStaticResource();
        void initResMeshHandle_(s32);
        void setupResModelForGhost_(void * /* nw::gfx::res::ResModel */, void * /* nw::gfx::res::ResGraphicsFile */, sead::Heap *);
        void replaceShyGuyLodTexture_(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResModel */, RaceSys::EShyGuyColor) const;
        void replaceVariationTexture_(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResModel */, s32, s32, bool, CFLFavoriteColor) const;
        
        /M/f32 m_ghost_alpha/0x4/0x20/
        /M/sead::PtrArray<nw::gfx::res::ResBlendOperation> m_res_blend_op_data/0xC/0x24/
    /END/
}