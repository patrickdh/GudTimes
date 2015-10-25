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
        int createAccount(const std::string& username, const std::string& password);
        int deleteAccount(const std::string& username, const std::string& password);
        int getCalendars(const std::string& username);
    protected:
    private:
        ssh::Session session;
};

class SSHException
{
    public:
        SSHException(const std::string& error);
        std::string what();
    private:
        std::string errorDescription;
};
