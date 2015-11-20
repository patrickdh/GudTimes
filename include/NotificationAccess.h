#pragma once

#include <vector>

#include "Notification.h"
#include "SSHConnection.h"

class NotificationAccess
{
    public:
        NotificationAccess(SSHConnection* sshconn);
        void clearNotifications(const std::vector<int>& indicesToClear);
        static std::vector<Notification> readNotifications();
    protected:
    private:
        SSHConnection* connection;
};
