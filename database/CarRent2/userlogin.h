#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>

const int MAXTNUM = 10000000;//设置最大允许的订单数
namespace Ui {
class UserLogin;
}

class UserLogin : public QDialog
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = 0);
    ~UserLogin();
private slots:
    void Exit();  
    void Rent();  
    void FinishOrder();
    void ReviseBasic();
    void AddMoney();
    void ChangePass();
    void select();
private:
    Ui::UserLogin *ui;
    void CarInfo_Show();
    void ShowMyOrder();
    void ShowBasic();
};

#endif // USERLOGIN_H
