#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "../../forward.hpp"
#include "../../types.hpp"

#include "base.hpp"

#include "../eMapdataAreaShape.hpp"
#include "../eMapdataAreaType.hpp"

BEGIN_NAMESPACE(Field)
{
    /START_STRUCT/NAME@MapdataAreaData/SIZE@0x30/
        /M/eMapdataAreaShape m_shape/0x1/0x0/
        /M/eMapdataAreaType m_type/0x1/0x1/
        /M/s8 m_came_index/0x1/0x2/ // camera areas: CAME entry shown inside the area, -1 none
        /M/u8 m_priority/0x1/0x3/ // camera areas: the highest priority wins among overlapping areas
        /M/sead::Vector3f position/0xC/0x4/ // centre of the base of the area
        /M/sead::Vector3f rotation/0xC/0x10/ // radians
        // Box: 1000 units per unit of scale wide and deep, 1000 tall. Cylinder: radius 500 per unit of scale.x and
        // scale.z, 500 tall per unit of scale.y
        /M/sead::Vector3f scale/0xC/0x1C/
        /M/u16 m_setting1/0x2/0x28/ // meaning depends on m_type
        /M/u16 m_setting2/0x2/0x2A/ // meaning depends on m_type
        /M/s8 m_route_id/0x1/0x2C/ // POTI route, -1 none
        /M/s8 m_enemy_id/0x1/0x2D/
    /END/

    /START_CLASS/NAME@MapdataArea/SIZE@0x8/BASE@MapdataDataBase<MapdataAreaData>/BSIZE@0x4/
    public:
        /M/MapdataAreaCalcBase *m_area_calc/0x4/0x4/
    /END/

    /START_CLASS/NAME@MapdataAreaCalcBase/SIZE@0x40/VTABLE@True/
    public:
        // The shape part of an area entry: MapdataAreaData from position to scale
        /START_STRUCT/NAME@SMapdataAreaCalcData/SIZE@0x24/
            /M/sead::Vector3f position/0xC/0x0/
            /M/sead::Vector3f rotation/0xC/0xC/
            /M/sead::Vector3f scale/0xC/0x18/
        /END/

        virtual bool isInside(sead::Vector3f &position); // 0
        virtual bool isInsideShape(sead::Vector3f &position); // 0
        
        /M/f32 m_bound_radius_sq/0x4/0x4/ // squared radius of a quick pre-test around position (horizontal only for cylinders)
        /M/sead::Vector3f m_extent/0xC/0x8/ // half width, height, half depth (box). Radius x, height, radius z (cylinder)
        /M/sead::Matrix33f m_axes/0x24/0x14/ // rows are the local X, Y and Z axes of the area
        /M/SMapdataAreaCalcData *m_area_point_data/0x4/0x38/ // points to MapdataAreaData::position of the entry
        /M/eMapdataAreaShape m_area_shape/0x1/0x3C/
        /M/eMapdataAreaType m_area_type/0x1/0x3D/
    /END/

    class MapdataAreaCalcBox : public MapdataAreaCalcBase
    {
        bool isInsideShape(sead::Vector3f &position) override;
    };
    static_assert(sizeof(MapdataAreaCalcBox) == 0x40);

    // Elliptic cylinder, it has no bottom, everything below its top counts as inside
    /START_CLASS/NAME@MapdataAreaCalcCylinder/SIZE@0x48/BASE@MapdataAreaCalcBase/BSIZE@0x40/
    public:
        bool isInside(sead::Vector3f &position) override;
        bool isInsideShape(sead::Vector3f &position) override;

        /M/f32 m_radius_sq/0x4/0x40/ // squared radius along the local X axis
        /M/f32 m_radius_ratio/0x4/0x44/ // radius along X divided by radius along Z
    /END/
}