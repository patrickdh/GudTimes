#include "SSHConnection.h"

using namespace std;

SSHConnection::SSHConnection(const string& username, const string& password)
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
            if (outFile.fail())
            {
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
                if (outFile.fail())
                {
                    sftp_close(file);
                    sftp_attributes_free(attributes);
                    sftp_closedir(userDir);
                    sftp_free(sftpSession);
                    throw SSHException("Error writing file");
                }
            }

            outFile.close();
            if (outFile.fail())
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


SSHException::SSHException(const string& error) : errorDescription(error) {}
string SSHException::what()
{
    return errorDescription;
}
