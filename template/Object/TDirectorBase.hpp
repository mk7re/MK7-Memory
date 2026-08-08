#pragma once

#include "../types.hpp"

#include "Actor.hpp"

BEGIN_NAMESPACE(Object)
{
    template <typename T, typename Base, typename It>
    class TDirectorBase : public Base
    {
    public:
        // A list of actors
        It m_it;
        // Inside the `accept` functions, setting this to `true`
        // prevents the children actors from `m_it` to be visited
        bool m_stop_actor_children_traversal;
    };
    static_assert(sizeof(TDirectorBase<void *, Actor, void *>) == 0x10);
}