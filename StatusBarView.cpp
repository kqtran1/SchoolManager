#include "StatusBarView.h"

#include <QtCore>

#include <QStatusBar>;
#include <QString>;

StatusBarView::StatusBarView(Poco::NotificationCenter & notificationCenter) :
    View(notificationCenter),
    statusBar(new QStatusBar())
{
    notificationCenter.addObserver(Poco::NObserver<StatusBarView, CreateTeacherNotification > (*this, &StatusBarView::handle));
}


StatusBarView::~StatusBarView()
{
}

const QWidget* StatusBarView::container() const
{
	return statusBar;
}

QStatusBar* StatusBarView::statusBarWidget() const
{
	return statusBar;
}

void StatusBarView::showMessage( QString message )
{
    statusBar->showMessage(message);
}

void StatusBarView::handle(const Poco::AutoPtr<CreateTeacherNotification> & notification)
{
    showMessage(QString("Add New Teacher: ").append(notification->teacher().firstname));
}
