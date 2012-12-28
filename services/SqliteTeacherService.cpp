#include "SqliteTeacherService.h"

#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include <boost/lexical_cast.hpp>

// Use Resource Manager
SqliteTeacherService::SqliteTeacherService()
{
    // don't throw in contructor!!!
    int dbStatus = sqlite3_open_v2("/Users/rastakiki/prout.db", &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    if(dbStatus == SQLITE_OK) {
        //createTables();
        //insertData();
        //printData();
    }
}

SqliteTeacherService::~SqliteTeacherService()
{
    sqlite3_close(db);
}

void SqliteTeacherService::create(const Teacher & newTeaher) {

}

void SqliteTeacherService::remove(const int teacherId) {

}

const std::vector<Teacher> SqliteTeacherService::all() {
    std::vector<Teacher> teacherList;
    const char * query = "SELECT * FROM teacher";
    sqlite3_stmt *statement;
    int prepRes = sqlite3_prepare_v2(db, query, -1, &statement, NULL);
    if(prepRes == SQLITE_OK) {
        if(sqlite3_step(statement) == SQLITE_DONE) {
            std::cout << "SQLITE_DONE not done" << std::endl;
        } else {
            while( sqlite3_column_text( statement, 0 ) )
            {
                Teacher teacher = {
                    sqlite3_column_int(statement, 0),
                    QString((const char *)sqlite3_column_text( statement, 1)),
                    QString((const char *)sqlite3_column_text( statement, 2))
                };
                teacherList.push_back(teacher);
                sqlite3_step( statement );
            }
        }
    }
    sqlite3_finalize(statement);
    return teacherList;
}

void SqliteTeacherService::createTables()
{
    const char * query = "CREATE TABLE teacher(id INT primary key, firstname VARCHAR(50), lastname VARCHAR(50))";
    sqlite3_stmt *createStatement;
    int prepRes = sqlite3_prepare_v2(db, query, -1, &createStatement, NULL);
    if(prepRes == SQLITE_OK) {
        if(sqlite3_step(createStatement) != SQLITE_DONE) {
            std::cout << "Somthing wrong happend" << std::endl;
        }
    }
    sqlite3_finalize(createStatement);
}

void SqliteTeacherService::insertData()
{
    for(int i = 0; i < 1000; ++i) {
        std::string id = boost::lexical_cast<std::string>(i);
        std::string queryStr = "INSERT INTO teacher VALUES(" + id + ", 'toto_" + id + "', 'tata_" + id + "')";
        sqlite3_stmt *statement;
        int prepRes = sqlite3_prepare_v2(db, queryStr.c_str(), -1, &statement, NULL);
        if(prepRes == SQLITE_OK) {
            if(sqlite3_step(statement) != SQLITE_DONE) {
                std::cout << "Somthing wrong happend" << std::endl;
            }
        }
        sqlite3_finalize(statement);
    }
}

void SqliteTeacherService::printData()
{
    const char * query = "SELECT * FROM teacher";
    sqlite3_stmt *statement;
    int prepRes = sqlite3_prepare_v2(db, query, -1, &statement, NULL);
    if(prepRes == SQLITE_OK) {
        if(sqlite3_step(statement) == SQLITE_DONE) {
            std::cout << "SQLITE_DONE not done" << std::endl;
        } else {
            while( sqlite3_column_text( statement, 0 ) )
            {
                std::cout << std::string((char *)sqlite3_column_text( statement, 1)) << std::endl;
                sqlite3_step( statement );
            }
        }
    }
    sqlite3_finalize(statement);
}

