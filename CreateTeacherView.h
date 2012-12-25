#ifndef MYAPPLICATIONVIEW_H
#define	MYAPPLICATIONVIEW_H

#include "CreateTeacherForm.h"

#include "mvp/View.h"

#include <QtGui>

#include <boost/shared_ptr.hpp>

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

typedef boost::shared_ptr<CreateTeacherView> CreateTeacherViewPtr;

#endif

