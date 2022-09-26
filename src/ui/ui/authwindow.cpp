#include "authwindow.h"
#include "ui_mainwindow.h"

AuthWindow::AuthWindow(GUIAuthManager &authManager,
                       GUIStudentManager &studentManager,
                       GUIThingManager &thingManager,
                       GUIRoomManager &roomManager,
                       QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    this->authManager = authManager;
    this->studentManager = studentManager;
    this->thingManager = thingManager;
    this->roomManager = roomManager;
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

Levels AuthWindow::on_enter_clicked()
{
    QMessageBox messageBox;
    Levels result = NON_AUTH;
    std::string login = this->ui->loginEdit->toPlainText().toStdString();
    std::string password = this->ui->passwordEdit->toPlainText().toStdString();
    try {
        LogAction().log("Попытка авторизации");
        result = this->authManager.TryToAuthorize(login, password);
        messageBox.information(0, "Успех!", "Удалось успешно войти в систему!");
        if (result == COMEND)
        {
            LogAction().log("Авторизация пользователя с ролью комендант");
            this->close();
            CommWindow *w = new CommWindow(this->authManager, this->studentManager,
                                          this->thingManager, this->roomManager);
            w->show();
        }
        else if (result == SUPPLY)
        {
            LogAction().log("Авторизация пользователя с ролью завхоз");
            this->close();
            suppwindow *w = new suppwindow(this->authManager, this->studentManager,
                                           this->thingManager, this->roomManager);
            w->show();
        }
        else if (result == STUDENT)
        {
            LogAction().log("Авторизация пользователя с ролью студент");
            this->close();
            int webID = this->authManager.GetUserID(login);
            std::string studentNumber = this->studentManager.getStudentByWebID(webID);
            StudentWindow *w = new StudentWindow(this->authManager, this->studentManager,
                               this->thingManager, this->roomManager, studentNumber);
            w->show();
        }
    }  catch (const std::exception &e) {
        LogAction().log(std::string("Возникла ошибка:") + e.what());
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500,200);
    }
    return result;
}

