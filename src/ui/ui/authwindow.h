#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMessageBox>
#include "../authManager/GuiAuthManager.h"
#include "../studentManager/GUIstudentManager.h"
#include "../thingManager/GUIthingManager.h"
#include "../roomManager/GUIroomManager.h"
#include "commwindow.h"
#include "suppwindow.h"
#include "studentwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AuthWindow;
               class CommWindow;
               class suppwindow;
               class StudentWindow;}
QT_END_NAMESPACE

class AuthWindow : public QMainWindow
{
    Q_OBJECT

public:
    AuthWindow(GUIAuthManager &manager, GUIStudentManager &studentManager,
               GUIThingManager &thingManager,
               GUIRoomManager &roomManager, QWidget *parent = nullptr);
    ~AuthWindow();

private slots:
    Levels on_enter_clicked();

private:
    Ui::AuthWindow *ui;
    GUIAuthManager authManager;
    GUIStudentManager studentManager;
    GUIThingManager thingManager;
    GUIRoomManager roomManager;
};
#endif // AUTHWINDOW_H
