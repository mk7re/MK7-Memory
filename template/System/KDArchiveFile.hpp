#pragma once

#include "../types.hpp"
#include "EArchiveID.hpp"
// #include "resource/seadSharcArchiveRes.h"
// #include "resource/seadResourceMgr.h"
#include "filedevice/seadFileDevice.h"

BEGIN_NAMESPACE(System)
{
    // TODO: Derives of KDArchiveBase
    /START_CLASS/NAME@KDArchiveFile/SIZE@0x9C/
    public:
        /M/void* m_res_manager/0x4/0x28/ // TODO: Convert to sead::ResourceMgr* when asserts fixed
        /M/char* m_archive_name/0x4/0x2C/
        /M/u32 m_archive_name_size/0x4/0x30/
        /M/EArchiveID m_archive_id/0x4/0x34/
        /M/void* m_sarc_data/0x4/0x38/
        /M/u32 m_sarc_size/0x4/0x3C/
        /M/u8 m_sarc[0x50]/0x50/0x40/ // TODO: Convert to sead::SharcArchiveRes when it matches properly
        /M/sead::FileDevice* m_filedevice/0x4/0x90/
        /M/sead::FileDevice* m_patch_filedevice/0x4/0x94/
        /U/void*/0x4/0x98/ // Related to Patch
    /END/
}