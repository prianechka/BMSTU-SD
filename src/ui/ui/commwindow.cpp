#include "commwindow.h"
#include "ui_commwindow.h"

CommWindow::CommWindow(GUIAuthManager &authManager,
                       GUIStudentManager &studentManager,
                       GUIThingManager &thingManager,
                       GUIRoomManager &roomManager,
                       QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommWindow)
{
    ui->setupUi(this);
    this->authManager = authManager;
    this->thingManager = thingManager;
    this->studentManager = studentManager;
    this->roomManager = roomManager;
}

CommWindow::~CommWindow()
{
    delete ui;
}

void CommWindow::on_enter_clicked()
{
    QMessageBox messageBox;
    if (this->ui->r1->isChecked())
    {
        LogAction().log("Комендант кочет добавить студента");
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
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r2->isChecked())
    {
        LogAction().log("Комендант хочет заселить студента");
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            int roomID = this->ui->roomEdit->toPlainText().toInt();
            this->studentManager.settleStudent(studNumber, roomID);
            messageBox.information(0, "Успех!", "Удалось успешно заселить студента!");
        }
        catch (const std::exception &e)
        {
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r3->isChecked())
    {
        LogAction().log("Комендант хочет выселить студента");
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.evicStudent(studNumber);
            messageBox.information(0, "Успех!", "Удалось успешно выселить студента!");
        }
        catch (const std::exception &e)
        {
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r4->isChecked())
    {
        LogAction().log("Комендант хочет изменить студента");
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        std::string group = this->ui->groupEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.changeStudentInfo(studNumber, group);
            messageBox.information(0, "Успех!", "Удалось успешно изменить студента!");
        }
        catch (const std::exception &e)
        {
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r5->isChecked())
    {
        LogAction().log("Комендант хочет посмотреть студентов");
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(4); // Указываем число колонок
        ui->tableWidget->setColumnWidth(0, 200);
        ui->tableWidget->setColumnWidth(1, 200);
        ui->tableWidget->setColumnWidth(2, 150);
        ui->tableWidget->setColumnWidth(3, 120);
        ui->tableWidget->setShowGrid(true); // Включаем сетку
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        // Устанавливаем заголовки колонок
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("Имя") \
                                                   << trUtf8("Фамилия") << trUtf8("Группа") \
                                                   << trUtf8("Билет"));
        std::vector<Student> students = this->studentManager.viewAllStudent();

        for( size_t i = 0; i < students.size(); i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(students[i].getName().c_str())));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(students[i].getSurname().c_str())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString(students[i].getStudentGroup().c_str())));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString(students[i].getStudentNumber().c_str())));
        }
    }
    else if (this->ui->r6->isChecked())
    {
        LogAction().log("Комендант хочет посмотреть студента");
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            StudentInfoDTO tmpStudent = this->studentManager.viewStudent(studNumber);
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->setColumnCount(5); // Указываем число колонок
            ui->tableWidget->setColumnWidth(0, 160);
            ui->tableWidget->setColumnWidth(1, 190);
            ui->tableWidget->setColumnWidth(2, 130);
            ui->tableWidget->setColumnWidth(3, 100);
            ui->tableWidget->setColumnWidth(4, 150);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("Имя") \
                                                       << trUtf8("Фамилия") << trUtf8("Группа") \
                                                       << trUtf8("Билет") << trUtf8("Комната"));
            ui->tableWidget->setShowGrid(true); // Включаем сетку
            ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString(tmpStudent.student.getName().c_str())));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(tmpStudent.student.getSurname().c_str())));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString(tmpStudent.student.getStudentGroup().c_str())));
            ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString(tmpStudent.student.getStudentNumber().c_str())));
            if (tmpStudent.room.getID() != NONE)
                ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString(std::to_string(tmpStudent.room.getRoomNumber()).c_str())));
            else
                ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString("Не живёт")));
        }
        catch (const std::exception &e)
        {
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
            LogAction().log(std::string("Возникла ошибка:") + e.what());
        }
    }
    else if (this->ui->r7->isChecked())
    {
        LogAction().log("Комендант хочет посмотреть комнаты");
        std::vector<Room> rooms = this->roomManager.getRooms();
        ui->tableWidget->setColumnCount(3); // Указываем число колонок
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnWidth(0, 50);
        ui->tableWidget->setColumnWidth(1, 200);
        ui->tableWidget->setColumnWidth(2, 200);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("ID") \
                                                   << trUtf8("Номер комнаты") << trUtf8("Тип"));
        ui->tableWidget->setShowGrid(true); // Включаем сетку
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        for (size_t i = 0; i < rooms.size(); i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(std::to_string(rooms[i].getID()).c_str())));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(std::to_string(rooms[i].getRoomNumber()).c_str())));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString(rooms[i].getRoomType().c_str())));
        }
    }
    else if (this->ui->r8->isChecked())
    {
        LogAction().log("Комендант хочет посмотреть вещи");
        ui->tableWidget->clear();
        try
        {
            std::vector<Thing> things = this->thingManager.viewAllThings();
            ui->tableWidget->setColumnCount(4); // Указываем число колонок
            ui->tableWidget->setRowCount(0);
            ui->tableWidget->setColumnWidth(0, 50);
            ui->tableWidget->setColumnWidth(1, 190);
            ui->tableWidget->setColumnWidth(2, 130);
            ui->tableWidget->setColumnWidth(3, 200);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("ID") \
                                                       << trUtf8("Марк.номер") << trUtf8("Тип") \
                                                       << trUtf8("Комната"));
            ui->tableWidget->setShowGrid(true); // Включаем сетку
            ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            for (size_t i = 0; i < things.size(); i++)
            {
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(std::to_string(things[i].getID()).c_str())));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(std::to_string(things[i].getMarkNumber()).c_str())));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString(things[i].getThingType().c_str())));
                if (things[i].getRoomID() <= 1)
                    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("На складе")));
                else
                {
                    Room info = this->roomManager.getRoomByID(things[i].getRoomID());
                    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString(std::to_string(info.getRoomNumber()).c_str())));
                }
            }
        }
        catch (const std::exception &e)
        {
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
    else if (this->ui->r9->isChecked())
    {
        LogAction().log("Комендант хочет переместить вещи");
        try
        {
            int roomID = this->ui->roomEdit->toPlainText().toInt();
            int markNumber = this->ui->markEdit->toPlainText().toInt();
            this->thingManager.transferThing(markNumber, roomID);
            messageBox.information(0, "Успех!", "Удалось успешно переместить вещь!");
        }
        catch (const std::exception &e)
        {
            LogAction().log(std::string("Возникла ошибка:") + e.what());
            messageBox.critical(0, "Ошибка!", e.what());
            messageBox.setFixedSize(500,200);
        }
    }
}


void CommWindow::on_exit_clicked()
{
    LogAction().log("Комендант выходит из программы");
    this->close();
    AuthWindow *w = new AuthWindow(authManager, studentManager, thingManager, roomManager);
    w->show();
}

