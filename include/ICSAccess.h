#pragma once

#include <string>
#include <vector>

#include "Event.h"

enum class Component{
    VCALENDAR, VEVENT
};

class ICSAccess
{
    public:
        ICSAccess(const std::string& file);
        std::vector<Event> getEvents();
        void addEvent(const Event& eventToAdd);
        void deleteEvent(int indexToDelete);
        void deleteICS();
    protected:
    private:
        std::string filename;
        int untilToCount(const std::string& firstTime, const std::string& freq, const std::string& lastTime) const;
        std::string getProperty(const std::string &Line) const;
        std::string getSubProperty(const std::string &Line, const char *SubProperty) const;

};

class FileNotFoundException
{
    public:
        FileNotFoundException(const std::string& errorMessage);
        std::string what() const;
    protected:
    private:
        std::string errorDescription;

};
