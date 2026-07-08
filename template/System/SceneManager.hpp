#pragma once

#include "../types.hpp"

#include "RootScene.hpp"

#include "../Render/RenderEngine.hpp"
#include "../Object/CharacterEngine.hpp"

BEGIN_NAMESPACE(System)
{
    class SceneManager
    {
    public:
        virtual ~SceneManager() = default;

        inline auto get_character_engine_director_list() const { return m_root_scene->get_character_engine()->m_director_list; }
        inline auto get_render_engine_director_list() const { return m_root_scene->get_render_engine()->m_director_list; }
        inline auto get_camera_engine_director_list() const { return m_root_scene->get_camera_engine()->m_director_list; }

        RootScene *m_root_scene;
    };
    static_assert(sizeof(SceneManager) == 0x8);
}