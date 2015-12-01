#include "NotificationAccess.h"

#include <wx/datetime.h>

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

NotificationAccess::NotificationAccess(SSHConnection* sshconn)
: connection(sshconn){}

void NotificationAccess::clearNotifications(std::vector<int> indicesToClear)
{
    connection->getNotifications();
    vector<Notification> notices = readNotifications();
    // Sorting removed as algorithm now relies on indicies being based on the list with all previous
    // deletions already processed.
    //sort (indicesToClear.begin(), indicesToClear.end(), greater<int>());
    //indicesToClear.erase( unique(indicesToClear.begin(), indicesToClear.end()), indicesToClear.end());
    for (unsigned int i = 0; i < indicesToClear.size() ; ++i)
    {
        notices.erase(notices.begin()+indicesToClear.at(i));
    }
    writeNotifications(notices);

    wxFileName file;
    file.AssignCwd();
    file.AppendDir(_("data"));
    file.SetFullName(_("notify.txt"));

    connection->uploadFile(file);
}

std::vector<Notification> NotificationAccess::readNotifications()
{
    vector<Notification> notices;
    ifstream noticeData ("./data/notify.txt");
    if (!noticeData)
    {
        throw NotificationException("Cannot open 'notify.txt'");
    }

    string line;

    while (getline(noticeData, line) && line.length() != 0)
    {
        stringstream ss;
        ss << line;

        string from, type, title, sDate, sTime, eDate, eTime;

        getline (ss, from, ';');
        getline (ss, type, ';');
        getline (ss, title, ';');
        getline (ss, sDate, ';');
        getline (ss, sTime, ';');
        getline (ss, eDate, ';');
        getline (ss, eTime);

        if (!ss)
        {
            throw NotificationException("Invalid notification file data (read line)");
        }

        int typenum;
        stringstream typess;
        typess << type;
        typess >> typenum;

        if (!typess)
        {
            throw NotificationException("Invalid notification file data (notice type)");
        }

        wxDateTime startDT;
        startDT.ParseDate(_(sDate.c_str()));
        startDT.ParseTime(_(sTime.c_str()));

        wxDateTime endDT;
        endDT.ParseDate(_(eDate.c_str()));
        endDT.ParseTime(_(eTime.c_str()));

        Event currEvent(title, startDT, endDT);

        if (!currEvent.isValid())
        {
            throw NotificationException("Invalid notification file data (event)");
        }

        notices.push_back(Notification(from, (NotificationTypeEnum) typenum, currEvent));
    }
    return notices;
}

void NotificationAccess::writeNotifications(const std::vector<Notification>& noticesToWrite)
{
    ofstream outFile("./data/notify.txt");
    if (!outFile)
    {
        throw NotificationException("Error opening 'notify.txt' for write");
    }

    for (unsigned int i = 0; i < noticesToWrite.size() ; i++)
    {
        outFile << noticesToWrite.at(i).getFrom()
                << ";" << (int) noticesToWrite.at(i).getType() << ";" << noticesToWrite.at(i).getEvent().getTitle()
                << ";" << noticesToWrite.at(i).getEvent().getStart().FormatISODate()
                << ";" << noticesToWrite.at(i).getEvent().getStart().FormatISOTime()
                << ";" << noticesToWrite.at(i).getEvent().getEnd().FormatISODate()
                << ";" << noticesToWrite.at(i).getEvent().getEnd().FormatISOTime() << endl;
    }
}

NotificationException::NotificationException(const std::string& error)
: errorDescription(error) {}

std::string NotificationException::what() const
{
    return errorDescription;
}
