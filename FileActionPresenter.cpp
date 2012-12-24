#include "FileActionPresenter.h"

#include <QtCore>

FileActionPresenter::FileActionPresenter(boost::shared_ptr<ToolBarView> view, Poco::NotificationCenter & notificationCenter):
Presenter<ToolBarView>(view, notificationCenter)
{
    Logger::logConstructor("ToolBarPresenter");
    notificationCenter.addObserver(Poco::NObserver<FileActionPresenter, OpenFileNotification > (*this, &FileActionPresenter::openFileAction));
}

FileActionPresenter::~FileActionPresenter()
{
}

void FileActionPresenter::openFileAction(const Poco::AutoPtr<OpenFileNotification> & notification) {
    Logger::logConstructor("Open File!!!");
}
