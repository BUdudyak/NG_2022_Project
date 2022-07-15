#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>

#include "driver.h"
#include "Windows.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mouse; }
QT_END_NAMESPACE

class mouse : public QObject
{
    Q_OBJECT

public:
    mouse();

protected slots:
    void pressMouseButton();


private:
    int m_press;
    int m_release;
};

#endif // MOUSE_H
