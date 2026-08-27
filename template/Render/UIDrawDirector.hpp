#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Render)
{
    // Size is 0x9C0 in `ALL_REV0`, `ALL_KIOSK` and `ALL_DLP`
    /START_CLASS/NAME@UIDrawDirector/SIZE@0x9BC/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1

        /M/bool m_fade_under_dialog/0x1/0x4cc/
        /M/UI::NwlytResourceAccessor *m_layout_resource_accessor/0x4/0x64c/
    /END/
}