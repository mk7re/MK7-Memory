#pragma once

#include "../Object/ActorEngine.hpp"
#include "../Object/TDirectorList.hpp"
#include "../Object/TLinkSocket.hpp"

#include "../System/RootSystem.hpp"

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@FieldDirector/SIZE@0x2AC/BASE@Object::TDirectorList<Object::Actor3DMdlList, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
    public:
        /M/CourseInfo *m_course_info/0x4/0x38/
        /M/FieldModel *m_field_model/0x4/0x40/
        /M/QuadTree *m_quad_tree/0x4/0x50/
    /END/

    inline static auto GetDirector()
    {
        return System::g_root_system->get_field_director();
    }
}