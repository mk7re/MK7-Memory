#pragma once

#include "KDThread.hpp"
#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

#include <nw/lyt/Material.hpp>
#include <nw/lyt/Picture.hpp>
#include <nw/lyt/TexMap.hpp>
#include <nw/lyt/lyt_common.hpp>

BEGIN_NAMESPACE(System)
{
#if GAME_VERSION != ALL_DLP
    // NOTE: Name is made up
    // KDThread name: "VideoDrawer"
    /START_CLASS/NAME@VideoDrawerThread/SIZE@0x230/BASE@KDThread/BSIZE@0xA4/VTABLE@True/
    public:
        virtual ~VideoDrawerThread();                   // 0x0017d08c (__sub_object) (VERSION_USA_REV1)
        virtual void destroy();                         // 0x0017cba8 (VERSION_USA_REV1)
        virtual void calcInner_(s32);                   // 0x0017c1a0 (VERSION_USA_REV1)

        VideoDrawerThread();                            // 0x0017cee4 (VERSION_USA_REV1)
        void init();                                    // 0x0017c9a8 (VERSION_USA_REV1)
        void FUN_001121b8();                            // 0x001121b8 (VERSION_USA_REV1)
        void FUN_0017c204();                            // 0x0017c204 (VERSION_USA_REV1)
        void FUN_0017cd64();                            // 0x0017cd64 (VERSION_USA_REV1)
        void setupTexMap(nw::lyt::Picture *, bool);     // 0x0017cc3c (VERSION_USA_REV1)
        void draw(bool, bool);                          // 0x0017c890 (VERSION_USA_REV1)

        /M/s16 m_input_lines_width/0x2/0xd0/
        /M/s16 m_input_lines/0x2/0xd4/
        /M/nw::lyt::Picture *m_movie_pane/0x4/0x1c0/
        /M/nw::lyt::TexMap m_tex_map/0x20/0x1c4/
        /M/nw::lyt::Material *m_movie_pane_material/0x4/0x1e4/
        /M/bool m_is_mirror_mode/0x1/0x22a/
    /END/

    extern nw::lyt::detail::TexCoord g_video_drawer_tex_coords;              // 0x00678a18 (VERSION_USA_REV1)
    extern nw::lyt::detail::TexCoord g_video_drawer_tex_coords_mirror_mode;  // 0x00678a38 (VERSION_USA_REV1)
    
#endif
}
