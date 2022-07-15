#include "driver.h"
#include "ui_driver.h"

driver::driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::driver)
    , m_gamepad(0)
{
    ui->setupUi(this);
    ui->l_connection->setReadOnly(true);

    m_gamepad = new QGamepad;

    connect(m_gamepad, &QGamepad::connectedChanged, this, &driver::showConnectionStatus);
}

driver::~driver()
{
    delete ui;
}

void driver::showConnectionStatus()
{
    if(m_gamepad->isConnected())
    {
        ui->l_connection->setText("Connected");
    }
    else
    {
        ui->l_connection->setText("Disconnected");
    }
}

