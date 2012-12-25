#ifndef STATUSBARVIEW_H
#define	STATUSBARVIEW_H

#include "mvp/View.h"

#include <QStatusBar>
#include <QString>

#include <boost/shared_ptr.hpp>

class StatusBarView : public View
{
public:
    StatusBarView(Poco::NotificationCenter & notificationCenter);
	~StatusBarView();

	virtual const QWidget* container() const;
	QStatusBar* statusBarWidget() const;

    void showMessage(QString message);
    void handle(const Poco::AutoPtr<CreateTeacherNotification> & notification);

private:
	QStatusBar * statusBar;
};

typedef boost::shared_ptr<StatusBarView> StatusBarViewPtr;

#endif

