#pragma once

#include "../types.hpp"
#include "../forward.hpp"
#include "../Net/NetworkEngine.hpp"
#include "../Net/NetworkErrorHandler.hpp"
#include "Common_SystemDialog.hpp"

BEGIN_NAMESPACE(Sequence)
{
    /START_CLASS/NAME@NetworkErrorChecker/SIZE@0x24/
    public:
        // State of calc
        enum class EState : s32 {
            WATCH = 0,                  // waiting for a network error
            SELECT_RETURN_CODE = 7,     // the page's return code is chosen once the dialog is closed
            DONE = 9,                   // the error is handled; calc returns true
        };

        enum class NetworkErrorMessageType : u32
        {
            ERROR_PRESS_HOME_TO_EXIT = 2
        };

        void stopScene_();
        void startWindow_(NetworkErrorMessageType);
        void startDisconnect_();
        bool calc();

        /M/Net::NetworkErrorHandler *m_error_handler/0x4/0x0/
        /M/EState m_state/0x4/0x8/
        /M/Common_SystemDialog *m_common_system_dialog/0x4/0x10/
        /M/Net::NetworkErrorHandler::EErrorKind m_error_kind/0x4/0x14/ // kind of the error being handled
        /M/Net::NetworkEngine::ENetworkMode m_network_mode/0x4/0x1C/ // network mode when the error was detected
    /END/
}
