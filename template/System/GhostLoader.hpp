#pragma once

#include "../common.hpp"
#include "../types.hpp"

#include "GhostSaveData.hpp"
#include "../RaceSys/ECourseID.hpp"

#include <prim/seadDelegate.h>

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@GhostLoader/SIZE@0x127C/
    public:
        /START_STRUCT/NAME@GhostData/SIZE@0xCC/
            GhostData();

            /M/GhostSaveDataHeader m_header/0xc0/0x0/
            /M/bool m_is_valid/0x1/0xc0/
            /U/s32/0x4/0xc4/
            /M/s32 m_ranking_ghost_idx/0x4/0xc8/
        /END/

        void updateInner();
        static void loadStaffGhostSync(GhostSaveData *, RaceSys::ECourseID, bool);
        static void loadPlayerGhostASync(System::GhostSaveData *, RaceSys::ECourseID);
        void loadRankingGhostASync(System::GhostSaveData *, RaceSys::ECourseID, s32);
        s32 loadRankingGhostInner();
        static bool doLoadStaffGhost(System::GhostSaveData *, u32, RaceSys::ECourseID, bool);     // NOTE: Name is made up. 0x00412bc0 (VERSION_EUR_DLP)
        static void getPlayerGhostLoadState(s32 *);                     // TODO. Double check if this prototype is correct.
        static void getRankingGhostLoadState(s32 *, GhostLoader *);     // TODO. Double check if this prototype is correct.
        RaceSys::ECourseID init();                                      // TODO. Double check if the return type is correct.
        void update(RaceSys::ECourseID, bool);                          // TODO. Double check if the return type is correct.

        // [0] -> Player ghost
        // [1] -> Staff ghost (Normal)
        // [2] -> Staff ghost (Expert)
        // [3] to [22] -> Ranking ghosts
        /M/GhostData m_ghosts[GHOST_LIST_MAX]/0x1254/0x0/
        /M/sead::Delegate<GhostLoader> m_update_inner/0x10/0x1254/
        /M/RaceSys::ECourseID m_ghost_course/0x4/0x1264/
        /U/bool/0x1/0x1269/
        /U/bool/0x1/0x126a/
        /U/bool/0x1/0x126b/
        /M/s32 m_ranking_ghost_load_state/0x4/0x126c/
        /M/GhostSaveData *m_ranking_ghost_data/0x4/0x1270/
        /M/RaceSys::ECourseID m_ranking_ghost_course/0x4/0x1274/
        /M/s32 m_ranking_ghost_idx/0x4/0x1278/
    /END/
}
