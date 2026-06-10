#pragma once

#include "VehicleMove.hpp"

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@VehicleReact/SIZE@0x123C/BASE@VehicleMove/BSIZE@0x1214/
	public:
		enum class EAcdType : u8
		{
			PipeFall = 0x0,	// SPIN_1_NORMAL
			Fireball = 0x1,	// SPIN_1_FIRE
			Flipper = 0x2,	// SPIN_1_ELECTRICITY
			NoSounds = 0x3,	// SPIN_1_3
			Spin1 = 0x4,	// SPIN_1_UPSIDE_DOWN_DRIVING. Activates when the kart goes upside down
			Spin2 = 0x5,	// SPIN_2_NORMAL
			FirePillar = 0x6,	// SPIN_2_FIRE
			KoopaZapper = 0x7,	// SPIN_2_ELECTRICITY
			Thunder = 0x8,
			_0x9 = 0x9,			// SPIN_2_9
			CrashDir = 0xA,
			CrashDirBig = 0xB,
			DokanWarp = 0xC,	// CRASH_SCENARIO
			CrashLR = 0xD,
			CrashLRBig = 0xE,
			CrashFwd = 0xF,
			CrashHop = 0x10,
			Freeze = 0x11,		// Used when stomped by Thwomps
			Dummy = 0x12,
			MAX = 0x13,
		};
		
		enum class ECallType : u32
		{
			NORMAL,
			REACT_ACCIDENT_NET,
			DONT_DROP_COINS_AFTER_HIT
		};

		enum class ESpinType
		{

		};
	/END/
}