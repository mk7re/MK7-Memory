#pragma once

#include "../types.hpp"

#include "LastingTask.hpp"
#include "../System/SaveDataManager.hpp"
#include "../CFL/cfl.hpp"

#include <prim/seadSafeString.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@BootTask/SIZE@0xBC/BASE@LastingTask/BSIZE@0x58/VTABLE@True/
    public:
        enum class EnterCode : s32
        {
            BOOT_SCENE,
            BOOT,
            FROM_FRIEND_LIST,
            DLC
        };

        enum class ReturnCode : s32
        {
            BOOT_SCENE,
            BOOT,
            FROM_FRIEND_LIST,
            DLC
        };

        enum class Mode : s32
        {
            DEFAULT
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
        virtual ~BootTask();
        virtual s32 onTaskStep();
        virtual s32 onTaskStart();

        s32 checkWithoutDialog();

        static void convertEnterCodeImpl(const sead::SafeString &);
        static void convertReturnCodeImpl(const sead::SafeString &);
        static void convertModeImpl(const sead::SafeString &);

        /M/System::SaveDataManager::ECommand m_save_command/0x1/0x58/
        /U/bool/0x1/0x59/
        /M/CFLStoreData m_mii/0x60/0x5c/
    /END/
}