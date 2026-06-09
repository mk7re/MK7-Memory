#pragma once

#include "../types.hpp"

#include "../CFL/cfl.hpp"

// Credits to libctru for these struct definitions

BEGIN_NAMESPACE(miisel)
{
    // `MiiSelectorConf` in libctru
    /START_STRUCT/NAME@Parameter/SIZE@0x104/
        /M/bool m_enable_cancel_button/0x1/0x0/
        /M/bool m_enable_selecting_guests/0x1/0x1/
        /M/bool m_show_on_top_screen/0x1/0x2/
        // UTF16-LE string displayed at the top of the applet
        /M/char16_t m_title[64]/0x80/0x8/
        // If nonzero, the applet shows a page with Guest Miis on launch
        /M/bool m_show_guets_page/0x1/0x8c/
        // Index of the initially selected Mii
        /M/s16 m_initial_mii_idx/0x2/0x90/
        // Each byte set to a nonzero value enables its corresponding Guest Mii to be enabled for selection.
        /M/bool m_mii_guest_whitelist[6]/0x6/0x94/
        // Each byte set to a nonzero value enables its corresponding Mii to be enabled for selection.
        /M/bool m_mii_whitelist[100]/0x64/0x9a/
        /U/u8/0x1/0xfe/
        /U/u8/0x1/0xff/
        // Always 0x13DE28CF
        /M/u32 m_magic/0x4/0x100/
    /END/

    // `MiiSelectorReturn` in libctru
    /START_STRUCT/NAME@Result/SIZE@0x84/
        /M/u32 m_no_mii_selected/0x4/0x0/
        /M/u32 m_guest_mii_was_selected/0x4/0x4/
        /M/u32 m_guest_mii_idx/0x4/0x8/
        /M/CFLStoreData m_mii/0x60/0xc/
        /M/char16_t m_guest_mii_name[12]/0x18/0x6c/
    /END/

    s32 StartMiiSelectApplet(Parameter *, Result *);
}