#pragma once

#include "../types.hpp"
#include "Page.hpp"
#include "../UI/Control.hpp"

#include <nw/lyt/Drawer.hpp>
#include <nw/lyt/DrawInfo.hpp>

BEGIN_NAMESPACE(Sequence)
{
    namespace Fader
    {
        enum class EFaderType : u8
        {
            FADE_IN_BLACK,
            FADE_IN_WHITE,
            FADE_OUT_BLACK,
            FADE_OUT_WHITE
        };

        enum class EFaderScreen : u32
        {
            TOP_SCREEN,
            BOTTOM_SCREEN,
            BOTH_SCREENS
        };
    }

    /START_CLASS/NAME@FaderPage/SIZE@0x13C/BASE@Page/BSIZE@0x5C/VTABLE@True/
    public:
        virtual Object::DTIClassInfo *getDTIClassInfo() const; // 0
        virtual Object::DTIClassInfo *getDTIClass() const; // 1
        virtual ~FaderPage();
        virtual void onGenerateControl(UI::ControlInitializer *);
        virtual void onPagePreStep();

        static void convertEnterCodeImpl(const sead::SafeString &);
        static void convertReturnCodeImpl(const sead::SafeString &);
        static void convertModeImpl(const sead::SafeString &);

        FaderPage();
        void draw(UI::Control::EDrawScreen, nw::lyt::Drawer *, nw::lyt::DrawInfo &);
        void forceEnd(Fader::EFaderScreen);
        void StartFadein(Fader::EFaderType, u32, Fader::EFaderScreen);
        void StartFadeout(Fader::EFaderType, u32, Fader::EFaderScreen);
        void ReserveFadein(Fader::EFaderType, u32, Fader::EFaderScreen);
        void setClearColor();
        bool isFade();
    /END/

    enum class EnterCode : s32
    {
        DEFAULT
    };

    enum class ReturnCode : s32
    {
        DEFAULT
    };

    enum class Mode : s32
    {
        DEFAULT
    };

    void ResumeFade();
    void DisableFade();
    void StartFadein(Fader::EFaderType, u32, Fader::EFaderScreen);
    void StartFadeout(Fader::EFaderType, u32, Fader::EFaderScreen);
    void ForceFadeEnd(Fader::EFaderScreen);
    void ReserveFadein(Fader::EFaderType, u32, Fader::EFaderScreen);
    void SetFaderClearColor();
    bool isFade();
    void WaitFade();
    void setClearColor();
}