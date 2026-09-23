#pragma once

#include "../../forward.hpp"
#include "../../types.hpp"

#include "../../KDMinMax.hpp"
#include "../../KDMtxT.hpp"

#include <math/seadVector.h>

BEGIN_NAMESPACE(Kart)
{
	/START_CLASS/NAME@Rigid/SIZE@0x74/
	public:
		Rigid()
		{
			m_position = &m_kd_mtx.m_vec;
			m_angle = &m_kd_mtx.m_kd_att;

			m_velocity_min_max.reset();

			m_reject.reset();

			reset();
		}

		void applyReject()
		{
			auto reject = m_reject.m_min;
			reject += m_reject.m_max;
			*m_position += reject;
		}

		void inputForceW(sead::Vector3f const &vec, void (KDMinMax::*func)(sead::Vector3f const &))
		{
			(m_velocity_min_max.*func)(vec);
		}

		void reset()
		{
			m_kd_mtx.init();

			m_velocity = sead::Vector3f::zero;

			m_velocity_min_max.reset();

			m_reject.reset();
		}

		void updatePos()
		{
			*m_position += m_velocity;
		}

		void updateVel(sead::Vector3f const &vel)
		{
			auto res = m_velocity_min_max.m_min;
			res += m_velocity_min_max.m_max;

			// TODO: implement sead::Vector operator
			m_velocity.x *= vel.x;
			m_velocity.y *= vel.y;
			m_velocity.z *= vel.z;

			m_velocity += res;
		}

		/M/KDMtxT m_kd_mtx/0x30/0x0/
		/M/KDAttT *m_angle/0x4/0x30/
		/M/sead::Vector3f *m_position/0x4/0x34/
		/M/sead::Vector3f m_velocity/0xC/0x38/
		/M/KDMinMax m_velocity_min_max/0x18/0x44/
		/M/KDMinMax m_reject/0x18/0x5C/
	/END/
}