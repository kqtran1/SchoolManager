#ifndef FILEACTIONPRESENTER_H
#define FILEACTIONPRESENTER_H

#include "mvp/Presenter.h"
#include "ToolBarView.h"
#include "Event.h"

class FileActionPresenter : public Presenter<ToolBarView>
{
    Q_OBJECT
public:
    FileActionPresenter(boost::shared_ptr<ToolBarView> view, Poco::NotificationCenter & notificationCenter);
    virtual ~FileActionPresenter();

    virtual void openFileAction(const Poco::AutoPtr<OpenFileNotification> & notification);
};

#endif // TOOLBARPRESENTER_H
