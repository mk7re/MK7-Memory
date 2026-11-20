#pragma once

#include "../types.hpp"

#include "GrandPrixOneData.hpp"

#include "../RaceSys/EEngineLevel.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GrandPrixCupData/SIZE@0x4/
    public:
        GrandPrixCupData();
        void init();

        /M/GrandPrixOneData m_grand_prix_one_data[std::to_underlying(RaceSys::EEngineLevel::MAX) + 1]/0x4/0x0/ // 50cc, 100cc, 150cc, Mirror
    /END/
}