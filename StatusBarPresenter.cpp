#include "StatusBarPresenter.h"

#include <Poco/NObserver.h>
#include <iostream>
#include <sstream>

using namespace std;

StatusBarPresenter::StatusBarPresenter(boost::shared_ptr<StatusBarView> view, Poco::NotificationCenter & notificationCenter):
Presenter<StatusBarView>(view, notificationCenter)
{
	Logger::logConstructor("StatusBarPresenter");
	notificationCenter.addObserver(Poco::NObserver<StatusBarPresenter, CreateTeacherNotification > (*this, &StatusBarPresenter::handle));
}


StatusBarPresenter::~StatusBarPresenter()
{
	Logger::logDestructor("StatusBarPresenter");
}

void StatusBarPresenter::handle(const Poco::AutoPtr<CreateTeacherNotification> & notification)
{
    view()->showMessage(QString("Add New Teacher: ").append(notification->teacher().firstname));
}
