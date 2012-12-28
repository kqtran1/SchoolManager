#include "SchoolManagerApplication.h"

#include "CreateTeacherView.h"
#include "TeacherListView.h"
#include "utils.h"
#include "TeacherListTableModel.h"
#include "StatusBarView.h"
#include "ToolBarView.h"
#include "FileActionPresenter.h"
#include "CanvasWidget.h"
#include "services/SqliteTeacherService.h"
#include "services/model/Teacher.h"

#include <QtGui>

#include <boost/shared_ptr.hpp>
#include <Poco/NotificationCenter.h>
#include <Poco/Task.h>
#include <Poco/TaskManager.h>

#include <sqlite3.h>
#include <vector>
#include <iostream>

SchoolManagerApplication::SchoolManagerApplication() {
    Logger::logConstructor("MyApplication");
}

SchoolManagerApplication::~SchoolManagerApplication() {
    Logger::logDestructor("MyApplication");
}

int SchoolManagerApplication::run(int argc, char *argv[]) {
    
    QApplication app(argc, argv);

    Poco::NotificationCenter notificationCenter;

    QMainWindow mainWindow;

    CreateTeacherView view(notificationCenter);
    QDockWidget * bondDataDockWidget = new QDockWidget("Create Teacher");
    bondDataDockWidget->setWidget(view.container());
    mainWindow.addDockWidget(Qt::LeftDockWidgetArea, bondDataDockWidget);

    SqliteTeacherService teacherService;
    TeacherListModel teacherListModel(notificationCenter, teacherService);

    TeacherListView canvasView(&teacherListModel, notificationCenter);
    QDockWidget * canvasDockWidget = new QDockWidget("My Canvas View");
    canvasDockWidget->setWidget(canvasView.container());
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, canvasDockWidget);

    TeacherListView canvasView2(&teacherListModel, notificationCenter);
    QDockWidget * canvasDockWidget2 = new QDockWidget("My Canvas View");
    canvasDockWidget2->setWidget(canvasView2.container());
    mainWindow.setCentralWidget(canvasDockWidget2);

    StatusBarView statusBar(notificationCenter);
    mainWindow.setStatusBar(statusBar.statusBarWidget());

    ToolBarView toolBar(notificationCenter);
    //FileActionPresenter toolbarPresenter(toolBar, notificationCenter);
    mainWindow.addToolBar(toolBar.toolBarWidget());

    mainWindow.show();

    std::vector<Teacher> teacherList = teacherService.all();

    for(int i = 0; i < teacherList.size(); ++i) {
        std::cout << teacherList[i].firstname.toStdString() << std::endl;
    }

    return app.exec();
}
