#include "Event.h"

using namespace std;

Event::Event()
{
    valid = false;
}

Event::Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish)
: title(eventTitle), startDT(start), endDT(finish)
{
    freq = FrequencyEnum::NONE;
    repeatCount = -1;
    if (!startDT.IsLaterThan(endDT))
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
}

Event::Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish, FrequencyEnum frequency, int repeatNum)
: title(eventTitle), startDT(start), endDT(finish), freq(frequency), repeatCount(repeatNum)
{
    if (!startDT.IsLaterThan(endDT))
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
}

std::string Event::getTitle() const
{
    return title;
}

wxDateTime Event::getStart() const
{
    return startDT;
}

wxDateTime Event::getEnd() const
{
    return endDT;
}

FrequencyEnum Event::getFrequency() const
{
    return freq;
}

int Event::getRepeatCount() const
{
    return repeatCount;
}

bool Event::isValid() const
{
    return valid;
}
