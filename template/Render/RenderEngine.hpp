#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

#include "../Object/Actor.hpp"
#include "../Object/ActorEngine.hpp"
#include "../Object/TDirectorList.hpp"

BEGIN_NAMESPACE(Render)
{
    // NOTE: Size: 0x84 in ALL_DLP
    /START_CLASS/NAME@RenderEngine/SIZE@0x88/BASE@Object::TDirectorList<Object::Actor, Object::ActorEngine>/BSIZE@0x1C/
    public:
        /START_STRUCT/NAME@Argument/SIZE@0xC/
        /END/

        // NOTE: guessed name
        /START_STRUCT/NAME@SDirectorList/SIZE@0x44/
            /M/Renderer *m_renderer/0x4/0x8/
            /M/Screen *m_screen_1/0x4/0xc/      // Left screen?
            /M/Screen *m_screen_2/0x4/0x10/     // Right screen?
            /M/Screen *m_screen_3/0x4/0x14/     // Bottom screen?
            /M/DrawMdlMgr *m_draw_mdl_mgr/0x4/0x18/
            /M/UIDrawDirector *m_ui_draw_director/0x4/0x20/
            /M/void *m_fog_manager/0x4/0x28/
            /M/Effect::ParticleDrawer *m_particle_drawer/0x4/0x30/
            /M/VRAMHeapMgr *m_vram_heap_mgr/0x4/0x38/
            /M/void *m_depth_buffer_reader/0x4/0x40/
        /END/

        using creator_t = void (*)(RenderEngine *, SDirectorList *);
        
        /M/SDirectorList *m_director_list/0x4/0x1C/
        /M/creator_t m_creator_list[8]/0x20/0x20/
#if GAME_VERSION != ALL_DLP
        /M/System::MobiClipThread *m_mobiclip_thread/0x4/0x84/
#endif
    /END/
}