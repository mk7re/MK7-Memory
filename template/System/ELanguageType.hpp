#pragma once

#include "../types.hpp"
#include "../versions.h"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(System)
{
    enum class ELanguageType : u8
    {
        JAPANESE,       // jp
        ENGLISH,        // ee (ALL_EUR) / ue (ALL_USA)
        GERMAN,         // ed
        FRENCH,         // ef (ALL_EUR) / uf (ALL_USA)
        SPANISH,        // es (ALL_EUR) / us (ALL_USA)
        ITALIAN,        // ei
        DUTCH,          // en
        RUSSIAN,        // er
        PORTUGUESE,     // ep
        SIMP_CHINESE,   // cc / ch (ALL_V11 / ALL_V12)
        KOREAN,         // kr
#if GAME_VERSION == ALL_V11 || GAME_VERSION == ALL_V12
        TRAD_CHINESE,   // tw
#endif

        LANGUAGE_MAX
    };

    // 0x005e0cd8 (VERSION_EUR_DLP)
    // 0x0065d078 (VERSION_USA_REV1)
    const char *PostfixStrings[static_cast<u32>(ELanguageType::LANGUAGE_MAX)];

    ELanguageType GetLanguageType();
    sead::SafeString GetLanguagePostfixString();
}