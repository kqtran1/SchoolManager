#-------------------------------------------------
#
# Project created by QtCreator 2012-12-23T11:17:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtProject
TEMPLATE = app


SOURCES += main.cpp \
    ToolBarView.cpp \
    StatusBarView.cpp \
    FileActionPresenter.cpp \
    CanvasWidget.cpp \
    CreateTeacherView.cpp \
    TeacherListTableModel.cpp \
    TeacherListView.cpp \
    SchoolManagerApplication.cpp \
    mvp/View.cpp

HEADERS  += \
    utils.h \
    ToolBarView.h \
    StatusBarView.h \
    FileActionPresenter.h \
    Event.h \
    CanvasWidget.h \
    mvp/View.h \
    mvp/Presenter.h \
    CreateTeacherView.h \
    CreateTeacherForm.h \
    services/model/Teacher.h \
    TeacherListTableModel.h \
    TeacherListView.h \
    SchoolManagerApplication.h

FORMS    += \
    BondComputationResultForm.ui \
    CreateTeacherForm.ui

RESOURCES += \
    application.qrc

OTHER_FILES += \
    openFile.png

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/release/ -lPocoFoundationd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/debug/ -lPocoFoundationd
else:unix: LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/ -lPocoFoundationd

INCLUDEPATH += $$PWD/../../../dev/poco-1.4.3p1/Foundation/include \
    $$PWD/../../../dev/boost_1_47_0
DEPENDPATH += $$PWD/../../../dev/poco-1.4.3p1/Foundation/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/release/ -lPocoUtil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/debug/ -lPocoUtil
else:unix: LIBS += -L$$PWD/../../../dev/poco-1.4.3p1/lib/Darwin/x86_64/ -lPocoUtil

INCLUDEPATH += $$PWD/../../../dev/poco-1.4.3p1/Util/include
DEPENDPATH += $$PWD/../../../dev/poco-1.4.3p1/Util/include
