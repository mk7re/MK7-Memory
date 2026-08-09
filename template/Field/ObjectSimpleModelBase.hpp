#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ObjectBase.hpp"
#include "../Object/Actor3DMdl.hpp"
#include "../System/EArchiveID.hpp"

#include <prim/seadSafeString.hpp>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectSimpleModelBase/SIZE@0x188/BASE@ObjectBase, Object::Actor3DMdl/BSIZE@0xF8/
    public:
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual void calcView();
        virtual void createObjectDefault(ObjectCreateArgument &);
        virtual void createObjectAnim(const ObjectCreateArgument &);
        virtual void createObjectExtend(const ObjectCreateArgument &);
        virtual void createObjectAnimExtend(const ObjectCreateArgument &);
        virtual void createDefaultMaterialAnim(const ObjectCreateArgument &);
        virtual void createMaterialAnimLeader(const ObjectCreateArgument &);
        virtual void initObjectAnim(const ObjectCreateArgument &);
        virtual void beginRegistAnimation(s32);
        virtual void endRegistAnimation();
        virtual void calc();
        virtual void init();
        virtual void updateMtx();
        virtual void updateLodFlag();
        virtual void calcLod();
        virtual void calcVisibility();
        virtual void calcShadow();
        virtual void calcWhenInvisible();
        virtual void loadResFile(ObjectCreateArgument &);
        virtual s32 getSpecialLightSetIndex() const;
        virtual void registSharedModel(void * /* nw::gfx::Model * */);
        virtual void registSharedModelLod(void * /* nw::gfx::Model * */, s32);
        virtual bool loadSkeletalAnim(const sead::SafeString *, s32);
        virtual bool loadSkeletalAnim(const sead::SafeString &);
        virtual bool loadMaterialAnim(const sead::SafeString &, s32);
        virtual void initQTClipContext();
        virtual void initClipParam_forNonModel();
        virtual void updateQTClipContext();
        virtual void clearShadowUpdate();
        virtual ObjectParameter::Parameter *getParameterForShare();

        ObjectSimpleModelBase(const ObjectCreateArgument &);
        void createLODModel_(const sead::SafeString &);
        bool isResourceExist(const char *);
        Object::DTIClassInfo *getDTIClassStatic();
        void create_DrawMdlArgs(ObjectCreateArgument &);
        void setClipParam_margin(sead::Vector3f);
        bool isMaterialAnimExist_();
        void updateClipParam_final();
        void createModelAfterInner_(const sead::SafeString &);
        void initClipParam_fromAABB();
        void create_DrawMdlArgsFinal(Render::DrawMdlCreateArgs &);
        void updateClipParam_byScale();
        void create_DrawMdlArgsInner_(const void * /* nw::gfx::res::ResGraphicsFile & */, Render::DrawMdlCreateArgs &, const sead::SafeString &);
        void calcQTV();
        void setupLight(Render::DrawMdl *);

        /M/s32 num_skeletal_animations/0x4/0xf8/
        /M/Render::DrawMdl *m_model_lod_state_medium/0x4/0x114/
        /M/Render::DrawMdl *m_model_lod_state_low/0x4/0x118/
        /M/Render::DrawMdl *m_model_lod_state_high/0x4/0x11c/
        /M/ClipContext *m_clip_context/0x4/0x120/
        /U/sead::Vector3f/0xc/0x124/
        /U/sead::Vector3f/0xc/0x130/
        /M/sead::Vector3f m_clip_param_margin/0xc/0x13c/
        /U/sead::Vector3f/0xc/0x148/
        /U/sead::Vector3f/0xc/0x154/
        /U/sead::Vector3f/0xc/0x160/
        /U/sead::Vector3f/0xc/0x16c/
        /U/bool/0x1/0x178/
        /U/bool/0x1/0x179/
        /U/u32/0x4/0x17c/
        /M/System::EArchiveID m_archive_id/0x4/0x180/
        /U/bool/0x1/0x184/
        /M/u8 m_state/0x1/0x185/
        // Delay before the become active after the start of the countdown
        /M/u16 m_start_delay/0x2/0x186/
    /END/
}