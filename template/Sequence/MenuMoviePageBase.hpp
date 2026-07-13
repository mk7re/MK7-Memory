#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include "BaseMenuPage.hpp"
#include "ECup.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../System/MobiClipThread.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuMoviePageBase/SIZE@0x2BC/BASE@BaseMenuPage/BSIZE@0x294/VTABLE@True/
    public:
        // Set to `true` when all `System::g_movie_params` are initialized (done in `MenuMoviePageBase`'s constructor)
        static bool s_movie_params_initialized;         // 0x006634e0 (VERSION_USA_REV1)    
    
        virtual ~MenuMoviePageBase();       // 0x004a4a3c (VERSION_USA_REV1)
        virtual void onPagePostStep();      // 0x004a3ddc (VERSION_USA_REV1)

        MenuMoviePageBase();                // 0x004a444c (VERSION_USA_REV1)
        void closeMovie(bool);              // 0x004a3cf4 (VERSION_USA_REV1)
        void onPageEnter_Channel();         // 0x004a4348 (VERSION_USA_REV1)
        void pageEnter();                   // 0x004a3de0 (VERSION_USA_REV1)
        void playCourseSelectRaceMovie(Sequence::ECup, RaceSys::ECourseID, bool);   // 0x004a40bc (VERSION_USA_REV1)
        static void FUN_004a3d6c();         // 0x004a3d6c (VERSION_USA_REV1)
        static void playMovie(const sead::SafeString &, bool);                      // 0x004a4370 (VERSION_USA_REV1)

        /M/System::MobiClipThread *m_mobiclip_thread/0x4/0x294/
        /U/u8/0x1/0x298/
        // Set to `true` for MenuSingle_Cup and to `false` for MenuSingle_CupGP,
        // so that the game doesn't automatically exit (or prompt the race start button)
        // after pressing a cup button
        /M/bool m_dont_exit_after_button_press/0x1/0x299/
        /M/System::MobiClipThread::Params *m_mobiclip_params/0x4/0x29c/
    /END/
}