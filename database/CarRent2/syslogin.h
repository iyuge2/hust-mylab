#ifndef SYSLOGIN_H
#define SYSLOGIN_H

#include <QDialog>
#include <QString>

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
/*
 * op==0 全部显示
 * op==1 显示特定车辆
 * op==2 显示特定员工
 * op==3 显示特定用户
 * op==4 显示特定时间
 */
    void RentInfo_Show(int op = 0);
private:
    Ui::SysLogin *ui;
};

#endif // SYSLOGIN_H
