#include "driver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    driver w;
    w.show();
    return a.exec();
}
