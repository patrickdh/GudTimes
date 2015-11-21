#define MAX_XFER_BUF_SIZE 16384

#include <libssh/sftp.h>

#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <fcntl.h>

#include "SSHConnection.h"

using namespace std;

SSHConnection::SSHConnection(const std::string& username, const std::string& password)
{
    if (username.length() == 0)
    {
        throw SSHException("Please enter a username");
    }
    if (password.length() == 0)
    {
        throw SSHException("Please enter a password");
    }

    session_user = username;

    session.setOption(SSH_OPTIONS_HOST, "vm320stu-1.caslab.queensu.ca");
    session.setOption(SSH_OPTIONS_PORT, 22);
    session.setOption(SSH_OPTIONS_USER, session_user.c_str());

    try
    {
        session.connect();
    }
    catch(ssh::SshException& e)
    {
        throw SSHException("Could not connect to server");
    }

    int res = session.userauthPassword(password.c_str());

    if (res != SSH_AUTH_SUCCESS)
    {
        throw SSHException("Invalid username or password");
    }
}

SSHConnection::~SSHConnection()
{
    session.disconnect();
}

int SSHConnection::createAccount(const std::string& username, const std::string& password)
{
    if (username.length() == 0)
    {
        throw SSHException("Please enter a username");
    }
    if (password.length() == 0)
    {
        throw SSHException("Please enter a password");
    }
    if (username.find("\"") != string::npos)
    {
        throw SSHException("Illegal character in username");
    }
    if (username.find(" ") != string::npos)
    {
        throw SSHException("Illegal character in username");
    }
    if (password.find("\"") != string::npos)
    {
        throw SSHException("Illegal character in password");
    }
    if (password.find(" ") != string::npos)
    {
        throw SSHException("Illegal character in password");
    }

    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/create_account.sh ";
    ss << username;
    ss << " ";
    ss << password;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();
    return result;
}

int SSHConnection::deleteAccount(const std::string& username, const std::string& password)
{
    if (username.length() == 0)
    {
        throw SSHException("Please enter a username");
    }
    if (password.length() == 0)
    {
        throw SSHException("Please enter a password");
    }
    if (username.find("\"") != string::npos)
    {
        throw SSHException("Illegal character in username");
    }
    if (username.find(" ") != string::npos)
    {
        throw SSHException("Illegal character in username");
    }
    if (password.find("\"") != string::npos)
    {
        throw SSHException("Illegal character in password");
    }
    if (password.find(" ") != string::npos)
    {
        throw SSHException("Illegal character in password");
    }

    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/delete_account.sh ";
    ss << username;
    ss << " ";
    ss << password;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();
    return result;
}

int SSHConnection::getCalendars()
{
    ssh_session currSession = session.getCSession();
    int rc;
    int numCalendars = 0;

    sftp_session sftpSession = sftp_new(currSession);
    if (sftpSession == NULL)
    {
        throw SSHException("Unable to allocate SFTP session");
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to initialize SFTP session");
    }

    sftp_dir userDir;
    sftp_attributes attributes;

    string userDirLoc = "/" + session_user;

    userDir = sftp_opendir(sftpSession, userDirLoc.c_str());

    if (!userDir)
    {
        sftp_free(sftpSession);
        throw SSHException("Error opening user directory");
    }

    while ((attributes = sftp_readdir(sftpSession,userDir)) != NULL)
    {
        string name(attributes->name);
        if ( name.length() >= 4 && name.substr(name.length()-4) == ".ics")
        {
            numCalendars++;
            int access_type = O_RDONLY;
            sftp_file file;
            char buffer[MAX_XFER_BUF_SIZE];
            int nbytes, rc;

            string fileName = userDirLoc + "/" + name;

            file = sftp_open(sftpSession, fileName.c_str(), access_type, 0);
            if (file == NULL)
            {
                sftp_attributes_free(attributes);
                sftp_closedir(userDir);
                sftp_free(sftpSession);
                throw SSHException("Error opening file (server)");
            }


            string outName = "./data/" + name;
            ofstream outFile(outName.c_str());
            if (!outFile)
            {
                sftp_close(file);
                sftp_attributes_free(attributes);
                sftp_closedir(userDir);
                sftp_free(sftpSession);
                throw SSHException("Error opening file (client)");
            }

            while (1)
            {
                nbytes = sftp_read(file,buffer,sizeof(buffer));
                if (nbytes == 0)
                {
                    break;
                }
                else if (nbytes < 0)
                {
                    sftp_close(file);
                    sftp_attributes_free(attributes);
                    sftp_closedir(userDir);
                    sftp_free(sftpSession);
                    throw SSHException("Error reading file");
                }

                outFile.write(buffer,nbytes);
                if (!outFile)
                {
                    sftp_close(file);
                    sftp_attributes_free(attributes);
                    sftp_closedir(userDir);
                    sftp_free(sftpSession);
                    throw SSHException("Error writing file");
                }
            }

            outFile.close();
            if (!outFile)
            {
                sftp_close(file);
                sftp_attributes_free(attributes);
                sftp_closedir(userDir);
                sftp_free(sftpSession);
                throw SSHException("Error closing file (client)");
            }

            rc = sftp_close(file);
            if (rc != SSH_OK)
            {
                sftp_attributes_free(attributes);
                sftp_closedir(userDir);
                sftp_free(sftpSession);
                throw SSHException("Error closing file (server)");
            }
        }
        sftp_attributes_free(attributes);
    }

    if (!sftp_dir_eof(userDir))
    {
        sftp_closedir(userDir);
        sftp_free(sftpSession);
        throw SSHException("Error reading user directory");
    }

    rc = sftp_closedir(userDir);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Error closing user directory");
    }

    sftp_free(sftpSession);

    return numCalendars;
}

void SSHConnection::uploadFile(const wxFileName& fileName)
{
    ssh_session currSession = session.getCSession();
    int rc;

    sftp_session sftpSession = sftp_new(currSession);
    if (sftpSession == NULL)
    {
        throw SSHException("Unable to allocate SFTP session");
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to initialize SFTP session");
    }

    string userDirLoc = "/" + session_user;

    int access_type = O_WRONLY | O_CREAT | O_TRUNC;
    sftp_file file;
    int nwritten;

    string filePath = userDirLoc + "/" + fileName.GetFullName().mb_str();

    file = sftp_open(sftpSession, filePath.c_str(), access_type, S_IRWXU);
    if (file == NULL)
    {
        string error(ssh_get_error(currSession));
        sftp_free(sftpSession);
        throw SSHException("Can't open file for writing (server)");
    }

    ifstream inFile(fileName.GetFullPath().mb_str());
    if (!inFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Can't open file for reading (client)");
    }

    stringstream ss;
    ss << inFile.rdbuf();
    string fileData = ss.str();

    if (!inFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error reading file");
    }

    nwritten = sftp_write(file,fileData.c_str(),fileData.length());

    if ( (unsigned int)nwritten != fileData.length())
    {
        string error(ssh_get_error(currSession));
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error writing file");
    }

    inFile.close();
    if (!inFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error closing file (client)");
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        throw SSHException("Error closing file (server)");
    }

    sftp_free(sftpSession);
}

void SSHConnection::deleteFile(const std::string& fileName)
{
    ssh_session currSession = session.getCSession();
    int rc;

    sftp_session sftpSession = sftp_new(currSession);
    if (sftpSession == NULL)
    {
        throw SSHException("Unable to allocate SFTP session");
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to initialize SFTP session");
    }

    string userDirLoc = "/" + session_user;

    string filePath = userDirLoc + "/" + fileName;

    rc = sftp_unlink(sftpSession, filePath.c_str());

    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to delete file (server)");
    }

    sftp_free(sftpSession);
}

SSHException::SSHException(const std::string& error)
: errorDescription(error) {}

std::string SSHException::what() const
{
    return errorDescription;
}

bool SSHConnection::doesUserExist(const std::string& username)
{
    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/check_account.sh ";
    ss << username;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();

    if (result == 1)
        return true;        // User exists
    else
        return false;       // User not found, or invalid input
}

int SSHConnection::findTimes(const std::vector<std::string>& usersToSearch, int length)
{
    string outName = "./data/";
    outName += "userslist.txt";
    ofstream outFile(outName.c_str());
    if (!outFile)
    {
        throw SSHException("Error opening file (client)");
    }

    for (unsigned int i = 0; i < usersToSearch.size() ; i++)
    {
        outFile << usersToSearch.at(i) << endl;
    }

    if (!outFile)
    {
        throw SSHException("Error writing file (client)");
    }

    outFile.close();

    wxFileName file;
    file.AssignCwd();
    file.AppendDir(_("data"));
    file.SetFullName(_("userslist.txt"));

    uploadFile(file);

    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/find_times.sh ";
    ss << session_user;
    ss << " ";
    ss << length;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();

    deleteFile("userslist.txt");
    remove("./data/userslist.txt");

    return result;
}

int SSHConnection::addURL(const std::string& url)
{
    string outName = "./data/";
    outName += "urladd.txt";
    ofstream outFile(outName.c_str());
    if (!outFile)
    {
        throw SSHException("Error opening file (client)");
    }

    outFile << url;

    if (!outFile)
    {
        throw SSHException("Error writing file (client)");
    }

    outFile.close();

    wxFileName file;
    file.AssignCwd();
    file.AppendDir(_("data"));
    file.SetFullName(_("urladd.txt"));

    uploadFile(file);

    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/add_url.sh ";
    ss << session_user;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();

    deleteFile("urladd.txt");
    remove("./data/urladd.txt");

    return result;
}

void SSHConnection::getNotifications()
{
    ssh_session currSession = session.getCSession();
    int rc;

    sftp_session sftpSession = sftp_new(currSession);
    if (sftpSession == NULL)
    {
        throw SSHException("Unable to allocate SFTP session");
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to initialize SFTP session");
    }

    string notifyFileLoc = "/" + session_user + "/notify.txt";

    int access_type = O_RDONLY;
    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes;

    file = sftp_open(sftpSession, notifyFileLoc.c_str(), access_type, 0);
    if (file == NULL)
    {
        sftp_free(sftpSession);
        throw SSHException("Error opening file (server)");
    }

    string outName = "./data/notify.txt";
    ofstream outFile(outName.c_str());
    if (!outFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error opening file (client)");
    }

    while (1)
    {
        nbytes = sftp_read(file,buffer,sizeof(buffer));
        if (nbytes == 0)
        {
            break;
        }
        else if (nbytes < 0)
        {
            sftp_close(file);
            sftp_free(sftpSession);
            throw SSHException("Error reading file");
        }

        outFile.write(buffer,nbytes);
        if (!outFile)
        {
            sftp_close(file);
            sftp_free(sftpSession);
            throw SSHException("Error writing file");
        }
    }

    outFile.close();
    if (!outFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error closing file (client)");
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Error closing file (server)");
    }

    sftp_free(sftpSession);
}

void SSHConnection::getTimes()
{
    ssh_session currSession = session.getCSession();
    int rc;

    sftp_session sftpSession = sftp_new(currSession);
    if (sftpSession == NULL)
    {
        throw SSHException("Unable to allocate SFTP session");
    }

    rc = sftp_init(sftpSession);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Unable to initialize SFTP session");
    }

    string notifyFileLoc = "/" + session_user + "/found_times.txt";

    int access_type = O_RDONLY;
    sftp_file file;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes;

    file = sftp_open(sftpSession, notifyFileLoc.c_str(), access_type, 0);
    if (file == NULL)
    {
        sftp_free(sftpSession);
        throw SSHException("Error opening file (server)");
    }

    string outName = "./data/found_times.txt";
    ofstream outFile(outName.c_str());
    if (!outFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error opening file (client)");
    }

    while (1)
    {
        nbytes = sftp_read(file,buffer,sizeof(buffer));
        if (nbytes == 0)
        {
            break;
        }
        else if (nbytes < 0)
        {
            sftp_close(file);
            sftp_free(sftpSession);
            throw SSHException("Error reading file");
        }

        outFile.write(buffer,nbytes);
        if (!outFile.good())
        {
            sftp_close(file);
            sftp_free(sftpSession);
            throw SSHException("Error writing file");
        }
    }

    outFile.close();
    if (!outFile)
    {
        sftp_close(file);
        sftp_free(sftpSession);
        throw SSHException("Error closing file (client)");
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        sftp_free(sftpSession);
        throw SSHException("Error closing file (server)");
    }

    sftp_free(sftpSession);
}

int SSHConnection::sendNotification(const Notification& notice, const std::vector<std::string>& usersToSend)
{
    string outName = "./data/";
    outName += "outboundNotices.txt";
    ofstream outFile(outName.c_str());
    if (!outFile)
    {
        throw SSHException("Error opening file (client)");
    }

    for (unsigned int i = 0; i < usersToSend.size() ; i++)
    {
        outFile << usersToSend.at(i) << ";" << (int) notice.getType() << ";" << notice.getEvent().getTitle()
                << ";" << notice.getEvent().getStart().FormatISODate()
                << ";" << notice.getEvent().getStart().FormatISOTime()
                << ";" << notice.getEvent().getEnd().FormatISODate()
                << ";" << notice.getEvent().getEnd().FormatISOTime() << endl;
    }

    if (!outFile)
    {
        throw SSHException("Error writing file (client)");
    }

    outFile.close();

    wxFileName file;
    file.AssignCwd();
    file.AppendDir(_("data"));
    file.SetFullName(_("outboundNotices.txt"));

    uploadFile(file);

    SSHConnection scriptAccess("appuser","apppass");

    stringstream ss;
    ss << "sudo /gudtimes/scripts/notify.sh ";
    ss << session_user;

    const string commandString = ss.str();

    ssh::Channel channel(scriptAccess.session);
    channel.openSession();
    channel.requestExec(commandString.c_str());
    channel.sendEof();
    while (channel.getExitStatus() == -1);
    int result = channel.getExitStatus();
    channel.close();

    deleteFile("outboundNotices.txt");
    remove("./data/outboundNotices.txt");

    return result;
}

int SSHConnection::sendNotification(const Notification& notice, const std::string& userToSend)
{
    vector<string> temp;
    temp.push_back(userToSend);
    return sendNotification(notice, temp);
}

UserNotFoundException::UserNotFoundException(const std::string& error)
: errorDescription(error) {}

std::string UserNotFoundException::what() const
{
    return errorDescription;
}
