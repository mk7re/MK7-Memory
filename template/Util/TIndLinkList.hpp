#pragma once

#include "../types.hpp"

#include "TLinkNode.hpp"

BEGIN_NAMESPACE(Util)
{
    /START_CLASS/NAME@TIndLinkList/TEMPLATE@template <class T>/SIZE@0x10/SIZEOF@TIndLinkList<void>/VTABLE@True/
    public:
        virtual bool append(TLinkNode<T> *); // 0
        virtual bool prepend(TLinkNode<T> *); // 1
        virtual bool release(TLinkNode<T> *); // 2

        /M/TLinkNode<T> *m_head/0x4/0x4/
        /M/TLinkNode<T> *m_tail/0x4/0x8/
        /M/s32 m_count/0x4/0xC/
    /END/
}