#ifndef SUPPWINDOW_H
#define SUPPWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <fstream>
#include "../authManager/GuiAuthManager.h"
#include "../studentManager/GUIstudentManager.h"
#include "../thingManager/GUIthingManager.h"
#include "../roomManager/GUIroomManager.h"
#include "authwindow.h"
#include "../log.h"

namespace Ui {
class suppwindow;
}

class suppwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit suppwindow(GUIAuthManager &manager, GUIStudentManager &studentManager,
                        GUIThingManager &thingManager,
                        GUIRoomManager &roomManager, QWidget *parent = nullptr);
    ~suppwindow();

private slots:
    void on_enter_clicked();

    void on_enter_2_clicked();

private:
    Ui::suppwindow *ui;
    GUIAuthManager authManager;
    GUIStudentManager studentManager;
    GUIThingManager thingManager;
    GUIRoomManager roomManager;
};

#endif // SUPPWINDOW_H
