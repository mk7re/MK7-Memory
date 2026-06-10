#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/ArgumentObj.hpp"

BEGIN_NAMESPACE(Sound){

    // TODO: Inherits from TDirectorBase
    /START_CLASS/NAME@SndSceneBase/SIZE@0x40/VTABLE@True/
    public:
        enum class EState : u8 {
            NONE,
            FADE_IN,
            ENTER,
            FADE_OUT,
            EXIT
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        static Object::DTIClassInfo *getDTIClassStatic();
        virtual ~SndSceneBase();
        virtual void calc();
        virtual void pauseOn(s32);
        virtual void pauseOff(s32);
        virtual void fadeIn(s32);
        virtual void stopAll(s32);
        virtual void createBeforeStructure(const Object::ArgumentObj *);
        virtual void createAfterStructure(const Object::ArgumentObj *);
        virtual void initBeforeStructure();
        virtual void fadeOut(s32);
        virtual void loadData();
        virtual void calcChild();
        virtual void calcFadeout();

        SndSceneBase();
        void stopSceneBgm(s32);
        void startSceneBgm(u32, s32);
        void holdSceneSysSe(u32);
        void startSceneSysSe(u32);

        /M/SndEngine *m_snd_engine/0x4/0x28/
        /M/SndBgm *m_snd_bgm/0x4/0x2c/
        /M/SndSysSe *m_snd_sys_se/0x4/0x30/
        /M/EState m_state/0x1/0x34/
        /M/s32 m_fade_frames/0x4/0x38/
        /M/bool m_pause_on/0x1/0x3c/
        /M/u8 m_0x3d/0x1/0x3d/
    /END/
};