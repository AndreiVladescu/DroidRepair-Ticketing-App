#include "ticketviewerdialog.h"
#include "ui_ticketviewerdialog.h"

TicketViewerDialog::TicketViewerDialog(QWidget *parent, vector<Ticket>* parentTicketVector) :
    QDialog(parent),
    ui(new Ui::TicketViewerDialog)
{
    this->ticketVectorPtr = parentTicketVector;

    ui->setupUi(this);
    this->ui->ticketTableWidget->setColumnWidth(0, 55);
    this->ui->ticketTableWidget->setColumnWidth(1, 60);
    this->ui->ticketTableWidget->setColumnWidth(2, 200);
    this->ui->ticketTableWidget->setColumnWidth(3, 200);

    this->on_pushButton_clicked();
}

TicketViewerDialog::~TicketViewerDialog()
{
    delete ui;
}

void TicketViewerDialog::on_pushButton_clicked()
{
    for (int i=0;i<this->ticketVectorPtr->size();i++){
        Ticket tempTicket = (*this->ticketVectorPtr)[i];
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromStdString(std::to_string(tempTicket.getID())));
        this->ui->ticketTableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromStdString(tempTicket.getCategory()));
        this->ui->ticketTableWidget->setItem(i, 1, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromStdString(tempTicket.getProblem()));
        this->ui->ticketTableWidget->setItem(i, 2, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromStdString(tempTicket.getSolution()));
        this->ui->ticketTableWidget->setItem(i, 3, item);
    }
}

