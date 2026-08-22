#pragma once

#include "../Object/Actor.hpp"

#include <nw/gfx/Camera.hpp>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Camera)
{
    /START_CLASS/NAME@CameraBase/SIZE@0x10C/BASE@Object::Actor/BSIZE@0x8/
    public:
        /M/float m_zoom/0x4/0x18/ // FOV multiplier? 0-1 range (0 all zoom in)
        /M/float m_near/0x4/0x24/
        /M/float m_far/0x4/0x28/
        /M/sead::Vector3f m_position/0xC/0x2C/
        /M/sead::Vector3f m_look_at/0xC/0x38/
        /U/sead::Vector3f/0xC/0x44/
        /M/bool m_enabled/0x4/0x100/ // Setting to false revents the camera from updating
        /M/nw::gfx::Camera *m_nw_gfx_camera/0x4/0x108/
    /END/
}