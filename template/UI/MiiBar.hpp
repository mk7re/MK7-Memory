#pragma once

#include "../forward.hpp"

#include "BaseFastControl.hpp"
#include "../RaceSys/EDriverID.hpp"

#include <math/seadVector.hpp>
#include <nw/lyt/Pane.hpp>
#include <nw/lyt/TextBox.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@MiiBar/SIZE@0xBC/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        virtual void onCreate(const Control::CreateArg *);
        
        void setCharaTex(RaceSys::EDriverID, s32);
        void setMiiTex(Mii::Icon *);
        void setMiiTex(u32);
        void setDriverTex(RaceSys::EDriverID, s32);                     // 0x00281a68 (VERSION_EUR_DLP)
        void setDriverTexFromConnectorInfo(RaceSys::EDriverID, s32);    // 0x00281d60 (VERSION_EUR_DLP)

        /M/nw::lyt::TextBox *m_T_name1/0x4/0x7c/
        /M/nw::lyt::Pane *m_P_mii/0x4/0xa8/
        /M/sead::Vector3f m_position/0xc/0xac/
        /M/bool m_driver_tex_set/0x1/0xb8/
        /M/bool m_is_checked/0x1/0xb9/
    /END/
}