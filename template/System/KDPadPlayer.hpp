#pragma once

#include "../types.hpp"

#include "KDPad.hpp"
#include "KDPadAddBase.hpp"
#include "KDPadBinData.hpp"
#include "KDPadDirector.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@KDPadPlayer/SIZE@0x2804/BASE@KDPadAddBase/BSIZE@0x24/VTABLE@True/
    public:
        void calcState();
        void resetCore();
        void initInner();

        KDPadPlayer(KDPad *, KDPadDataOnFrame &);
        void create();
        bool calcPlay();
        void setBuffer(const KDPadBinData &);

        /M/KDPadBinData m_input_data/0x27d8/0x24/
        /M/KDPadDirector *m_director/0x4/0x27fc/
        /M/bool m_is_gyro_mode/0x1/0x2800/
        // Set to `true` when a player replay ends.
        /M/bool m_finished_replay_playback/0x1/0x2801/
    /END/
}
