#pragma once

#include "../types.hpp"

#include "Actor.hpp"

BEGIN_NAMESPACE(Object)
{
    template <typename T, typename Base, typename It>
    class TDirectorBase : public Base
    {
    public:
        virtual void create(ArgumentObj const *); // 4
		virtual void init(); // 5
		virtual void calc(); // 6
		virtual void render(); // 7
		virtual void renderMainL(); // 8
		virtual void renderMainR(); // 9
		virtual void renderSub(); // 10
		virtual void accept(ActorVisitor &); // 12
		virtual void initOuter();
        virtual void createBeforeStructure(const ArgumentObj *);
        virtual void createAfterStructure(const ArgumentObj *);
        virtual void initBeforeStructure();
        virtual void initAfterStructure();
        virtual void calcBeforeStructure();
        virtual void calcAfterStructure();
        virtual void renderBeforeStructure();
        virtual void renderAfterStructure();
        virtual void renderMainLBeforeStructure();
        virtual void renderMainLAfterStructure();
        virtual void renderMainRBeforeStructure();
        virtual void renderMainRAfterStructure();
        virtual void renderSubBeforeStructure();
        virtual void renderSubAfterStructure();

        // A list of actors
        It m_it;
        // Inside the `accept` functions, setting this to `true`
        // prevents the children actors from `m_it` to be visited
        bool m_stop_actor_children_traversal;
    };
    static_assert(sizeof(TDirectorBase<void *, Actor, void *>) == 0x10);
}