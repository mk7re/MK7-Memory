#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "eMapdataGeoObjID.hpp"

#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@SFieldObjCreatorFuncNode/SIZE@0x10/
        static bool D_005f5d50;                                                     // 0x005f5d50 (VERSION_EUR_DLP)
        static SFieldObjCreatorFuncNode *D_00608870;                                // 0x00608870 (VERSION_EUR_DLP)
        static sead::PtrArray<SFieldObjCreatorFuncNode> s_creator_func_node_array;  // 0x00608864 (VERSION_EUR_DLP)

        u32 calcSortKey();
        static s32 compare(const SFieldObjCreatorFuncNode *, const SFieldObjCreatorFuncNode *);

        /M/u32 m_id/0x4/0x0/    // See the `eMapdataGeoObjID` enum
        /M/ObjectBase *(*m_obj_creator_function)(ObjectCreateArgument &)/0x4/0x4/
        /M/Object::DTIClassInfo *m_obj_dticlass/0x4/0x8/
        /M/u32 m_sort_key/0x4/0xc/
    /END/
}