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
        Notification(const std::string& sender, NotificationTypeEnum noticeType, const Event& noticeEvent);
        std::string getFrom() const;
        NotificationTypeEnum getType() const;
        Event getEvent() const;
    protected:
    private:
        std::string from;
        NotificationTypeEnum type;
        Event event;
};
