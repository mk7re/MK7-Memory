#pragma once

#include "../types.hpp"

#include "TIndLinkList.hpp"

BEGIN_NAMESPACE(Util)
{
    /START_CLASS/NAME@TLinkList/TEMPLATE@template <class T>/SIZE@0x14/SIZEOF@TLinkList<void>/VTABLE@True/BASE@TIndLinkList<T>/BSIZE@0x10/
    public:
        virtual bool append(TLinkNode<T> *); // 0
        virtual bool release(TLinkNode<T> *); // 2

        /M/u16 m_0x10/0x2/0x10/
    /END/
}