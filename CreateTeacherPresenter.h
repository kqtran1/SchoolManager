#ifndef MYAPPLICATIONPRESENTER_H
#define	MYAPPLICATIONPRESENTER_H

#include "CreateTeacherView.h"
#include "utils.h"

#include "mvp/Presenter.h"

class CreateTeacherPresenter : public Presenter<CreateTeacherView> {
    Q_OBJECT
public:
    CreateTeacherPresenter(BondViewPtr view,
            Poco::NotificationCenter & notificationCenter);
    
    virtual ~CreateTeacherPresenter();

    void log(std::string msg) const;

public slots:
    void logNothing();
};

#endif
