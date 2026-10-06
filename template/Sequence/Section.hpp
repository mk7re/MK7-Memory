#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "../Object/Actor.hpp"

#include "SequenceResource.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@Section/SIZE@0x34/BASE@Object::Actor/BSIZE@0x8/VTABLE@True/
    public:
        // TODO: Complete this enum
        enum class EFadeKind : u8
        {
            FADE_KIND_0
        };

        enum class EState : u8
        {
            CREATE = 1,
            ENTER,
            STANDBY,
            START,
            /**
             * - State is `COMPLETE` only when `Section.nextState == FINISH_OR_REENTER`
             * - Otherwise state is `CALC` or `CANCEL`
             */
            CALC_COMPLETE_OR_CANCEL,
            /**
             * - State is `FINISH` only when `Section.nextState == EXIT`
             * - Otherwise state is `REENTER`
             */
            FINISH_OR_REENTER,
            EXIT,
            CLEAR
        };

		virtual ~Section(); // 2 (_sub_object), 3 (_deallocating)
		virtual void create(Object::ArgumentObj const *); // 4
		virtual void init(); // 5
		virtual void calc(); // 6
		virtual void callbackInvokeEventID(s32);
        virtual void destroy();
        virtual s32 getSectionType() const = 0;    // See `SectionType` in `SequenceResource.hpp`
        virtual bool isCompletable() const = 0;
        virtual bool isSyncFadein() const = 0;
        virtual s32 getFadeFelay() const;
        virtual u32 updateState();
        virtual void step() = 0;
        virtual void ready() = 0;
        virtual void enter(EFadeKind, u32) = 0;
        virtual void standby() = 0;
        virtual void start() = 0;
        virtual void complete() = 0;
        virtual void cancel(EFadeKind, u32) = 0;
        virtual void finish(EFadeKind, u32) = 0;
        virtual void reenter() = 0;
        virtual void exit() = 0;
        virtual void clear() = 0;
        virtual void sceneStart(s32) = 0;
        virtual void sceneFinish(s32) = 0;

        Section();
        void clearOuter();
        void enterOuter(u16, EFadeKind, u32);
        void readyOuter(u32, u16);
        void startOuter();
        void cancelOuter(EFadeKind, u32);
        void finishOuter(EFadeKind, u32);
        void reenterOuter(u16);
        void standbyOuter();
        void stepOuter();
        void completeOuter(u16);
        void exitOuter();
        u32 updateStateOuter();
        void detachLayer();
        void createForPracticalSection(u32);
        void destroyForPracticalSection();
        EFadeKind getFadeKind() const;
        const char *getModeName(u16) const;
        const char *getSectionName() const;
        const char **getStringTable() const;
        const char *getEnterCodeName(u16) const;
        const char *getReturnCodeName(u16) const;
        SectionDirector *getSectionDirector() const;
        
        /M/SequenceResource *m_resource/0x4/0x8/
        /M/SequenceLayer *m_parent_layer/0x4/0xC/
        /M/SequenceResource::SectionBlock *m_block/0x4/0x10/
        /M/EState m_current_state/0x1/0x14/
        /M/EState m_next_state/0x1/0x15/
        /M/u32 m_sequence_id/0x4/0x18/
        /M/u16 m_mode_id/0x2/0x1C/ // mode given by the parent: the mode of a practical section, the block of a sequence
        /M/u16 m_enter_code_id/0x2/0x1E/ // an m_id of the block's enter code table
        /M/u16 m_return_code_id/0x2/0x20/ // an m_id of the block's return code table, valid once the section completes
        /M/u32 m_active_time/0x4/0x24/
        /M/u32 m_active_time_2/0x4/0x28/
        /M/EFadeKind m_fade_kind/0x1/0x2C/
        /M/u32 m_fade_delay/0x4/0x30/
    /END/
}