#pragma once

#include "../types.hpp"

#include "TDirectorBase.hpp"

#include "../Util/TIndLinkList.hpp"

BEGIN_NAMESPACE(Object)
{
    template <typename T, typename Base>
    class TDirectorList : public TDirectorBase<T, Base, Util::TIndLinkList<T>> {
    public:
        template<typename TDirector>
        TDirector* createDirector();
    };
    static_assert(sizeof(TDirectorList<void *, Actor>) == 0x1C);
}