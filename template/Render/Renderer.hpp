#pragma once

#include "../forward.hpp"
#include "../Object/Actor.hpp"

BEGIN_NAMESPACE(Render)
{
    /START_CLASS/NAME@Renderer/SIZE@0x1C/BASE@Object::Actor/BSIZE@0x8/
    public:
        enum class ERenderLocale : u8 {
            LEFT,       // Top screen (left eye)
            RIGHT,      // Top screen (right eye)
            SUB         // Bottom screen
        };

        virtual DTIClassInfo *getDTIClassInfo() const;
		virtual DTIClassInfo *getDTIClass() const;
        virtual void init();
		virtual void calc();
		virtual void render();
		virtual void renderMainL();
		virtual void renderMainR();
		virtual void renderSub();
        virtual void selectCamera();
        virtual void initInner();
        virtual void renderMainInner(Render::Renderer::ERenderLocale);

        Renderer();

        /U/s32/0x4/0x8/
        /U/s32/0x4/0xc/
        /U/s32/0x4/0x10/
        /M/Render::DrawMdlMgr *m_draw_mdl_mgr/0x4/0x14/
        /M/Camera::CameraBase *m_camera/0x4/0x18/
    /END/
}