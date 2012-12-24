#include "TeacherListPresenter.h"

#include "Event.h"

TeacherListPresenter::TeacherListPresenter(boost::shared_ptr<TeacherListView> view, Poco::NotificationCenter & notificationCenter):
Presenter<TeacherListView>(view, notificationCenter) {
    Logger::logConstructor("MyCanvasPresenter");
    notificationCenter.addObserver(Poco::NObserver<TeacherListPresenter, CreateTeacherNotification > (*this, &TeacherListPresenter::handle));
}

TeacherListPresenter::~TeacherListPresenter() {
    Logger::logDestructor("MyCanvasPresenter");
}

void TeacherListPresenter::handle(const Poco::AutoPtr<CreateTeacherNotification> & notification) {
    this->presenterView->addTeacher(notification->teacher());
}
