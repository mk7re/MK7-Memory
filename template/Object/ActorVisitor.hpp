#pragma once

#include "../forward.hpp"
#include "../types.hpp"

BEGIN_NAMESPACE(Object)
{
	/START_CLASS/NAME@ActorVisitor/SIZE@0x14/VTABLE@True/
    public:
		virtual void vf_0x0();
		virtual void vf_0x4();
		virtual void down(Actor *);
		virtual void up(Actor *, Actor *);
		virtual void vf_0x10();
		virtual void visit(Actor *);

		// When traversing actors that are children of other actors, this tells the
		// current "depth" level in the parent / children tree of actors.
		/M/u32 m_current_depth_level/0x4/0x4/
		/M/Actor *m_actor/0x4/0x8/
		// If `true`, call the `callbackInvokeEventID` function instead of the `visit` one.
		/M/bool m_execute_callback_invoke_event_id/0x1/0xc/
		// Only used by SectionDirector? Set to 0x10000 to notify the game to destroy
		// all the created sections.
		/M/u32 m_event_id/0x4/0x10/
    /END/
}