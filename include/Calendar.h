#pragma once

#include <string>
#include <vector>

#include "Event.h"
#include "ICSAccess.h"

class Calendar
{
    public:
        Calendar(const std::string& file, bool editable);
        void addEvent(const Event& event);
        void deleteEvent(int indexToDelete);
        void deleteCalendar();
        std::string getFileName() const;
        std::vector<Event> getEvents() const;
        bool getIsEditable() const;
    protected:
    private:
        ICSAccess ics;
        std::string fileName;
        std::vector<Event> events;
        bool isEditable;
};

class ReadOnlyException
{
    public:
        ReadOnlyException(const std::string& error);
        std::string what() const;
    protected:
    private:
        std::string errorDescription;
};
