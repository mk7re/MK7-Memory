#pragma once

#include "../common.hpp"
#include "../forward.hpp"

#include "SequenceEngine.hpp"
#include "../System/Flag.hpp"
#include "../System/GhostSaveData.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@DashSequenceEngine/SIZE@0x16F5C/BASE@SequenceEngine/BSIZE@0xAC/VTABLE@True/
    public:
        virtual DashSectionClassManager *getSectionClassManager();
        virtual DashSceneIDConverter *getSceneIDConverter();
        virtual DashEngineCreatorManager *getEngineCreatorManager();
        virtual UI::DashFontManager *getFontManager();
        virtual UI::DashMessageWriter *getMessageWriter();

        DashSequenceEngine();
        void setPlayerGhostHeader(const System::GhostSaveDataHeader &);

        /M/SectionClassManager *m_section_class_manager/0x4/0xAC/
        /M/DashSceneIDConverter *m_scene_id_converter/0x4/0xB0/
        /M/DashEngineCreatorManager *m_engine_creator_manager/0x4/0xB4/
        /M/UI::FontManager *m_font_manager/0x4/0xB8/
        /M/UI::DashMessageWriter *m_message_writer/0x4/0xBC/
        /M/MenuData *m_menu_data/0x4/0xC0/
        /M/SequenceIDTable *m_sequence_id_table/0x4/0xC4/
        /M/RootExitTask *m_root_exit_task/0x4/0xCC/
        /M/bool m_exit_app/0x1/0xD0/
        /M/UI::TexIDConverter *m_tex_id_converter/0x4/0xD4/
        /M/UI::MessageIDConverter *m_message_id_converter/0x4/0xD8/
        /M/AIRivalTableLoader *m_ai_rival_table_loader/0x4/0xDC/
        /M/System::Flag::Checker *m_flag_checker/0x4/0xE4/
        // Array with the selected options from the LRSelect (and maybe other UI elements too). Up to 23 entries.
        /M/s32 *m_selected_cursor_item_idx_array/0x4/0xE8/
        /M/bool m_is_player_ghost_ready/0x1/0xEC/
        /M/s32 m_player_ghost_idx/0x4/0xF0/
        /M/System::GhostSaveDataHeader m_player_ghost_header/0xc0/0xF4/
        /M/System::GhostSaveData m_ghosts[KART_MAX]/0x144c0/0x1B4/
        /U/bool/0x1/0x14674/
        /M/System::GhostSaveData m_player_ghost/0x2898/0x14678/
    /END/

    DashSequenceEngine *GetDashSequenceEngine();
    UI::TexIDConverter *GetTexIDConverter();
    System::GhostSaveData *GetGhostDataPtr(s32);
}