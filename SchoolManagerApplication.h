#ifndef MYAPPLICATION_H
#define	MYAPPLICATION_H

#include "utils.h"

#include <boost/utility.hpp>

class sqlite3;

class SchoolManagerApplication : public boost::noncopyable {
public:
    SchoolManagerApplication();
    ~SchoolManagerApplication();
    
    int run(int argc, char *argv[]);

private:
    void createTables(sqlite3 *db);
    void insertData(sqlite3 *db);
    void printData(sqlite3 *db);
};

#endif

