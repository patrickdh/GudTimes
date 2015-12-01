#include "Calendar.h"

using namespace std;

Calendar::Calendar(const std::string& file, bool editable)
: ics(ICSAccess(file)), fileName(file), isEditable(editable)
{
    events = ics.getEvents();
}

void Calendar::addEvent(const Event& event)
{
    if (!isEditable)
    {
        string temp("Cannot add event. ");
        temp += fileName;
        temp += " is a read-only calendar.";
        throw ReadOnlyException(temp);
    }
    ics.addEvent(event);
    events.insert(events.begin(),event);
}

void Calendar::deleteEvent(int indexToDelete)
{
    if (!isEditable)
    {
        string temp("Cannot delete event. ");
        temp += fileName;
        temp += " is a read-only calendar.";
        throw ReadOnlyException(temp);
    }
    ics.deleteEvent(indexToDelete);
    events.erase(events.begin()+indexToDelete);
}

void Calendar::deleteCalendar()
{
    ics.deleteICS();
    events.clear();
    isEditable = false;
}

std::string Calendar::getFileName() const
{
    return fileName;
}

std::vector<Event> Calendar::getEvents() const
{
    return events;
}

bool Calendar::getIsEditable() const
{
    return isEditable;
}

ReadOnlyException::ReadOnlyException(const std::string& error)
: errorDescription(error){}

std::string ReadOnlyException::what() const
{
    return errorDescription;
}
