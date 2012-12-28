#ifndef _BONDFORM_H
#define	_BONDFORM_H

#include "ui_CreateTeacherForm.h"
#include "utils.h"

class CreateTeacherForm : public QWidget {
    Q_OBJECT
public:
    CreateTeacherForm()  {
        widget.setupUi(this);
    }
    ~CreateTeacherForm() {
        Logger::logDestructor("CreateTeacherForm");
    };
    
    Ui::CreateTeacherForm widget;
};

#endif
