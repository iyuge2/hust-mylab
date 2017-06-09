#ifndef WORKERLOGIN_H
#define WORKERLOGIN_H

#include <QDialog>

namespace Ui {
class WorkerLogin;
}

class WorkerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerLogin(QWidget *parent = 0);
    ~WorkerLogin();
private slots:
    void Exit();
    void select();
    void AddCar();
    void DelCar();
    void RevCar();
    void DelUser();
    void QueryRent();
    void DealRequest();
    void ChangeBasic();
    void ChangePass();
private:
    void CarInfo_Show();
    void UserInfo_Show();
/*
 * op==0 全部显示
 * op==1 显示特定车辆
 * op==2 显示特定员工
 * op==3 显示特定用户
 * op==4 显示特定时间
 */
    void RentInfo_Show(int op = 0);
    void BasicShow();
private:
    Ui::WorkerLogin *ui;
};

#endif // WORKERLOGIN_H
