#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../System/EArchiveID.hpp"
#include "../Render/EVRAMModel.hpp"

#include <heap/seadDisposer.h>
#include <heap/seadHeap.h>
#include <math/seadMatrix.hpp>
#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Render)
{
    /START_CLASS/NAME@DrawMdl/SIZE@0xC4/BASE@sead::IDisposer/BSIZE@0x10/VTABLE@True/
    public:
        enum EFlags : u32 {
            DRAWMDL_FLAG_VISIBLE = 0x00000001
        };

        virtual ~DrawMdl();

        DrawMdl();
        void setPoseMtx(const sead::Matrix34f &);
        void setVisible(bool);
        void createModel(Render::DrawMdlCreateArgs &);
        void initKeyCache();
        void InitKeyCache(void * /* nw::gfx::Model */ *);
        void RetouchModel(void * /* nw::gfx::Model */ *, const Render::DrawMdlCreateArgs &);
        void pauseAnimation();
        void RetouchResModel(void * /* nw::gfx::res::ResModel */, const Render::DrawMdlCreateArgs &);
        void createAnimation(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, s32);
        void createAnimation(void * /* nw::anim::res::ResAnim */, s32);
        void createAnimation(const sead::SafeString &, const sead::SafeString &, s32, System::EArchiveID);
        void createAnimation(const sead::SafeString &, s32, System::EArchiveID);
        void SetLocationFlags(void * /* nw::gfx::res::ResTexture */, Render::VRAMCollection *, bool);
        void unmountSceneTree_();
        void loadResourceDirect(const sead::SafeString &, bool, System::EArchiveID, sead::Heap *);
        bool tryCreateAnimation(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, s32);
        bool tryCreateAnimation(const sead::SafeString &, const sead::SafeString &, s32, System::EArchiveID);
        void attachToParentNode_();
        void beginRegistAnimation(s32);
        bool changeAnimationBlend(s32, f32, f32, bool);
        void setFrameMaterialAnim(f32);
        void updateAnimationBlend();
        void SetLocationFlagsFCRAM(const Render::DrawMdlCreateArgs &, void * /* nw::gfx::res::ResGraphicsFile */);
        void SetVertexLocationFlag(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResModel */, bool, s32 *, s32 *);
        bool changeAnimationDirect(s32, f32);
        void pauseMaterialAnimation();
        void *GetResPixelBasedTexture(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResTexture */);
        bool ReplaceTextureReference(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, void * /* nw::gfx::res::ResGraphicsFile */, Render::EVRAMModel, System::NWAllocator *, bool);
        bool ReplaceTextureReference(void ** /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, const sead::SafeString &, System::NWAllocator *);
        bool ReplaceTextureReference(void *** /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, const sead::SafeString &, s32);
        bool ReplaceTextureReference(void **** /* nw::gfx::res::ResModel */, const sead::SafeString &, void * /* nw::gfx::res::ResGraphicsFile */, Render::EVRAMModel, System::NWAllocator *, s32, bool);
        bool ReplaceTextureReference(void ***** /* nw::gfx::res::ResModel */, const sead::SafeString &, const sead::SafeString &, s32);
        void changeMaterialAnimation(s32, f32);
        void createMaterialAnimation(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, s32);
        void createMaterialAnimation(void * /* nw::anim::res::ResAnim */, s32);
        void createMaterialAnimation(const sead::SafeString &, const sead::SafeString &, s32, System::EArchiveID);
        void resumeMaterialAnimation();
        void updateAnimationForcibly();
        void InvokePreCalculateMatrix(void * /* nw::gfx::Skeleton */ *, s32);
        void InvokePostCalculateMatrix(void * /* nw::gfx::Skeleton */ *, s32);
        void SetVertexLocationFlagFCRAM(void * /* nw::gfx::res::ResGraphicsFile */, bool);
        bool tryCreateMaterialAnimation(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &, s32);
        void SetTextureLocationFlagInner(void * /* nw::gfx::res::ResGraphicsFile */, void * /* nw::gfx::res::ResModel */, void * /* nw::gfx::res::ResTexture */, bool, bool, s32 *, s32 *);
        bool checkMaterialAnimationExist(void * /* nw::gfx::res::ResGraphicsFile */, const sead::SafeString &);
        void CreateMaterialActivatorFixed(void * /* nw::gfx::Model */ *, void * /* nw::os::IAllocator */ *);
        void beginRegistMaterialAnimation(s32);
        void *createMaterialAnimationLeader();
        void followMaterialAnimationLeader(void * /* Render::DrawMdl::MatAnimLeader */ *);
        void updateMaterialAnimationForcibly();
        void RetouchResModelForRejectingThunder(void * /* nw::gfx::res::ResModel */);
        bool isStepOver(f32) const;
        void *getResTexture(void * /* nw::gfx::res::ResMaterial */, s32) const;
        void *getResTexture(sead::SafeString) const;

        /M/sead::Matrix34f *m_pos_mtx/0x4/0x40/
        /M/s32 m_anim_idx/0x4/0x74/
        /M/f32 m_material_anim_idx/0x4/0xa4/ // TODO: Double check is this is a f32 or a s32
        /M/s32 m_material_anim_num/0x4/0xa8/
        /M/bool m_material_anim_exists/0x1/0xac/
        /M/u32 m_flags/0x4/0xc0/            // See the `EFlags` enum
    /END/
}