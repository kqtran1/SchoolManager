#ifndef MYAPPLICATIONVIEW_H
#define	MYAPPLICATIONVIEW_H

#include "mvp/View.h"
#include "CreateTeacherForm.h"

class QWidget;

class CreateTeacherView : public View {
    Q_OBJECT
public:
    CreateTeacherView(Poco::NotificationCenter & notificationCenter);
    virtual ~CreateTeacherView();

    virtual QWidget* container() const;

public slots:
    void createTeacher();

private:
    CreateTeacherForm * createTeacherForm;
};

#endif

