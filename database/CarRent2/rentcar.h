#ifndef RENTCAR_H
#define RENTCAR_H

#include <QDialog>

namespace Ui {
class RentCar;
}

class RentCar : public QDialog
{
    Q_OBJECT

public:
    explicit RentCar(QWidget *parent = 0);
    ~RentCar();

private:
    Ui::RentCar *ui;
};

#endif // RENTCAR_H
