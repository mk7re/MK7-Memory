

#include "../types.hpp"
#include <container/seadBuffer.h>
#include <heap/seadDisposer.h>
#include <heap/seadExpHeap.h>
#include "EArchiveID.hpp"
#include "KDArchiveFile.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KDArchive/SIZE@0x34/BASE@sead::IDisposer/BSIZE@0x10/VTABLE@True/
    public:
        /M/EArchiveID m_archive_id/0x4/0x10/
        /M/sead::ExpHeap* m_expheap/0x4/0x14/
        /M/u32 m_alloc_align/0x4/0x18/
        /M/u32 m_alloc_size/0x4/0x1C/
        /M/sead::Buffer<System::KDArchiveFile*> m_archives/0x8/0x20/
        /M/bool m_mounted/0x1/0x28/
    /END/
}
