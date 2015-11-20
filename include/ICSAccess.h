#pragma once

#include <string>
#include <vector>

#include "Event.h"

class ICSAccess
{
    public:
        ICSAccess(std::string file);
        std::vector<Event> getEvents();
        void addEvent(Event eventToAdd);
        void deleteEvent(int indexToDelete);
        void deleteICS();
    protected:
    private:
        std::string fileName;
};

class FileNotFoundException
{
    public:
        FileNotFoundException(const std::string& errorMessage);
        std::string what();
    protected:
    private:
        std::string errorDescription;
};