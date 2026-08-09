#pragma once

#include "../forward.hpp"

#include <math/seadMatrix.h>

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@SMapdataPosture/SIZE@0x24/
        // TODO: The symbol indicates that this function has no arguments,
        // but the assembly suggests it has an additional "SData *" argument?
        sead::Matrix33f getPosture() const;

        /M/sead::Matrix33f m_matrix/0x24/0x0/
    /END/
}