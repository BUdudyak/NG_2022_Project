#include "mouse.h"

mouse::mouse()
{
    m_press = 0;
    m_release = 0;
}

void mouse::pressMouseButton()
{
    ui->l_LB->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
}
