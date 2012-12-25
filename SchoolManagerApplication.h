#ifndef MYAPPLICATION_H
#define	MYAPPLICATION_H

#include "utils.h"

#include <QtCore/QObject>
#include <boost/utility.hpp>

class SchoolManagerApplication : public boost::noncopyable {
public:
    SchoolManagerApplication();
    virtual ~SchoolManagerApplication();
    
    int run(int argc, char *argv[]);
};

#endif

