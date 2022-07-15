#include "driver.h"
#include "ui_driver.h"

driver::driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::driver)
    , m_gamepad(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Gamepad Driver for XBox");
    //ui->l_connection->setReadOnly(true);

    m_press = 0;
    m_release = 0;
    m_gamepad = new QGamepad;

    connect(m_gamepad, &QGamepad::connectedChanged, this, &driver::showConnectionStatus);
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, &driver::pressMouseButton);
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, &driver::pressMouseButton);
    connect(m_gamepad, &QGamepad::buttonAChanged, this, &driver::pressMouseButton);
    connect(m_gamepad, &QGamepad::buttonBChanged, this, &driver::pressMouseButton);
    connect(m_gamepad, &QGamepad::buttonXChanged, this, &driver::pressMouseButton);
    connect(m_gamepad, &QGamepad::buttonYChanged, this, &driver::pressMouseButton);

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

void driver::pressMouseButton()
{
    QGamepad *button = (QGamepad*)sender();
    QLabel *textLabel = ui->l_LB;
    bool buttonPressed = false;

    if (button->buttonL1())
    {
        buttonPressed = button->buttonL1();
        m_press = LEFTDOWN;
        m_release = LEFTUP;
        textLabel = ui->l_LB;
    }
    if (button->buttonR1())
    {
        buttonPressed = button->buttonR1();
        m_press = RIGHTDOWN;
        m_release = RIGHTUP;
        textLabel = ui->l_RB;
    }
    if (button->buttonA())
    {
        buttonPressed = button->buttonA();
        m_press = MIDDLEDOWN;
        m_release = MIDDLEUP;
        textLabel = ui->l_A;
    }

    if (buttonPressed == true)    {
        mouse_event(m_press, QCursor::pos().x(), QCursor::pos().y(), 0, 0);
        textLabel->setStyleSheet("background-color: rgb(125, 125, 126);\ncolor: rgb(255, 255, 255)");
    }
    else {
        mouse_event(m_release, QCursor::pos().x(), QCursor::pos().y(), 0, 0);
        ui->l_LB->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
        ui->l_RB->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
        ui->l_A->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
        ui->l_B->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
        ui->l_X->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
        ui->l_Y->setStyleSheet("background-color: rgb(32, 33, 34);\ncolor: rgb(255, 255, 255)");
    }
}

