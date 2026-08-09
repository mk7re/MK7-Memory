#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/TDirectorArray.hpp"
#include "../Object/TLinkSocket.hpp"
#include "KDPad.hpp"
#include "KDPadPlayer.hpp"

#include <container/seadPtrArray.h>
#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KDPadDirectorBase/SIZE@0x28/BASE@Object::TDirectorArray<System::KDPad, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
    /END/

    /START_CLASS/NAME@KDPadDirector/SIZE@0x88/BASE@KDPadDirectorBase/BSIZE@0x28/
    public:
        enum class eKDPadListIndex : s32
        {
            PLAYER,
            UI,
            PLAYER_RECORD,
            AI_0,
            AI_1,
            AI_2,
            AI_3,
            AI_4,
            AI_5,
            AI_6,
            AI_7,
            REPLAY_PLAYER_0,
            REPLAY_PLAYER_1,
            REPLAY_PLAYER_2,
            REPLAY_PLAYER_3,
            REPLAY_PLAYER_4,
            REPLAY_PLAYER_5,
            REPLAY_PLAYER_6,
            REPLAY_PLAYER_7
        };

        // TODO
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        void calc();
        void createBeforeStructure(const Object::ArgumentObj *);
        void initAfterStructure();

        void acceptGyroChange();
        void createPad(eKDPadListIndex);
        void initPad();
        void pauseIn();
        void pauseOut();
        void startRace();
        void finishRace();
        void sceneExit();

        /M/sead::PtrArray<KDPad> m_pads/0xC/0x28/                   // See the `eKDPadListIndex` enum
        /M/sead::PtrArray<KDPadPlayer> m_kdpad_player_list/0xC/0x34/
        /M/u8 m_num_ai_pads/0x1/0x40/
        /M/u8 m_num_replay_pads/0x1/0x41/
        /M/sead::Delegate<KDPadDirector> m_pause_in/0x10/0x44/    // System::KDPadDirector::pauseIn
        /M/sead::Delegate<KDPadDirector> m_pause_out/0x10/0x54/   // System::KDPadDirector::pauseOut
        /M/sead::Delegate<KDPadDirector> m_start_race/0x10/0x64/  // System::KDPadDirector::startRace
        /M/sead::Delegate<KDPadDirector> m_finish_race/0x10/0x74/ // System::KDPadDirector::finishRace 
        /M/bool m_race_started/0x1/0x84/
        /M/bool m_is_gyro_mode/0x1/0x85/
        /M/bool m_is_paused/0x1/0x86/
    /END/
}