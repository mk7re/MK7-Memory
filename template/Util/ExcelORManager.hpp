#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../System/EArchiveID.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Util)
{
	/START_CLASS/NAME@ExcelORManager/SIZE@0x10/
	public:
        void load(System::ResourceLoader *, System::EArchiveID);

        /M/Kart::RawKartConstructInfoBin *m_raw_file/0x4/0x0/
        /U/s32/0x4/0x4/         // Field 0x08 of `System::ResourceLoader::LoadArg`
        /M/sead::SafeString m_filepath/0x8/0x8/
	/END/
}