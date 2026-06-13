#pragma once

#include "../types.hpp"
#include "../forward.hpp"

#include "BaseFastControl.hpp"
#include "ControlSight.hpp"
#include "CursorItem.hpp"
#include "KeyItem.hpp"
#include "MenuCaption.hpp"
#include "../Sequence/BaseMenuPage.hpp"
#include "../Sound/SndSeEvent.hpp"

#include <math/seadVector.hpp>
#include <prim/seadSafeString.hpp>
#include <nw/lyt/Pane.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@BaseMenuButtonControl/SIZE@0x23C/BASE@BaseFastControl/BSIZE@0x7C/VTABLE@True/
    public:
        struct ActiveHandlersButton
		{
			u32
				HANDLER_A 				: 1, // 0x1
				_0x2 				    : 1, // 0x2
			 	HANDLER_B 				: 1, // 0x4
			    HANDLER_START 			: 1, // 0x8
			    HANDLER_TOUCH 			: 1, // 0x10. selectHandlerOn / selectHandlerOff
			    HANDLER_TOUCH_CURSOR_A 	: 1, // 0x20. keyHandlerCursorA
			    _0x40 		            : 1, // 0x40
			    _0x80 					: 1, // 0x80
			    _0x100 					: 1, // 0x100
			    _0x200 					: 1, // 0x200
			    _0x400 			        : 1, // 0x400
			    _0x800 				    : 1, // 0x800
			    _0x1000 				: 1; // 0x1000
		};
		static_assert(sizeof(ActiveHandlersButton) == 0x4);

        struct ControlAnimationTypeFlags
		{
			u32
				TYPE_TOUCH_SELECT 				: 1, // 0x1
				_0x2 				            : 1, // 0x2
			 	TYPE_TOUCH_SELECT_LOOP 			: 1, // 0x4
			    TYPE_TOUCH_SELECT_FADE 			: 1, // 0x8
			    TYPE_RACE_BASIC_BUTTON 			: 1, // 0x10. Also set for `RaceCloseButton`
			    TYPE_BACK 	                    : 1, // 0x20
			    TYPE_TITLE_BUTTON 		        : 1, // 0x40
			    TYPE_TITLE_CH_BUTTON 			: 1, // 0x80
			    TYPE_MENU_BUTTON 				: 1, // 0x100
			    TYPE_COURSE_BUTTON 				: 1, // 0x200
			    TYPE_CHARA_BUTTON 			    : 1, // 0x400
			    TYPE_CUP_BUTTON 				: 1, // 0x800
			    TYPE_RACE_DIALOG_BUTTON 		: 1, // 0x1000
                TYPE_OK_BUTTON 				    : 1, // 0x2000
                _0x4000 				        : 1, // 0x4000. `TYPE_TOUCH_SELECT_FADE_BUTTON` ?
                TYPE_MENU_BUTTON_ON_OFF 		: 1; // 0x8000
		};
		static_assert(sizeof(ControlAnimationTypeFlags) == 0x4);

        // NOTE: Name is made up
        enum class ECompleteNextMode : s32 {
            MODE_NONE = -1,
            MODE_OPEN_MENU = -2,      // Calls the page's `procOpenMenu` function
            MODE_CLOSE_MENU = -3,     // Calls the page's `procCloseMenu` function
            MODE_M4 = -4
        };

        /START_STRUCT/NAME@AnimationDefine_Dummy/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TouchSelect/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_Common/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_OKButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_CupButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_BackButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_MenuButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_CharaButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TitleButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_CourseButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TitleChButton/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_MenuButtonOnOff/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TouchSelectFade/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TouchSelectLoop/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@AnimationDefine_TouchSelectFadeLoop/SIZE@0x18/BASE@ControlAnimator::AnimationDefine/BSIZE@0x18/VTABLE@True/
            void defineAnimation(); // 0
        /END/

        /START_STRUCT/NAME@CreateArg/SIZE@0x90/BASE@VisualControl::CreateArg/BSIZE@0x90/VTABLE@True/
            CreateArg(): VisualControl::CreateArg() {}
        
            const ControlAnimator::AnimationDefine *getAnimationDefine () const; // 3
        /END/

        virtual ~BaseMenuButtonControl();
        virtual void create(Object::ArgumentObj const *); // 4
        virtual void calc(); // 6
        virtual void reset(); // 20
        virtual void animMenuIn(); // 31
        virtual void animMenuOut(); // 32

        BaseMenuButtonControl();
        void changeAnim(s32, s32);
        void changeLoop();
        void setCaption(MenuCaption *, u32);
        void bindHitPane(nw::lyt::Pane *);
        void initHandler();
        void keyHandlerB(s32, EKeyID);
        void completeNext();
        bool canManipulate();
        void touchHandlerUp(s32, const sead::Vector2f &);
        void keyHandlerStart(s32, EKeyID);
        void selectHandlerOn(s32, s32);
        void keyHandlerA(s32, EKeyID);
        void keyHandlerCommon(s32, EKeyID);
        void touchHandlerDown(s32, const sead::Vector2f &);
        void keyHandlerCursorA(s32, s32);
        void touchHandlerSlideIn(s32, const sead::Vector2f &);
        void touchHandlerSlideOut(s32, const sead::Vector2f &);
        void setBg(BaseFastControl *, const sead::SafeString &);
        void follow();
        void setTex(s32, s32);
        void animKeep();
        void stopLoop();
        void setCursor(BaseFastControl *, const sead::SafeString &);
        void selectHandlerOff(s32, s32);

        /M/ActiveHandlersButton m_active_handlers/0x4/0x7c/
        /M/ControlAnimationTypeFlags m_animation_type_flags/0x4/0x80/
        /M/ControlSight *m_bg_control_sight/0x4/0x84/
        /M/ControlSight *m_cursor_control_sight/0x4/0x88/
        /M/ControlSight::ElementHandle *m_bg_element/0x4/0x8c/
        /M/ControlSight::ElementHandle *m_cursor_element/0x4/0x90/
        /M/ControlSight::ElementHandle m_key_items[3]/0xc/0x94/
        /M/KeyItem m_key_item_a/0x1c/0xa0/
        /M/KeyItem m_key_item_b/0x1c/0xbc/
        /M/KeyItem m_key_item_start/0x1c/0xd8/
        /M/KeyItem m_key_item_touch/0x1c/0xf4/
        /M/CursorItem m_cursor_item/0x30/0x130/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, EKeyID> m_key_handler_a/0x10/0x160/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, EKeyID> m_key_handler_b/0x10/0x170/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, EKeyID> m_key_handler_start/0x10/0x180/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, EKeyID> m_key_handler_cursor_a/0x10/0x190/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_down/0x10/0x1a0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_slide_out/0x10/0x1b0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_slide_in/0x10/0x1c0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_slide_capture_out/0x10/0x1d0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_up/0x10/0x1e0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_on/0x10/0x1f0/
        /M/sead::Delegate2<BaseMenuButtonControl, s32, sead::Vector2f const &> m_touch_handler_off/0x10/0x200/
        /M/s32 m_selected_option_idx/0x4/0x210/
        /M/s32 m_0x214/0x4/0x214/
        /M/MenuCaption *m_caption/0x4/0x218/
        /M/s32 m_caption_message_id/0x4/0x21c/
        /M/bool m_0x220/0x1/0x220/
        /M/Sound::SndSeEvent::EEvent m_on_touch_selection_se/0x1/0x221/
        /M/Sound::SndSeEvent::EEvent m_on_touch_deselection_se/0x1/0x222/
        /M/Sound::SndSeEvent::EEvent m_on_selection_se/0x1/0x223/
        /M/Sound::SndSeEvent::EEvent m_on_button_press_se/0x1/0x224/
        /M/Sound::SndSeEvent::EEvent m_on_invalid_button_press_se/0x1/0x225/
        /M/u32 m_on_button_press_se_param/0x4/0x228/
        /M/Sequence::BaseMenuPage *m_page/0x4/0x22c/    // Attached page
        // The return code enum (associated to the attached page,
        // and the page's convertReturnCode function) the game will traverse
        // after pressing / touching the button
        // If set to -1, the button won't be interactable (see `UI::BaseMenuButtonControl::canManipulate`)
        /M/s32 m_return_code/0x4/0x230/
        // A state variable that changes the "exit" behaviour
        // after pressing the button (i.e. when `UI::BaseMenuButtonControl::completeNext` is executed)
        // See the `ECompleteNextMode` enum
        /M/s32 m_on_complete_next_mode/0x4/0x234/
        /M/s32 m_sync_return_code/0x4/0x238/
    /END/
}