#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "SndHandle.hpp"
#include "SndSceneBase.hpp"
#include "EMenuPage.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndSceneMenu/SIZE@0xA4/BASE@SndSceneBase/BSIZE@0x40/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~SndSceneMenu();
        virtual void pauseOn(s32);
        virtual void pauseOff(s32);
        virtual void fadeIn(s32);
        virtual void createAfterStructure(const Object::ArgumentObj *);
        virtual void calcAfterStructure();
        virtual void fadeOut(s32);
        virtual void loadData();

        SndSceneMenu();
        void pageComplete(s32);
        void playKartMoveSe(s32);
        void holdKartRunbleSe(s32);
        void changeTrackStatus(u32, s32);
        void holdKartSlotRollSe(s32, f32);
        void startPresentFanfare();
        void pageEnter(EMenuPage);

        /M/EMenuPage m_current_menu/0x4/0x4c/
        /M/EMenuPage m_previous_menu/0x4/0x50/
        /M/SndHandle m_snd_handle/0x4/0x54/
        /U/bool/0x1/0x58/
        /U/bool/0x1/0x59/   // Set to `true` when unlocking something?
        /M/u32 m_track_status/0x4/0x5c/
    /END/
};