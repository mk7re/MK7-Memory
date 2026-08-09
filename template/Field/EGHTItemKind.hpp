#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Field)
{
    enum class EGHTItemKind : u32
    {
        KouraG,    // Green Shell
        KouraR,    // Red Shell
        Banana,    // Banana
        Kinoko,    // Mushroom
        Star,      // Star
        KouraB,    // Blue Shell
        Thunder,   // Lightning
        FakeBox,   // Test3
        KinokoP,   // Golden Mushroom
        Bomhei,    // Bob-omb
        Gesso,     // Blooper
        BigKinoko, // Test4
        Killer,    // Bullet Bill
        Flower,    // Fire Flower
        Tail,      // Super Leaf
        Seven,     // Lucky Seven
        MAX,
    };
}