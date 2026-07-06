#pragma once

#include "Actor.hpp"

#include <math/seadMatrix.h>

BEGIN_NAMESPACE(Object)
{
    /START_CLASS/NAME@Actor3DMdl/SIZE@0x58/BASE@Actor/BSIZE@0x8/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const { return {}; }; // 0
		virtual Object::DTIClassInfo *getDTIClass() const { return {}; }; // 1
        virtual void init();    // NOTE: This is pure virtual here
        virtual void calc();    // NOTE: This is pure virtual here

        Actor3DMdl();
        void createModel(Render::DrawMdlCreateArgs &, Render::DrawMdl *);
        void beginRegistAnimation(s32);
        void endRegistAnimation();
        void beginRegistMaterialAnimation(s32);

        /M/sead::Vector3f m_scale/0xC/0x8/
        /M/sead::Matrix34f m_matrix/0x30/0x14/
        /M/bool m_update_scale/0x1/0x44/
        /U/s32/0x4/0x48/
        /U/s32/0x4/0x4C/
        /U/s32/0x4/0x50/
        /M/Render::DrawMdl *m_draw_mdl/0x4/0x54/
    /END/
}