#pragma once

#include "../forward.hpp"
#include "../types.hpp"

#include "ArgumentObj.hpp"

BEGIN_NAMESPACE(Object)
{
	/START_CLASS/NAME@Actor/SIZE@0x8/VTABLE@True/
	public:
		virtual DTIClassInfo *getDTIClassInfo() const { return {}; }; // 0
		virtual DTIClassInfo *getDTIClass() const { return {}; }; // 1

		virtual ~Actor() {}; // 2 (_sub_object), 3 (_deallocating)

		virtual void create(ArgumentObj const *) {}; // 4
		virtual void init() = 0; // 5
		virtual void calc() = 0; // 6

		virtual void render() {}; // 7
		virtual void renderMainL() {}; // 8
		virtual void renderMainR() {}; // 9
		virtual void renderSub() {}; // 10

		virtual void _0x2C() = 0; // 11

		virtual void accept(ActorVisitor &); // 12
		virtual void callbackInvokeEventID(s32) {}; // 13

		virtual void _0x38() = 0; // 14

		virtual void createOuter(void const *); // 15
		virtual void initOuter(); // 16

		virtual void _0x44() = 0; // 17

		Actor();
		void initOuterImpl();
		void calcOuter();
		void renderOuter();
		void renderMainLOuter();
		void renderMainROuter();
		void renderSubOuter();

		inline Actor *getParent() const { return m_parent; }
		inline void setParent(Actor *parent) { m_parent = parent; }

		/M/Actor *m_parent/0x4/0x4/
	/END/
}