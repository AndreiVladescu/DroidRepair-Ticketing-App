#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <fstream>
#include <iostream>

using namespace std;

#include "ticketviewerdialog.h"
#include "Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    friend bool Login(MainWindow* ui);
private slots:
    void on_loginButton_clicked();

    void on_passwordcheckBox_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_ipLineEdit_editingFinished();

    void on_emailLineEdit_editingFinished();

    void on_passwordLineEdit_editingFinished();

    void on_saveCredentialsButton_clicked();

private:
    Ui::MainWindow *ui;
    QString password = "";
    QString email = "";
    TicketViewerDialog* ticketWindow = nullptr;

    void loadCache();

};
#endif // MAINWINDOW_H
