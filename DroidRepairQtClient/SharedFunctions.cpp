#include "mainwindow.h"
#include "Client.h"

void TransferTickets(Client* clientPtr, MainWindow* windowPtr)
{
    windowPtr->ticketVector = clientPtr->ticketVector;
}
