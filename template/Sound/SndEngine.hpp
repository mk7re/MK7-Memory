#pragma once

#include "../Object/ActorEngine.hpp"
#include "../Object/TDirectorList.hpp"
#include "../Object/ArgumentObj.hpp"
#include "../System/SceneID.hpp"

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Sound)
{
    /START_CLASS/NAME@SndEngine/SIZE@0xB0/BASE@Object::TDirectorList<SndBase, Object::ActorEngine>/BSIZE@0x1C/
    public:
        // NOTE: guessed name
        /START_STRUCT/NAME@SDirectorList/SIZE@0x20/
            /M/SndSceneBoot *m_snd_scene_boot/0x4/0x0/
            /M/SndSceneMenu *m_snd_scene_menu/0x4/0x4/
            /M/SndSceneRace *m_snd_scene_race/0x4/0x8/
            /M/SndSceneTrophy *m_snd_scene_trophy/0x4/0xc/
            /M/SndSceneThankyou *m_snd_scene_thankyou/0x4/0x10/
            /M/SndSceneEnding *m_snd_scene_ending/0x4/0x14/
            /M/SndSceneDemo *m_snd_scene_demo/0x4/0x18/
        /END/

        void sceneEnter(System::SceneID);
        void startSound(SndHandle *, u32, void * /* nw::snd::SoundStartable::StartInfo* */);
        SndHandle *startSysSe(u32);
        void stopTitleBgm();
        SndSysSe *getSceneSysSe();
        bool isScenePaused();
        void loadSceneData();
        void setAppletMute(bool);
        void setDialogMute(bool);
        void startSceneBgm(u32, s32);
        void startTitleBgm();
        void holdSceneSysSe(u32);
        void enterHomeButton();
        void leaveHomeButton(bool);
        void startSceneSysSe(u32);
        bool isSceneFinishedFadeOut();
        void fadeIn(s32);
        void fadeOut(s32);
        void holdSound(SndHandle *, u32, void * /* nw::snd::SoundStartable::StartInfo* */);
        SndEngine();

        using creator_t = void (*)(SndEngine *, SDirectorList *);

        /M/SDirectorList *m_director_list/0x4/0x84/
    /END/
}