#pragma once

#include "../types.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // The course's .div file: for each shape of the course model ("BADC" header, then "PAHS" with the shape count),
    // the XZ bounding rectangle of each of its index streams
    /START_CLASS/NAME@DivFile/SIZE@0x14/
    public:
        // "MRTS" block of one shape, followed by m_area_num SArea
        /START_STRUCT/NAME@SStream/SIZE@0x8/
            /M/u32 m_magic/0x4/0x0/
            /M/u16 m_area_num/0x2/0x4/         // number of index streams of the shape
            /M/u16 m_vertex_num/0x2/0x6/       // vertices of the shape
        /END/

        /START_STRUCT/NAME@SArea/SIZE@0x10/
            /M/sead::Vector2f m_min/0x8/0x0/   // X, Z
            /M/sead::Vector2f m_max/0x8/0x8/
        /END/

        void setFile(void *);
        void getMinMax(sead::Vector2f *, sead::Vector2f *, u16, u16);
        void getTotalMinMax(sead::Vector2f *, sead::Vector2f *);

        /M/void *m_file/0x4/0x0/
        /M/u16 m_stream_num/0x2/0x4/
        /M/sead::PtrArray<SStream> m_streams/0xC/0x8/
    /END/
}
