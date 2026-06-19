#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../versions.h"

#include "../Object/EEngineType.hpp"
#include "../Debug/ConfigLoader.hpp"

BEGIN_NAMESPACE(System)
{
#if GAME_VERSION == VERSION_E3_2010
    /START_CLASS/NAME@SystemEngine/SIZE@0x5C/
    public:
        /M/KDPadController *m_pad_controller/0x4/0x30/
        /M/Debug::ConfigLoader *m_config_loader/0x4/0x40/

        // 0x001ebab4
        static Debug::ConfigLoader *getConfigLoader();
    /END/

    // 0x001b95f4
    SystemEngine *getSystemEngine(Object::EEngineType);
#endif
}