#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "ObjectBase.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@ObjectBaseNoModel/SIZE@0xA0/BASE@ObjectBase/BSIZE@0xA0/
    public:
        virtual void createObjectDefault(ObjectCreateArgument &);
        virtual void createObjectAnim(const ObjectCreateArgument &);
        virtual void createObjectExtend(const ObjectCreateArgument &);
        virtual void createObjectAnimExtend(const ObjectCreateArgument &);
        virtual void createDefaultMaterialAnim(const ObjectCreateArgument &);
        virtual void initObjectAnim(const ObjectCreateArgument &);
        virtual void beginRegistAnimation(s32);
        virtual void endRegistAnimation();
        
        virtual void createCollision(SObjectCollisionSet *);
        virtual const char *getResourceName();
    /END/
}