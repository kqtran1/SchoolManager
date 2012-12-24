#ifndef _BONDFORM_H
#define	_BONDFORM_H

#include "ui_CreateTeacherForm.h"

class CreateTeacherForm : public QWidget {
    Q_OBJECT
public:
    CreateTeacherForm()  {
        widget.setupUi(this);
    }
    
    Ui::CreateTeacherForm widget;
};

#endif
