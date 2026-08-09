#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ObjectSimpleModelBase.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectFixedModelBase/SIZE@0x188/BASE@ObjectSimpleModelBase/BSIZE@0x188/
    public:
        virtual void calcView();
        virtual void calc();
        virtual void init();

        Object::DTIClassInfo *getDTIClassStatic();
    /END/
}