#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Util/TStateObserver.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AIEngine/SIZE@0x50/VTABLE@True/
    public:
        virtual void stateInitIdle();
        virtual void stateIdle();
        virtual void stateInitReady();
        virtual void stateReady();
        virtual void stateInitRun();
        virtual void stateRun();
        virtual void stateInitPlayerIdle();
        virtual void statePlayerIdle();
        virtual void stateInitGhostIdle();
        virtual void stateGhostIdle();
        virtual void stateInitAfterGoal();
        virtual void stateAfterGoal();
        virtual void stateInitStop();
        virtual void stateStop();

        /M/Util::TStateObserverEx<AIEngine> m_observer/0x20/0x4/
        /M/AIInfo *m_ai_info/0x4/0x24/
        /M/AIManager *m_ai_manager/0x4/0x28/
        /M/AI *m_ai/0x4/0x2C/
        /M/AIControlBase *m_ai_control/0x4/0x30/
        /M/AISpeedRaceBase *m_ai_speed/0x4/0x34/
        /M/AIItemBase *m_ai_item/0x4/0x38/
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0x3C/
        /M/bool m_is_do_as_ai/0x1/0x47/
        /M/bool m_is_net_object/0x1/0x48/
        /M/u32 m_wall_frames/0x4/0x4C/ // frames in a row touching a wall; above 30 the kart is re-routed
	/END/
}