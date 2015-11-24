#pragma once

#include <vector>

#include "Notification.h"
#include "SSHConnection.h"

class NotificationAccess
{
    public:
        NotificationAccess(SSHConnection* sshconn);
        void clearNotifications(std::vector<int> indicesToClear);
        static std::vector<Notification> readNotifications();
    protected:
    private:
        SSHConnection* connection;
        static void writeNotifications(const std::vector<Notification>& noticesToWrite);
};

class NotificationException
{
    public:
        NotificationException(const std::string& error);
        std::string what() const;
    protected:
    private:
        std::string errorDescription;
};
