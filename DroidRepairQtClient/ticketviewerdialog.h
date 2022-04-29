#ifndef TICKETVIEWERDIALOG_H
#define TICKETVIEWERDIALOG_H

#include <QDialog>

namespace Ui {
class TicketViewerDialog;
}

class TicketViewerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketViewerDialog(QWidget *parent = nullptr);
    ~TicketViewerDialog();

private:
    Ui::TicketViewerDialog *ui;
};

#endif // TICKETVIEWERDIALOG_H
