#ifndef MYAPPLICATIONVIEW_H
#define	MYAPPLICATIONVIEW_H

#include "CreateTeacherForm.h"

#include "mvp/View.h"

#include <QtGui>

#include <boost/shared_ptr.hpp>

class CreateTeacherView : public View {
public:
    CreateTeacherView();
    virtual ~CreateTeacherView();

    virtual QWidget* container() const;
    QLineEdit* firstnameInput() const;
    QLineEdit* lastnameInput() const;
    QPushButton* addButton() const;

public:
    CreateTeacherForm * createTeacherForm;
};

typedef boost::shared_ptr<CreateTeacherView> BondViewPtr;

#endif

