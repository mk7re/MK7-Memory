#pragma once

#include "ControlSight.hpp"
#include "NwlytInfo.hpp"

#include <nw/lyt/Pane.hpp>
#include <nw/lyt/TextBox.hpp>
#include <nw/lyt/Bounding.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@NwlytControlSightBase/SIZE@0xC/BASE@ControlSight/BSIZE@0x4/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytControlSightBase, ControlSight)
        
        virtual void _0x4(); // 1 (__sub_object)
        virtual s32 build(const CreateArg*) = 0; // 3
        virtual void calc() = 0; // 4
        virtual void draw(); // 5
        virtual void *getElementHandle(const sead::SafeString &, EElementType) = 0; // 6
        virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const = 0; // 7
        virtual void setPosImpl(u32, const sead::Vector3f&); // 8
        virtual const sead::Vector3f &getPosImpl(u32) const; // 9
        virtual const sead::Vector2f &getSizeImpl(u32) const; // 11
        virtual const sead::Matrix34f &getGlobalMtxImpl(u32) const; // 18
        virtual void setAlphaImpl(u32, u8); // 19
        virtual u8 getGlobalAlphaImpl(u32) const = 0; // 21
        virtual void setVisibleImpl(u32, bool) = 0; // 22
        virtual bool getGlobalVisibleImpl(u32) const = 0; // 24
        virtual nw::lyt::Pane *getPane(u32); // 26
        virtual void replaceMessageImpl(u32, const MessageString &, const MessageArg *, LetterStepper *) = 0; // 28
        virtual void replaceGraphicImpl(u32, const sead::SafeString &) = 0; // 29
        virtual void setRootPosImpl(const sead::Vector3f &) = 0; // 32
        virtual const sead::Vector3f &getRootPosImpl() const = 0; // 33
        virtual void setRootMtxImpl(const sead::Matrix34f &) = 0; // 34
        virtual const sead::Matrix34f &getGlobalRootMtxImpl() const = 0; // 36
        virtual void setRootAlphaImpl(u8) = 0; // 37
        virtual u8 getGlobalRootAlphaImpl() const = 0; // 39
        virtual void setRootVisibleImpl(bool) = 0; // 40
        virtual bool getRootVisibleImpl() const = 0; // 41
        virtual bool getGlobalRootVisibleImpl() const = 0; // 42
        virtual void _0xAC() = 0; // 43
        virtual void _0xB0() = 0; // 44
        virtual void _0xB4() = 0; // 45
        virtual NwlytInfo *getLayoutInfo() = 0; // 46
        virtual nw::lyt::Pane *getRootPane() = 0; // 47
        virtual const nw::lyt::Pane *getRootPane() const = 0; // 48
        virtual bool getParentGlobalVisible() const = 0; // 49

        /M/s32 m_0x4/0x4/0x4/
        /M/s32 m_0x8/0x4/0x8/
    /END/

    /START_CLASS/NAME@NwlytControlSight/SIZE@0x90/BASE@NwlytControlSightBase/BSIZE@0xC/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytControlSight, NwlytControlSightBase)

        virtual void _0x8(); // 2 (__deallocating)
        virtual s32 build(const CreateArg*); // 3
        virtual void calc(); // 4
        virtual void *getElementHandle(const sead::SafeString &, EElementType); // 6
        virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const; // 7
        virtual NwlytInfo *getLayoutInfo() = 0; // 46
        virtual nw::lyt::Pane *getRootPane() = 0; // 47
        virtual const nw::lyt::Pane *getRootPane() const = 0; // 48
        virtual bool getParentGlobalVisible() const = 0; // 49

        /M/NwlytInfo m_layout_info/0x84/0xC/
    /END/

    /START_CLASS/NAME@NwlytDummyControlSight/SIZE@0xA0/BASE@NwlytControlSight/BSIZE@0x90/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytDummyControlSight, NwlytControlSight)

        virtual void _0x8(); // 2 (__deallocating)
        virtual s32 build(const CreateArg*); // 3
        virtual void *getElementHandle(const sead::SafeString &, EElementType); // 6
        virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const; // 7
        virtual void replaceMessageImpl(u32, const MessageString &, const MessageArg *, LetterStepper *); // 28
        virtual void replaceGraphicImpl(u32, const sead::SafeString &); // 29

        /M/nw::lyt::TextBox *m_textbox/0x4/0x90/
        /M/nw::lyt::Pane *m_back/0x4/0x94/
        /M/nw::lyt::Bounding *m_bounding/0x4/0x98/
        /M/bool m_pane_width_or_height_is_zero/0x1/0x9C/
    /END/

    // Unknown symbol
    /START_CLASS/NAME@struct_103/SIZE@0x14/
    public:
        /M/s32 m_0x0/0x4/0x0/
        /M/s32 m_0x4/0x4/0x4/
        /M/nw::lyt::Pane *m_root_pane/0x4/0x8/
        /M/s32 m_0xC/0x4/0xC/
        /M/s32 m_0x10/0x4/0x10/
    /END/

    /START_CLASS/NAME@NwlytDivControlSight/SIZE@0xA4/BASE@NwlytControlSightBase/BSIZE@0xC/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytDivControlSight, NwlytControlSightBase)    

        virtual void _0x4(); // 1 (__sub_object)
        virtual s32 build(const CreateArg*) = 0; // 3
        virtual void calc() = 0; // 4
        virtual void *getElementHandle(const sead::SafeString &, EElementType); // 6
        virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const; // 7
        virtual bool getGlobalRootVisibleImpl() const; // 42
        virtual void _0xAC() = 0; // 43
        virtual void _0xB0() = 0; // 44
        virtual void _0xB4() = 0; // 45
        virtual NwlytInfo *getLayoutInfo() = 0; // 46
        virtual nw::lyt::Pane *getRootPane(); // 47
        virtual const nw::lyt::Pane *getRootPane() const; // 48
        virtual bool getParentGlobalVisible() const = 0; // 49

        /M/struct_103 *m_0xC/0x4/0xC/
        /M/void *m_0x10/0x4/0x10/
        /M/void *m_0x14/0x4/0x14/
        /M/s32 m_0x18/0x4/0x18/
        /M/s32 m_0x1C/0x4/0x1C/
        // `NwlytDivRootControlSight`'s layout suggest this is a `NwlytInfo`
        // but `NwlytDivPartControlSight`'s layout suggests this is a `NwlytDivControlSight *` ?
        /M/NwlytInfo m_layout_info/0x84/0x20/
    /END/

    /START_CLASS/NAME@NwlytDivPartControlSight/SIZE@0xF8/BASE@NwlytDivControlSight/BSIZE@0xA4/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytDivPartControlSight, NwlytDivControlSight)

        virtual void _0x8(); // 2 (__deallocating)
        virtual s32 build(const CreateArg*); // 3
        virtual void calc(); // 4
        virtual NwlytInfo *getLayoutInfo(); // 46
        virtual bool getParentGlobalVisible() const; // 49
    /END/

    /START_CLASS/NAME@NwlytDivRootControlSight/SIZE@0xA4/BASE@NwlytDivControlSight/BSIZE@0xA4/VTABLE@True/
    public:
        virtual void* getRuntimeTypeInfo(); // 0
        //SEAD_RTTI_OVERRIDE(NwlytDivRootControlSight, NwlytDivControlSight)
        
        virtual void _0x8(); // 2 (__deallocating)
        virtual s32 build(const CreateArg*); // 3
        virtual void calc(); // 4
        virtual NwlytInfo *getLayoutInfo(); // 46
        virtual bool getParentGlobalVisible() const; // 49
    /END/
}