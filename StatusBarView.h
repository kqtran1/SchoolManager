#ifndef STATUSBARVIEW_H
#define	STATUSBARVIEW_H

#include "mvp/View.h"

#include <QStatusBar>
#include <QString>

#include <boost/shared_ptr.hpp>

class StatusBarView : public View
{
public:
	StatusBarView();
	~StatusBarView();

	virtual const QWidget* container() const;
	QStatusBar* statusBarWidget() const;

    void showMessage(QString message);

private:
	QStatusBar * statusBar;
};

typedef boost::shared_ptr<StatusBarView> StatusBarViewPtr;

#endif

