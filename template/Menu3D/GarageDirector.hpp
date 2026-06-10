#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../CFL/cfl.hpp"
#include "../Object/TDirectorList.hpp"
#include "../Object/TLinkSocket.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"
#include "EOnlineState.hpp"
#include "EarthModel.hpp"
#include "EScene.hpp"
#include "EState.hpp"

#include <prim/seadDelegate.h>
#include <math/seadMatrix.h>

BEGIN_NAMESPACE(Menu3D)
{
    /START_CLASS/NAME@GarageDirector/SIZE@0xCC/BASE@Object::TDirectorList<Object::Actor, Object::TLinkSocket<Object::Actor, Object::Actor>>/BSIZE@0x28/
	public:
		virtual Object::DTIClassInfo *getDTIClassInfo() const;
		virtual Object::DTIClassInfo *getDTIClass() const;
		virtual void createBeforeStructure(const Object::ArgumentObj *);
		virtual void calcBeforeStructure();

		GarageDirector();
		void hideGlobe();
		void startEarthRotation(const EarthModel::Location &);
		void setScene(EScene);
		void calcAfterCameraUpdate();
		void fade(bool);
		void cancelBlind();
		void resumeMiiIntroduction(Mii::Face *);
		void hideMii();
		void getMiiStorage();
		void setMiiPoseMatrix(const sead::Matrix34f &);
		void freeMiiStorageByPlayerID(s32);
		void getMiiStorageByStorageID_withFree(s32);
		void clearMii(s32);
		void hideGarage();
		void deleteModel();
		void changeBody(RaceSys::EBodyID);
		void changeTire(RaceSys::ETireID);
		void changeWing(RaceSys::EWingID);
		void setKartMii(bool);
		void setMiiFace(Mii::Face *);
		void hideKartMii();
		void showKartMii(bool);
		void preserveMii_(Mii::Face *, Mii::Icon *);
		void onUpdateState_();
		void decideCharacter(s32, bool);
		void onWFCOKStateFunc();
		void updateTurnTable_();
		void isDecidedCharacter();
		void onMultiOKStateFunc();
		void onSingleOKInitFunc();
		void onWFCModeStateFunc();
		void requestChangeState(EState, bool);
		void resetEarthRotation(EState, bool);
		void onMultiEndStateFunc();
		void onSingleOKStateFunc();
		void onMultiModeStateFunc();
		void onSingleEndStateFunc();
		void startMiiIntroduction(s32, EOnlineState);
		void onSingleModeStateFunc();
		void onWFCOpponentStateFunc();
		void onWFCBattleCupStateFunc();
		void onWFCVersusCupStateFunc();
		void onMultiMatchingStateFunc();
		void onWFCBattleKartStateFunc();
		void onWFCConnectionStateFunc();
		void onWFCVersusKartStateFunc();
		void onMultiVersusCupStateFunc();
		void onWFCBattleGlobeStateFunc();
		void onWFCVersusGlobeStateFunc();
		void onMultiBattleKartStateFunc();
		void onMultiVersusKartStateFunc();
		void onWFCBattleCourseStateFunc();
		void onWFCBattleDriverStateFunc();
		void onWFCBattleMemberStateFunc();
		void onWFCVersusCourseStateFunc();
		void onWFCVersusDriverStateFunc();
		void onWFCVersusMemberStateFunc();
		void onMultiBattleRulesStateFunc();
		void onMultiVersusRulesStateFunc();
		void onSingleBattleKartStateFunc();
		void onSingleBattleRulesInitFunc();
		void onWFCBattleConfirmStateFunc();
		void onWFCGrandPrixKartStateFunc();
		void onWFCTimeTrialKartStateFunc();
		void onWFCVersusConfirmStateFunc();
		void onMultiBattleCourseStateFunc();
		void onMultiBattleDriverStateFunc();
		void onMultiGrandPrixCupStateFunc();
		void onMultiVersusCourseStateFunc();
		void onMultiVersusDriverStateFunc();
		void onSingleBattleRulesStateFunc();
		void onSingleGrandPrixCupInitFunc();
		void onMultiGrandPrixKartStateFunc();
		void onSingleBattleCourseStateFunc();
		void onSingleBattleDriverStateFunc();
		void onSingleGrandPrixCupStateFunc();
		void onSingleTimeTrialCupStateFunc();
		void onWFCGrandPrixDriverStateFunc();
		void onWFCTimeTrialDriverStateFunc();
		void onMultiGrandPrixClassStateFunc();
		void onSingleGrandPrixKartStateFunc();
		void onSingleTimeTrialKartStateFunc();
		void onMultiGrandPrixDriverStateFunc();
		void onSingleGrandPrixClassStateFunc();
		void onSingleTimeTrialGhostStateFunc();
		void onSingleGrandPrixDriverStateFunc();
		void onSingleTimeTrialCourseStateFunc();
		void onSingleTimeTrialDriverStateFunc();
		void showModel();
		void createModel(const Kart::KartPartsConstructParam &, bool);
		void cleanupModel();
		void getWingScale() const;
		void setUnlock(const Kart::KartPartsConstructParam &);
		void openLockDriver();
		void openWing();
		void closeWing();
		void getCameraPos() const;
		void isEndEarthRotation() const;
		void getShutterOpenRatio() const;
		void isEndMiiIntroduction() const;
		void isNormalEarthRotation() const;

		/M/CameraManager *m_camera_manager/0x4/0x28/
		/U/s32/0x4/0x2c/
		/M/EarthModel *m_earth_model/0x4/0x30/
		/M/FaderModel *m_fader_model/0x4/0x34/
		/M/GarageModel *m_garage_model/0x4/0x38/
		/M/MiiManager *m_mii_manager/0x4/0x3c/
		/M/PreviewPartsManager *m_preview_parts_manager/0x4/0x40/
		/M/sead::Delegate<GarageDirector> m_on_state_func/0x10/0x44/
		/U/s32/0x4/0x54/
		/U/s32/0x4/0x58/
		/U/s32/0x4/0x5c/
		/U/bool/0x1/0x61/
		/U/bool/0x1/0x62/
		/M/EScene m_scene/0x1/0x63/
		/M/EMode m_mode/0x1/0x64/
		/M/EState m_prev_state/0x1/0x65/
		/M/EState m_curr_state/0x1/0x66/
		/M/bool m_is_entering_state/0x1/0x67/
		/M/bool m_is_channel_mode/0x1/0x68/
		/U/s32/0x4/0x6c/
		/U/sead::Matrix34f/0x30/0x70/
		/M/RaceSys::EDriverID m_driver/0x4/0xa0/
		/U/f32/0x4/0xa4/
		/U/s32/0x4/0xa8/
		/M/Render::LightSet *m_lightset/0x4/0xac/
		/U/s32/0x4/0xb0/
		/M/Mii::Face *m_mii_face/0x4/0xb4/
		/M/CFLStoreData *m_my_mii_data/0x4/0xb8/
		/M/sead::Delegate2<GarageDirector, Mii::Face *, Mii::Icon *> m_preserve_mii_func/0x10/0xbc/
	/END/
}