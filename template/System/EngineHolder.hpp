#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../versions.h"

#include "../Object/ActorEngine.hpp"
#include "../Object/EEngineType.hpp"

#include <utility>

BEGIN_NAMESPACE(System)
{
    class EngineHolder
    {
        auto static constexpr ENGINE_KEY = u32{0x75F1B26B};

    public:
        struct Priority
        {
            s16 m_0x0;
            s8 m_0x2;
            s8 m_0x3;
        };
        static_assert(sizeof(Priority) == 0x4);

        class EngineManager
        {
        public:
            virtual ~EngineManager() = default;

            struct SEngineInfo
            {
                Object::ActorEngine *engine;
                bool exists;
                Priority priority;
            };
            static_assert(sizeof(SEngineInfo) == 0xC);

            inline auto const &get_engine_info(Object::EEngineType type) const { return m_engine_infos[std::to_underlying(type)]; }

            SEngineInfo m_engine_infos[std::to_underlying(Object::EEngineType::MAX)];
        };
        static_assert(sizeof(EngineManager) == 0x7C);

        template <typename t>
        inline t *get_engine(Object::EEngineType type) const
        {
            auto const &engine_info = m_engine_manager.get_engine_info(type);
            return engine_info.exists ? reinterpret_cast<t *>(reinterpret_cast<decltype(ENGINE_KEY)>(engine_info.engine) ^ ENGINE_KEY) : nullptr;
        }

        void setEngine(Object::ActorEngine *, Object::EEngineType, const Priority &);
#if GAME_VERSION == VERSION_E3_2010
        ActorEngine *getEngine(Object::EEngineType);
#endif

        EngineManager m_engine_manager;
        // It's not clear if this gap is here or in RootScene.
        u8 gap_0x7C[0x10];
    };
    static_assert(sizeof(EngineHolder) == 0x8C);
}