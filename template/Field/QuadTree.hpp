#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // The camera as the QuadTree sees it: a copy taken for the quadtree thread
    /START_STRUCT/NAME@CameraData/SIZE@0xA0/
        /M/sead::Vector3f m_position/0xC/0x0/
        /M/f32 m_far/0x4/0x10/
        /M/sead::Vector3f m_dir/0xC/0x14/
        // Corners of the view volume: bit 0 of the index is the bottom side, bit 1 the near plane, bit 2 the
        // other horizontal side
        /M/sead::Vector3f m_corners[8]/0x60/0x3C/
    /END/

    // One cell of the QuadTree: a rectangle of the course on the XZ plane
    /START_CLASS/NAME@QuadCell/SIZE@0xB0/VTABLE@True/
    public:
        // A convex region of the XZ plane: the inside is where every edge normal points away
        /START_STRUCT/NAME@SClipData/SIZE@0xA4/
            /M/sead::Vector2f m_origin/0x8/0x0/    // camera position, for the distances along m_dir
            /M/sead::Vector2f m_dir/0x8/0x8/       // camera direction
            /M/sead::Vector2f m_normals[8]/0x40/0x10/  // outward unit normal of each edge
            /M/sead::Vector2f m_points[8]/0x40/0x50/   // a point of each edge
            /M/u8 m_edge_num/0x1/0x90/
            /M/sead::Vector2f m_min/0x8/0x94/      // bounding box of m_points
            /M/sead::Vector2f m_max/0x8/0x9C/
        /END/

        virtual ~QuadCell();

        bool expandRect(const sead::Vector2f &, const sead::Vector2f &);
        bool checkInside(const SClipData &, f32 *, f32 *, bool);
        bool checkWholeInside(const SClipData &, bool);
        void checkClipInternal(const SClipData &, s32);
        void checkWallInternal(const SClipData &);
        void setInvisibleInternal();
        void setupManualClipInternal(const SClipData &, s32);
        void setManualClipFlagInternal(s32);

        /M/u16 m_index/0x2/0x4/                  // position in its level, in Morton order (bit 0 is X)
        /M/u8 m_level/0x1/0x6/                   // 0 for the root
        /M/bool m_has_children/0x1/0x7/
        /M/bool m_prev_visible/0x1/0x9/          // m_visible of the previous update
        /M/sead::Vector2f m_pos/0x8/0xC/         // minimum corner (X, Z)
        /M/sead::Vector2f m_size/0x8/0x14/
        /M/sead::Vector2f m_corners[4]/0x20/0x1C/
        /M/sead::Vector2f m_outer_corners[4]/0x20/0x3C/  // m_corners pushed out by QuadTree::m_margin
        // Area that expandRect may grow the cell into: centred on m_pos, 1.7 leaf cells wide
        /M/sead::Vector2f m_expand_limit_pos/0x8/0x5C/
        /M/sead::Vector2f m_expand_limit_size/0x8/0x64/
        /M/bool m_visible[2]/0x2/0x70/           // double buffered with the quadtree thread
        /M/f32 m_view_dist_min[2]/0x8/0x74/      // nearest corner along SClipData::m_dir of the camera, 0 if around it
        /M/f32 m_view_dist_max[2]/0x8/0x7C/      // farthest corner along SClipData::m_dir of the camera
        /M/QuadTreeThread *m_thread/0x4/0x84/
        /M/u32 m_clip_id_flags/0x4/0x8C/         // bit n: hidden while the current clip ID is n
        /M/sead::PtrArray<QuadCell> m_children/0xC/0x90/
        /M/QuadCell *m_children_buffer[4]/0x10/0x9C/
        /M/QuadCell *m_parent/0x4/0xAC/
    /END/

    // Where an object or kart is, for QuadTree culling
    /START_CLASS/NAME@ClipContext/SIZE@0x1C/
    public:
        bool isVisible_();

        /M/QuadCell *m_cell/0x4/0x0/              // smallest cell that holds the square around m_center
        /M/sead::Vector2f m_center/0x8/0x4/      // X, Z
        /M/f32 m_radius/0x4/0xC/
        /M/FieldDirector *m_field_director/0x4/0x10/
        /M/bool m_view_test/0x1/0x14/             // also test the circle against the view, not only the cell
        /M/bool m_was_visible/0x1/0x15/
        /M/f32 m_view_test_timer/0x4/0x18/
    /END/

    // Course culling on the XZ plane: a linear quadtree over the bounding box of the course model's div file,
    // updated every frame from the camera, the clip ID of the current checkpoint and the occlusion objects
    /START_CLASS/NAME@QuadTree/SIZE@0x140/VTABLE@True/
    public:
        virtual ~QuadTree();

        void reset();
        void update(const CameraData &);
        void convertTo(QuadCell::SClipData *, const CameraData &);
        void rectFixed();
        QuadCell *getCell(const sead::Vector2f &, const sead::Vector2f &, bool);
        void getClipContext(ClipContext *, const sead::Vector3f &, f32, bool);
        u32 getLowestIndex(const sead::Vector2f &);

        // All the cells, level by level (1, 4, 16 and 64 for m_depth 3), each level in Morton order
        /M/sead::PtrArray<QuadCell> m_cells/0xC/0x4/
        /M/s32 m_cell_num/0x4/0x18/
        /M/s32 m_leaf_num/0x4/0x1C/             // cells of the last level
        /M/s32 m_leaf_index_max/0x4/0x20/       // (1 << m_depth) - 1
        /M/u8 m_depth/0x1/0x24/
        /M/bool m_reset_requested/0x1/0x26/
        /M/sead::Vector2f m_rect_min/0x8/0x28/
        /M/sead::Vector2f m_rect_max/0x8/0x30/
        /M/sead::Vector2f m_margin/0x8/0x38/     // 0.025 leaf cells
        /M/sead::Vector2f m_outer_min/0x8/0x40/  // m_rect_min - m_margin
        /M/sead::Vector2f m_outer_max/0x8/0x48/  // m_rect_max + m_margin
        /M/sead::Vector3f m_model_min/0xC/0x50/  // bounding box of the course model
        /M/sead::Vector3f m_model_max/0xC/0x5C/
        /M/sead::Vector2f m_leaf_size/0x8/0x78/
        /M/sead::Vector2f m_leaf_size_inv/0x8/0x80/
        /M/bool m_use_clip_id/0x1/0x8C/
        /M/u64 m_visible_leaves[2]/0x10/0x90/   // bit n: leaf n (m_cells index 21 + n) is visible; double buffered
        /M/RaceSys::LapRankChecker *m_lap_rank_checker/0x4/0xB0/
        /M/MapdataCheckPointAccessor *m_check_point_accessor/0x4/0xB4/
        /M/sead::PtrArray<QuadInvisibleWall> m_invisible_walls/0xC/0xB8/  // one per occlusion object
        /M/QuadTreeThread *m_thread/0x4/0xE4/
        /M/bool m_result_ready/0x1/0xE8/        // m_visible_leaves holds a result not yet applied to the course model
        /M/bool m_hide_all/0x1/0xE9/
    /END/
}
