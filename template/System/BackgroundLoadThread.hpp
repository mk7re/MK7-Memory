#pragma once

#include "../types.hpp"
#include "heap/seadDisposer.h"
#include "../RaceSys/CourseArchiveManager.hpp"

BEGIN_NAMESPACE(System)
{

    // TODO: Inherits from System::KDThread, but the
    // size depends on the version.
    // Current size is from EUR REV2
    /START_CLASS/NAME@BackgroundLoadThread/SIZE@0xEC/
    public:
        /M/sead::IDisposer m_disposer/0x10/0xAC/
        /M/RaceSys::CourseArchiveManager* m_course_archive_manager/0x4/0xC0/
    /END/
}