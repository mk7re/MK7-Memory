#pragma once

#include "ObjectFixedModelBase.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectPuddle/SIZE@0x188/BASE@ObjectFixedModelBase/BSIZE@0x188/
    public:
        static eMapdataGeoObjIDIndex s_object_enum_index;   // 0x005e31c9 (VERSION_EUR_DLP)

        virtual void initObj();
        virtual eMapdataGeoObjIDIndex getObjectEnumIndex();
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual Object::DTIClassInfo *getDTIClassInfo() const;

        static ObjectBase *creator(ObjectCreateArgument &);
    /END/
}