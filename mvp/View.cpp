#include "mvp/View.h"

View::View(Poco::NotificationCenter & notificationCenter) :
    notificationCenter(notificationCenter)
{
    Logger::logConstructor("View");
}

View::~View() {
    Logger::logDestructor("View");
}
