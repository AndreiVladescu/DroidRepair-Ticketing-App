#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "mainwindow.h"
#include "Client.h"
#include "Enum_Packets.h"

#include <QApplication>
#include <QDebug>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
