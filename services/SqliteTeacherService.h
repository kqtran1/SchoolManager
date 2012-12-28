#ifndef SQLITETEACHERSERVICE_H
#define SQLITETEACHERSERVICE_H

#include "TeacherService.h"

class sqlite3;

class SqliteTeacherService: public TeacherService
{
public:
    SqliteTeacherService();
    virtual ~SqliteTeacherService();

    virtual void create(const Teacher & newTeaher);
    virtual void remove(const int teacherId);
    virtual const std::vector<Teacher> all();

private:
    void createTables();
    void insertData();
    void printData();

private:
    sqlite3 *db;
};

#endif // SQLITETEACHERSERVICE_H
