#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>

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

    void CarInfo_Show();
    void Rent();

    void ReviseBasic();
    void AddMoney();
    void ChangePass();
private:
    Ui::UserLogin *ui;
    void ShowBasic();
};

#endif // USERLOGIN_H
