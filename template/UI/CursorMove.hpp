#pragma once

#include "../types.hpp"

#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@CursorMove/SIZE@0x24/
    public:
        enum class EType : u8
        {
            NEXT_ROW,
            NEXT_COL,
            NEXT_MATRIX,
            NEXT_CHARA_SELECT,
            NEXT_CUP_SELECT,
            NEXT_PARTS_SLOT,
            NEXT_GAME_SETTING,
            NEXT_DONT_MOVE
        };

        enum EDir : s32 {
            DIR_RIGHT     = 0x00000001,
            DIR_LEFT      = 0x00000002,
            DIR_DOWN      = 0x00000004,
            DIR_UP        = 0x00000008,
            DIR_NEUTRAL   = 0x10000000      // No direction
        };

        s32 next_DontMove(CursorItem *);
        s32 next_CupSelect(CursorItem *);
        s32 next_PartsSlot(CursorItem *);
        s32 next_CharaSelect(CursorItem *);
        s32 next_GameSetting(CursorItem *);
        s32 next_Matrix(CursorItem *);
        s32 next_Matrix_Impl(CursorItem *, s32, s32);
        s32 next(CursorItem *);
        s32 getDir(CursorItem *);   // See the `EDir` enum
        s32 setType(EType);
        s32 next_Col(CursorItem *);
        s32 next_Row(CursorItem *);

        /M/EType m_type/0x1/0x0/
        /M/sead::Delegate1R<CursorMove, CursorItem *, s32> m_on_next_delegate/0x10/0x4/
        /M/s32 m_num_rows/0x4/0x14/
        /M/s32 m_num_columns/0x4/0x18/
        /U/u8/0x1/0x1c/
        // If `true`, the cursor will roll over when attempting to select prior to the first option,
        // or after the last option
        /M/bool m_roll_over/0x1/0x1d/
        /U/s32/0x4/0x20/
    /END/
}