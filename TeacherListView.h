#ifndef MYCANVASVIEW_H
#define	MYCANVASVIEW_H

#include "TeacherListTableModel.h"
#include "services/model/Teacher.h"
#include "CanvasWidget.h"
#include "utils.h"

#include "mvp/View.h"
#include <QTableView>
#include <QWidget>
#include <QMainWindow>

#include <string>

class TeacherListView : public View {
public:
    TeacherListView(TeacherListModel * model, Poco::NotificationCenter & notificationCenter);
    virtual ~TeacherListView();
    
    virtual QWidget* container() const;
    
    void addTeacher(const Teacher & teacher);
    
private:
    std::string text;
    TeacherListModel * model;
    QTableView * tableView;
};

#endif
