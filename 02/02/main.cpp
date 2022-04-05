#include "singleslot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SingleSlot w;
    w.show();

    return a.exec();
}
