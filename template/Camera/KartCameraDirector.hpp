#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(Camera)
{
    /START_CLASS/NAME@KartCameraDirector/SIZE@0x70/
    public:
        enum class EMode : u8 {
            DEFAULT,    // Regular, 3rd person camera
            DEMO,       // Dynamic cameras, used in replays, the course introduction and in the awards

            MAX
        };

        KartCameraDirector();
        void changeMode();
        void requestChangeMode(EMode);
        void _setMode(EMode);

        /M/bool m_is_valid_camera_mode/0x1/0x28/
        /M/u8 m_game_mode/0x1/0x4c/ // See the `Object::CharacterEngine::EMode` enum
        /M/EMode m_prev_mode/0x1/0x4d/
        /M/EMode m_curr_mode/0x1/0x4e/
        /M/s32 m_calc_time/0x4/0x50/
        /M/bool m_is_start_demo/0x1/0x54/
        /M/bool m_is_goal/0x1/0x55/
        /M/RaceSys::KartInfo *m_kart_info/0x4/0x58/
        /M/Demo::DemoCameraDirector *m_demo_camera_director/0x4/0x5c/
        /M/sead::Delegate<KartCameraDirector> m_change_mode_delegate/0x10/0x60/   // `Camera::KartCameraDirector::changeMode()`
    /END/
}