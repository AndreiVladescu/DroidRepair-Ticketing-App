/********************************************************************************
** Form generated from reading UI file 'ticketviewingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETVIEWINGWINDOW_H
#define UI_TICKETVIEWINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketViewingWindow
{
public:
    QListView *listViewTickets;
    QLineEdit *lineEdit;

    void setupUi(QWidget *TicketViewingWindow)
    {
        if (TicketViewingWindow->objectName().isEmpty())
            TicketViewingWindow->setObjectName(QString::fromUtf8("TicketViewingWindow"));
        TicketViewingWindow->resize(793, 531);
        listViewTickets = new QListView(TicketViewingWindow);
        listViewTickets->setObjectName(QString::fromUtf8("listViewTickets"));
        listViewTickets->setGeometry(QRect(10, 10, 771, 511));
        lineEdit = new QLineEdit(TicketViewingWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(330, 120, 113, 22));

        retranslateUi(TicketViewingWindow);

        QMetaObject::connectSlotsByName(TicketViewingWindow);
    } // setupUi

    void retranslateUi(QWidget *TicketViewingWindow)
    {
        TicketViewingWindow->setWindowTitle(QCoreApplication::translate("TicketViewingWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketViewingWindow: public Ui_TicketViewingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETVIEWINGWINDOW_H
