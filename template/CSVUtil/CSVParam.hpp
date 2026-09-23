#pragma once

#include "../types.hpp"

#include "../System/EArchiveID.hpp"

#include <math/seadVector.h>
#include <heap/seadHeap.h>
#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(CSVUtil)
{
    /START_CLASS/NAME@CSVParam/SIZE@0x128/
    public:
        CSVParam(System::EArchiveID, const sead::SafeString &, const sead::SafeString &, const sead::SafeString &, const sead::SafeString &, sead::Heap *);
        f32 getData_f32(s32, s32) const;
        s32 getData_int(s32, s32) const;
        const sead::Vector3f &getData_vec3(s32, s32) const;

        /M/void *m_raw_file/0x4/0x0/
        // The start of the string data
        /M/void *m_raw_file_string_data/0x4/0x4/
        // The start of the max numeric data (floats). Aka `ORRange` in MK8
        /M/void *m_raw_file_limit_data/0x4/0x8/
        // The start of the numeric data
        /M/void *m_raw_file_value_data/0x4/0xc/
        /U/s32/0x4/0x10/
        /U/s32/0x4/0x14/
        /M/sead::FixedSafeString<32> m_directory/0x2c/0x18/
        /M/sead::FixedSafeString<32> m_filename/0x2c/0x44/
        /M/sead::FixedSafeString<32> m_directory_2/0x2c/0x70/
        /M/sead::FixedSafeString<128> m_include_directory/0x8c/0x9c/
	/END/
}