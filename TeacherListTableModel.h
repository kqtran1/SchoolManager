#ifndef TEACHERLISTTABLEMODEL_H
#define	TEACHERLISTTABLEMODEL_H

#include "services/model/Teacher.h"
#include "utils.h"

#include <QtCore/QAbstractTableModel>
#include <Poco/NotificationCenter.h>

class TeacherService;
class CreateTeacherNotification;

class TeacherListModel : public QAbstractTableModel {
    Q_OBJECT

public:
    TeacherListModel(Poco::NotificationCenter & notificationCenter, TeacherService & teacherService);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void addTeacher(const Teacher & teacher);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual void handle(const Poco::AutoPtr<CreateTeacherNotification> & notification);

private:
    Poco::NotificationCenter & notificationCenter;
    TeacherService & teacherService;
    std::vector<Teacher> cachedTeacher;
};

#endif
