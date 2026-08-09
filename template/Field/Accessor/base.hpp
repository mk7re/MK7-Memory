#pragma once

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>

#include "../../types.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@MapdataAccessorBase/TEMPLATE@template <typename Entry, typename Data>/SIZE@0x18/SIZEOF@MapdataAccessorBase<void *, void *>/VTABLE@True/
    public:
        virtual void constructLocal(); // 0

        /M/sead::Buffer<Data> m_datas/0x8/0x4/
        /M/sead::PtrArray<Entry> m_entries/0xC/0xC/
    /END/
}