#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "SceneID.hpp"

#include <framework/seadTaskID.h>

BEGIN_NAMESPACE(System)
{
    // TODO: Inheritance tree.
    // sead::UlcdTask -> sead::DualScreenTask -> sead::TaskBase
    /START_CLASS/NAME@Scene/SIZE@0x1E0/VTABLE@True/
    public:
        enum class SceneState : u8 {
            PREPARE = 2,
            CALC,
            DRAW,
            EXIT
        };

        enum SceneAttribute : u32 {
            SCENE = 0,
            ROOT_SCENE = 1,
            GAME_SCENE = 2
        };

        /START_STRUCT/NAME@VRAMSet/SIZE@0x14/
            void create(Scene *);
            void create_(GfxFrmHeap *);

            /M/GfxFrmHeap *m_heap_a_1/0x4/0x4/
            /M/GfxFrmHeap *m_heap_b_1/0x4/0x8/
            /M/GfxFrmHeap *m_heap_a_2/0x4/0xc/
            /M/GfxFrmHeap *m_heap_b_2/0x4/0x10/
        /END/

        virtual ~Scene() = default;

        Scene(const sead::TaskConstructArg &, SceneID, u32);
        void createDrawHeap();

        /M/VRAMSet m_vram_set/0x14/0x1ac/
        /M/SceneID m_child_scene_id/0x1/0x1c0/
        /M/bool m_is_exiting_scene/0x1/0x1c1/
        /M/Scene *m_previous_scene/0x4/0x1c4/
        /M/SceneState m_state/0x1/0x1d0/
        /M/u32 m_attribute/0x4/0x1d4/     // See the `SceneAttribute` enum
        /M/SceneID m_scene_id/0x1/0x1d8/
        /M/u32 m_game_scene_calc_time/0x4/0x1dc/
    /END/
}