#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/Actor.hpp"
#include "ObjectBaseNoModel.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectNoModelBase/SIZE@0xA8/BASE@ObjectBaseNoModel, Object::Actor/BSIZE@0xA8/
    public:
        virtual void calcView();
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual void init();
        virtual void calc();

        ObjectNoModelBase(const ObjectCreateArgument &);
        Object::DTIClassInfo *getDTIClassStatic();
    /END/
}