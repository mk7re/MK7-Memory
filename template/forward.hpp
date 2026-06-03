#pragma once

#include "types.hpp"

BEGIN_NAMESPACE(BoxCol)
{
	class Manager;
	class Unit;
}

BEGIN_NAMESPACE(Camera)
{
	class CameraBase;
	class CameraEngine;
	class KartCameraDirector;
}

BEGIN_NAMESPACE(CSVUtil)
{
	class CSVParam;
}

BEGIN_NAMESPACE(Demo)
{
	class DemoCameraDirector;
}

BEGIN_NAMESPACE(Effect)
{
	class EffectEngine;
	class GameEffectDirector;
	class GameParticle;
	class GPUPtclStripe;
	class GPUPtclStripeImpl;
	class KartEffect;
	class ParticleDrawer;
}

BEGIN_NAMESPACE(Enemy)
{
	class AI;
	class AIAutoSteer;
	class AIBattleManager;
	class AIBlockLine;
	class AIControlBase;
	class AIDriftDrive;
	class AIInfo;
	class AIItemBase;
	class AIManager;
	class AIObjectManager;
	class AIParamLoader;
	class AIParamLoader;
	class AIPathHandler;
	class AIPathManager;
	class AIPathManager;
	class AIPathPoint;
	class AIProbabilityBase;
	class AIRank;
	class AIRankManager;
	class AISpeedRaceBase;
	class AIStuck;
	class DriveInfo;
}

BEGIN_NAMESPACE(Field)
{
	class ClipContext;
	class CourseInfo;
	class FieldDirector;
	class MapdataAreaAccessor;
	class MapdataAreaCalcBase;
	class MapdataCameraAccessor;
	class MapdataCannonPointAccessor;
	class MapdataCheckPathAccessor;
	class MapdataCheckPointAccessor;
	class MapdataCourseAccessor;
	class MapdataEnemyPathAccessor;
	class MapdataEnemyPointAccessor;
	class MapdataGeoObjAccessor;
	class MapdataGlidePointAccessor;
	class MapdataGlidePathAccessor;
	class MapdataItemPathAccessor;
	class MapdataItemPointAccessor;
	class MapdataJugemPoint;
	class MapdataJugemPointAccessor;
	class MapdataMissionPointAccessor;
	class MapdataPath;
	class MapdataPathAccessor;
	class MapdataStageAccessor;
	class MapdataStartPointAccessor;
	class MenuVRModel;
	class ObjectDirector;
	class QuadTree;
	class ObjectBase;
}

BEGIN_NAMESPACE(Item)
{
	class ItemDirector;
	class ItemObjBanana;
	class ItemObjBananaDirector;
	class ItemObjBase;
	class ItemObjBomhei;
	class ItemObjBomheiDirector;
	class ItemObjDirectorBase;
	class ItemObjFlower;
	class ItemObjFlowerDirector;
	class ItemObjGesso;
	class ItemObjGessoDirector;
	class ItemObjKiller;
	class ItemObjKillerDirector;
	class ItemObjKinoko;
	class ItemObjKinokoDirector;
	class ItemObjKouraB;
	class ItemObjKouraBDirector;
	class ItemObjKouraG;
	class ItemObjKouraGDirector;
	class ItemObjKouraR;
	class ItemObjKouraRDirector;
	class ItemObjSevenDirector;
	class ItemObjStar;
	class ItemObjStarDirector;
	class ItemObjTail;
	class ItemObjTailDirector;
	class ItemObjThunder;
	class ItemObjThunderDirector;
	class ItemReactProxy;
	class ItemSlot;
	class ItemSlotTable;
	class KartItem;
	class KartItemProxy;
}

BEGIN_NAMESPACE(Jugem)
{
	class Director;
	class Switch;
	class SwitchCountDown;
	class SwitchGoal;
	class SwitchLap;
	class SwitchLift;
	class SwitchReverse;
	class Unit;
}

BEGIN_NAMESPACE(Kart)
{
	class KartConstructInfoAccessor;
	class DriverCallback;
	class DriverHop;
	class GhostVisible;
	class WingPathData;
	class PullPathData;
	class Camera;
	class Director;
	class DispBody;
	class DispKiller;
	class DispWing;
	class Driver;
	class InfoProxy;
	class KartPartsConstructParam;
	class KartPartsCustomedParam;
	struct NetData;
	class PartsDriveParam;
	class ReplayInfo;
	class Rigid;
	class Unit;
	class Vehicle;
	class VehicleBase;
	class VehicleControl;
	class VehicleControlAI;
	class VehicleControlNet;
	class VehicleMove;
	class VehicleReact;
}

BEGIN_NAMESPACE(KDGndCol)
{
	class Manager;
	class CheckIF_EX;
}

BEGIN_NAMESPACE(LibEffect)
{
	class Particle;
}

BEGIN_NAMESPACE(Menu3D)
{
	class CameraManager;
	class EarthModel;
	class FaderModel;
	class GarageDirector;
	class GarageModel;
	class MiiManager;
	class ModelCreateManager;
	class PreviewPartsManager;
	class SimpleModelManager;
}

BEGIN_NAMESPACE(Mii)
{
	class Face;
	class FaceManager;
	class Factory;
	class HiddenDatabase;
	class Icon;
	class IconManager;
	class MiddleDatabase;
	class MiiEngine;
	class MiiRenderCommand;
	class RandomDatabase;
}

BEGIN_NAMESPACE(miisel)
{
	class Parameter;
	class Result;
}

BEGIN_NAMESPACE(Net)
{
	class NetworkBuffer;
	class NetworkBufferController;
	class NetworkEngine;
	class NetworkErrorHandler;
	class NetworkEventModule;
	class NetworkFriendsManager;
	class NetworkGameMgr;
	class NetworkItemEventDataMgr;
	class NetworkPlayerData;
	class NetworkPlayerDataManager;
	class NetworkReceivedInfo;
	class NetworkSelectMenuProcess;
	class NetworkSystemInfo;
	class NetworkStationBufferManager;
}

BEGIN_NAMESPACE(Object)
{
	class Actor;
	class Actor3DMdl;
	class Actor3DMdlList;
	class ActorEngine;
    class ActorVisitor;
	class BattleObjectMgrBase;
	class CharacterEngine;
	class DTIClassInfo;
	class Trophy3DModelManager;
}

BEGIN_NAMESPACE(RaceSys)
{
	class BalloonRankChecker;
	class CoinRankChecker;
	class CRaceInfo;
	class CRaceMode;
	class CTime;
	class KartInfo;
	class LapRankChecker;
	class LogRecorder;
	class ModeManagerBase;
	class ModeManagerBattle;
	class RaceDirector;
	class RaceTimer;
	class CFrameWatch;
}

BEGIN_NAMESPACE(Render)
{
	namespace RaceLight
	{
		class LightObj;
	}

	class DrawMdl;
	class LightSet;
	class RenderEngine;
	class ShadowVolume;
	class UIDrawDirector;
	class UIDrawDirectorFast;
	class UIDrawDirectorProxy;
}

BEGIN_NAMESPACE(Sequence)
{
	class AIRivalTableLoader;
	class BgPage;
	class BasePage;
	class BaseRacePage;
	class BaseMenuPage;
	class ClearRaceInfoTask;
	class Common_SystemDialog;
	class CrossFadeSequence;
	class DashEngineCreatorManager;
	class DashSceneIDConverter;
	class DashSequenceEngine;
	class DashSectionClassManager;
	class DummyPage;
	class DelegateSequence;
	class ExecutableSection;
	class FaderPage;
	class LayeredSequence;
	class MenuData;
	class MenuSingle_Ghost;
	class MenuSingle_GhostLoad;
	class MenuSingle_Chara;
	class MenuWifi_Confirm;
	class Menu_UpBarController;
	class MenuTitle;
	class NetworkErrorChecker;
	class Page;
	class ParallelSequence;
	class PracticalSection;
	class RacePage;
	class SceneSequence;
	class SceneSequenceProxy;
	class Section;
	class SectionDirector;
	class SectionClassManager;
	class SectionClassInfoBase;
	class SequenceEngine;
	class SequenceIDTable;
	class SequenceLayer;
	class SerialSequence;
	class TimerPage;
	class TimeAttackChart;
	class SequenceResource;
}

BEGIN_NAMESPACE(Sound)
{
	class SndActorBase;
	class SndActorItem;
	class SndActorKart;
	class SndBase;
	class SndBgm;
	class SndEngine;
	class SndHandle;
	class SndSceneBase;
	class SndSceneBoot;
	class SndSceneDemo;
	class SndSceneEnding;
	class SndSceneMenu;
	class SndSceneRace;
	class SndSceneThankyou;
	class SndSceneTrophy;
	class SndSysSe;
}

BEGIN_NAMESPACE(System)
{
	class KDPlayerPad;
	class BackgroundLoadThread;
	class BackgroundThread;
	class BackupManager;
	class BootRenderThread;
	class BootPictureBase;
	class BootPictureIcon;
	class ControllerBase;
	class EngineHolder;
	class GameFramework;
	class GhostLoader;
	class GameSetting;
	class GameScene;
	class GhostSaveData;
	class GhostSaveDataHeader;
	class KDAIPad;
	class KDPad;
	class KDPadAddBase;
	class KDPadControllerCore;
	class KDPadDirector;
	class KDPadInputer;
	class KDPadMirrorInputer;
	class KDPadPlayer;
	class KDPlayerRecordPad;
	class KDReplayPad;
	class KDUIPad;
	class KDThread;
	class MobiClipThread;
	class MobiClipThreadProxy;
	class PlayerData;
	class ResourceLoader;
	class RootScene;
	class RootSystem;
	class SaveDataManager;
	class Scene;
	class GfxFrmHeap;
	class SceneManager;
	class SystemEngine;
	class ThreadManager;
	struct PlayerDataNoMii;
	struct SystemSaveData;
	class VideoDrawerThread;
	class AppletLauncher;
	class AppletLaunchThread;
	class MobiClipThread;
	class MobiClipThreadProxy;
}

BEGIN_NAMESPACE(UI)
{
	class BattleCountDownControl;
	class BackButton;
	class BackButtonB;
	class BackButtonT;
	class BaseResultBar;
	class BgRaceMapBombControl;
	class BgRaceMapCharaControl;
	class BgRaceMapControl;
	class BgView;
	class Control;
	class ControlAnimator;
	class ControlInitializer;
	class ControlSight;
	class CursorMove;
	class DashMessageWriter;
	class DashFontManager;
	class FontManager;
	class NullControlSight;
	class NwlytControlSight;
	class NwlytDummyControlSight;
	class NwlytDivControlSight;
	class NwlytDivPartControlSight;
	class NwlytDivRootControlSight;
	class NwlytControlAnimator;
	class NwlytDivControlAnimator;
	class NwlytResourceAccessor;
	class MenuButton;
	class MenuButtonMch;
	class MenuCharaName;
	class MenuCourseName;
	class MenuPartsName;
	class MenuWaitMark;
	class MessageData;
	class MessageIDConverter;
	class MessageWriter;
	class MessageString;
	class OKButton;
	class OKButton2;
	class OKButton3;
	class TexIDConverter;
	class TimeControl;
	class TitleInfoIcon;
	class TitleInfoIcon2;
	class Page;
	class PresentBox;
	class PresentBoxBg;
	class GraphicResourceInfo;
	class ControlDirector;
	class ControlInitializer;
	class Manipulator;
	class BaseMenuButtonControl;
	class BaseMenuInputControl;
	class CursorItem;
	class TouchItem;
	class SelectTimer;
	class RaceNoTextControl;
	class RaceTextControl;
	class RaceRankControl;
	class RaceRankNameControl;
	class RacePauseControl;
	class RaceBasicButton;
	class RaceCloseButton;
	class RaceLiveControl;
	class RaceNewRecordControl;
	class ResultBg;
	class ResultBgTA;
	class ResultBar;
	class ResultBarBT;
	class ResultBarTA;
	class ResultBarTeam;
	class ResultBarWiFi;
	class ResultBattlePoint;
	class RaceTimeupControl;
	class CoinControl;
	class LapControl;
	class PointControl;
	class BgRaceMapLoopControl;
	class ScrollList;
	class ScrollListBarBase;
	class ScrollListFrame;
	class ScrollListBg;
	class MenuCaption;
	class MenuClassCaption;
	class UIMenuMiiBarController;
	class MiiBar;
	class MiiStrBar;
	class MiiGroupBar;
	class MiiCheckBar;
	class ChartMeter;
	class ChartDot;
	class ChartGhost;
	class ChartGhostSelect;
	class MenuDialogBody;
	class MenuDialogHalfBody;
	class SystemDialogButton;
	class GessoControl;
	class EndingMovieView;
	class StaffRoll;
}

BEGIN_NAMESPACE(Util)
{
	class ExcelORManager;
	class Shape;
}

BEGIN_NAMESPACE(Utility)
{
	class Random;
}