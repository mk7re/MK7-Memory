#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Enemy)
{
    /START_CLASS/NAME@AIPathHandler/SIZE@0x4C/
    public:
        // How a race CPU tests whether it has driven past its target point
        enum class EPassMode : s32 {
            NONE = 0,                   // no test
            BISECTOR = 1,               // plane bisecting the turn at the target
            LEAVING = 2,                // plane square to the direction the route leaves the target in
        };

        // Whether a CPU holding a Mushroom takes a mushroom shortcut
        enum class EShortcutMode : u8 {
            NEVER = 0,
            HALF = 1,                   // decided at random when the item is received, 50 %
            ALWAYS = 2,
        };

        void update();
        void goNextPath_(GoNextInfo &);
        bool isTargetToStartDrift();
        bool isTimeToEndDrift();

        /M/EPassMode m_pass_mode/0x4/0x0/
        /M/EPassMode m_relocate_pass_mode/0x4/0x4/ // m_pass_mode after a relocation
        /U/s32/0x4/0x8/
        /M/u32 m_check_timer/0x4/0xC/
        /M/f32 m_reach_radius_sq/0x4/0x10/
        /M/f32 m_default_reach_radius_sq/0x4/0x14/
        /M/f32 m_reach_cos_min/0x4/0x18/
        /M/f32 m_corner_line_shift/0x4/0x1C/
        /M/f32 m_target_dist_sq/0x4/0x20/
        /M/AIPathPoint *m_path_point/0x4/0x24/
        /M/AIManager *m_ai_manager/0x4/0x28/
        /M/AI *m_ai/0x4/0x2C/
        /M/AIAutoSteer *m_ai_auto_steer/0x4/0x30/
        /M/AIControlBase *m_ai_control/0x4/0x34/
        /M/PointParam *m_current_param/0x4/0x38/ // the point just reached
        /M/PointParam *m_next_param/0x4/0x3C/ // the target point
        /M/Field::MapdataEnemyPath *m_pending_path/0x4/0x40/
        /M/bool m_can_adjust_offset/0x1/0x44/
        /M/bool m_do_not_select_backward/0x1/0x45/
        /M/bool m_do_select_root_branch/0x1/0x46/
        /M/bool m_is_battle/0x1/0x47/
        /M/EShortcutMode m_shortcut_mode/0x1/0x48/
        /M/bool m_do_select_shortcut/0x1/0x49/
        /M/bool m_advanced_this_frame/0x1/0x4A/
    /END/
}
