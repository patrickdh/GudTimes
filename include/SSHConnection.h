#pragma once

#define MAX_XFER_BUF_SIZE 16384


#include "mylibsshpp.hpp"
#include <libssh/sftp.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <fcntl.h>

class SSHConnection
{
    public:
        SSHConnection(const std::string& username,const std::string& password);
        ~SSHConnection();
        static int createAccount(const std::string& username, const std::string& password);
        static int deleteAccount(const std::string& username, const std::string& password);
        int getCalendars();
    protected:
    private:
        ssh::Session session;
        std::string session_user;
};

class SSHException
{
    public:
        SSHException(const std::string& error);
        std::string what();
    private:
        std::string errorDescription;
};
