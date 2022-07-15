#ifndef DRIVER_H
#define DRIVER_H

#include <QMainWindow>

#include <QtGamepad/QGamepadManager>
#include <QGamepad>
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

public slots:
    void showConnectionStatus();

private:
    Ui::driver *ui;
    QGamepad* m_gamepad;

};
#endif // DRIVER_H
