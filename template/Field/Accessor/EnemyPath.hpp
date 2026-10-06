#pragma once

#include "../../forward.hpp"
#include "base.hpp"

#include "../Entry/EnemyPath.hpp"

#include "../CourseInfo.hpp"
#include "../FieldDirector.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@MapdataEnemyPathAccessor/SIZE@0x20/BASE@MapdataAccessorBase<MapdataEnemyPath, MapdataEnemyPath::SData>/BSIZE@0x18/
    public:
        void setupObjLink_();
        void setupPathDepth();
        void setupPathPointLink(MapdataEnemyPointAccessor *);

        /M/MapdataEnemyPointAccessor *m_enemy_point_accessor/0x4/0x18/
        /M/s32 m_depth_num/0x4/0x1C/ // highest m_depth of the paths + 1
    /END/

    inline auto GetEnemyPathAccessor()
    {
        return GetDirector()->m_course_info->m_enemy_path_accessor;
    }
}