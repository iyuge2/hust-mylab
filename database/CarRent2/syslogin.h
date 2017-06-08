#ifndef SYSLOGIN_H
#define SYSLOGIN_H

#include <QDialog>

namespace Ui {
class SysLogin;
}

class SysLogin : public QDialog
{
    Q_OBJECT

public:
    explicit SysLogin(QWidget *parent = 0);
    ~SysLogin();
private slots:
    void Exit();
    void select();
    void AddCar();
    void DelCar();
    void RevCar();
    void AddWorker();
    void DelWorker();
    void DelUser();
    void QueryRent();
private:
    void CarInfo_Show();
    void WorkerInfo_Show();
    void UserInfo_Show();
    void RentInfo_Show();
private:
    Ui::SysLogin *ui;
};

#endif // SYSLOGIN_H
