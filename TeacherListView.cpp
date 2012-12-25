#include "CanvasWidget.h"
#include "SchoolManagerApplication.h"
#include "TeacherListView.h"

TeacherListView::TeacherListView(TeacherListModel * model, Poco::NotificationCenter & notificationCenter) :
    View(notificationCenter),
    tableView(new QTableView()),
    model(model),
    text("Default")
{
    Logger::logConstructor("MyCanvasView");
    tableView->setModel(model);
    tableView->setMinimumSize(400, 400);
}

TeacherListView::~TeacherListView() {
    Logger::logDestructor("MyCanvasView");
}

QWidget* TeacherListView::container() const {
    return tableView;
}

void TeacherListView::addTeacher(const Teacher & teacher) {
    std::cout << "add teacher" << std::endl;
    this->model->addTeacher(teacher);
}
