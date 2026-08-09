#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    enum class eObjectModelType : u8
    {
        SIMPLE_MODEL,           // ObjectSimpleModelBase
        OBJECT_MODEL_TYPE_1,
        GENERATOR,              // ObjectGeneratorBase
        NO_MODEL,               // ObjectNoModelBase

        MAX
    };
}