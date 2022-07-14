#ifndef DRIVER_H
#define DRIVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class driver; }
QT_END_NAMESPACE

class driver : public QMainWindow
{
    Q_OBJECT

public:
    driver(QWidget *parent = nullptr);
    ~driver();

private:
    Ui::driver *ui;
};
#endif // DRIVER_H
