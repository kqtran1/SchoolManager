#include "ToolBarView.h"

#include "Event.h"

#include <QtGui>

ToolBarView::ToolBarView(Poco::NotificationCenter & notificationCenter):
    View(notificationCenter),
    toolBar(new QToolBar()),
    m_openFileAction(new QAction(QIcon(":/openFile.png"), "Open File", 0))
{
    QObject::connect(m_openFileAction, SIGNAL(triggered()), this, SLOT(openFileAction()));
    toolBar->addAction(m_openFileAction);
}


ToolBarView::~ToolBarView()
{
}

const QWidget* ToolBarView::container() const
{
	return toolBar;
}

QToolBar* ToolBarView::toolBarWidget() const
{
	return toolBar;
}

QAction* ToolBarView::openFileAction() const
{
    return m_openFileAction;
}

void ToolBarView::openFileAction() {
    notificationCenter.postNotification(new OpenFileNotification("TOTO PATH"));
}


