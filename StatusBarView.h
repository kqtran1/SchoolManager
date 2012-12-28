#ifndef STATUSBARVIEW_H
#define	STATUSBARVIEW_H

#include "mvp/View.h"

class QStatusBar;
class QString;

class StatusBarView : public View
{
public:
    StatusBarView(Poco::NotificationCenter & notificationCenter);
    virtual ~StatusBarView();

	virtual const QWidget* container() const;
	QStatusBar* statusBarWidget() const;

    void showMessage(QString message);
    void handle(const Poco::AutoPtr<CreateTeacherNotification> & notification);

private:
	QStatusBar * statusBar;
};

#endif

