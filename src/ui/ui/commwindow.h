#ifndef COMMWINDOW_H
#define COMMWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../authManager/GuiAuthManager.h"
#include "../studentManager/GUIstudentManager.h"
#include "../thingManager/GUIthingManager.h"
#include "../roomManager/GUIroomManager.h"
#include "authwindow.h"
#include "suppwindow.h"
#include "studentwindow.h"

namespace Ui {
class CommWindow;
}

class CommWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommWindow(GUIAuthManager &manager, GUIStudentManager &studentManager,
                        GUIThingManager &thingManager,
                        GUIRoomManager &roomManager, QWidget *parent = nullptr);
    ~CommWindow();

private slots:
    void on_enter_clicked();

    void on_exit_clicked();

private:
    Ui::CommWindow *ui;
    GUIAuthManager authManager;
    GUIStudentManager studentManager;
    GUIThingManager thingManager;
    GUIRoomManager roomManager;
};

#endif // COMMWINDOW_H
