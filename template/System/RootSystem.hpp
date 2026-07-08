#pragma once

#include "../types.hpp"

#include "SceneManager.hpp"

#include "SystemEngine.hpp"

#include "../Render/UIDrawDirector.hpp"

#include "../Sequence/DashSequenceEngine.hpp"

#include <prim/seadDelegateEventSlot.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@RootSystem/SIZE@0x60/VTABLE@True/
	public:
        virtual ~RootSystem() = default;

        inline auto get_kart_director() const { return m_scene_manager->get_character_engine_director_list()->m_kart_director; }
        inline auto get_field_director() const { return m_scene_manager->get_character_engine_director_list()->m_field_director; }
        inline auto get_object_director() const { return m_scene_manager->get_character_engine_director_list()->m_object_director; }
        inline auto get_race_director() const { return m_scene_manager->get_character_engine_director_list()->m_race_director; }
        inline auto get_item_director() const { return m_scene_manager->get_character_engine_director_list()->m_item_director; }
        inline auto get_demo_camera_director() const { return m_scene_manager->get_character_engine_director_list()->m_demo_camera_director; }

        inline auto get_nwlyt_resource_accessor() const { return m_scene_manager->get_render_engine_director_list()->m_ui_draw_director->m_layout_resource_accessor; }

        inline auto get_game_setting() const { return m_root_scene->get_system_engine()->m_game_setting; }
        inline auto get_pad_director() const { return m_root_scene->get_system_engine()->m_pad_director; }

        inline auto get_menu_data() const { return m_root_scene->get_sequence_engine()->m_menu_data; }
        inline auto get_message_id_converter() const { return m_root_scene->get_sequence_engine()->m_message_id_converter; }

        inline auto get_kart_camera_director() const { return m_scene_manager->get_camera_engine_director_list()->m_kart_camera_director; }
        inline auto get_default_camera_director() const { return m_scene_manager->get_camera_engine_director_list()->m_default_camera_director; }

        /M/SceneManager *m_scene_manager/0x4/0x4/
        /M/ThreadManager *m_thread_manager/0x4/0xC/
        /M/RootScene *m_root_scene/0x4/0x10/
        /M/GameFramework *m_game_framework/0x4/0x14/
        /M/sead::DelegateEvent<char const *>::Slot m_delegate_event_slot/0x38/0x18/
        /M/bool m_0x50/0x1/0x50/
        /M/sead::ListImpl *m_list/0x4/0x54/
        /M/BootRenderThread *m_boot_render_thread/0x4/0x58/
        /M/bool m_is_sleep_acceptable/0x1/0x5C/
    /END/

    // NOTE: must be provided by the user
    inline RootSystem *g_root_system{};
}