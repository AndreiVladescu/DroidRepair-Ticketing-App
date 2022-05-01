#include "mainwindow.h"
#include "./ui_mainwindow.h"

Client* myClient;

bool Login(MainWindow* ui)
{
    string email, password;
    bool userLogged = false;

    email = ui->email.toStdString();
    password = ui->password.toStdString();

    myClient->SendPacketType(Login_Client_Request);
    myClient->SendString(email);
    myClient->SendString(password);

    myClient->GetBool(userLogged);
    return userLogged;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->ipLineEdit->setVisible(false);
    ui->ipLabel->setVisible(false);
    ui->saveCredentialsButton->setVisible(false);

    this->loadCache();

    serverIP = ui->ipLineEdit->text().toStdString();
}

void MainWindow::loadCache()
{
    ifstream cacheFile("usercache.txt");
    if (cacheFile.is_open()){
        string tempMail;
        string tempPassword;
        cacheFile >> tempMail;
        cacheFile >> tempPassword;

        this->email =QString::fromStdString(tempMail);
        this->password =QString::fromStdString(tempPassword);
        ui->emailLineEdit->setText(email);
        ui->passwordLineEdit->setText(password);
    }
    else {
        ofstream writeCache("usercache.txt");
        writeCache.close();
    }
    cacheFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    WSACleanup();
}


void MainWindow::on_loginButton_clicked()
{
    myClient = new Client(serverIP.c_str(), DEFAULT_PORT, this);

    if (!myClient->Connect())
        {
            exit(EXIT_FAILURE);
        }

    if (Login(this)){
        myClient->StartSubRoutine();
        ui->labelConnectionStatus->setText(QString("Connected"));
        ui->labelLed->setPixmap(QPixmap(QString::fromUtf8(":/imgs/Resources/green_led.jpg")));
        myClient->SendPacketType(Send_Ticket_Vector_Request);
        //PACKET_HEADER packet_Type;


        Sleep(500);
        this->hide();

        // TODO add user to constructor
        ticketWindow = new TicketViewerDialog(this, &this->ticketVector);
        //icketWindow->ticketVectorPtr = &this->ticketVector;
        ticketWindow->setModal(true);
        ticketWindow->exec();

        if(this->ticketWindow != nullptr)
        {
            delete ticketWindow;
            ticketWindow = nullptr;
        }
        show();
    }
   else {
        ui->labelConnectionStatus->setText(QString("Couldn't connect"));
        ui->labelLed->setPixmap(QPixmap(QString::fromUtf8(":/imgs/Resources/red_led.jpg")));
        delete myClient;
        myClient = nullptr;
    }
}

void MainWindow::on_passwordcheckBox_stateChanged(int arg1)
{
    if (ui->passwordLineEdit->echoMode() == QLineEdit::Password)
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
    else
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->ipLabel->isVisible() && ui->ipLineEdit->isVisible()){
        ui->ipLabel->setVisible(false);
        ui->ipLineEdit->setVisible(false);
        ui->saveCredentialsButton->setVisible(false);
    }
    else {
        ui->ipLabel->setVisible(true);
        ui->ipLineEdit->setVisible(true);
        ui->saveCredentialsButton->setVisible(true);
    }
}


void MainWindow::on_ipLineEdit_editingFinished()
{
    serverIP = ui->ipLineEdit->text().toStdString();
}


void MainWindow::on_emailLineEdit_editingFinished()
{
    this->email = ui->emailLineEdit->text();
}


void MainWindow::on_passwordLineEdit_editingFinished()
{
    this->password = ui->passwordLineEdit->text();
}


void MainWindow::on_saveCredentialsButton_clicked()
{
    string tempMail;
    string tempPassword;
    tempMail = this->email.toStdString();
    tempPassword = this->password.toStdString();
    ofstream cacheFile("usercache.txt");
    cacheFile << tempMail;
    cacheFile << endl;
    cacheFile << tempPassword;
    cacheFile.close();
}

