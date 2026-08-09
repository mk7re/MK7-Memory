#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "ObjectNoModelBase.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectWaterFix/SIZE@0xA8/BASE@ObjectNoModelBase/BSIZE@0xA8/
    public:
        static eMapdataGeoObjIDIndex s_object_enum_index;   // 0x005e3590 (VERSION_EUR_DLP)

        virtual void initObj();
        virtual eMapdataGeoObjIDIndex getObjectEnumIndex();
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual Object::DTIClassInfo *getDTIClassInfo() const;

        Object::DTIClassInfo *getDTIClassStatic();
        static ObjectBase *creator(ObjectCreateArgument &);
    /END/
}