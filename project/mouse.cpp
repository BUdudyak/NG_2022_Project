#include "mouse.h"
#include "ui_mouse.h"

mouse::mouse(QObject *parent)
{
    ui->setupUi(this);
}

void mouse::pressMouseButton()
{
    ui->l_LB->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
}
