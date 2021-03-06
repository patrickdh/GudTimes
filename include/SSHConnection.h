#pragma once

#include <wx/filename.h>

#include "mylibsshpp.hpp"

#include <string>
#include <vector>

#include "Notification.h"

class SSHConnection
{
    public:
        SSHConnection(const std::string& username,const std::string& password);
        ~SSHConnection();
        static int createAccount(const std::string& username, const std::string& password);
        static int deleteAccount(const std::string& username, const std::string& password);
        static bool doesUserExist(const std::string& username);
        int addURL (const std::string& url);
        int findTimes(const std::vector<std::string>& usersToSearch, int length, const std::string date);
        int getCalendars();
        void getNotifications();
        void getTimes();
        int sendNotification(const Notification& notice, const std::vector<std::string>& usersToSend);
        int sendNotification(const Notification& notice, const std::string& userToSend);
        void uploadFile(const wxFileName& fileName);
        void deleteFile(const std::string& fileName);
    protected:
    private:
        ssh::Session session;
        std::string session_user;
};

class SSHException
{
    public:
        SSHException(const std::string& error);
        std::string what() const;
    protected:
    private:
        std::string errorDescription;
};
