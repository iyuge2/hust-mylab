#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = 0,float old = 0);
    ~Deposit();
private slots:
    void Ok();
    void Cancel();
private:
    Ui::Deposit *ui;
    float oldMoney;
};

#endif // DEPOSIT_H
