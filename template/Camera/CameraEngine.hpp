#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Camera)
{
    /START_CLASS/NAME@CameraEngine/SIZE@0xE8/
    public:
        /START_STRUCT/NAME@Argument/SIZE@0xC/
        /END/

        // NOTE: guessed name
        /START_STRUCT/NAME@SDirectorList/SIZE@0xC/
            /M/KartCameraDirector *m_kart_camera_director/0x4/0x0/
            /U/void */0x4/0x4/
            /M/DefaultCameraDirector *m_default_camera_director/0x4/0x8/
        /END/

        using creator_t = void (*)(CameraEngine *, SDirectorList *);

        /M/SDirectorList *m_director_list/0x4/0x1C/
        /M/creator_t m_creator_list[8]/0x20/0x20/
        /M/FinalOutputCamera *m_final_output_camera/0x4/0x48/
        /M/FinalOutputCamera *m_final_output_camera_2/0x4/0x4c/
    /END/
}