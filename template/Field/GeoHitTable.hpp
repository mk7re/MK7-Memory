#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@GeoHitTable/SIZE@0xC/
    public:
        GeoHitTable(const char *);

        /M/u16 m_num_rows/0x2/0x0/
        /M/u16 m_num_columns/0x2/0x2/
        /M/void **m_entries_array/0x4/0x4/
        // The list of indices of the rows where the value is found.
        /M/u16 *m_row_idx_list/0x4/0x8/
    /END/
}