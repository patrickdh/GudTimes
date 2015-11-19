#pragma once

#include <string>

#include "Event.h"

enum class NotificationTypeEnum
{
    NEWEVENT,
    ACCEPTEDEVENT,
    DECLINEDEVENT
};

class Notification
{
    public:
        Notification(std::string sender, NotificationTypeEnum noticeType, Event noticeEvent);
        std::string getFrom();
        NotificationTypeEnum getType();
        Event getEvent();
    protected:
    private:
        std::string from;
        NotificationTypeEnum type;
        Event event;
};
