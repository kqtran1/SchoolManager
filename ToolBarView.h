#ifndef TOOLBARVIEW_H
#define TOOLBARVIEW_H

#include "mvp/View.h"

#include <QToolBar>
#include <QAction>
#include <QtCore/QObject>
#include <boost/shared_ptr.hpp>

#include <Poco/NotificationCenter.h>

class ToolBarView : public QObject, public View {
    Q_OBJECT
public:
    ToolBarView(Poco::NotificationCenter & notificationCenter);
    ~ToolBarView();

	virtual const QWidget* container() const;
    QToolBar* toolBarWidget() const;
    QAction* openFileAction() const;

public slots:
    void openFileAction();

protected:
    Poco::NotificationCenter & notificationCenter;

private:
	QToolBar * toolBar;
    QAction * m_openFileAction;
};

typedef boost::shared_ptr<ToolBarView> ToolBarViewPtr;

#endif


