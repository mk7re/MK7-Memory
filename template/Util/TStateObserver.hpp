#pragma once

#include "../types.hpp"

BEGIN_NAMESPACE(Util)
{
    /START_CLASS/NAME@TStateObserver/TEMPLATE@template <class T>/SIZE@0x20/SIZEOF@TStateObserver<void>/VTABLE@True/
    public:
        struct StateCallInfo {
            union {
                void(*state_func)(T*);
                u32 vtable_offset;

                u32 raw;
            } call_info;
            union {
                struct {
                    u32 is_vtable_offset : 1;
                    u32 base_object_offset : 31;
                } flags;
                u32 raw_flags;
            };
        };
        static_assert(sizeof(StateCallInfo) == 8);

        static void CallState(T* baseObject, StateCallInfo* sci, u8 state) {
            if (!sci->call_info.raw && (!sci->flags.is_vtable_offset || !sci->raw_flags))
                return;
            T* UseObject = (T*)(((uintptr_t)baseObject) + sci->flags.base_object_offset);
            if (sci->flags.is_vtable_offset) {
                ((void(*)(T*))((uintptr_t**)UseObject)[0][sci->call_info.vtable_offset/4])(UseObject);
            } else {
                sci->call_info.state_func(UseObject);
            }
        }

        void update() {
            if (m_state_change) {
                CallState(m_base_object, m_end_call_info, m_state_previous);
                m_state_change = false;
                CallState(m_base_object, m_init_call_info, m_state_current);
            }
            CallState(m_base_object, m_calc_call_info, m_state_current);
            m_state_counter++;
        }
        
        virtual ~TStateObserver() {}; // 1
        virtual void resetState(void) { // 2
            m_state_previous = m_state_current = 0;
            m_state_change = true;
            m_state_counter = 0;
        }
        virtual void executeState(void) { // 3
            update();
        }
        
        /M/u8 m_state_current/0x1/0x4/
        /M/u8 m_state_previous/0x1/0x5/
        /M/bool m_state_change/0x1/0x6/
        /M/T* m_base_object/0x4/0x8/
        /M/StateCallInfo* m_init_call_info/0x4/0xC/
        /M/StateCallInfo* m_calc_call_info/0x4/0x10/
        /M/StateCallInfo* m_end_call_info/0x4/0x14/
        /M/u32 m_state_counter/0x4/0x18/
        /M/u8 m_state_amount/0x1/0x1C/        
    /END/

    /START_CLASS/NAME@TStateObserverEx/TEMPLATE@template <class T>/SIZE@0x20/SIZEOF@TStateObserverEx<void>/VTABLE@True/
    public:
        void update(void) {
            this->m_state_counter++;
            if (this->m_state_change) {
                TStateObserver<T>::CallState(this->m_base_object, this->m_end_call_info, this->m_state_current);
                this->m_state_previous = this->m_state_current;
                this->m_state_current = this->m_requested_state;
                this->m_state_counter = 0;
                this->m_state_change = false;
                TStateObserver<T>::CallState(this->m_base_object, this->m_init_call_info, this->m_state_current);
            }
            TStateObserver<T>::CallState(this->m_base_object, this->m_calc_call_info, this->m_state_current);
        }

        virtual ~TStateObserverEx() {}; // 1
        virtual void resetState(void) { // 2
            this->m_state_previous = this->m_state_current = 0;
            this->m_state_change = true;
            this->m_state_counter = 0;
            this->m_requested_state = 0;
        }
        virtual void executeState(void) { // 3
            update();
        }

        /M/u8 m_state_current/0x1/0x4/
        /M/u8 m_state_previous/0x1/0x5/
        /M/bool m_state_change/0x1/0x6/
        /M/T* m_base_object/0x4/0x8/
        /M/TStateObserver<T>::StateCallInfo* m_init_call_info/0x4/0xC/
        /M/TStateObserver<T>::StateCallInfo* m_calc_call_info/0x4/0x10/
        /M/TStateObserver<T>::StateCallInfo* m_end_call_info/0x4/0x14/
        /M/u32 m_state_counter/0x4/0x18/
        /M/u8 m_state_amount/0x1/0x1C/
        /M/u8 m_requested_state/0x1/0x1D/
    /END/
}