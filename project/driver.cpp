#include "driver.h"
#include "ui_driver.h"

driver::driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::driver)
{
    ui->setupUi(this);
}

driver::~driver()
{
    delete ui;
}

