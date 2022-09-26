#include "suppwindow.h"
#include "ui_suppwindow.h"

suppwindow::suppwindow(GUIAuthManager &authManager,
                       GUIStudentManager &studentManager,
                       GUIThingManager &thingManager,
                       GUIRoomManager &roomManager,
                       QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::suppwindow)
{
    ui->setupUi(this);
    this->authManager = authManager;
    this->thingManager = thingManager;
    this->studentManager = studentManager;
    this->roomManager = roomManager;
}

suppwindow::~suppwindow()
{
    delete ui;
}

void suppwindow::on_enter_clicked()
{
    QMessageBox messageBox;
    if (this->ui->r1->isChecked())
    {
        LogAction().log("Пользователь хочет добавить вещь");
        int markNumber = this->ui->markEdit->toPlainText().toInt();
        std::string type = this->ui->typeEdit->toPlainText().toStdString();
        try
        {
            this->thingManager.addNewThing(markNumber, type);
            messageBox.information(0, "Успех!", "Удалось успешно добавить вещь!");
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
        LogAction().log("Пользователь хочет выдать вещь студенту");
        int markNumber = this->ui->markEdit->toPlainText().toInt();
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.giveStudentThing(studNumber, markNumber);
            messageBox.information(0, "Успех!", "Удалось успешно выдать вещь студенту!");
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
        LogAction().log("Пользователь хочет забрать вещь у студента");
        int markNumber = this->ui->markEdit->toPlainText().toInt();
        std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
        try
        {
            this->studentManager.returnStudentThing(studNumber, markNumber);
            messageBox.information(0, "Успех!", "Удалось успешно забрать вещь у студента!");
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
        LogAction().log("Пользователь хочет посмотреть студентов");
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
    else if (this->ui->r5->isChecked())
    {
        LogAction().log("Пользователь хочет посмотреть комнаты");
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
    else if (this->ui->r6->isChecked())
    {
        LogAction().log("Пользователь хочет посмотреть вещи");
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
                    if (info.getRoomType() == "Склад")
                        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("На складе")));
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
    else if (this->ui->r7->isChecked())
    {
        LogAction().log("Пользователь хочет посмотреть свободные вещи");
        ui->tableWidget->clear();
        try
        {
            std::vector<Thing> things = this->thingManager.viewFreeThings();
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
                if (things[i].getRoomID() == 0)
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
    else if (this->ui->r8->isChecked())
    {
        LogAction().log("Пользователь хочет переместить вещь");
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
    else if (this->ui->r9->isChecked())
    {
        LogAction().log("Пользователь хочет посмотреть вещи студента");
        ui->tableWidget->clear();
        try
        {
            std::string studNumber = this->ui->studEdit->toPlainText().toStdString();
            std::vector<Thing> things = this->thingManager.viewStudentThings(studNumber);
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
                if (things[i].getRoomID() == 0)
                    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("На складе")));
                else
                {
                    Room info = this->roomManager.getRoomByID(things[i].getRoomID());
                    if (info.getRoomType() == "Склад")
                        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("На складе")));
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
}


void suppwindow::on_enter_2_clicked()
{
    LogAction().log("Пользователь выходит из аккаунта");
    this->close();
    AuthWindow *w = new AuthWindow(authManager, studentManager, thingManager, roomManager);
    w->show();
}

