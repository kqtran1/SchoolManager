#ifndef EVENT_H
#define	EVENT_H

#include "services/model/Teacher.h"
#include "utils.h"

#include <Poco/Notification.h>

class RunBondComputationNotification : public Poco::Notification {
public:

    RunBondComputationNotification(std::string compText) : compText(compText) {
        Logger::logConstructor("RunBondComputationNotification");
    };

    ~RunBondComputationNotification() {
        Logger::logDestructor("RunBondComputationNotification");
    }

    std::string text() const {
        return compText;
    };

private:
    std::string compText;
    ;
};

class CreateTeacherNotification : public Poco::Notification {
public:

    CreateTeacherNotification(Teacher teacher) : newTeacher(teacher) {
        Logger::logConstructor("CreateTeacherNotification");
    };

    ~CreateTeacherNotification() {
        Logger::logDestructor("CreateTeacherNotification");
    }

    Teacher teacher() const {
        return newTeacher;
    };

private:
    Teacher newTeacher;
};

class OpenFileNotification : public Poco::Notification {
public:

    OpenFileNotification(std::string filePath) : m_filePath(filePath) {
        Logger::logConstructor("OpenFileNotification");
    };

    ~OpenFileNotification() {
        Logger::logDestructor("OpenFileNotification");
    }

    std::string filePath() const {
        return m_filePath;
    };

private:
    std::string m_filePath;
};

#endif
