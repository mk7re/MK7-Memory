#pragma once

#include <container/seadBuffer.h>

#include "../types.hpp"
#include "../forward.hpp"

#include <math/seadVector.h>

BEGIN_NAMESPACE(RaceSys)
{
	/START_CLASS/NAME@LapRankChecker/SIZE@0x3C/BASE@Object::Actor/BSIZE@0x8/VTABLE@True/
	public:
		/START_CLASS/NAME@KartInfo/SIZE@0x44/
		public:
			enum class Flags : u32
			{
				Going_Reverse = 1 << 0,
				// Triggers a respawn when leaving a checkpoint's area
				Out_of_Checkpoint_Area = 1 << 1,
				// This flag is set when reaching 90% race completion (reaching the end) of Maka Wuhu,
				// and then going back to the start line and onwards.
				// Also set when, in Toad Circuit, you perform the glitch to finish the lap in reverse
				// by dropping into a blue and white block in the glider section.
				Force_No_Lap_Completion = 1 << 2,
				// Set when a player idles for some time.
				// This is used to know when a player should disconnect from an online match
				// because of idling for some time.
				Idle = 1 << 3,
			};

			KartInfo();

			/M/Kart::InfoProxy *m_info_proxy/0x4/0x0/
			/M/sead::Vector2f m_checkpoint_dir/0x8/0x4/
			/M/u8 m_previous_checkpoint_index/0x1/0xC/
			/M/u8 m_current_checkpoint_index/0x1/0xD/
			/M/s16 m_last_valid_checkpoint_index/0x2/0xE/ // Normally -1, but set to last valid index when going out of checkpoints
			/M/u8 m_key_checkpoint_id/0x1/0x10/
			/M/u8 m_section/0x1/0x11/ // Current section, in section-based courses
			/M/f32 m_current_race_progress/0x4/0x14/
			/M/f32 m_max_race_progress/0x4/0x18/
			/M/s32 m_current_lap/0x4/0x1C/ // Zero index
			/M/s32 m_current_rank/0x4/0x20/
			/M/Flags m_flags/0x4/0x24/
			/M/sead::Vector3f m_current_pos/0xC/0x28/
			/M/sead::Vector3f m_previous_pos/0xC/0x34/
			/M/bool m_current_rank_updated/0x1/0x40/
		/END/

		virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1

		virtual void init(); // 5
		virtual void calc(); // 6

		LapRankChecker();
		void onOutOfBounds(s32, s32);
		void calcLapPosition_(KartInfo *);
		s32 calcIntervalToGoal(s32);
		f32 getCourseLength() const;
		f32 calcGapRatioFromTargetKart(const sead::Vector3f &, f32, s32, s32, s32) const;

		/M/Field::MapdataCheckPointAccessor *m_checkpoint_accesor/0x4/0x8/
		/M/Field::MapdataCheckPathAccessor *m_checkpath_accesor/0x4/0xC/
		/U/u8/0x1/0x10/
		/M/bool m_is_maka_wuhu/0x1/0x11/
		/M/u8 m_course_lap_amount/0x1/0x12/
		/M/s32 m_num_players/0x4/0x14/
		/M/s32 m_max_checkpoint_id/0x4/0x18/
		/M/s32 m_master_player_id/0x4/0x1C/
		/M/s32 m_idle_timer_1/0x4/0x20/
		/M/f32 m_idle_timer_2/0x4/0x24/
		/M/sead::Buffer<LapRankChecker::KartInfo> m_kart_infos/0x8/0x28/
		/U/s32/0x4/0x30/
		/M/s32 *m_player_id_array/0x4/0x34/
		/M/s32 m_checkpoint_type/0x4/0x38/
	/END/

	LapRankChecker *GetLapRankChecker();
}