#pragma once

#include "MessageString.hpp"
#include "../RaceSys/EEngineLevel.hpp"

#include <prim/seadSafeString.h>

BEGIN_NAMESPACE(UI)
{
    /START_STRUCT/NAME@MessageArg/SIZE@0x128/VTABLE@True/
        virtual void *getRuntimeTypeInfo() const;
        
        /M/MessageString m_message/0x4/0x4/
        /M/s32 m_message_char_count/0x4/0xC/
        /M/char16_t m_message_buffer[128]/0x100/0x10/
        /M/s32 m_numbers[2]/0x8/0x110/
    /END/

    /START_STRUCT/NAME@DashMessageArg/SIZE@0x128/BASE@MessageArg/BSIZE@0x128/VTABLE@True/
        void *getRuntimeTypeInfo() const;

        void setMiiName(const sead::WSafeString &);
        void setEngineLevel(RaceSys::EEngineLevel);
        void setNumber(s32, s32);
        void setString(const sead::WFixedSafeString<128> &);
        DashMessageArg();
    /END/
}