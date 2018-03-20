#include "userlogin.h"
#include "ui_userlogin.h"
#include "revisebasicinfo.h"
#include "deposit.h"
#include "revisepass.h"
#include <QListWidget>
#include <QLabel>
#include <QTime>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QDebug>

extern QSqlQuery query;
extern QString Logid;

UserLogin::UserLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    ShowBasic();
    CarInfo_Show();
    ShowMyOrder();
    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(Exit()));

    connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(select()));
    connect(ui->RentButton,SIGNAL(clicked()),this,SLOT(Rent()));

    connect(ui->FOButton,SIGNAL(clicked()),this,SLOT(FinishOrder()));

    connect(ui->BasicButton,SIGNAL(clicked()),this,SLOT(ReviseBasic()));
    connect(ui->AccountButton,SIGNAL(clicked()),this,SLOT(AddMoney()));
    connect(ui->PassButton,SIGNAL(clicked()),this,SLOT(ChangePass()));
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::select()
{
    if(ui->tabWidget->currentIndex() == 0)
    {
        CarInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {
        ShowMyOrder();
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {
        ShowBasic();
    }
}
void UserLogin::CarInfo_Show()
{
    int carNum = 0;
    ui->tableWidget->clearContents();
    query.exec("select * from CarInfo");
    while(query.next())
    {
        ui->tableWidget->setRowCount(carNum+1);
        QString cnum = query.value(0).toString();
        QString brand = query.value(1).toString();
        QString color = query.value(2).toString();
        QString status = query.value(3).toString();
        QString fee = query.value(4).toString();
        QString cash = query.value(6).toString();
        QString ree = query.value(7).toString();
        QString vip = (query.value(8).toString() == "Y" ? "仅限vip" : "无");
        if(status == "A")
            status = "空闲";
        else if(status == "B")
            status = "正在使用中";
        else
            status = "维修中";
        ui->tableWidget->setItem(carNum,0,new QTableWidgetItem(cnum));
        ui->tableWidget->setItem(carNum,1,new QTableWidgetItem(brand));
        ui->tableWidget->setItem(carNum,2,new QTableWidgetItem(color));
        ui->tableWidget->setItem(carNum,3,new QTableWidgetItem(status));
        ui->tableWidget->setItem(carNum,4,new QTableWidgetItem(fee));
        ui->tableWidget->setItem(carNum,5,new QTableWidgetItem(cash));
        ui->tableWidget->setItem(carNum,6,new QTableWidgetItem(ree));
        ui->tableWidget->setItem(carNum,7,new QTableWidgetItem(vip));
        carNum++;
    }
}

void UserLogin::Rent()
{
    QString tnum = "";
    QString cnum0;
    QString cnum1 = "";
    QString cnum2 = ui->lineEdit->text();
    if(ui->tableWidget->currentRow() != -1)
    {
        cnum1 = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
    }
    if(cnum2.isEmpty())
    {
        if(cnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "您未选择任何车辆!", QMessageBox::Ok);
            return;
        }
        else
        {
            cnum0 = cnum1;
        }
    }
    else
    {
        cnum0 = cnum2;
    }
    const QString temp0 = "select Sta,Cash,Vip from CarInfo where Cnum='" + cnum0 + "'";
    const QString temp1 = "select Acn,Cre from User where Uname='" + Logid + "'";
    float ree = 0,acn = 0;
    QString cre = "",vip = "";
    query.exec(temp0);
    if(query.next())
    {
        if(query.value(0).toString() == "B")
        {
            QMessageBox::information(this, "Tips", "这辆车已经被别人抢走了!", QMessageBox::Ok);
            return;
        }
        else if(query.value(0).toString() == "C")
        {
            QMessageBox::information(this, "Tips", "这辆车还在修养之中!", QMessageBox::Ok);
            return;
        }
        ree = query.value(1).toFloat();
        vip = query.value(2).toString();
    }
    else
    {
        QMessageBox::information(this, "Tips", "oh~no,这辆车不见了...!", QMessageBox::Ok);
        return;
    }
    query.exec(temp1);
    if(query.next())
    {
        acn = query.value(0).toFloat();
        cre = query.value(1).toString();
        if((vip == "Y") && (acn < 10000))
        {
            QMessageBox::information(this, "Tips", "很抱歉，您不是vip用户\n无法使用此车!", QMessageBox::Ok);
            return;
        }
    }
    else
    {
        QMessageBox::information(this, "Tips", "系统异常!", QMessageBox::Ok);
        return;
    }
    //根据用户信用等级判断用户账户余额是否满足租车条件
    if(((cre == "A") && (acn < 100))|| //A等级免押金，但需要账户余额大于100，避免不能正常缴费
       ((cre == "B") && (acn < ree)) || //B等级正常押金
       ((cre == "C") && (acn < ree*1.2)) ||//C等级1.2倍押金
       ((cre == "D") && (acn < ree*2)))//D等级2倍押金
    {
        QMessageBox::information(this, "Tips", "账户余额不足!", QMessageBox::Ok);
        return;
    }
    const QString temp2 = "select Wnum from RentInfo where Uname='" + Logid + "'";
    query.exec(temp2);
    while(query.next())
    {
        if(query.value(0).toString() == "W000000000")
        {
            QMessageBox::information(this, "Tips", "您当前还有未完成订单！", QMessageBox::Ok);
            return;
        }
    }
        while(1)
        {//获得一个有效的订单编号
            tnum = "T" + QString::number(qrand()%MAXTNUM);
            const QString temp3 = "select Tnum from RentInfo where Tnum='" + tnum + "'";
            query.exec(temp3);
            if(!query.next())
            {
                break;
            }
        }
        const QString temp4 = "insert into RentInfo values('" + tnum + "','W000000000','" + Logid + "','" + cnum0 + \
                "','" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "',null,0,0,'A')";
        const QString temp5 = "update CarInfo set Sta='B' where Cnum='" + cnum0 + "'";
        if(query.exec(temp4) && query.exec(temp5))
        {
            QMessageBox::information(this, "Tips", "租车成功，请平安驾驶！", QMessageBox::Ok);          
            return;
        }
        else
        {
            QMessageBox::information(this, "Tips", "系统异常，租车失败！", QMessageBox::Ok);
            return;
        }
}

void UserLogin::ShowMyOrder()
{
    int carNum = 0;
    ui->tableWidget->clearContents();
    const QString temp = "select * from RentInfo where Uname='" + Logid + "'";
    query.exec(temp);
    while(query.next())
    {
        ui->tableWidget_2->setRowCount(carNum+1);
        QString tnum = query.value(0).toString();
        QString cnum = query.value(3).toString();
        QDateTime stime = query.value(4).toDateTime();
        QDateTime ftime = query.value(5).toDateTime();
        QString OrderStatus = (query.value(1).toString() == "W000000000") ? "结束申请处理中..." : "已完成";
        QString fee = query.value(6).toString();
        QString fine = query.value(7).toString();
        QString allFee = QString::number((fee.toFloat() + fine.toFloat()),'f',2);
        if(ftime.isNull())
        {
            OrderStatus = "正在行驶中...";
            QDateTime s1 = stime;
            QDateTime s2 = QDateTime::currentDateTime();
            float ree = 0;
            const QString temp2 = "select Ree from CarInfo where Cnum='" + cnum + "'";
            QSqlQuery query2 = query;
            query2.exec(temp2);
            if(query2.next())
            {
                ree = query2.value(0).toFloat();
            }
            ree = ree * (s2.toTime_t() - s1.toTime_t()) / 3600.0;
            fee = QString::number(ree,'f',2);
            allFee = fee;
        }
        ui->tableWidget_2->setItem(carNum,0,new QTableWidgetItem(tnum));
        ui->tableWidget_2->setItem(carNum,1,new QTableWidgetItem(OrderStatus));
        ui->tableWidget_2->setItem(carNum,2,new QTableWidgetItem(cnum));
        ui->tableWidget_2->setItem(carNum,3,new QTableWidgetItem(stime.toString()));
        ui->tableWidget_2->setItem(carNum,4,new QTableWidgetItem(ftime.toString()));
        ui->tableWidget_2->setItem(carNum,5,new QTableWidgetItem(fee));
        ui->tableWidget_2->setItem(carNum,6,new QTableWidgetItem(fine));
        ui->tableWidget_2->setItem(carNum,7,new QTableWidgetItem(allFee));
        carNum++;
    }
}

void UserLogin::FinishOrder()
{
    QString tnum0;
    QString tnum1 = "";
    QString tnum2 = ui->lineEdit_2->text();
    if(ui->tableWidget_2->currentRow() != -1)
    {
        tnum1 = ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),0)->text();
    }
    if(tnum2.isEmpty())
    {
        if(tnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何行程!", QMessageBox::Ok);
            return;
        }
        else
        {
            tnum0 = tnum1;
        }
    }
    else
    {
        tnum0 = tnum2;
    }
    const QString temp = "select Wnum,Uname,Stm,Cnum from RentInfo where Tnum='" + tnum0 + "'";
    query.exec(temp);
    if(query.next())
    {
        if(query.value(1).toString() == Logid)
        {
            if(query.value(0).toString() != "W000000000")
            {
                QMessageBox::information(this, "Tips", "该订单已完成!", QMessageBox::Ok);
                return;
            }
        }
        else
        {
            QMessageBox::information(this, "Tips", "您没有该订单编号!", QMessageBox::Ok);
            return;
        }
    }
    else
    {
        QMessageBox::information(this, "Tips", "该订单不存在!", QMessageBox::Ok);
        return;
    }
    QString cnum = query.value(3).toString();
    QDateTime s1 = query.value(2).toDateTime();
    QDateTime s2 = QDateTime::currentDateTime();
    float ree = 0;
    const QString temp2 = "select Ree from CarInfo where Cnum='" + cnum + "'";
    query.exec(temp2);
    if(query.next())
    {
        ree = query.value(0).toFloat();
    }
    ree = ree * (s2.toTime_t() - s1.toTime_t()) / 3600.0;
    //提交订单结束申请
    const QString temp3 = "update RentInfo set Ftm='" +  s2.toString("yyyy-MM-dd hh:mm:ss") + "',Cash=" + QString::number(ree,'f',2) +\
                                " where Tnum='" + tnum0 + "'";
    if(query.exec(temp3))
    {
        QMessageBox::information(this, "Tips", "订单结束请求已提交!", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Tips", "订单结束请求提交失败!", QMessageBox::Ok);
    }
}

void UserLogin::ShowBasic()
{
    const QString temp = "select Uname,Sex,Age,Cre,Acn from User where Uname='" + Logid + "'";
    if(query.exec(temp) && query.next())
    {
        ui->label_name->setText(query.value(0).toString());
        ui->label_sex->setText((query.value(1).toString()=="M") ? "先生" : "女士");
        ui->label_age->setText(query.value(2).toString());
        ui->label_credit->setText(query.value(3).toString());
        ui->label_account->setText(query.value(4).toString());
        ui->label_grade->setText((query.value(4).toFloat() < 10000) ? "普通会员" : "黄金会员");
    }
    else
    {
        QMessageBox::information(this, "Tips", "用户信息读取错误！", QMessageBox::Ok);
    }
}

void UserLogin::ReviseBasic()
{
    ReviseBasicInfo* w = new ReviseBasicInfo(this);
    w->exec();
    delete w;
    ShowBasic();
}

void UserLogin::AddMoney()
{
    Deposit* w = new Deposit(this,ui->label_account->text().toFloat());
    w->exec();
    delete w;
    ShowBasic();
}

void UserLogin::ChangePass()
{
    RevisePass* w = new RevisePass(this);
    w->exec();
    delete w;
}

void UserLogin::Exit()
{
    this->close();
    parentWidget()->show();
}
