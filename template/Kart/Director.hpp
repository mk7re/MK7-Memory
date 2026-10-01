#pragma once

#include "../common.hpp"
#include "../forward.hpp"
#include "../types.hpp"

#include "Unit.hpp"

#include "../Object/TDirectorArray.hpp"
#include "../Object/TLinkSocket.hpp"

#include "../System/KDPad.hpp"
#include "../System/RootSystem.hpp"

#include <container/seadBuffer.h>

BEGIN_NAMESPACE(Kart)
{
    /START_CLASS/NAME@Director/SIZE@0x1A0/BASE@Object::TDirectorArray<Object::Actor, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
    public:
        Vehicle *getKart(s32 index) { return m_units(index)->m_vehicle; }

        void setPad(s32, System::KDPad *);

        /M/sead::Buffer<Unit *> m_units/0x8/0x28/
        /M/s32 m_culling_target_player_id/0x4/0x30/
        /M/void *m_kart_disps[KART_MAX]/0x20/0x34/
        /M/Mii::MiiEngine *m_mii_engine/0x4/0x54/
        /M/Enemy::AIManager *m_ai_manager/0x4/0x58/
        /M/Enemy::AI **m_ais/0x4/0x5C/
        /M/GhostVisible *m_ghost_visible/0x4/0x60/
        /M/s32 m_wing_path_data_num/0x4/0x64/
        /M/WingPathData *m_wing_path_datas[KART_MAX]/0x20/0x68/
        /M/PullPathData *m_pull_path_datas[KART_MAX * 8]/0x100/0x88/
        /M/bool m_is_battle/0x1/0x188/
        /M/bool m_is_net_object/0x1/0x189/
        /M/bool m_is_demo/0x1/0x18A/
        /M/bool m_has_audience/0x1/0x18C/
        /M/bool m_is_racing/0x1/0x190/
        /M/u32 m_frame_since_countdown/0x4/0x198/
        /M/bool m_is_ai_valid/0x1/0x19C/    // Set to `true` if there are CPU paths in the course and they're valid
    /END/

    inline static auto GetDirector()
    {
        return System::g_root_system->get_kart_director();
    }
}