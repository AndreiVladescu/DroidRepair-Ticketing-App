/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *passwordLabel;
    QLabel *emailLabel;
    QLabel *loginLabel;
    QLineEdit *ipLineEdit;
    QLabel *ipLabel;
    QLabel *label_image;
    QPushButton *loginButton;
    QCheckBox *passwordcheckBox;
    QPushButton *pushButton;
    QLabel *labelConnectionStatus;
    QLabel *labelLed;
    QPushButton *saveCredentialsButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(637, 435);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Resources/droid_repair.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        emailLineEdit = new QLineEdit(centralwidget);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setGeometry(QRect(220, 310, 211, 31));
        QFont font;
        font.setPointSize(14);
        emailLineEdit->setFont(font);
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(220, 350, 211, 31));
        passwordLineEdit->setFont(font);
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(100, 360, 91, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(16);
        passwordLabel->setFont(font1);
        emailLabel = new QLabel(centralwidget);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(130, 310, 51, 20));
        emailLabel->setFont(font1);
        loginLabel = new QLabel(centralwidget);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(300, 10, 61, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(20);
        loginLabel->setFont(font2);
        ipLineEdit = new QLineEdit(centralwidget);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(460, 40, 113, 22));
        QFont font3;
        font3.setPointSize(12);
        ipLineEdit->setFont(font3);
        ipLabel = new QLabel(centralwidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        ipLabel->setGeometry(QRect(480, 10, 91, 20));
        ipLabel->setFont(font1);
        label_image = new QLabel(centralwidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(230, 110, 191, 181));
        label_image->setTextFormat(Qt::RichText);
        label_image->setPixmap(QPixmap(QString::fromUtf8(":/imgs/Resources/droid_repair.png")));
        label_image->setScaledContents(true);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(520, 300, 81, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(18);
        loginButton->setFont(font4);
        loginButton->setFlat(false);
        passwordcheckBox = new QCheckBox(centralwidget);
        passwordcheckBox->setObjectName(QString::fromUtf8("passwordcheckBox"));
        passwordcheckBox->setGeometry(QRect(450, 360, 141, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Calibri")});
        font5.setPointSize(12);
        passwordcheckBox->setFont(font5);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 0, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Resources/cog_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(32, 32));
        labelConnectionStatus = new QLabel(centralwidget);
        labelConnectionStatus->setObjectName(QString::fromUtf8("labelConnectionStatus"));
        labelConnectionStatus->setGeometry(QRect(10, 10, 121, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Calibri")});
        font6.setPointSize(14);
        labelConnectionStatus->setFont(font6);
        labelLed = new QLabel(centralwidget);
        labelLed->setObjectName(QString::fromUtf8("labelLed"));
        labelLed->setGeometry(QRect(50, 40, 31, 31));
        labelLed->setPixmap(QPixmap(QString::fromUtf8(":/imgs/Resources/red_led.jpg")));
        labelLed->setScaledContents(true);
        saveCredentialsButton = new QPushButton(centralwidget);
        saveCredentialsButton->setObjectName(QString::fromUtf8("saveCredentialsButton"));
        saveCredentialsButton->setGeometry(QRect(460, 70, 141, 41));
        saveCredentialsButton->setFont(font6);
        saveCredentialsButton->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 637, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DroidRepair", nullptr));
        emailLineEdit->setText(QString());
        passwordLineEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        ipLineEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        ipLabel->setText(QCoreApplication::translate("MainWindow", "Server IP", nullptr));
        label_image->setText(QString());
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        passwordcheckBox->setText(QCoreApplication::translate("MainWindow", "Password Visible", nullptr));
        pushButton->setText(QString());
        labelConnectionStatus->setText(QCoreApplication::translate("MainWindow", "Not Connected", nullptr));
        labelLed->setText(QString());
        saveCredentialsButton->setText(QCoreApplication::translate("MainWindow", "Save Credentials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
