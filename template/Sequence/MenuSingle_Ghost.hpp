#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include "BaseMenuPage.hpp"
#include "GhostList.hpp"
#include "../System/GhostLoader.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@MenuSingle_Ghost/SIZE@0x17ac/BASE@BaseMenuPage/BSIZE@0x294/VTABLE@True/
    public:
        // NOTE: Name is made up
        /START_CLASS/NAME@GhostListHolder/SIZE@0x1280/
        public:
            /M/System::GhostLoader m_ghost_loader/0x127c/0x0/
            /M/bool m_is_ready_to_load_ghost_list/0x1/0x127c/
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~MenuSingle_Ghost();
        virtual void onPagePreStep();
        virtual void onPageEnter();
        virtual void onPageStart();
        virtual void onPageComplete();
        virtual bool canFinishFadein();
        virtual bool canFinishFadeout();
        virtual void initControl();
        virtual void onPageFadeout();
        virtual void buttonHandler_OK(s32);
        virtual void onSliderSetting(bool, bool);

        /M/UI::ScrollList *m_scroll_list/0x4/0x294/
        /M/GhostList m_ghost_list/0x280/0x298/
        /M/GhostListHolder m_ghost_list_holder/0x1280/0x520/
        /M/s32 m_selected_ghost_idx/0x4/0x17a0/                     // Index in the ghost list to the currently highlighted ghost
        /M/bool m_dialog_started/0x1/0x17a4/                        // ("Please wait..." dialog)
        /M/bool m_dialog_finished/0x1/0x17a5/                       // ("Please wait..." dialog)
        /M/bool m_loading_ext_savedata_ghosts/0x1/0x17a6/           // i.e. SpotPass ghosts
        /M/bool m_do_update/0x1/0x17a7/
        /M/bool m_removed_sd_card/0x1/0x17a8/
    /END/
}