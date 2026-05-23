#pragma once

#include "../common.hpp"
#include "../types.hpp"
#include "../forward.hpp"

#include "../System/GhostLoader.hpp"

#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@GhostList/SIZE@0x280/
    public:
        /START_STRUCT/NAME@GhostPtr/SIZE@0x8/
            enum GhostType : u32 {
                PLAYER_GHOST,
                STAFF_GHOST,
                RANKING_GHOST   // SpotPass / StreetPass ghost
            };

            /M/s32 m_ghost_type/0x4/0x0/
            /M/s32 m_index/0x4/0x4/
        /END/

        void getSelect7(s32 *);
        void selectRandom(s32, s32, s32, s32);
        void init(System::GhostLoader *);
        void clear();
        void select(s32);
        void select7();
        static s32 cmpGhost(const GhostPtr *, const GhostPtr *);
        const System::GhostSaveDataHeader &getHeader(s32) const;
        GhostList();

        /M/System::GhostLoader *m_ghost_loader/0x4/0x0/
        /M/sead::PtrArray<GhostPtr> m_ghost_ptr_array/0xC/0x4/
        /U/GhostPtr */0x4/0x10/
        /U/GhostPtr */0x4/0x14/
        /M/GhostPtr m_ghost_ptr_array_buffer[GHOST_LIST_MAX]/0xb8/0x18/
        /M/System::GhostLoader::GhostData *m_ghost_list[GHOST_LIST_MAX]/0x5c/0xd0/
        /M/s32 m_num_ghosts/0x4/0x12c/
        /M/s32 m_num_player_ghosts/0x4/0x130/
        /M/s32 m_num_staff_ghosts/0x4/0x134/
        /M/s32 m_num_ranking_ghosts/0x4/0x138/
        /M/s32 m_selected_ghost_idx/0x4/0x13c/
        /M/s32 m_selected_ghosts[7]/0x1c/0x140/
        /U/s32/0x4/0x16c/
        /U/s32/0x4/0x170/
        /M/s32 unk_0x174[GHOST_LIST_MAX - 1]/0x58/0x174/
        /U/s32/0x4/0x27c/
    /END/
}