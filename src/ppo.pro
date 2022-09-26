QT       += core gui

LIBS += -lgtest -lpqxx -lpq

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    db/exceptions.cpp \
    db/pgRoomRepo.cpp \
    db/pgStudentRepo.cpp \
    db/pgThingRepo.cpp \
    db/pgUserRepo.cpp \
    db/roomRepo.cpp \
    db/sql.cpp \
    db/studentRepo.cpp \
    db/thingRepo.cpp \
    db/userRepo.cpp \
    logic/roomController.cpp \
    logic/studentController.cpp \
    logic/thingController.cpp \
    logic/userController.cpp \
    objects/connection.cpp \
    objects/error.cpp \
    objects/room.cpp \
    objects/student.cpp \
    objects/thing.cpp \
    objects/user.cpp \
    tech_gui/app/app.cpp \
    tech_gui/app/main.cpp \
    tech_gui/app/printer.cpp \
    tech_gui/app/request.cpp \
    tech_gui/app/states.cpp \
    tech_gui/auth_manager/authGetter.cpp \
    tech_gui/auth_manager/authManager.cpp \
    tech_gui/auth_manager/authPrinter.cpp \
    tech_gui/room_manager/roomManager.cpp \
    tech_gui/room_manager/roomPrinter.cpp \
    tech_gui/student_manager/studentGetter.cpp \
    tech_gui/student_manager/studentManager.cpp \
    tech_gui/student_manager/studentPrinter.cpp \
    tech_gui/thing_manager/thingGetter.cpp \
    tech_gui/thing_manager/thingManager.cpp \
    tech_gui/thing_manager/thingPrinter.cpp \
    tests/test_main.cpp \
    ui/GuiApp.cpp \
    ui/authManager/GuiAuthManager.cpp \
    ui/roomManager/GUIroomManager.cpp \
    ui/studentManager/GUIstudentManager.cpp \
    ui/thingManager/GUIthingManager.cpp \
    ui/ui/authwindow.cpp \
    ui/ui/commwindow.cpp \
    ui/ui/suppwindow.cpp \
    ui/ui/studentwindow.cpp

HEADERS += \
    db/exceptions.h \
    db/roomRepo.h \
    db/sql.h \
    db/studentRepo.h \
    db/thingRepo.h \
    db/userRepo.h \
    logic/roomController.h \
    logic/studentController.h \
    logic/thingController.h \
    logic/userController.h \
    db/pgRoomRepo.h \
    db/pgStudentRepo.h \
    db/pgThingRepo.h \
    db/pgUserRepo.h \
    objects/connection.h \
    objects/consts.h \
    objects/error.h \
    objects/room.h \
    objects/student.h \
    objects/thing.h \
    objects/user.h \
    tech_gui/app/app.h \
    tech_gui/app/printer.h \
    tech_gui/app/request.h \
    tech_gui/app/states.h \
    tech_gui/auth_manager/authGetter.h \
    tech_gui/auth_manager/authManager.h \
    tech_gui/auth_manager/authPrinter.h \
    tech_gui/room_manager/roomManager.h \
    tech_gui/room_manager/roomPrinter.h \
    tech_gui/student_manager/studentGetter.h \
    tech_gui/student_manager/studentManager.h \
    tech_gui/student_manager/studentPrinter.h \
    tech_gui/thing_manager/thingGetter.h \
    tech_gui/thing_manager/thingManager.h \
    tech_gui/thing_manager/thingPrinter.h \
    ui/GuiApp.h \
    ui/authManager/GUIauthManager.h \
    ui/roomManager/GUIroomManager.h \
    ui/studentManager/GUIstudentManager.h \
    ui/studentwindow.h \
    ui/thingManager/GUIthingManager.h \
    ui/ui/authwindow.h \
    ui/ui/commwindow.h \
    ui/ui/suppwindow.h \
    ui/ui/studentwindow.h

FORMS += \
    ui/ui/studentwindow.ui \
    ui/ui/authwindow.ui \
    ui/ui/commwindow.ui \
    ui/ui/suppwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
