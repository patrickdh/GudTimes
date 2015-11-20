#include "Notification.h"

using namespace std;

Notification::Notification(const std::string& sender, NotificationTypeEnum noticeType, const Event& noticeEvent)
: from(sender), type(noticeType), event(noticeEvent) {}

std::string Notification::getFrom()
{
    return from;
}

NotificationTypeEnum Notification::getType()
{
    return type;
}

Event Notification::getEvent()
{
    return event;
}

