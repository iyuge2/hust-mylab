#include "userlogin.h"
#include "ui_userlogin.h"
#include "revisebasicinfo.h"
#include "deposit.h"
#include "revisepass.h"
#include <QListWidget>
#include <QLabel>
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
    //第一个Tab界面
    QStringList header;
    header<<tr("车辆编号")<<tr("品牌")<<tr("颜色")<<tr("车辆状态")<<tr("购入费用")<<tr("所需押金")<<tr("租金(/h)")<<tr("其他");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //第三个界面
    ShowBasic();

    CarInfo_Show();
    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(Exit()));

    connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(CarInfo_Show()));
    connect(ui->RentButton,SIGNAL(clicked()),this,SLOT(Rent()));

    connect(ui->BasicButton,SIGNAL(clicked()),this,SLOT(ReviseBasic()));
    connect(ui->AccountButton,SIGNAL(clicked()),this,SLOT(AddMoney()));
    connect(ui->PassButton,SIGNAL(clicked()),this,SLOT(ChangePass()));
}

UserLogin::~UserLogin()
{
    delete ui;
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
        QString cash = query.value(5).toString();
        QString ree = query.value(6).toString();
        QString vip = (query.value(7).toString() == "Y" ? "仅限vip" : "无");
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
    ;
}

void UserLogin::ShowBasic()
{
    const QString temp = "select Uname,Sex,Age,Cre,Acn,Ide from User where Uname='" + Logid + "'";
    if(query.exec(temp))
    {
        query.next();
        ui->label_name->setText(query.value(0).toString());
        ui->label_sex->setText((query.value(1).toString()=="M") ? "先生" : "女士");
        ui->label_age->setText(query.value(2).toString());
        ui->label_credit->setText(query.value(3).toString());
        ui->label_account->setText(query.value(4).toString());
        ui->label_grade->setText((query.value(5).toString() == "0") ? "普通会员" : "黄金会员");
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
