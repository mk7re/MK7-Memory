#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Field/Entry/EnemyPoint.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@PointParam/SIZE@0x10/
    public:
        void setParam(Field::MapdataEnemyPoint *);

        bool isUseKinoko() const;
        bool isContinueDrift() const;
        bool isEndDrift() const;
        bool isDisableDrift() const;
        bool isAbleToMiniTurbo() const;

        /M/Field::MapdataEnemyPointData::EMushroomSetting m_mushroom_setting/0x2/0x0/
        /M/Field::MapdataEnemyPointData::EDriftSetting m_drift_setting/0x1/0x2/
        /M/u32 m_flags/0x4/0x4/ // See the `Field::EnemyPointFlags` enum
        /M/f32 m_corner/0x4/0x8/
        /U/u32/0x4/0xC/
    /END/
}
