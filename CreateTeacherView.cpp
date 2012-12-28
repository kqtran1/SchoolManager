#include "CreateTeacherView.h"
#include "SchoolManagerApplication.h"
#include "utils.h"

#include <cstdlib>

#include <QWidget>

CreateTeacherView::CreateTeacherView(Poco::NotificationCenter & notificationCenter) :
    View(notificationCenter),
    createTeacherForm(new CreateTeacherForm())
{
    Logger::logConstructor("CreateTeacherView");

    QObject::connect(createTeacherForm->widget.addButton, SIGNAL(clicked()), this, SLOT(createTeacher()));
}

CreateTeacherView::~CreateTeacherView() {
    Logger::logDestructor("CreateTeacherView");
}

QWidget* CreateTeacherView::container() const {
    return createTeacherForm;
}

void CreateTeacherView::createTeacher() {

    Teacher newTeacher = {
        rand() + 2000,
        createTeacherForm->widget.firstnameInput->text(),
        createTeacherForm->widget.lastnameInput->text()
    };
    notificationCenter.postNotification(new CreateTeacherNotification(newTeacher));
}
