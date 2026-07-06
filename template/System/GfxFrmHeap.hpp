#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GfxFrmHeap/SIZE@0x18/VTABLE@True/
    public:
        enum class EType : u8
        {
            VRAM_AREA_A,        // VRAM address ranges: 0x1f000000 - 0x1f300000
            VRAM_AREA_B,        // VRAM address ranges: 0x1f300000 - 0x1f600000
            VRAM_AREA_INVALID
        };

        virtual void freeAll();
        virtual u32 alloc(u32, u32);
        virtual void vf_0x08();
        virtual u32 getAllocatableSize(u32);
        virtual void setAnchor();
        virtual void backToAnchor();
        
        // Initial allocation position
        /M/u32 m_start/0x4/0x4/
        // Size of the heap
        /M/u32 m_size/0x4/0x8/
        // How far into the heap the next allocation will be placed
        /M/u32 m_cursor/0x4/0xc/
        // A saved copy of the current allocation offset
        /M/u32 m_anchor/0x4/0x10/
        /M/EType m_type/0x1/0x14/
    /END/
}