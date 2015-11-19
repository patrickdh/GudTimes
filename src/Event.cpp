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

std::string Event::getTitle()
{

}

wxDateTime Event::getStart()
{

}

wxDateTime Event::getEnd()
{

}

FrequencyEnum Event::getFrequency()
{

}

int Event::getRepeatCount()
{

}

bool Event::isValid()
{

}
