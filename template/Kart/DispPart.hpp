#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "../RaceSys/EScrewID.hpp"

#include <heap/seadHeap.h>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@DispPart/SIZE@0x8/
    public:
        /START_STRUCT/NAME@ConstructArgsBase/SIZE@0x24/
            /M/bool m_is_detail/0x1/0x0/
            /M/bool m_is_ghost/0x1/0x1/
            /U/u8/0x1/0x2/
            /U/u8/0x1/0x3/
            /M/s32 m_player_idx/0x4/0x4/
            /M/RaceSys::EDriverID m_driver/0x4/0x8/
            /M/RaceSys::EBodyID m_body/0x4/0xc/
            /M/RaceSys::ETireID m_tire/0x4/0x10/
            /M/RaceSys::EWingID m_wing/0x4/0x14/
            /M/RaceSys::EScrewID m_screw/0x4/0x18/
            /M/sead::Heap *m_heap/0x4/0x1c/
            /U/s32/0x4/0x20/
        /END/

        /START_STRUCT/NAME@CreateArgs/SIZE@0x28/
            CreateArgs(const ConstructArgsBase &);

            /M/ConstructArgsBase *m_construct_args/0x4/0x0/
            /M/void *m_res_graphics_file/0x4/0x4/   // nw::gfx::res::ResGraphicsFile *
            /M/void *m_res_model/0x4/0x8/           // nw::gfx::res::ResModel *
            /U/s32/0x4/0xc/
            /U/s32/0x4/0x10/
            /U/s32/0x4/0x14/
            /M/u32 m_model_flags/0x4/0x18/          // Render::DrawMdl's `m_flags`
            /M/s32 m_render_priority_opa_start/0x4/0x1c/
            /M/s32 m_render_priority_opa_end/0x4/0x20/
            /M/void *m_model/0x4/0x24/              // nw::gfx::Model *
        /END/

        void replaceTexture(void * /* nw::gfx::res::ResGraphicsFile */, s32, sead::Heap *);
        bool HasGhostMaterial(void * /* nw::gfx::res::ResModel */);
        static void *GetGhostResGraphicsFile();
        void create(const CreateArgs &);

        /M/Render::DrawMdl *m_model/0x4/0x0/
        /M/bool m_is_ghost/0x1/0x4/
        /M/bool m_is_invisible/0x1/0x5/
    /END/
}