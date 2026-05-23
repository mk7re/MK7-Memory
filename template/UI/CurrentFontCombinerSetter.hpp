#pragma once

#include "../types.hpp"
#include "../forward.hpp"

BEGIN_NAMESPACE(UI)
{
    /START_STRUCT/NAME@CurrentFontCombinerSetter/SIZE@0x8/
    public:
        CurrentFontCombinerSetter(u8 /* nw::font::FontCombinerType */);
        ~CurrentFontCombinerSetter();

        /M/NwlytResourceAccessor *m_layout_resource_accessor/0x4/0x0/
        /M/u8 m_font_combiner_type/0x1/0x4/  // nw::font::FontCombinerType
    /END/
}