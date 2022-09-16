#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../authManager/GuiAuthManager.h"
#include "../studentManager/GUIstudentManager.h"
#include "../thingManager/GUIthingManager.h"
#include "../roomManager/GUIroomManager.h"
#include "commwindow.h"
#include "suppwindow.h"

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(GUIAuthManager &manager, GUIStudentManager &studentManager,
                           GUIThingManager &thingManager,
                           GUIRoomManager &roomManager,
                           std::string studentNumber,
                           QWidget *parent = nullptr);
    ~StudentWindow();

private slots:
    void on_enter_clicked();

    void on_exit_clicked();

private:
    Ui::StudentWindow *ui;
    GUIAuthManager authManager;
    GUIStudentManager studentManager;
    GUIThingManager thingManager;
    GUIRoomManager roomManager;
    std::string studentNumber;
};

#endif // STUDENTWINDOW_H
