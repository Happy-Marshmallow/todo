#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QtGui>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updatelistview();

private slots:
    void on_addbutton_clicked();

    void on_removebutton_clicked();

    void on_statusbutton_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
