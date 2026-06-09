#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(SndMii)
{

// NOTE: Name is made up
enum class EType {
    TYPE_0,
    TYPE_1,
    TYPE_2,
    TYPE_3
};

EType getMiiTypeByPlayerId(s32);
EType getMiiTypeOnSelectMenu();

}