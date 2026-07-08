#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../Object/Actor.hpp"
#include "../Object/ArgumentObj.hpp"
#include "../Util/TStateObserver.hpp"
#include "../Field/Entry/Area.hpp"
#include "../Camera/CameraBase.hpp"
#include "../RaceSys/ECourseID.hpp"

#include <container/seadPtrArray.h>
#include <prim/seadDelegate.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Demo)
{
    /START_CLASS/NAME@DemoCameraDirector/SIZE@0xA4/BASE@Object::Actor/BSIZE@0x8/
    public:
        enum class EState : u8 {
            INIT,
            NORMAL,
            NORMAL_WITH_DUMMY_START,
            START,
            GOAL,
            COURSE,         // Course introduction
            WINNING_RUN,
            WATCH_IMAGE     // Live view
        };

        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
		virtual Object::DTIClassInfo *getDTIClass() const; // 1
        virtual void create(Object::ArgumentObj const *); // 4
		virtual void init(); // 5
		virtual void calc(); // 6

        DemoCameraDirector();
        void start();
        void changeCamera();
        void changeCourseCamera();
        Demo::DemoCameraBase *createCamera_(Camera::CameraBase *, Field::MapdataCamera *, s32, bool);
        void stopDummyStartDemo();
        void changeFog_() const;
        s32 calcInAreaIndex_(const sead::Vector3f &, s32) const;
        bool isStartDemoFinished() const;
        void stateStart();
        void stateCourse();
        void stateNormal();
        void startGoalDemo();
        void stateInitGoal();
        void stateInitWait();
        void stopStartDemo();
        void stateInitStart();
        void startCourseDemo();
        void startWatchImage();
        void stateExitCourse();
        void stateExitNormal();
        void stateInitCourse();
        void stateInitNormal();
        void stateWatchImage();
        void stateWinningRun();
        void startWinningRunDemo();
        void stateExitWatchImage();
        void stateExitWinningRun();
        void stateInitWatchImage();
        void stateInitWinningRun();
        void stateNormalWithDummyStart();
        void stateExitNormalWithDummyStart();
        void stateInitNormalWithDummyStart();
        void stateGoal();
        void stateWait();
        
        /U/s32/0x4/0x8/
        /U/s32/0x4/0xc/
        /U/s32/0x4/0x10/
        /M/Util::TStateObserver<DemoCameraDirector> m_state_observer/0x20/0x14/
        /M/sead::PtrArray<Field::MapdataArea> m_mapdata_area_array/0xC/0x34/
        /M/sead::PtrArray<Camera::CameraBase> m_goal_cameras/0xC/0x40/
        // The cameras active in the course preview and awards
        /M/sead::PtrArray<Camera::CameraBase> m_demo_cameras/0xC/0x4c/
        /M/Camera::CameraBase *m_current_camera/0x4/0x58/
        /M/Demo::DemoCameraBase *m_current_demo_camera/0x4/0x5c/
        /M/Demo::DemoCameraGoal *m_goal_camera/0x4/0x60/
        /M/Demo::DemoCameraStart *m_start_camera/0x4/0x64/
        /M/Kart::InfoProxy *m_kart_info/0x4/0x68/
        /M/sead::Delegate<DemoCameraDirector> m_change_camera_delegate/0x10/0x6c/   // `Demo::DemoCameraDirector::changeCamera`
        /M/RaceSys::ECourseID m_course/0x4/0x7c/
        /M/s32 m_current_camera_index/0x4/0x80/ // Or current area index?
        /M/s32 m_next_camera_index/0x4/0x84/
        /M/s32 m_current_demo_camera_index/0x4/0x88/
        /M/s32 m_next_demo_camera_index/0x4/0x8c/
        /M/s32 m_camera_target_player_id/0x4/0x90/
        /M/s32 m_current_camera_active_time/0x4/0x94/
        // Current camera time while in `Demo::DemoCameraDirector::stateNormal`
        /M/s32 m_state_normal_current_camera_time/0x4/0x98/
        /M/bool m_is_initialized/0x1/0x9c/
        /U/u8/0x1/0x9d/
        /M/bool m_is_respawning/0x1/0x9e/
        /M/s8 m_goal_camera_index/0x1/0x9f/
        /M/bool m_is_replay/0x1/0xa0/
        /M/bool m_was_first_person/0x1/0xa1/
        /M/bool m_is_first_person/0x1/0xa2/
        /M/bool m_is_goal_camera_activated/0x1/0xa3/
    /END/
}