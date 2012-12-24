#include "CreateTeacherPresenter.h"
#include "services/model/Teacher.h"
#include "Event.h"
#include "utils.h"

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

#include <QtCore>

CreateTeacherPresenter::CreateTeacherPresenter(boost::shared_ptr<CreateTeacherView> view,
        Poco::NotificationCenter & notificationCenter) :
Presenter<CreateTeacherView>(view, notificationCenter) 
{
    Logger::logConstructor("CreateTeacherPresenter");

    QObject::connect(view->addButton(), SIGNAL(clicked()), this, SLOT(logNothing()));
}

CreateTeacherPresenter::~CreateTeacherPresenter() {
    Logger::logDestructor("CreateTeacherPresenter");
}

void CreateTeacherPresenter::log(std::string msg) const {
    std::cout << msg << std::endl;
}

void CreateTeacherPresenter::logNothing() {
    Teacher newTeacher = {2, presenterView->firstnameInput()->text(), presenterView->lastnameInput()->text()};

    notificationCenter.postNotification(new CreateTeacherNotification(newTeacher));
}
