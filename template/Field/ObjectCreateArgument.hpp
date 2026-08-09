#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../Render/DrawMdlCreateArgs.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@ObjectCreateArgument/SIZE@0x138/
        ObjectCreateArgument(const ObjectCreateArgument &);

        /M/MapdataGeoObj *m_mapdata/0x4/0x0/
        /M/ObjectParameter *m_object_parameter/0x4/0x4/
        /M/Render::DrawMdlCreateArgs m_model_create_args/0x124/0x8/
        /M/void *m_model_resource/0x4/0x12c/
        /M/ObjectGeneratorBase *m_object_generator/0x4/0x130/
        /U/s32/0x4/0x134/
    /END/
}