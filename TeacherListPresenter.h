#ifndef MYCANVASPRESENTER_H
#define	MYCANVASPRESENTER_H

#include "Event.h"
#include "TeacherListView.h"

#include "mvp/Presenter.h"
#include "utils.h"

class TeacherListPresenter : public Presenter<TeacherListView> {
public:
    TeacherListPresenter(MyCanvasViewPtr view, Poco::NotificationCenter & notificationCenter);
    virtual ~TeacherListPresenter();
    
    virtual void handle(const Poco::AutoPtr<CreateTeacherNotification> & notification);
    
private:

};

#endif
