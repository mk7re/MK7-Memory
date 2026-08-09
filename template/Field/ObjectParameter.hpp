#pragma once

#include "../types.hpp"

#include "eMapdataGeoObjID.hpp"
#include "../Render/DrawMdl.hpp"

#include <container/seadPtrArray.h>
#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Field)
{
    struct SObjectCollisionSet
    {
        enum class EMode : u8 {
            NO_COLLISION,
            SPHERE,
            CYLINDER,
            ORIGINAL,
            BOX,
            GROUND,
            CAPSULE
        };

        u8 unk_0x0;                 // (O:0x0,S:0x1)
        EMode m_mode;               // (O:0x1,S:0x1)
        // Source: https://github.com/vabold/Kinoko/blob/5a3ca2cd5603f84373d199949d425bc939ea685b/source/game/field/ObjectFlowTable.hh#L26-L39
        union {
            struct {
                s16 radius;
            } sphere;
            struct {
                s16 radius;
                s16 height;
            } cylinder;
            struct {
                s16 x;
                s16 y;
                s16 z;
            } box;
        } params;
    };
    static_assert(sizeof(SObjectCollisionSet) == 0x8);

    /START_CLASS/NAME@ObjectParameter/SIZE@0x10/
    public:
        /START_STRUCT/NAME@Parameter/SIZE@0x84/
            // NOTE: guessed name
            // This represents an object entry in `ObjFlow.bin`
            /START_STRUCT/NAME@Info/SIZE@0xA0/
                enum ObjFlowBinEntryFlags : u16 {
                    FLAG_0x0400,    // Checked at 0033d300? (VERSION_EUR_DLP)
                    FLAG_0x0800,    // Checked at 0033d308  (VERSION_EUR_DLP)
                    FLAG_0x1000,    // Checked at 0037c488 and 0033d310 (VERSION_EUR_DLP). Lightset-related?
                    // If this flag is set, then CPUs will be able to pass through this object
                    // when they're far away from you. Checked in `Field::ObjectBase::checkDetail_KartHitObj`
                    CPUS_CAN_IGNORE_COLLISION,
                    // Ignore the GOBJ presence flags, and make the object be able to appear on any game mode.
                    // Checked in `Field::ObjectDirector::isNCObject_`
                    APPEARS_IN_ALL_GAME_MODES,
                    // This is only set on VR objects
                    IS_SKYBOX
                };

                /M/eMapdataGeoObjID m_mapdata_geo_obj_id/0x2/0x0/
                /M/u16 m_flags/0x2/0x2/    // See the `ObjFlowBinEntryFlags` enum
                /U/u16/0x2/0x4/
                /U/u16/0x2/0x6/
                // Checked in `Field::getLodState`
                // [0] -> High distance
                // [1] -> Medium distance
                // [2] -> Low distance
                /M/u32 m_lod_distances[3]/0xC/0x8/
                /M/SObjectCollisionSet m_collision_set/0x8/0x14/
                /M/char m_name[32]/0x20/0x20/
                // Always 0? Set in `Field::ObjectParameter::initialize`
                /U/u8/0x1/0x5f/
                // If the object uses a graphical particle effect, this is the name of said particle effect.
                /M/char m_particle_name[32]/0x20/0x60/
                // Always 0? Set in `Field::ObjectParameter::initialize`
                /U/u8/0x1/0x9f/
            /END/

            /M/Info *m_info/0x4/0x0/
            /M/Render::DrawMdl::MatAnimLeader *m_mat_anim_leader/0x4/0x7c/
        /END/

        bool initHeader(void *);
        void initialize();
        static s32 compare(const Parameter *, const Parameter *);
        Parameter *getParam(eMapdataGeoObjID);

        /M/sead::PtrArray<Parameter> m_parameters/0xC/0x0/
        /M/s32 m_object_count/0x4/0xC/
    /END/
}