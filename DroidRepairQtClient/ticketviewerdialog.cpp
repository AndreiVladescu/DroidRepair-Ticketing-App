#include "ticketviewerdialog.h"
#include "ui_ticketviewerdialog.h"

TicketViewerDialog::TicketViewerDialog(QWidget *parent, vector<Ticket>* parentTicketVector) :
    QDialog(parent),
    ui(new Ui::TicketViewerDialog)
{
    this->ticketVectorPtr = parentTicketVector;
    ui->setupUi(this);
}

TicketViewerDialog::~TicketViewerDialog()
{
    delete ui;
}

void TicketViewerDialog::on_pushButton_clicked()
{
    this->ui->label->setText(QString::number(this->ticketVectorPtr->size()));
}

