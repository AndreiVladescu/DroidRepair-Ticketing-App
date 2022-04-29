/********************************************************************************
** Form generated from reading UI file 'ticketviewerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETVIEWERDIALOG_H
#define UI_TICKETVIEWERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_TicketViewerDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *TicketViewerDialog)
    {
        if (TicketViewerDialog->objectName().isEmpty())
            TicketViewerDialog->setObjectName(QString::fromUtf8("TicketViewerDialog"));
        TicketViewerDialog->resize(400, 300);
        label = new QLabel(TicketViewerDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 120, 49, 16));

        retranslateUi(TicketViewerDialog);

        QMetaObject::connectSlotsByName(TicketViewerDialog);
    } // setupUi

    void retranslateUi(QDialog *TicketViewerDialog)
    {
        TicketViewerDialog->setWindowTitle(QCoreApplication::translate("TicketViewerDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TicketViewerDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketViewerDialog: public Ui_TicketViewerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETVIEWERDIALOG_H
