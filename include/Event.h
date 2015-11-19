#pragma once

#include <wx/datetime.h>

#include <string>


enum class FrequencyEnum
{
    NONE,
    DAILY,
    WEEKLY,
    MONTHLY,
    ANNUALLY
};

class Event
{
    public:
        Event();
        Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish);
        Event(const std::string& eventTitle, const wxDateTime& start, const wxDateTime& finish, FrequencyEnum frequency, int repeatNum);
        std::string getTitle();
        wxDateTime getStart();
        wxDateTime getEnd();
        FrequencyEnum getFrequency();
        int getRepeatCount();
        bool isValid();
    protected:
    private:
        std::string title;
        wxDateTime startDT;
        wxDateTime endDT;
        FrequencyEnum freq;
        int repeatCount;
        bool valid;
};
