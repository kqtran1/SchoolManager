#ifndef TEACHERLISTTABLEMODEL_H
#define	TEACHERLISTTABLEMODEL_H

#include "services/model/Teacher.h"
#include "Event.h"
#include "mvp/Presenter.h"
#include "utils.h"

#include <QtCore/QAbstractTableModel>

class TeacherListModel : public QAbstractTableModel {
    Q_OBJECT

public:
    TeacherListModel(Poco::NotificationCenter & notificationCenter, QObject *parent);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void addTeacher(const Teacher & teacher);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual void handle(const Poco::AutoPtr<CreateTeacherNotification> & notification);

private:
    Poco::NotificationCenter & notificationCenter;
    std::vector<Teacher> teachers;
};

#endif
