#pragma once

#include "../common.hpp"
#include "../types.hpp"
#include "../forward.hpp"

#include "BaseMenuPage.hpp"
#include "GhostList.hpp"
#include "../RaceSys/ECourseID.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuSingle_GhostLoad/SIZE@0x558/BASE@BaseMenuPage/BSIZE@0x294/VTABLE@True/
    public:
        enum class EnterCode : s32
        {
            TIME_ATTACK,
            CHANNEL
        };

        enum class EState : u8 {
            STATE_DEFAULT,
            STATE_INIT,
            STATE_LOADING_GHOSTS,
            STATE_FINISH
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MenuSingle_GhostLoad();
        virtual void onPagePreStep();
        virtual void onPageEnter();
        virtual bool canFinishFadeout();

        void setRaceInfo();
        void calcGhostLoad();
        void setPlayerGhostInfo();
        void loadPost();
        void loadStaffGhosts();         // Name is made up. 0x004bedd4 (VERSION_USA_REV1). Inlined inside `loadPost()` in VERSION_EUR_DLP
        MenuSingle_GhostLoad();

        static void convertEnterCodeImpl(const sead::SafeString &);

        /M/EState m_state/0x1/0x294/
        /M/bool m_can_update_ghost_loader/0x1/0x295/
        /M/RaceSys::ECourseID m_course/0x4/0x298/
        /M/System::GhostLoader *m_ghost_loader/0x4/0x29c/
        /M/Sequence::GhostList *m_ghost_list_ptr/0x4/0x2a0/
        /M/Sequence::GhostList m_ghost_list/0x280/0x2a4/
        /M/s32 m_selected_ghost_num/0x4/0x52c/
        /M/s32 m_selected_ghosts[KART_MAX - 1]/0x1c/0x530/
        /U/bool/0x1/0x54c/
        /U/u8/0x1/0x54d/
        /M/s32 m_currently_selected_ghost_idx/0x4/0x550/
        /U/bool/0x1/0x554/
    /END/
}