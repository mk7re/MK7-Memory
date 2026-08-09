#pragma once

#include "../types.hpp"

#include "TDirectorBase.hpp"

#include "../Util/TClassPtrArray.hpp"

BEGIN_NAMESPACE(Object)
{
    template <typename T, typename Base>
    class TDirectorArray : public TDirectorBase<T, Base, Util::TClassPtrArray<T>> {
    public:
        void deleteActor(T*);
    };
    static_assert(sizeof(TDirectorArray<void *, Actor>) == 0x1C);
}