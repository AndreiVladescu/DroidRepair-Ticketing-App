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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketViewerDialog
{
public:
    QTableWidget *ticketTableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *TicketViewerDialog)
    {
        if (TicketViewerDialog->objectName().isEmpty())
            TicketViewerDialog->setObjectName(QString::fromUtf8("TicketViewerDialog"));
        TicketViewerDialog->resize(935, 375);
        ticketTableWidget = new QTableWidget(TicketViewerDialog);
        if (ticketTableWidget->columnCount() < 4)
            ticketTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ticketTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ticketTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ticketTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ticketTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (ticketTableWidget->rowCount() < 2)
            ticketTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ticketTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ticketTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ticketTableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        ticketTableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        ticketTableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        ticketTableWidget->setItem(0, 3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        ticketTableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ticketTableWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        ticketTableWidget->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        ticketTableWidget->setItem(1, 3, __qtablewidgetitem13);
        ticketTableWidget->setObjectName(QString::fromUtf8("ticketTableWidget"));
        ticketTableWidget->setGeometry(QRect(60, 0, 861, 371));
        ticketTableWidget->setMaximumSize(QSize(16777215, 16777215));
        ticketTableWidget->setLayoutDirection(Qt::LeftToRight);
        ticketTableWidget->setFrameShape(QFrame::Panel);
        ticketTableWidget->setFrameShadow(QFrame::Sunken);
        ticketTableWidget->setShowGrid(true);
        ticketTableWidget->setGridStyle(Qt::SolidLine);
        ticketTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        ticketTableWidget->horizontalHeader()->setDefaultSectionSize(190);
        ticketTableWidget->horizontalHeader()->setHighlightSections(true);
        ticketTableWidget->horizontalHeader()->setStretchLastSection(true);
        ticketTableWidget->verticalHeader()->setStretchLastSection(false);
        pushButton = new QPushButton(TicketViewerDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 10, 61, 61));

        retranslateUi(TicketViewerDialog);

        QMetaObject::connectSlotsByName(TicketViewerDialog);
    } // setupUi

    void retranslateUi(QDialog *TicketViewerDialog)
    {
        TicketViewerDialog->setWindowTitle(QCoreApplication::translate("TicketViewerDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ticketTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TicketViewerDialog", "Ticket ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ticketTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TicketViewerDialog", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ticketTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TicketViewerDialog", "Problem", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = ticketTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TicketViewerDialog", "Solution", nullptr));

        const bool __sortingEnabled = ticketTableWidget->isSortingEnabled();
        ticketTableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = ticketTableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TicketViewerDialog", "53", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = ticketTableWidget->item(0, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TicketViewerDialog", "Hardware", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = ticketTableWidget->item(0, 2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TicketViewerDialog", "LCD is bad", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = ticketTableWidget->item(0, 3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TicketViewerDialog", "Replace LCD", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = ticketTableWidget->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("TicketViewerDialog", "67", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = ticketTableWidget->item(1, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("TicketViewerDialog", "Software", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = ticketTableWidget->item(1, 2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("TicketViewerDialog", "There are some bad glitches going on in this app, maybe the devs need to look more closely on that damned spagetti code!", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = ticketTableWidget->item(1, 3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("TicketViewerDialog", "The devs (don't) know what they're doing. Ticket has been submitted and they are testing the solution right now.", nullptr));
        ticketTableWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QCoreApplication::translate("TicketViewerDialog", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketViewerDialog: public Ui_TicketViewerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETVIEWERDIALOG_H
