#pragma once

#include <math/seadVector.h>

#include "../../types.hpp"

#include "base.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@MapdataCheckPointData/SIZE@0x18/
        /M/sead::Vector2f m_sector_left/0x8/0x0/
        /M/sead::Vector2f m_sector_right/0x8/0x8/
        /M/s8 m_jugem_point_index/0x1/0x10/
        /M/s8 m_check_point_type/0x1/0x11/
        /M/s8 m_check_point_prev/0x1/0x12/
        /M/s8 m_check_point_next/0x1/0x13/
        /U/u8/0x1/0x14/
        // -1 on most checkpoints. On 1-lap courses it marks where a section starts: reaching this checkpoint sets
        // LapRankChecker::KartInfo::m_section to this value + 1. On 3-lap courses, 1 lets the kart change to this
        // checkpoint from any other one, offline even across key checkpoint sections.
        /M/s8 m_section/0x1/0x15/
        /U/u16/0x2/0x16/
    /END/
    
    class MapdataCheckPath;

    /START_CLASS/NAME@MapdataCheckPoint/SIZE@0xD0/BASE@MapdataDataBase<MapdataCheckPointData>/BSIZE@0x4/
    public:
        // Link to one following checkpoint, with the two side edges of the quad between them
        /START_STRUCT/NAME@SNextInfo/SIZE@0x18/
            /M/MapdataCheckPoint *m_point/0x4/0x0/
            /M/sead::Vector2f m_left_edge/0x8/0x4/ // m_point.m_sector_left - m_sector_left
            /M/sead::Vector2f m_right_edge/0x8/0xC/ // m_point.m_sector_right - m_sector_right
            /M/f32 m_distance/0x4/0x14/ // between the two m_center
        /END/

        /M/u8 m_next_num/0x1/0x4/
        /M/u8 m_prev_num/0x1/0x5/
        // Bit n: already tested for player n during this frame's search. Bit 31: m_key_check_point_id has been set.
        /M/u32 m_search_flags/0x4/0x8/
        /M/u8 m_index/0x1/0xC/
        /M/u8 m_key_check_point_id/0x1/0xD/ // m_check_point_type of the last key checkpoint at or before this one
        /M/f32 m_distance_from_start/0x4/0x10/
        /M/sead::Vector2f m_center/0x8/0x14/
        /M/sead::Vector2f m_forward/0x8/0x1C/ // unit normal of the checkpoint line, pointing to the next checkpoint
        /M/MapdataCheckPoint *m_prev_points[6]/0x18/0x24/
        /M/MapdataCheckPath *m_path/0x4/0x3C/
        /M/SNextInfo m_next_infos[6]/0x90/0x40/
    /END/
}