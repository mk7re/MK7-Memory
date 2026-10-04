#pragma once

#include "../System/Flag.hpp"
#include "../RaceSys/EDriverID.hpp"
#include "../RaceSys/EBodyID.hpp"
#include "../RaceSys/ETireID.hpp"
#include "../RaceSys/EWingID.hpp"

#include <container/seadTList.h>
#include <random/seadRandom.h>

BEGIN_NAMESPACE(RaceSys)
{
    // Static initializer at 0x0050ae70 (VERSION_EUR_DLP)
    /START_CLASS/NAME@PartsSelector/SIZE@0x64/
    public:
        PartsSelector(System::Flag::PlayerDataContext *);
        ~PartsSelector();
        EDriverID getDriverAtRandom(sead::Random *);
        /**
         * At the end of this function, various checks are in place
         * to prevent characters that are not Peach, Daisy, Rosalina or Honey Queen
         * to have the Birthday Girl body to be selected.
         */
        EBodyID getBodyAtRandom(EDriverID, sead::Random *);
        /**
         * The three "get recommend" functions run using a few "modes" which determine
         * how the recommended parts are going to be selected. These modes are chosen randomly per CPU.
         * 
         * -- getRecommendBody --
         * 0: Only the Standard body is selected.
         * 1: Randomly select one of the two recommended bodies from `s_recommended_bodies`.
         * Otherwise: The body is selected 100% at random, except for Birthday Girl in certain scenarios as well as the Gold body entirely.
         * 
         * -- getRecommendTire --
         * 0: Randomly select one of the two recommended tires from `s_recommended_tires`.
         * Otherwise: The tire is selected 100% at random, except for the Gold tires.
         * 
         * -- getRecommendWing --
         * 0: Randomly select one of the two recommended tires from `s_recommended_wings`.
         * Otherwise: The wing is selected 100% at random, except for the Gold wing.
         */
        EBodyID getRecommendBody(EDriverID, sead::Random *);
        ETireID getRecommendTire(EBodyID, sead::Random *);
        EWingID getRecommendWing(EBodyID, sead::Random *);
        void clear();
        /**
         * Various check are in place in this function that prevents
         * Mii drivers nor any of the gold parts to be selected for CPUs.
         * 
         * This doesn't take into account StreetPass Miis, which are selected in other code.
         */
        void setup();

        /M/sead::TList<s32> m_list_driver/0xc/0x0/
        /M/sead::TList<s32> m_list_body/0xc/0xc/
        /M/sead::TList<s32> m_list_tires/0xc/0x18/
        /M/sead::TList<s32> m_list_wing/0xc/0x24/
        // These "used" lists hold the entries already selected previously at random,
        // in order to prevent the same entry to be selected again multiple times one after the other.
        /M/sead::TList<s32> m_list_driver_used/0xc/0x30/
        /M/sead::TList<s32> m_list_body_used/0xc/0x3c/
        /M/sead::TList<s32> m_list_tires_used/0xc/0x48/
        /M/sead::TList<s32> m_list_wing_used/0xc/0x54/
        /M/System::Flag::PlayerDataContext *m_player_data_context/0x4/0x60/

        static sead::TListNode<s32> s_select_list_driver[static_cast<u32>(EDriverID::MAX)];   // 0x005f83bc (VERSION_EUR_DLP)
        static sead::TListNode<s32> s_select_list_body[static_cast<u32>(EBodyID::MAX)];       // 0x005f84dc (VERSION_EUR_DLP)
        static sead::TListNode<s32> s_select_list_tires[static_cast<u32>(ETireID::MAX)];      // 0x005f85ec (VERSION_EUR_DLP)
        static sead::TListNode<s32> s_select_list_wing[static_cast<u32>(EWingID::MAX)];       // 0x005f868c (VERSION_EUR_DLP)

        // Two recommended bodies per driver.
        // 0x005f86fc (VERSION_EUR_DLP)
        /**
         * NOTE: Miis never get to use a recommended body, since only StreetPass Miis can
         * ever appear in a Grand Prix, and in those cases the body is always the one that
         * was selected for them in the StreetPass data.
         * 
         * Because of this, the male and female entries for Miis goes unused.
         * The choice of bodies, however, suggests that Miis were not taken into account when
         * deciding the bodies for each character.
         * 
         * For example, Honey Queen and Daisy both have Birthday Girl as a recommended body, but Peach and Rosalina don't.
         * However, if we discard the male and female Miis IDs so that Peach and Rosalina use them instead,
         * we can see that they will both have the Birthday Girl as a recommended body.
         * 
         * Not only that, but this array doesn't have entries for Wiggler or Yoshi at all, ending at Wario.
         * If we discard the male and female Mii IDs like above, then Wiggler and Yoshi will fit the array properly again,
         * and the recommended bodies will make more sense to the characters assigned.
         * For example, in this case, Yoshi would have the Bumble V and Egg 1 as recommended bodies, as seen 
         * in official art, and overall fit Yoshi better than Wario.
         * 
         * In practice, Wiggler and Yoshi's recommended bodies end up overflowing into `s_recommended_bodies_yoshi_and_wiggler`
         * (assuming that `s_recommended_bodies_yoshi_and_wiggler` is indeed a separate array), which isn't even explicitly initialized
         * to any value like with the values from `s_recommended_bodies`.
         * Because of these, `s_recommended_bodies_yoshi_and_wiggler` is all 0 in practice, which makes both Wiggler and Yoshi
         * both have the Standard as the recommended body.
         */
        inline static EBodyID s_recommended_bodies[static_cast<u32>(EDriverID::MAX) - 2][2] =
        {
            { EBodyID::KoopaClown,   EBodyID::BoltBuggy    }, // EDriverID::Bowser
            { EBodyID::BirthdayGirl, EBodyID::TinyTug      }, // EDriverID::Daisy
            { EBodyID::BoltBuggy,    EBodyID::BarrelTrain  }, // EDriverID::DonkeyKong
            { EBodyID::BirthdayGirl, EBodyID::BumbleV      }, // EDriverID::HoneyQueen
            { EBodyID::SodaJet,      EBodyID::PipeFrame    }, // EDriverID::KoopaTroopa
            { EBodyID::Cloud9,       EBodyID::Zucchini     }, // EDriverID::Lakitu
            { EBodyID::BlueSeven,    EBodyID::Zucchini     }, // EDriverID::Luigi
            { EBodyID::BDasher,      EBodyID::BlueSeven    }, // EDriverID::Mario
            { EBodyID::Standard,     EBodyID::Standard     }, // EDriverID::MetalMario
            { EBodyID::BirthdayGirl, EBodyID::BumbleV      }, // EDriverID::MiiMale
            { EBodyID::BirthdayGirl, EBodyID::SodaJet      }, // EDriverID::MiiFemale
            { EBodyID::TinyTug,      EBodyID::Egg1         }, // EDriverID::Peach
            { EBodyID::BoltBuggy,    EBodyID::Cloud9       }, // EDriverID::Rosalina
            { EBodyID::Bruiser,      EBodyID::PipeFrame    }, // EDriverID::ShyGuy
            { EBodyID::CactX,        EBodyID::CactX        }, // EDriverID::Toad
            { EBodyID::BumbleV,      EBodyID::Egg1         }, // EDriverID::Wario
        };

        // The static initializer suggests that these are stored in a separate array to `s_recommended_bodies`
        // 0x005f877c (VERSION_EUR_DLP)
        inline static EBodyID s_recommended_bodies_yoshi_and_wiggler[2][2] =
        {
            { EBodyID::Standard,   EBodyID::Standard    }, // EDriverID::Wiggler
            { EBodyID::Standard,   EBodyID::Standard    }, // EDriverID::Yoshi
        };

        // Two recommended tires per body.
        // 0x005f878c (VERSION_EUR_DLP)
        inline static ETireID s_recommended_tires[static_cast<u32>(EBodyID::MAX)][2] =
        {
            { ETireID::Standard,    ETireID::Standard     }, // EBodyID::Standard
            { ETireID::RedMonster,  ETireID::Monster      }, // EBodyID::BoltBuggy
            { ETireID::Roller,      ETireID::Sponge       }, // EBodyID::BirthdayGirl
            { ETireID::Roller,      ETireID::Monster      }, // EBodyID::Egg1
            { ETireID::Slick,       ETireID::Slim         }, // EBodyID::BDasher
            { ETireID::Standard,    ETireID::Monster      }, // EBodyID::Zucchini
            { ETireID::Roller,      ETireID::Monster      }, // EBodyID::KoopaClown
            { ETireID::Slim,        ETireID::Roller       }, // EBodyID::TinyTug
            { ETireID::Sponge,      ETireID::Slick        }, // EBodyID::BumbleV
            { ETireID::Sponge,      ETireID::Roller       }, // EBodyID::CactX
            { ETireID::Slim,        ETireID::RedMonster   }, // EBodyID::Bruiser
            { ETireID::Standard,    ETireID::Slick        }, // EBodyID::PipeFrame
            { ETireID::Wood,        ETireID::Slim         }, // EBodyID::BarrelTrain
            { ETireID::Sponge,      ETireID::Mushroom     }, // EBodyID::Cloud9
            { ETireID::Slick,       ETireID::Monster      }, // EBodyID::BlueSeven
            { ETireID::Roller,      ETireID::Sponge       }, // EBodyID::SodaJet
            { ETireID::GoldTires,   ETireID::GoldTires    }, // EBodyID::GoldStandard. Unused.
        };

        // Recommended wing per body.
        // 0x005f8814 (VERSION_EUR_DLP)
        inline static EWingID s_recommended_wings[static_cast<u32>(EBodyID::MAX)] =
        {
            EWingID::SuperGlider,   // EBodyID::Standard
            EWingID::Paraglider,    // EBodyID::BoltBuggy
            EWingID::PeachParasol,  // EBodyID::BirthdayGirl
            EWingID::FlowerGlider,  // EBodyID::Egg1
            EWingID::SuperGlider,   // EBodyID::BDasher
            EWingID::SuperGlider,   // EBodyID::Zucchini
            EWingID::Swooper,       // EBodyID::KoopaClown
            EWingID::Paraglider,    // EBodyID::TinyTug
            EWingID::FlowerGlider,  // EBodyID::BumbleV
            EWingID::FlowerGlider,  // EBodyID::CactX
            EWingID::BeastGlider,   // EBodyID::Bruiser
            EWingID::SuperGlider,   // EBodyID::PipeFrame
            EWingID::SuperGlider,   // EBodyID::BarrelTrain
            EWingID::Paraglider,    // EBodyID::Cloud9
            EWingID::SuperGlider,   // EBodyID::BlueSeven
            EWingID::Paraglider,    // EBodyID::SodaJet
            EWingID::GoldGlider,    // EBodyID::GoldStandard. Unused.
        };

        inline static bool s_select_lists_initialized = false;   // 0x005e0fa0 (VERSION_EUR_DLP)
        inline static bool s_is_active = false;                  // 0x005e0fa1 (VERSION_EUR_DLP)
    /END/
}