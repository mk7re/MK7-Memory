#pragma once

#include "../types.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(System)
{
    enum class ELanguageType : u8
    {
        JAPANESE,
        ENGLISH,
        GERMAN,
        FRENCH,
        SPANISH,
        ITALIAN,
        DUTCH,
        RUSSIAN,
        PORTUGUESE,
        CHINESE,
        KOREAN,

        LANGUAGE_MAX
    };

    ELanguageType GetLanguageType();
    sead::SafeString GetLanguagePostfixString();
}