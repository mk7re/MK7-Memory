#pragma once

#include "../types.hpp"
#include "ECourseID.hpp"

BEGIN_NAMESPACE(RaceSys)
{
    // TODO: Inherits from some kind of generic
    // ArchiveManager class.
    /START_CLASS/NAME@CourseArchiveManager/SIZE@0x2C/
    public:
        /M/bool m_override_cache/0x1/0x20/
        /M/bool m_with_trans/0x1/0x21/ // Enables download play course transmission
        /M/ECourseID m_to_load_course_id/0x4/0x24/
        /M/ECourseID m_cached_course_id/0x4/0x28/
    /END/
}