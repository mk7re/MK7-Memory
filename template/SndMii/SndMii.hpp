#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(SndMii)
{

// NOTE: Name is made up
enum EType : u32 {
    TYPE_MIM,      // Male (Red, Orange, Pink)
    TYPE_MIM2,     // Male (Yelow, Yellow-green, Sky-blue)
    TYPE_MIM3,     // Male (Green, Blue, Purple)
    TYPE_MIM4,     // Male (Brown, White, Black)
    TYPE_MIF,      // Female (Red, Orange, Pink)
    TYPE_MIF2,     // Female (Yelow, Yellow-green, Sky-blue)
    TYPE_MIF3,     // Female (Green, Blue, Purple)
    TYPE_MIF4      // Female (Brown, White, Black)
};

EType getMiiTypeByPlayerId(s32);
EType getMiiTypeOnSelectMenu();

}