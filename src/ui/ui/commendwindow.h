#ifndef COMMENDWINDOW_H
#define COMMENDWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMessageBox>
#include "../studentManager/GUIstudentManager.h"
#include "../../../../ppo/build-ppo-Desktop_Qt_5_15_2_GCC_64bit-Debug/ui_commendwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CommendWindow; }
QT_END_NAMESPACE

class CommendWindow : public QMainWindow
{
    Q_OBJECT

public:
    CommendWindow(GUIStudentManager &manager, QWidget *parent = nullptr);
    ~CommendWindow();

private slots:
    void on_enter_clicked();

private:
    Ui::CommendWindow *ui;
    GUIStudentManager studentManager;
};


#endif // COMMENDWINDOW_H
