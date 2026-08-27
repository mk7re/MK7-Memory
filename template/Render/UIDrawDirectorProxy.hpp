#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

BEGIN_NAMESPACE(Render)
{
    // Size is 0x40 in `ALL_DLP`
    /START_CLASS/NAME@UIDrawDirectorProxy/SIZE@0x44/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1

        /M/UIDrawDirector *m_ui_draw_director/0x4/0x3c/
#if GAME_VERSION != ALL_DLP
        /M/System::MobiClipThread *m_mobiclip_thread/0x4/0x40/
#endif
    /END/
}