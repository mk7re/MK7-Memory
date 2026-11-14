#pragma once

#include "../forward.hpp"
#include "../types.hpp"
#include "../Object/Actor.hpp"
#include "../Object/ArgumentObj.hpp"
#include "../Util/TStateObserver.hpp"
#include "../Field/Entry/Area.hpp"
#include "../Camera/CameraBase.hpp"
#include "../RaceSys/ECourseID.hpp"
#include "../Util/TLinkNode.hpp"

#include <container/seadPtrArray.h>
#include <prim/seadDelegate.h>
#include <math/seadVector.h>

BEGIN_NAMESPACE(Demo)
{
    /START_CLASS/NAME@DemoCameraDirector/SIZE@0xA4/BASE@Object::Actor/BSIZE@0x8/
    public:
        enum class EState : u8 {
            WAIT,
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
        
        /M/Util::TLinkNode<DemoCameraDirector> m_node/0xC/0x8/
        /M/Util::TStateObserver<DemoCameraDirector> m_state_observer/0x20/0x14/
        /M/sead::PtrArray<Field::MapdataArea> m_mapdata_area_array/0xC/0x34/
        // One camera per entry of m_mapdata_area_array, built from the CAME entry of that camera area. Areas whose
        // camera is of type GOAL or has a non-zero m_video_next are left out of both arrays
        /M/sead::PtrArray<Demo::DemoCameraBase> m_area_cameras/0xC/0x40/
        // The cameras of the course intro and the award ceremony, in the order of their m_next links
        /M/sead::PtrArray<Demo::DemoCameraBase> m_demo_cameras/0xC/0x4c/
        /M/Camera::CameraBase *m_current_camera/0x4/0x58/
        /M/Demo::DemoCameraBase *m_current_demo_camera/0x4/0x5c/
        /M/Demo::DemoCameraGoal *m_goal_camera/0x4/0x60/
        /M/Demo::DemoCameraStart *m_start_camera/0x4/0x64/
        /M/Kart::InfoProxy *m_kart_info/0x4/0x68/
        /M/sead::Delegate<DemoCameraDirector> m_change_camera_delegate/0x10/0x6c/   // `Demo::DemoCameraDirector::changeCamera`
        /M/RaceSys::ECourseID m_course/0x4/0x7c/
        /M/s32 m_area_index/0x4/0x80/ // index in m_mapdata_area_array of the camera area the kart is in, -1 none
        /M/s32 m_next_area_index/0x4/0x84/
        /M/s32 m_demo_camera_index/0x4/0x88/ // index in m_demo_cameras
        /M/s32 m_next_demo_camera_index/0x4/0x8c/
        /M/s32 m_camera_target_player_id/0x4/0x90/
        /M/s32 m_state_timer/0x4/0x94/ // frames in the current state (course intro, award ceremony, goal)
        // Frames spent outside every camera area, or inside one while m_is_out_of_area is set
        /M/s32 m_area_switch_timer/0x4/0x98/
        /M/bool m_is_initialized/0x1/0x9c/
        /U/u8/0x1/0x9d/
        /M/bool m_is_respawning/0x1/0x9e/
        /M/bool m_is_out_of_area/0x1/0x9f/ // the kart camera is shown because the kart left the camera areas
        /M/bool m_is_replay/0x1/0xa0/
        /M/bool m_was_first_person/0x1/0xa1/
        /M/bool m_is_first_person/0x1/0xa2/
        // Set to `true` when displaying the dynamic demo cameras.
        // Otherwise (regular 3rd and 1st person camera) false
        /M/bool m_is_demo_camera_activated/0x1/0xa3/
    /END/
}