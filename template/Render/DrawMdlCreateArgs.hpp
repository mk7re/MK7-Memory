#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../System/EArchiveID.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Render)
{
    /START_STRUCT/NAME@DrawMdlCreateArgs/SIZE@0x124/
        // These values are correlated with the `nw::gfx::Model::BufferOption` enum
        enum EModelBufferOption : u32 {
            FLAG_BUFFER_TEXTURE_MAPPER = 0x0001,
            FLAG_BUFFER_TEXTURE_COORDINATOR = 0x0002,
            FLAG_BUFFER_SCENE_ENVIRONMENT = 0x0004,
            FLAG_BUFFER_MATERIAL_COLOR = 0x0008,
            FLAG_BUFFER_FRAGMENT_OPERATION = 0x0010,
        };

        DrawMdlCreateArgs();
        void SetLoadInfo(const sead::SafeString &, s32, bool);
        void SetPathInfoNoLoad(const sead::SafeString &);

        /M/sead::FixedSafeString<128> m_resource_path/0x8c/0x0/
        /M/bool m_is_detail/0x1/0x8c/   // TODO: Double check
        // If `true`, we already have resource and resourceModel loaded and stored in the struct,
        // so we don't have to load them again
        /M/bool m_load_resource_direct/0x1/0x8d/
        /M/void *m_res_graphics_file/0x4/0x90/  // nw::gfx::res::ResGraphicsFile
        /M/void *m_res_model/0x4/0x94/          // nw::gfx::res::ResModel
        // If the .bcmdl has many CMDL entries, then this corresponds to the index of the specific CMDL
        // we want to load
        /M/s32 m_res_model_idx/0x4/0x98/
        /M/sead::FixedSafeString<64> m_model_name/0x4c/0x9c/
        /U/s32/0x4/0xe8/
        /M/u32 m_model_buffer_option/0x4/0xec/  // See the `EModelBufferOption` enum
        /U/s32/0x4/0xf0/
        /M/void *m_model/0x4/0xf4/              // nw::gfx::Model *
        /M/s32 m_material_anim_idx/0x4/0xf8/
        /U/u8/0x1/0xfc/
        /U/u8/0x1/0xfd/
        /U/u8/0x1/0xfe/
        /U/u8/0x1/0xff/
        /M/s32 m_render_priority_opa_start/0x4/0x100/
        /M/s32 m_render_priority_opa_end/0x4/0x104/
        /U/s32/0x4/0x108/
        /U/s32/0x4/0x10c/
        /M/Render::VRAMCollection *m_vram_collection/0x4/0x110/
        /U/s32/0x4/0x114/
        /U/u8/0x1/0x118/
        /U/bool/0x1/0x119/
        /U/bool/0x1/0x11a/
        /U/u8/0x1/0x11b/
        /U/u8/0x1/0x11c/
        /U/u8/0x1/0x11d/
        /U/u8/0x1/0x11e/
        /U/u8/0x1/0x11f/
        /M/System::EArchiveID m_archive_id/0x4/0x120/
    /END/
}