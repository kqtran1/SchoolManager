#ifndef TEACHERSERVICE_H
#define TEACHERSERVICE_H

#include "services/model/Teacher.h"

#include <vector>

class TeacherService
{
public:
    TeacherService();
    virtual ~TeacherService();

    virtual void create(const Teacher & newTeaher) = 0;
    virtual void remove(const int teacherId) = 0;
    virtual const std::vector<Teacher> all() = 0;
};

#endif // TEACHERSERVICE_H
