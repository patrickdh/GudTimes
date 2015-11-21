#include "Event.h"

using namespace std;

Event::Event()
{
    //ctor
}

Event::Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish)
{

}

Event::Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish, FrequencyEnum frequency, int repeatNum)
{

}

std::string Event::getTitle() const
{

}

wxDateTime Event::getStart() const
{

}

wxDateTime Event::getEnd() const
{

}

FrequencyEnum Event::getFrequency() const
{

}

int Event::getRepeatCount() const
{

}

bool Event::isValid() const
{

}
