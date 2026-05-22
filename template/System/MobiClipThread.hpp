#pragma once

#include "KDThread.hpp"
#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

#include <heap/seadExpHeap.h>
#include <nw/lyt/Picture.hpp>

BEGIN_NAMESPACE(System)
{
#if GAME_VERSION != ALL_DLP
    // NOTE: Unknown name
    /START_STRUCT/NAME@struct_51/SIZE@0x14/
    public:
        /M/s32 m_0x00/0x4/0x0/
        /M/s32 m_0x04/0x4/0x4/
        /M/s32 m_0x08/0x4/0x8/
        /M/s32 m_0x0c/0x4/0xc/
        /M/s32 m_0x10/0x4/0x10/
    /END/

    // NOTE: Name is made up
    // KDThread name: "MobiClip"
    /START_CLASS/NAME@MobiClipThread/SIZE@0x16C0/BASE@KDThread/BSIZE@0xA4/VTABLE@True/
    public:
        // NOTE: Name is made up
        /START_STRUCT/NAME@Params/SIZE@0x8C/
        /END/

        // NOTE: Name is made up
        /START_CLASS/NAME@Info/SIZE@0x168/
        public:
            /M/VideoDrawerThread *m_video_drawer_thread/0x4/0x0/
            /M/Params *m_params/0x4/0x98/
            /M/bool m_is_stopped/0x1/0x161/
            /M/bool m_in_calc_state/0x1/0x167/
        /END/

        virtual ~MobiClipThread();                      // 0x0017f880 (VERSION_USA_REV1)
        virtual void calcInner_(s32);                   // 0x0017d85c (VERSION_USA_REV1)

        MobiClipThread();                               // 0x0017f434 (VERSION_USA_REV1)
        s32 calcState(s32);                             // 0x0017e834 (VERSION_USA_REV1)
        void createMoflexHeap(const struct_51 &);       // 0x0017e744 (VERSION_USA_REV1)
        void createVideoDrawerThread();                 // 0x0017daa8 (VERSION_USA_REV1)
        void freeResources();                           // 0x0017dba0 (VERSION_USA_REV1)
        void FUN_0017e344();                            // 0x0017e344 (VERSION_USA_REV1)
        void loadMovie1(const char *);                  // 0x0017e500 (VERSION_USA_REV1)
        void loadMovie2(const char *);                  // 0x0017e020 (VERSION_USA_REV1)
        void pauseMovie();                              // 0x0017f314 (VERSION_USA_REV1)
        void resumeMovie();                             // 0x0017d98c (VERSION_USA_REV1)
        void stopMovie();                               // 0x0017e6b8 (VERSION_USA_REV1)
        void stopMovieAndFreeResources();               // 0x0017db88 (VERSION_USA_REV1)
        void terminate();                               // 0x0017f2e0 (VERSION_USA_REV1)
        void applyParams(const Params &);               // 0x0017e084 (VERSION_USA_REV1)
        // Might be a static `BaseMenuPage` or `MenuMoviePageBase` function, based on the address?
        static void playMovie(const char *, bool);      // 0x004a4370 (VERSION_USA_REV1)

        /M/sead::ExpHeap *m_moflex_heap/0x4/0xe0/
        /M/Info m_info/0x168/0x1558/
    /END/

    // NOTE: Name is made up
    /START_CLASS/NAME@MobiClipThreadProxy/SIZE@0x8/
    public:
        MobiClipThreadProxy();                          // 0x00144b10 (VERSION_USA_REV1)
        void draw();                                    // 0x00144aa8 (VERSION_USA_REV1)

        /M/nw::lyt::Picture *m_movie_pane/0x4/0x0/      // Usually `P_movie_dammy`
        /M/MobiClipThread *mobiclip_thread/0x4/0x4/
    /END/

    extern MobiClipThread::Params unk_0069438c[5];      // 0x0069438c (VERSION_USA_REV1)
    extern MobiClipThread::Params g_movie_params[8];    // 0x00692a64 (VERSION_USA_REV1)
#endif
}
