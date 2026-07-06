#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Render)
{
    /START_CLASS/NAME@VRAMCollection/SIZE@0x10/
    public:
        VRAMCollection();
        void createHeapA(System::GfxFrmHeap *, s32);
        void createHeapB(System::GfxFrmHeap *, s32);

        /M/System::GfxFrmHeap *m_heap_a/0x4/0x0/
        /M/System::GfxFrmHeap *m_heap_b/0x4/0x4/
        /U/s32/0x4/0x8/
        /U/u8/0x1/0xc/
        /U/u8/0x1/0xd/
    /END/
}