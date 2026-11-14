#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/Actor3DMdl.hpp"

#include "DivFile.hpp"
#include "QuadTree.hpp"

#include <container/seadBuffer.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Field)
{
    // The course model (the model named after the course in its .bcmdl), culled by index stream with the QuadTree
    /START_CLASS/NAME@FieldModel/SIZE@0x98/BASE@Object::Actor3DMdl/BSIZE@0x58/
    public:
        // One mesh of the model: drawn while one of its index streams is
        /START_STRUCT/NAME@MeshChecker/SIZE@0xC/
            /M/void *m_mesh/0x4/0x0/                 // nw::gfx::res::ResMeshData *
            /M/s16 m_stream_num/0x2/0x4/
            /M/s16 m_visible_stream_num/0x2/0x6/
        /END/

        // One index stream of the model, with its div area
        /START_STRUCT/NAME@MeshInfo/SIZE@0x30/
            /M/QuadCell *m_cell/0x4/0x0/             // null when the stream is never culled
            /M/u64 m_leaf_mask/0x8/0x8/              // bit n: the area touches leaf n of the QuadTree
            /M/sead::Vector2f m_min/0x8/0x10/        // the div area (X, Z)
            /M/sead::Vector2f m_max/0x8/0x18/
            /M/void *m_index_stream/0x4/0x20/        // nw::gfx::res::ResIndexStreamData *
            /M/void *m_shape/0x4/0x24/               // nw::gfx::res::ResSeparateDataShapeData *
            /M/MeshChecker *m_mesh_checker/0x4/0x28/ // the first mesh that draws the shape
        /END/

        void attachCells(QuadTree *);
        void changeStreamVisible(QuadTree *);

        /M/sead::Buffer<MeshInfo> m_mesh_infos/0x8/0x68/
        /M/DivFile m_div_file/0x14/0x74/
        /M/u32 m_hide_slot/0x4/0x88/                  // 0 to 7: which eighth of the visible streams may be hidden this frame
        /M/s32 m_mesh_checker_num/0x4/0x8C/
        /M/sead::Buffer<MeshChecker> m_mesh_checkers/0x8/0x90/
    /END/
}
