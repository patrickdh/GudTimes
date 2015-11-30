#pragma once

#include <string>
#include <vector>

#include "Event.h"

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
        int untilToCount(const string& firstTime, const string& freq, const string& lastTime) const;
        std::string getProperty(const string &Line) const;
        std::string getSubProperty(const string &Line, const char *SubProperty) const;

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
