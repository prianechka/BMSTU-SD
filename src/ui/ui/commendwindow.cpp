#include "commendwindow.h"

CommendWindow::CommendWindow(GUIStudentManager &studentManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommendWindow)
{
    ui->setupUi(this);
    this->studentManager = studentManager;
}

CommendWindow::~CommendWindow()
{
    delete ui;
}


void CommendWindow::on_enter_clicked()
{
    QMessageBox messageBox;
    messageBox.information(0, "Успех!", "Удалось успешно добавить студента!");
    if (this->ui->r1->isEnabled())
    {
        std::string name = this->ui->nameEdit->toPlainText().toStdString();
        std::string surname = this->ui->surnameEdit->toPlainText().toStdString();
        std::string studGroup = this->ui->groupEdit->toPlainText().toStdString();
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        std::string login = this->ui->loginEdit->toPlainText().toStdString();
        std::string password = this->ui->passwordEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.addNewStudent(name, surname, studGroup, studNumber,
                                               login, password);
            messageBox.information(0, "Успех!", "Удалось успешно добавить студента!");
        }
        catch (const std::exception &e)
        {
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r2->isEnabled())
    {
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            int roomID = this->ui->roomEdit->toPlainText().toInt();
            this->studentManager.settleStudent(studNumber, roomID);
            messageBox.information(0, "Успех!", "Удалось успешно заселить студента!");
        }
        catch (const std::exception &e)
        {
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r3->isEnabled())
    {
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.evicStudent(studNumber);
            messageBox.information(0, "Успех!", "Удалось успешно выселить студента!");
        }
        catch (const std::exception &e)
        {
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r4->isEnabled())
    {}
    else if (this->ui->r5->isEnabled())
    {}
    else if (this->ui->r6->isEnabled())
    {}
    else if (this->ui->r7->isEnabled())
    {}
    else if (this->ui->r8->isEnabled())
    {}
    else if (this->ui->r9->isEnabled())
    {}
}
