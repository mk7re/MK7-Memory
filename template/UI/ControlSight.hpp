#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "GraphicResourceInfo.hpp"
#include "DashMessageArg.hpp"
#include "LetterStepper.hpp"
#include "MessageString.hpp"

#include <math/seadVector.hpp>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>
#include <container/seadPtrArray.h>
#include <math/seadMatrix.h>
#include <nw/lyt/Pane.hpp>

BEGIN_NAMESPACE(UI)
{
    /START_CLASS/NAME@ControlSight/SIZE@0x4/VTABLE@True/
    public:
        enum ControlSightType {
            CONTROL_SIGHT_TYPE_DUMMY = 1,   // NwlytDummyControlSight
            CONTROL_SIGHT_TYPE_DEFAULT,     // NwlytControlSight
            CONTROL_SIGHT_TYPE_DIV_ROOT,    // NwlytDivRootControlSight
            CONTROL_SIGHT_TYPE_DIV_PART     // NwlytDivPartControlSight
        };

        enum class EElementType : u32
        {
            ELEMENT_TYPE_PANE,      // `nw::lyt::Pane`, or derived
            ELEMENT_TYPE_TEXTBOX,   // `nw::lyt::TextBox`
            ELEMENT_TYPE_2,
            ELEMENT_TYPE_BOUNDING,  // `nw::lyt::Bounding`
            ELEMENT_TYPE_BACK
        };

        public:
            /START_STRUCT/NAME@CreateArg/SIZE@0x48/
                /M/sead::SafeString m_layout_name/0x8/0x0/
                /M/sead::SafeString m_bctr_filename/0x8/0x8/
                /M/sead::Vector3f m_position/0xC/0x10/
                /M/f32 m_pane_width/0x4/0x1C/
                /M/f32 m_pane_height/0x4/0x20/
                /M/bool m_0x24/0x1/0x24/
                /M/s32 m_0x28/0x4/0x28/
                /M/s32 m_0x2C/0x4/0x2C/
                /M/sead::SafeString m_0x30/0x8/0x30/
                /M/void *m_0x38/0x4/0x38/
                /M/sead::SafeString m_0x3C/0x8/0x3c/
                /M/sead::PtrArray<GraphicResourceInfo> *m_graphics_resource_info_array/0x4/0x44/
            /END/

            /START_STRUCT/NAME@ElementHandle/SIZE@0x4/
                /M/void *m_element/0x4/0x0/

                ElementHandle();
            /END/
            
            SEAD_RTTI_BASE(ControlSight)

            virtual void _0x4(); // 1 (__sub_object)
            virtual void _0x8() = 0; // 2 (__deallocating)
            virtual s32 build(const CreateArg*) = 0; // 3
            virtual void calc() = 0; // 4
            virtual void draw() = 0; // 5
            virtual void *getElementHandle(const sead::SafeString &, EElementType) = 0; // 6
            virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const = 0; // 7
            virtual void setPosImpl(u32, const sead::Vector3f&) = 0; // 8
            virtual const sead::Vector3f &getPosImpl(u32) const = 0; // 9
            virtual void _0x28() = 0; // 10
            virtual const sead::Vector2f &getSizeImpl(u32) const = 0; // 11
            virtual void _0x30() = 0; // 12
            virtual void _0x34() = 0; // 13
            virtual void _0x38() = 0; // 14
            virtual void _0x3C() = 0; // 15
            virtual void _0x40() = 0; // 16
            virtual void _0x44() = 0; // 17
            virtual const sead::Matrix34f &getGlobalMtxImpl(u32) const = 0; // 18
            virtual void setAlphaImpl(u32, u8) = 0; // 19
            virtual void _0x50() = 0; // 20
            virtual u8 getGlobalAlphaImpl(u32) const = 0; // 21
            virtual void setVisibleImpl(u32, bool) = 0; // 22
            virtual void _0x5C() = 0; // 23
            virtual bool getGlobalVisibleImpl(u32) const = 0; // 24
            virtual void _0x64() = 0; // 25
            virtual nw::lyt::Pane *getPane(u32); // 26
            virtual void _0x6C() = 0; // 27
            virtual void replaceMessageImpl(u32, const MessageString &, const MessageArg *, LetterStepper *) = 0; // 28
            virtual void replaceGraphicImpl(u32, const sead::SafeString &) = 0; // 29
            virtual void _0x78() = 0; // 30
            virtual void _0x7C() = 0; // 31
            virtual void setRootPosImpl(const sead::Vector3f &) = 0; // 32
            virtual const sead::Vector3f &getRootPosImpl() const = 0; // 33
            virtual void setRootMtxImpl(const sead::Matrix34f &) = 0; // 34
            virtual void _0x8C() = 0; // 35
            virtual const sead::Matrix34f &getGlobalRootMtxImpl() const = 0; // 36
            virtual void setRootAlphaImpl(u8) = 0; // 37
            virtual void _0x98() = 0; // 38
            virtual u8 getGlobalRootAlphaImpl() const = 0; // 39
            virtual void setRootVisibleImpl(bool) = 0; // 40
            virtual bool getRootVisibleImpl() const = 0; // 41
            virtual bool getGlobalRootVisibleImpl() const = 0; // 42
            virtual void _0xAC() = 0; // 43
            virtual void _0xB0() = 0; // 44
            virtual void _0xB4() = 0; // 45
    /END/

    /START_CLASS/NAME@NullControlSight/SIZE@0x40/BASE@ControlSight/BSIZE@0x4/VTABLE@True/
    public:
        SEAD_RTTI_OVERRIDE(NullControlSight, ControlSight)

        virtual s32 build(const CreateArg*); // 3
        virtual void calc(); // 4
        virtual void draw(); // 5
        virtual void *getElementHandle(const sead::SafeString &, EElementType); // 6
        virtual void *getConstElementHandle(const sead::SafeString &, EElementType) const; // 7
        virtual void setPosImpl(u32, const sead::Vector3f&); // 8
        virtual const sead::Vector3f &getPosImpl(u32) const; // 9
        virtual const sead::Vector2f &getSizeImpl(u32) const; // 11
        virtual const sead::Matrix34f &getGlobalMtxImpl(u32) const; // 18
        virtual void setAlphaImpl(u32, u8); // 19
        virtual u8 getGlobalAlphaImpl(u32) const; // 21
        virtual void setVisibleImpl(u32, bool); // 22
        virtual bool getGlobalVisibleImpl(u32) const; // 24
        virtual void replaceMessageImpl(u32, const MessageString &, const MessageArg *, LetterStepper *); // 28
        virtual void replaceGraphicImpl(u32, const sead::SafeString &); // 29
        virtual void setRootPosImpl(const sead::Vector3f &); // 32
        virtual const sead::Vector3f &getRootPosImpl() const; // 33
        virtual void setRootMtxImpl(const sead::Matrix34f &); // 34
        virtual void setRootAlphaImpl(u8); // 37
        virtual void setRootVisibleImpl(bool); // 40
        virtual bool getRootVisibleImpl() const; // 41

        /M/sead::Matrix34f m_matrix/0x30/0x4/
        /M/u8 m_alpha/0x1/0x34/
        /M/bool m_visible/0x1/0x35/
        /M/void *m_0x38/0x4/0x38/
        /M/s32 m_0x3C/0x4/0x3C/
    /END/
}