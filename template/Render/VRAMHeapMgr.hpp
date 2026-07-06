#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Render)
{
    /START_CLASS/NAME@VRAMHeapMgr/SIZE@0x8/
    public:
        /START_STRUCT/NAME@SceneVRAM/SIZE@0xC/
        /END/

        VRAMHeapMgr(const SceneVRAM *);

        /M/s32 m_collection_num/0x4/0x0/
        /M/VRAMCollection *m_collection/0x4/0x4/
    /END/
}