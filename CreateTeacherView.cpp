#include "CreateTeacherView.h"
#include "SchoolManagerApplication.h"
#include "utils.h"

#include <QtGui>

CreateTeacherView::CreateTeacherView(Poco::NotificationCenter & notificationCenter) :
    View(notificationCenter),
    createTeacherForm(new CreateTeacherForm())
{
    Logger::logConstructor("MyApplicationView");

    QObject::connect(createTeacherForm->widget.addButton, SIGNAL(clicked()), this, SLOT(createTeacher()));
}

CreateTeacherView::~CreateTeacherView() {
    Logger::logDestructor("MyApplicationView");
}

QWidget* CreateTeacherView::container() const {
    return createTeacherForm;
}

void CreateTeacherView::createTeacher() {
    Teacher newTeacher = {2, createTeacherForm->widget.firstnameInput->text(), createTeacherForm->widget.lastnameInput->text()};
    notificationCenter.postNotification(new CreateTeacherNotification(newTeacher));
}
