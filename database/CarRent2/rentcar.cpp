#include "rentcar.h"
#include "ui_rentcar.h"

RentCar::RentCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RentCar)
{
    ui->setupUi(this);
}

RentCar::~RentCar()
{
    delete ui;
}
