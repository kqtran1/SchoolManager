#include "SchoolManagerApplication.h"

#include "CreateTeacherView.h"
#include "CreateTeacherPresenter.h"
#include "TeacherListPresenter.h"
#include "TeacherListView.h"
#include "utils.h"
#include "TeacherListTableModel.h"
#include "StatusBarView.h"
#include "StatusBarPresenter.h"
#include "ToolBarView.h"
#include "FileActionPresenter.h"
#include "CanvasWidget.h"

#include <QtGui>

#include <boost/shared_ptr.hpp>
#include <Poco/NotificationCenter.h>
#include <Poco/Task.h>
#include <Poco/TaskManager.h>

MyApplication::MyApplication() {
    Logger::logConstructor("MyApplication");
}

MyApplication::~MyApplication() {
    Logger::logDestructor("MyApplication");
}

int MyApplication::run(int argc, char *argv[]) {
    

    QApplication app(argc, argv);

    Poco::NotificationCenter notificationCenter;

    QMainWindow mainWindow;

    BondViewPtr view(new CreateTeacherView());
    CreateTeacherPresenter presenter(view, notificationCenter);
    QDockWidget * bondDataDockWidget = new QDockWidget("Create Teacher");
    bondDataDockWidget->setWidget(view->container());
    mainWindow.addDockWidget(Qt::LeftDockWidgetArea, bondDataDockWidget);

    TeacherListModel model1(0);
    MyCanvasViewPtr canvasView(new TeacherListView(&model1));
    TeacherListPresenter canvasPresenter(canvasView, notificationCenter);
    QDockWidget * canvasDockWidget = new QDockWidget("My Canvas View");
    canvasDockWidget->setWidget(canvasView->container());
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, canvasDockWidget);

    TeacherListModel model2(0);
    MyCanvasViewPtr canvasView2(new TeacherListView(&model2));
    TeacherListPresenter canvasPresenter2(canvasView2, notificationCenter);
    QDockWidget * canvasDockWidget2 = new QDockWidget("My Canvas View");
    canvasDockWidget2->setWidget(canvasView2->container());
    mainWindow.setCentralWidget(canvasDockWidget2);

    StatusBarViewPtr statusBar(new StatusBarView());
    StatusBarPresenter statusBarPresenter(statusBar, notificationCenter);
    mainWindow.setStatusBar(statusBar->statusBarWidget());

    ToolBarViewPtr toolBar(new ToolBarView(notificationCenter));
    FileActionPresenter toolbarPresenter(toolBar, notificationCenter);
    mainWindow.addToolBar(toolBar->toolBarWidget());

    mainWindow.show();

    return app.exec();
}
