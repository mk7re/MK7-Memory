#pragma once

#include "../common.hpp"
#include "../types.hpp"
#include "../forward.hpp"
#include "../versions.h"
#include "../System/GhostSaveData.hpp"
#include "../Item/eItemSlot.hpp"
#include "../Item/eItemType.hpp"
#include "RaceSys/CRaceMode.hpp"
#include "BasePage.hpp"

#include <nw/lyt/TextureInfo.hpp>
#include <prim/seadDelegate.h>
#include <container/seadPtrArray.h>
#include <prim/seadSafeString.hpp>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@BaseRacePage/SIZE@0x31FC/BASE@BasePage/BSIZE@0x26C/VTABLE@True/
    public:
        enum class ReturnCode : s32
        {
            SINGLEGP_NEXT,
            SINGLEGP_REPLAY,
            SINGLEGP_EXIT,
            SINGLEGP_TROPHY,
            SINGLETA_RETRY,
            SINGLETA_CHARA,
            SINGLETA_COURSE,
            SINGLETA_REPLAY,
            SINGLETA_RANK,
            SINGLETA_EXIT,
            SINGLEBT_NEXT,
            SINGLEBB_COURSE,
            SINGLEBC_COURSE,
            SINGLEBT_EXIT,
            SINGLEBT_TROPHY,
            MULTIGP_NEXT,
            MULTIGP_EXIT,
            MULTIGP_TROPHY,
            MULTIVS_NEXT,
            MULTIVS_COURSE,
            MULTIVS_EXIT,
            MULTIVS_TROPHY,
            MULTIBT_NEXT,
            MULTIBB_COURSE,
            MULTIBC_COURSE,
            MULTIBT_EXIT,
            MULTIBT_TROPHY,
            WIFIVS_NEXT,
            WIFIVS_EXIT,
            WIFIBT_NEXT,
            WIFIBT_EXIT,
            COMMU_TROPHY,
            COMMU_COURSE,
            DEBUG_RETRY,
            DEBUG_EXIT,
            DEBUG_RELOAD
        };

        enum class ERaceState : u8
        {
            COUNTDOWN,
            RACE,
            PAUSE,
            GOAL,
            ON_RESULT,
            ON_NEXT_MENU,

            MAX
        };

        // NOTE: Name is made up
        /START_STRUCT/NAME@PauseButtons/SIZE@0x18/
            /M/UI::RaceCloseButton *m_button_1/0x4/0x0/
            /M/UI::RaceBasicButton *m_button_2/0x4/0x4/
            /M/UI::RaceBasicButton *m_button_3/0x4/0x8/
            /M/UI::RaceCloseButton *m_button_4/0x4/0xc/
            /M/UI::RaceBasicButton *m_button_5/0x4/0x10/
            /M/UI::RaceBasicButton *m_button_6/0x4/0x14/
        /END/

        // NOTE: Name is made up
        /START_STRUCT/NAME@NextButtons/SIZE@0x14/
            /M/UI::RaceBasicButton *m_button_1/0x4/0x0/
            /M/UI::RaceBasicButton *m_button_2/0x4/0x4/
            /M/UI::RaceBasicButton *m_button_3/0x4/0x8/
            /M/UI::RaceBasicButton *m_button_4/0x4/0xc/
            /M/UI::RaceBasicButton *m_button_5/0x4/0x10/
        /END/

        virtual Object::DTIClassInfo *getDTIClassInfo() const;
        virtual Object::DTIClassInfo *getDTIClass() const;
        virtual ~BaseRacePage();
        virtual void enter(Section::EFadeKind, u32);
        virtual void complete();
        virtual void exit();
        virtual void onPagePreStep();
        virtual bool canFinishFadein();
        virtual bool canFinishFadeout();
        virtual void calcItemIcon();
        virtual void onPageFadeout();
        virtual void buttonHandler_OK(s32);
        virtual void onMenuEnter();
        virtual void onMenuComplete();
        virtual void onMenuExit();

        BaseRacePage();
        void emitEffectGesso();
        void sub_thunder(s32);
        void sub_killerOff(s32);
        void sub_thunderOff(s32);
        void sub_vanish(s32);
        void sub_killer(s32);
        void applyPoint();
        void calcResult();
        void detachFunc();
        void initCommon();
        void initEffect();
        void initNameTA();
        void resultCalc();
        void saveTrophy();
        void showResult(bool);
        void initCaption();
        void initMapIcon();
        void loadTexture();
        void resultEnter();
        void setItemIcon();
        void sub_bombRed(const sead::Vector3f &);
        void sub_getItem(s32, Item::eItemSlot);
        void sub_leafOff(s32);
        void sub_loopOff(UI::BgRaceMapLoopControl*);
        void sub_useItem(s32);
        void updatePoint();
        void calcNextMenu();
        void callbackGoal();
        void drawItemIcon(s32);
        s32 getBestGhost();
        void initItemSlot();
        void item_useAnim();
        void saveCecParts();
        void setRaceState(ERaceState);
        void sub_bombBlue(const sead::Vector3f &);
        void sub_goalKart(s32);
        void sub_lostItem(s32);
        void sub_moveItem(Item::eItemType, s32);
        void calcCountDown();
        void calcRankBoard();
        void initRankBoard();
        void sub_equipItem(Item::eItemType, s32, s32);
        void checkNewRecord();
        void checkWatchSync();
        void enterLensFlare();
        void enterRankBoard();
        void sub_getItemBox(s32);
        void item_useKinoko2(s32);
        void item_useKinoko3(s32);
        void calcRankBoardOut();
        void loadCharaTexture(RaceSys::EDriverID, s32);
        void sortByTotalPoint(s32 *, s32);
        void checkGhostNotSave(u32);
        void sub_disappearItem(Item::eItemType, s32);
        void updateBattlePoint();
        void sub_setItemVisible(Item::eItemType, s32, bool);
        void initBattleCountDown();
        void initDrawPriorityBar();
        void swapDrawPriorityBar(UI::RaceRankNameControl *, UI::RaceRankNameControl *);
        void initDrawPriorityItem();
        void showForceFinishCaption(u32);
        void animWin();
        void initLap();
        void initMap();
        void pauseOn(bool);
        void calcGoal();
        void calcRace();
        void calcSave();
        void initCoin();
        void initName();
        void initRank();
        void initText();
        void initWipe();
        void sub_leaf(s32);
        void sub_loop(UI::BgRaceMapLoopControl *);
        void calcInput();
        void calcPause();
        void calcPoint();
        void changeMap(bool);
        void countDown();
        void initPoint();
        void pauseExit();
        void saveGrade();
        void initTime();
        void reloadGhostReplay();
        void reloadGhost(const System::GhostSaveData &);
#if GAME_VERSION != ALL_DLP
        void saveRankingData();     // 0x0047e014 (VERSION_USA_REV1)
#endif

        static void convertReturnCodeImpl(s32);

        template <typename T>
        T *setupResultControl(const sead::SafeString &, const sead::SafeString &);

        /M/RaceSys::CRaceMode m_race_mode/0xC/0x26C/
        /M/UI::RaceItemBoxControl *m_race_itembox_control/0x4/0x280/
        /M/UI::RaceItemEquipControl *m_race_item_equip_control/0x4/0x284/
        /M/UI::RaceRankControl *m_race_rank_control/0x4/0x288/
        /M/UI::LapControl *m_lap_control/0x4/0x290/
        /M/UI::CoinControl *m_coin_control/0x4/0x294/
        /M/UI::PointControl *m_point_control/0x4/0x298/
        /M/UI::BgRaceMapControl *m_current_bg_race_map_control/0x4/0x29C/
        /M/UI::BgRaceMapControl *m_bg_race_map_control/0x4/0x2A0/
        /M/UI::BgRaceMapControl *m_bg_race_zoom_map_control/0x4/0x2A4/
        /M/UI::BgRaceMapCharaControl *m_bg_race_map_chara_control[KART_MAX]/0x20/0x2A8/
        /M/UI::MenuCaption *m_menu_caption/0x4/0x318/
        /M/UI::SelectTimer *m_select_timer/0x4/0x31c/
        /M/UI::ResultBg *m_result_bg/0x4/0x320/
        /M/PauseButtons m_pause_buttons/0x18/0x324/
        /M/NextButtons m_next_buttons/0x14/0x33c/
        /M/UI::GessoControl *m_gesso_control/0x4/0x354/
        /M/UI::RaceNoTextControl *m_race_no_text_control/0x4/0x368/
        /M/UI::RaceTextControl *m_race_text_control/0x4/0x36c/
        /M/UI::RaceTimeupControl *m_race_timeup_control/0x4/0x370/
        /M/UI::RacePauseControl *m_race_pause_control/0x4/0x374/
        /M/UI::RaceNewRecordControl *m_race_new_record_control/0x4/0x378/
        /M/UI::RaceLiveControl *m_race_live_control/0x4/0x37c/
        /M/UI::BgView *m_race_live_bg_view/0x4/0x380/
        /M/UI::BattleCountDownControl *m_battle_countdown_control/0x4/0x384/
        /M/RaceSys::ModeManagerBase *m_mode_manager/0x4/0x388/
        /M/RaceSys::ModeManagerBattle *m_mode_manager_battle/0x4/0x38c/
        /M/Kart::InfoProxy *m_player/0x4/0x390/
        /M/ERaceState m_race_state/0x1/0x398/
        /M/u32 m_player_num/0x4/0x39c/
        /M/u32 m_target_player_id/0x4/0x3a0/
        /M/bool m_display_rankboard/0x1/0x3a4/
        /M/bool m_update_rankboard/0x1/0x3a5/
        /M/s32 m_time_before_switching_to_results/0x4/0x3a8/
        /M/s32 m_race_new_record_display_timer/0x4/0x3ac/
        /M/s32 m_on_back_return_code/0x4/0x3b4/
        /M/u8 m_fader_type/0x4/0x3b8/
        /M/sead::Delegate<BaseRacePage> m_calc_state_delegate[static_cast<u32>(ERaceState::MAX)]/0x60/0x3bc/    // One per ERaceState
        /M/sead::Delegate<BaseRacePage> m_calc_input_delegate/0x10/0x41c/
        /M/bool m_is_single_player_or_master_player_replay/0x1/0x42c/
        /M/bool m_can_pause/0x1/0x42d/      // Can pause the game while in-race. Set to `false` for multiplayer and online
        /M/s32 m_on_exit_return_code/0x4/0x438/
        /M/u8 m_calc_save_state/0x1/0x440/
        /M/bool m_change_calc_save_state/0x1/0x441/
        /M/bool m_request_save/0x1/0x442/
        /M/bool m_is_new_save/0x1/0x443/
        /M/bool m_not_time_trial/0x1/0x444/
        /M/bool m_display_caption_at_end_of_time_trial/0x1/0x446/
        /M/s32 m_gp_hidden_score/0x4/0x448/
        /M/u32 m_result_bar_point_timer/0x4/0x2E34/
        /M/u32 m_result_bar_point_sound_timer/0x4/0x2E38/
        /M/u32 m_result_bar_point_increment/0x4/0x2E48/
        /M/u32 m_result_bar_point_interval/0x4/0x2E4C/
        /M/u32 m_result_bar_point_sound_interval/0x4/0x2E50/
        /M/s32 m_total_ranks[KART_MAX]/0x20/0x3010/
        /M/s32 m_gp_score[KART_MAX]/0x20/0x3030/
        /M/s32 m_total_point_red_team[KART_MAX]/0x20/0x3050/
        /M/s32 m_total_point_blue_team[KART_MAX]/0x20/0x3070/
        /M/bool m_is_master_player[KART_MAX]/0x8/0x3098/
        /M/nw::lyt::TextureInfo m_map_killer_r90_texture/0x14/0x30a0/
        /M/sead::PtrArray<UI::BgRaceMapItemControl> m_bg_race_map_item_controls[static_cast<u32>(Item::eItemType::MAX)]/0xc0/0x30b4/
        /M/sead::PtrArray<UI::BgRaceMapStarControl> m_bg_race_map_star_controls/0xC/0x3174/
        /M/sead::PtrArray<UI::BgRaceMapFlowerControl> m_bg_race_map_flower_controls/0xC/0x3180/
        /M/sead::PtrArray<UI::BgRaceMapLeafControl> m_bg_race_map_leaf_controls/0xC/0x318c/
        /M/sead::PtrArray<UI::BgRaceMapBombControl> m_bg_race_map_bomb_controls/0xC/0x3198/
        /M/sead::Delegate<BaseRacePage> m_draw_item_icon_delegate/0x10/0x31e8/
        /M/bool m_is_live_view/0x1/0x31f8/
        /M/u8 m_live_view_state/0x1/0x31f9/
        /M/bool m_is_finish_sync_finished/0x1/0x31fa/
    /END/

    void StartCountDown();
}