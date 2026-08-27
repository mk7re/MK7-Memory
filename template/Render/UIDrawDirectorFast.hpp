#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Render)
{
    // Size is 0xA30 in `ALL_REV0`, `ALL_KIOSK` and `ALL_DLP`
    /START_CLASS/NAME@UIDrawDirectorFast/SIZE@0xA2C/BASE@UIDrawDirector/BSIZE@0x9BC/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
    /END/
}