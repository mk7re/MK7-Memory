#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ObjectBase.hpp"

#include "container/seadPtrArray.h"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectDirector/SIZE@0x1D0/BASE@Object::TDirectorArray<Object::Actor, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
		virtual void calc(); // 6
        virtual void createBeforeStructure(const Object::ArgumentObj *);
        virtual void initAfterStructure();
        virtual void calcBeforeStructure();
        virtual void calcAfterStructure();

        /M/sead::PtrArray<ObjectBase> m_objects/0xC/0x44/
        /M/Object::CoinManager *m_coin_manager/0x4/0xb8/
    /END/
}