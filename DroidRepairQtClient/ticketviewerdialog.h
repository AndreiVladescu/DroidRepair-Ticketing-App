#ifndef TICKETVIEWERDIALOG_H
#define TICKETVIEWERDIALOG_H

#include <QDialog>
#include <vector>
#include <iostream>

#include "Ticket.h"

using namespace std;

namespace Ui {
class TicketViewerDialog;
}

class TicketViewerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketViewerDialog(QWidget *parent = nullptr, vector<Ticket>* parentTicketVector = nullptr);
    ~TicketViewerDialog();
    vector<Ticket>* ticketVectorPtr;
private slots:
    void on_pushButton_clicked();

private:
    Ui::TicketViewerDialog *ui;
};

#endif // TICKETVIEWERDIALOG_H
