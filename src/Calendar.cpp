#include "Calendar.h"

using namespace std;

Calendar::Calendar(const std::string& file, bool editable)
: ics(ICSAccess(file))
{
    //ctor
}

void Calendar::addEvent(const Event& event)
{

}

void Calendar::deleteEvent(int indexToDelete)
{

}

void Calendar::deleteCalendar()
{

}

std::string Calendar::getFileName()
{

}

std::vector<Event> Calendar::getEvents()
{

}

bool Calendar::getIsEditable()
{

}

ReadOnlyException::ReadOnlyException(const std::string& error)
{

}

std::string ReadOnlyException::what()
{

}
