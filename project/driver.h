#ifndef DRIVER_H
#define DRIVER_H

#include <QMainWindow>

#include <QGamepad>
#include <QObject>
#include <QPoint>
#include <QWidget>
#include <QEvent>
#include <QCloseEvent>
#include <QDebug>

#include "windows.h"

QT_BEGIN_NAMESPACE
namespace Ui { class driver; }
QT_END_NAMESPACE

class driver : public QMainWindow
{
    Q_OBJECT

public:
    driver(QWidget *parent = nullptr);
    ~driver();

    enum mouseEvent
    {
        LEFTDOWN = 0x0002,
        LEFTUP = 0x0004,
        RIGHTDOWN = 0x0008,
        RIGHTUP = 0x0010,
        MIDDLEDOWN = 0x0020,
        MIDDLEUP = 0x0040,
        WHEELROTATE = 0x0800,
        MOVE = 0x0001
    };

public slots:
    void showConnectionStatus();
    void pressButton();
    void changeCursorPos();
    void drawButtons();
    void changeSensitivity();
    bool checkButtonsStatus();

private:
    Ui::driver *ui;
    QGamepad *m_gamepad;

    QPoint cursorPosition;
    int m_press;
    int m_release;
    int m_wheelSensitivity;
    int m_cursorSensitivity;

};
#endif // DRIVER_H
