#include "TeacherListTableModel.h"
#include "services/TeacherService.h"
#include "Event.h"

#include <Poco/NObserver.h>

TeacherListModel::TeacherListModel(Poco::NotificationCenter & notificationCenter, TeacherService & teacherService) :
    QAbstractTableModel(),
    notificationCenter(notificationCenter),
    teacherService(teacherService),
    cachedTeacher(teacherService.all()) {
    notificationCenter.addObserver(Poco::NObserver<TeacherListModel, CreateTeacherNotification > (*this, &TeacherListModel::handle));

}

int TeacherListModel::rowCount(const QModelIndex & parent) const {
    return cachedTeacher.size();
}

int TeacherListModel::columnCount(const QModelIndex & parent) const {
    return 3;
}

QVariant TeacherListModel::data(const QModelIndex &index, int role) const {
    Teacher teacher = cachedTeacher[index.row()];

    if (role == Qt::DisplayRole) {
        int column = index.column();
        if (column == 0) {
            return QVariant(teacher.id);
        } else if (column == 1) {
            return teacher.firstname;
        } else if (column == 2) {
            return teacher.lastname;
        }
    }
    return QVariant();
}

void TeacherListModel::addTeacher(const Teacher & teacher) {
    int size = cachedTeacher.size();
    beginInsertRows(QModelIndex(), size, size);
    cachedTeacher.push_back(teacher);
    teacherService.create(teacher);
    endInsertRows();
    
    QModelIndex top = createIndex(size + 1, 0, (void*) 0);
    QModelIndex bottom = createIndex(size + 1, 3, (void*) 0);

    emit dataChanged(top, bottom);
}

QVariant TeacherListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Id");
                case 1:
                    return QString("Firstname");
                case 2:
                    return QString("Lastname");
            }
        }
    }
    return QVariant();
}

void TeacherListModel::handle(const Poco::AutoPtr<CreateTeacherNotification> & notification) {
    addTeacher(notification->teacher());
}
