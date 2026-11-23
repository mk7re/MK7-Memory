#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GrandPrixOneData/SIZE@0x1/
    public:
        GrandPrixOneData() : completed{}, record{}, trophy{} {}
        void init() { completed = record = trophy = {}; }

        /M/u8 completed : 1, record : 3, trophy : 2, _unknown : 2/0x1/0x0/ // see RaceSys::GrandPrixData for field types
    /END/
}