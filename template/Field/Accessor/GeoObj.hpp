#pragma once

#include "base.hpp"

#include "../Entry/GeoObj.hpp"
#include "../eMapdataGeoObjID.hpp"

#include "../CourseInfo.hpp"
#include "../FieldDirector.hpp"

#include <math/seadVector.hpp>

BEGIN_NAMESPACE(Field)
{
    /START_CLASS/NAME@MapdataGeoObjAccessor/SIZE@0x1C/BASE@MapdataAccessorBase<MapdataGeoObj, MapdataGeoObj::SData>/BSIZE@0x18/
    public:
        bool searchGet_Pos_Dir(eMapdataGeoObjID, sead::Vector3f *, sead::Vector3f *, u16);
        u32 collect_AllPointer(eMapdataGeoObjID, sead::PtrArray<MapdataGeoObj> *, u16);
        MapdataGeoObj *search(eMapdataGeoObjID, u16);
        void setPath(MapdataPathAccessor *);

        /M/MapdataPathAccessor *m_mapdata_path_accessor/0x4/0x18/
    /END/

    inline auto GetGeoObjAccessor()
    {
        return GetDirector()->m_course_info->m_geo_obj_accessor;
    }
}