#include "CreateTeacherView.h"
#include "SchoolManagerApplication.h"
#include "utils.h"

#include <QtGui>

CreateTeacherView::CreateTeacherView() :
        createTeacherForm(new CreateTeacherForm()) {
    Logger::logConstructor("MyApplicationView");
}

CreateTeacherView::~CreateTeacherView() {
    Logger::logDestructor("MyApplicationView");
}

QWidget* CreateTeacherView::container() const {
    return createTeacherForm;
}

QLineEdit* CreateTeacherView::firstnameInput() const {
    return createTeacherForm->widget.firstnameInput;
}

QLineEdit* CreateTeacherView::lastnameInput() const {
    return createTeacherForm->widget.lastnameInput;
}


QPushButton* CreateTeacherView::addButton() const {
    return createTeacherForm->widget.addButton;
}
