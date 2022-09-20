#include "mainwindow.h"
#include "databasemanager.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = databaseManager::open();
    databaseManager::initDatabase(db);
    updatelistview();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatelistview()
{
    ui->listWidget->clear();
    QSqlDatabase db;
    db = databaseManager::open();
    QList<datatemplate> listdata = databaseManager::getsData(db);
    databaseManager::close(db);
    for (int i = 0; i < listdata.length(); i++)
    {
        ui->listWidget->addItem(listdata.at(i).name);
    }
}

void MainWindow::on_addbutton_clicked()
{
    datatemplate temp;
    QSqlDatabase db;
    db = databaseManager::open();
    temp.name = ui->lineEdit->text();
    databaseManager::insertData(db, temp);
    databaseManager::close(db);
    updatelistview();
}


void MainWindow::on_removebutton_clicked()
{
    QSqlDatabase db;
    datatemplate temp;
    temp.name = ui->lineEdit->text();
    databaseManager::removeData(db, temp);
    databaseManager::close(db);
    updatelistview();
}


void MainWindow::on_statusbutton_clicked()
{

}


void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ui->lineEdit->setText(ui->listWidget->currentItem()->text());
}

