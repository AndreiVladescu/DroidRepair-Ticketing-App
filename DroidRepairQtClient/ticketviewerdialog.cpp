#include "ticketviewerdialog.h"
#include "ui_ticketviewerdialog.h"

TicketViewerDialog::TicketViewerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketViewerDialog)
{
    ui->setupUi(this);
}

TicketViewerDialog::~TicketViewerDialog()
{
    delete ui;
}
