#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/Actor.hpp"
#include "../Object/TDirectorArray.hpp"

BEGIN_NAMESPACE(System)
{
    /START_CLASS/NAME@SystemEngine/SIZE@0xFC/BASE@Object::TDirectorArray<Object::Actor, Object::ActorEngine>/BSIZE@0x1C/
    public:
        /M/ControllerBase *m_controller_base/0x4/0x1C/
        /M/ResourceLoader *m_resource_loader/0x4/0x20/
        /M/BackupManager *m_backup_manager/0x4/0x24/
        /M/SaveDataManager *m_save_data_manager/0x4/0x28/
        /M/KDPadDirector *m_pad_director/0x4/0x3c/
        /M/GameSetting *m_game_setting/0x4/0x40/
        /M/AppletLaunchThread *m_applet_launch_thread/0x4/0x54/
        /M/BackgroundThread *m_background_thread/0x4/0x58/
        /M/BackgroundLoadThread *m_background_load_thread/0x4/0x5C/
    /END/

    void getMyPlayerData(PlayerData *, bool);
}