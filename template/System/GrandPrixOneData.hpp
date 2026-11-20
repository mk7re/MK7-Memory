#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GrandPrixOneData/SIZE@0x1/
    public:
        GrandPrixOneData() : completed{}, rank{}, trophy{} {}
        void init() { completed = rank = trophy = {}; }

        /M/u8 completed : 1, rank : 3, trophy : 2, _unknown : 2/0x1/0x0/
    /END/
}