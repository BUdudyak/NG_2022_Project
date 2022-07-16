#include "driver.h"
#include "ui_driver.h"

driver::driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::driver)
    , m_gamepad(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Gamepad Driver for XBox");
    ui->l_connection->setStyleSheet("color: red");

    m_press = 0;
    m_release = 0;
    m_gamepad = new QGamepad;
    m_cursorSensitivity = 20;

    connect(m_gamepad, &QGamepad::connectedChanged, this, &driver::showConnectionStatus);
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, &driver::pressButton);
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, &driver::pressButton);
    connect(m_gamepad, &QGamepad::buttonAChanged, this, &driver::pressButton);
    connect(m_gamepad, &QGamepad::buttonBChanged, this, &driver::pressButton);
    connect(m_gamepad, &QGamepad::buttonXChanged, this, &driver::pressButton);
    connect(m_gamepad, &QGamepad::buttonYChanged, this, &driver::pressButton);

    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, &driver::changeCursorPos);
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, &driver::changeCursorPos);

    connect (ui->s_mouseSens, &QSlider::valueChanged, this, &driver::changeSensitivity);
}

driver::~driver()
{
    delete ui;
}

void driver::showConnectionStatus()
{
    if(m_gamepad->isConnected())
    {
        ui->l_connection->setStyleSheet("color: lime");
        ui->l_connection->setText("Connected");
    }
    else
    {
        ui->l_connection->setStyleSheet("color: red;");
        ui->l_connection->setText("Disconnected");
    }
}

void driver::pressButton()
{
    drawButtons();

    bool buttonPressed = checkButtonsStatus();

    if(buttonPressed == true)
    {
        mouse_event(m_press, QCursor::pos().x(), QCursor::pos().y(), 0, 0);
    }
    else
    {
        mouse_event(m_release, QCursor::pos().x(), QCursor::pos().y(), 0, 0);
    }
}

void driver::changeCursorPos()
{
    mouse_event(MOVE, (m_gamepad->axisLeftX() * m_cursorSensitivity)/7, 0, 0, 0);
    mouse_event(MOVE, 0, (m_gamepad->axisLeftY() * m_cursorSensitivity)/7, 0, 0);

    ui->s_axisX->setValue(qRound(m_gamepad->axisLeftX()*100));
    ui->s_axisY->setValue(qRound(m_gamepad->axisLeftY()*100));
}

void driver::drawButtons()
{
    QString pressed = "background-color: rgb(125, 125, 126);\ncolor: rgb(255, 255, 255)";
    QString released = "background-color: rgb(240, 240, 240);\ncolor: rgb(0, 0, 0)";

    ui->l_LB->setStyleSheet(m_gamepad->buttonL1() ? pressed : released);
    ui->l_RB->setStyleSheet(m_gamepad->buttonR1() ? pressed : released);
    ui->l_A->setStyleSheet(m_gamepad->buttonA()   ? "background-color: rgb(125, 125, 126);\ncolor: chartreuse"  : released);
    ui->l_B->setStyleSheet(m_gamepad->buttonB()   ? "background-color: rgb(125, 125, 126);\ncolor: red"         : released);
    ui->l_X->setStyleSheet(m_gamepad->buttonX()   ? "background-color: rgb(125, 125, 126);\ncolor: blue"        : released);
    ui->l_Y->setStyleSheet(m_gamepad->buttonY()   ? "background-color: rgb(125, 125, 126);\ncolor: yellow"      : released);
}

void driver::changeSensitivity()
{
    m_cursorSensitivity = ui->s_mouseSens->value();
}

bool driver::checkButtonsStatus()
{
    bool buttonPressed = false;

    if(m_gamepad->buttonB() && m_gamepad->buttonX())
    {
        system("start explorer");
    }
    else if(m_gamepad->buttonB() && m_gamepad->buttonY())
    {
        system("start steam://rungameid/570");
    }
    else if(m_gamepad->buttonX() && m_gamepad->buttonY())
    {
        system("start C:\\Users\\User\\Pictures\\_720_2147418549_Trim_Trim.mp4");
    }
    else if(m_gamepad->buttonL1())
    {
        buttonPressed = m_gamepad->buttonL1();
        m_press = LEFTDOWN;
        m_release = LEFTUP;
    }
    else if(m_gamepad->buttonR1())
    {
        buttonPressed = m_gamepad->buttonR1();
        m_press = RIGHTDOWN;
        m_release = RIGHTUP;
    }
    else if(m_gamepad->buttonA())
    {
        buttonPressed = m_gamepad->buttonA();
        m_press = MIDDLEDOWN;
        m_release = MIDDLEUP;
    }
    return buttonPressed;
}
