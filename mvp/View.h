#ifndef VIEW_H
#define	VIEW_H

#include "Event.h"
#include "utils.h"

#include <QObject>
#include <QtWidgets>
#include <Poco/NotificationCenter.h>
#include <Poco/NObserver.h>
#include <boost/utility.hpp>

class View : public QObject, public boost::noncopyable {
public:
    View(Poco::NotificationCenter & notificationCenter);
    virtual ~View();

    virtual const QWidget* container() const = 0;

protected:
    Poco::NotificationCenter & notificationCenter;
};

#endif
