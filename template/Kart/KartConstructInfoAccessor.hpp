#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "KartPartsConstructParam.hpp"

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@KartConstructInfoAccessor/SIZE@0x1C/
	public:
		// NOTE: Name is made up
		enum class EDriverSizeType : u32 {
			SMALL,
			MEDIUM,
			LARGE
		};

		KartConstructInfoAccessor();
		EDriverSizeType getDriverSizeType();
		void loadData(System::ResourceLoader *);

		/M/KartPartsConstructParam m_kart_parts_construct_param/0x14/0x0/
        /M/KartConstructInfoAccessor *m_self/0x4/0x14/ // ?
        /M/KartConstructInfoData *m_data/0x4/0x18/
	/END/
}