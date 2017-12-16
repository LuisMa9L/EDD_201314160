#include "pantalla.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pantalla w;
    w.show();

    return a.exec();
}
