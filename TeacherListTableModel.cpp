#include "TeacherListTableModel.h"

TeacherListModel::TeacherListModel(QObject *parent) :
    QAbstractTableModel(parent), 
    teachers() {
}

int TeacherListModel::rowCount(const QModelIndex & parent) const {
    return teachers.size();
}

int TeacherListModel::columnCount(const QModelIndex & parent) const {
    return 3;
}

QVariant TeacherListModel::data(const QModelIndex &index, int role) const {
    Teacher teacher = teachers[index.row()];

    if (role == Qt::DisplayRole) {
        int column = index.column();
        if (column == 0) {
            return QString("ID");
        } else if (column == 1) {
            return teacher.firstname;
        } else if (column == 2) {
            return teacher.lastname;
        }
    }
    return QVariant();
}

void TeacherListModel::addTeacher(const Teacher & teacher) {
    beginInsertRows(QModelIndex(), teachers.size(), teachers.size());
    teachers.push_back(teacher);
    endInsertRows();
    
    QModelIndex top = createIndex(teachers.size(), 0, (void*) 0);
    QModelIndex bottom = createIndex(teachers.size(), 3, (void*) 0);

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
    this->presenterView->addTeacher(notification->teacher());
}
