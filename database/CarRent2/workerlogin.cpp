#include "workerlogin.h"
#include "ui_workerlogin.h"
#include "addcarinfo.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QComboBox>

extern QSqlQuery query;
extern QString Logid;

WorkerLogin::WorkerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerLogin)
{
    ui->setupUi(this);

    //第一个Tab界面
    QStringList header;
    header<<tr("车辆编号")<<tr("品牌")<<tr("颜色")<<tr("车辆状态")<<tr("购入费用")<<tr("所需押金")<<tr("租金(/h)")<<tr("其他");
    ui->tableWidget_5->setHorizontalHeaderLabels(header);

    //第三个界面
    header<<tr("用户名")<<tr("性别")<<tr("年龄")<<tr("信用评级")<<tr("账户余额")<<tr("其他");
    ui->tableWidget_7->setHorizontalHeaderLabels(header);

    //第三个界面
    header<<tr("交易编号")<<tr("员工编号")<<tr("用户名")<<tr("车辆编号")<<tr("开始时间")<<tr("结束时间")<<tr("费用")<<tr("违罚款")<<tr("总费用");
    ui->tableWidget_8->setHorizontalHeaderLabels(header);

    CarInfo_Show();
    UserInfo_Show();
    RentInfo_Show();

    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(Exit()));
    connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(select()));

    connect(ui->ACButton_3,SIGNAL(clicked()),this,SLOT(AddCar()));
    connect(ui->DCButton_2,SIGNAL(clicked()),this,SLOT(DelCar()));
    connect(ui->RCButton_2,SIGNAL(clicked()),this,SLOT(RevCar()));

    connect(ui->DUButton_2,SIGNAL(clicked()),this,SLOT(DelUser()));

    connect(ui->RentOkButton_2,SIGNAL(clicked()),this,SLOT(QueryRent()));
    connect(ui->DealButton,SIGNAL(clicked()),this,SLOT(DealRequest()));
}

WorkerLogin::~WorkerLogin()
{
    delete ui;
}

void WorkerLogin::Exit()
{
    this->close();
    parentWidget()->show();
}

void WorkerLogin::select()
{
    if(ui->tabWidget->currentIndex() == 0)
    {
        CarInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {
        UserInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {
        RentInfo_Show();
    }
}

void WorkerLogin::CarInfo_Show()
{
    int carNum = 0;
    ui->tableWidget_5->clearContents();
    query.exec("select * from CarInfo");
    while(query.next())
    {
        ui->tableWidget_5->setRowCount(carNum+1);
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
        ui->tableWidget_5->setItem(carNum,0,new QTableWidgetItem(cnum));
        ui->tableWidget_5->setItem(carNum,1,new QTableWidgetItem(brand));
        ui->tableWidget_5->setItem(carNum,2,new QTableWidgetItem(color));
        ui->tableWidget_5->setItem(carNum,3,new QTableWidgetItem(status));
        ui->tableWidget_5->setItem(carNum,4,new QTableWidgetItem(fee));
        ui->tableWidget_5->setItem(carNum,5,new QTableWidgetItem(cash));
        ui->tableWidget_5->setItem(carNum,6,new QTableWidgetItem(ree));
        ui->tableWidget_5->setItem(carNum,7,new QTableWidgetItem(vip));
        carNum++;
    }
}

void WorkerLogin::AddCar()
{
    AddCarInfo* AcWin = new AddCarInfo(this);
    AcWin->exec();
    delete AcWin;
    CarInfo_Show();
}

void WorkerLogin::DelCar()
{
    QString cnum0;
    QString cnum1 = "";
    QString cnum2 = ui->lineEdit_5->text();
    if(ui->tableWidget_5->currentRow() != -1)
    {
        cnum1 = ui->tableWidget_5->item(ui->tableWidget_5->currentRow(),0)->text();
    }
    if(cnum2.isEmpty())
    {
        if(cnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何车辆!", QMessageBox::Ok);
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
    const QString temp1 = "select Cnum from CarInfo where Cnum='" + cnum0 + "'";
    query.exec(temp1);
    if(!query.next())
    {
        QMessageBox::information(this, "Tips", "不存在该车编号!", QMessageBox::Ok);
        return;
    }
    if(QMessageBox::question(this,"question","确定删除这条车辆信息吗?",QMessageBox::Yes|QMessageBox::No))
    {
        const QString temp2 = "delete from CarInfo where Cnum='" + cnum0 + "'";
        if(query.exec(temp2))
        {
            QMessageBox::information(this, "Tips", "删除成功!", QMessageBox::Ok);
            CarInfo_Show();
        }
        else
        {
            QMessageBox::information(this, "Tips", "删除失败!", QMessageBox::Ok);
        }
    }
}

void WorkerLogin::RevCar()
{//只有处于空闲状态的车可以修改编号信息
    QString cnum0;
    QString cnum1 = "";
    QString cnum2 = ui->lineEdit_5->text();
    if(ui->tableWidget_5->currentRow() != -1)
    {
        cnum1 = ui->tableWidget_5->item(ui->tableWidget_5->currentRow(),0)->text();
    }
    if(cnum2.isEmpty())
    {
        if(cnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何车辆!", QMessageBox::Ok);
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
    const QString temp = "select Cnum from CarInfo where Cnum='" + cnum0 + "'";
    query.exec(temp);
    if(query.next())
    {
        AddCarInfo* AcWin = new AddCarInfo(this,1,cnum0);
        AcWin->exec();
        delete AcWin;
        CarInfo_Show();
    }
    else
    {
        QMessageBox::information(this, "Tips", "该车牌号不存在!", QMessageBox::Ok);
        return;
    }
}


void WorkerLogin::UserInfo_Show()
{
    int carNum = 0;
    ui->tableWidget_7->clearContents();
    query.exec("select * from User");
    while(query.next())
    {
        ui->tableWidget_7->setRowCount(carNum+1);
        QString uname = query.value(0).toString();
        QString sex = (query.value(2).toString() == 'M') ? "男" : "女";
        QString age = query.value(3).toString();
        QString cre = query.value(4).toString();
        QString acn = query.value(5).toString();
        QString ide = (query.value(5).toFloat() < 1000) ? "普通会员" : "黄金会员";
        ui->tableWidget_7->setItem(carNum,0,new QTableWidgetItem(uname));
        ui->tableWidget_7->setItem(carNum,1,new QTableWidgetItem(sex));
        ui->tableWidget_7->setItem(carNum,2,new QTableWidgetItem(age));
        ui->tableWidget_7->setItem(carNum,3,new QTableWidgetItem(cre));
        ui->tableWidget_7->setItem(carNum,4,new QTableWidgetItem(acn));
        ui->tableWidget_7->setItem(carNum,5,new QTableWidgetItem(ide));
        carNum++;
    }
}

void WorkerLogin::DelUser()
{
    QString uname0;
    QString uname1 = "";
    QString uname2 = ui->lineEdit_7->text();
    if(ui->tableWidget_7->currentRow() != -1)
    {
        uname1 = ui->tableWidget_7->item(ui->tableWidget_7->currentRow(),0)->text();
    }
    if(uname2.isEmpty())
    {
        if(uname1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何客户!", QMessageBox::Ok);
            return;
        }
        else
        {
            uname0 = uname1;
        }
    }
    else
    {
        uname0 = uname2;
    }
    const QString temp1 = "select Uname from User where Uname='" + uname0 + "'";
    query.exec(temp1);
    if(!query.next())
    {
        QMessageBox::information(this, "Tips", "不存在该用户!", QMessageBox::Ok);
        return;
    }
    if(QMessageBox::question(this,"question","确定删除此客户吗?",QMessageBox::Yes|QMessageBox::No))
    {
        const QString temp2 = "delete from User where Uname='" + uname0 + "'";
        if(query.exec(temp2))
        {
            QMessageBox::information(this, "Tips", "删除成功!", QMessageBox::Ok);
            UserInfo_Show();
        }
        else
        {
            QMessageBox::information(this, "Tips", "删除失败!", QMessageBox::Ok);
        }
    }
}

void WorkerLogin::RentInfo_Show(int op)
{
    int carNum = 0;
    ui->tableWidget_8->clearContents();
    query.exec("select * from RentInfo");
    while(query.next())
    {
        if(op == 1)
        {
            if(query.value(3).toString() != ui->lineEdit_8->text())
            {
                continue;
            }
        }
        else if(op == 2)
        {
            if(query.value(1).toString() != "W000000000")
            {
                continue;
            }
        }
        else if(op == 3)
        {
            if(query.value(2).toString() != ui->lineEdit_8->text())
            {
                continue;
            }
        }
        else if(op == 4)
        {
            int s = QDateTime::fromString(query.value(4).toString()).toTime_t();
            int s1 = QDateTime::fromString(ui->TimeEdit1_2->text()).toTime_t();
            int s2 = QDateTime::fromString(ui->TimeEdit2_2->text()).toTime_t();
            if(s < s1 || s > s2)
            {
                continue;
            }
        }
        ui->tableWidget_8->setRowCount(carNum+1);
        QString tnum = query.value(0).toString();
        QString wnum = query.value(1).toString();
        QString uname = query.value(2).toString();
        QString cnum = query.value(3).toString();
        QString stime = query.value(4).toString();
        QString ftime = query.value(5).toString();
        QString cash = query.value(6).toString();
        QString fine = query.value(7).toString();
        QString csta = query.value(8).toString();
        if(csta == "A")
        {
            csta = "优";
        }
        else if(csta == "B")
        {
            csta = "良";
        }
        else if(csta == "C")
        {
            csta = "一般";
        }
        else
        {
            csta = "差";
        }
        ui->tableWidget_8->setItem(carNum,0,new QTableWidgetItem(tnum));
        ui->tableWidget_8->setItem(carNum,1,new QTableWidgetItem(wnum));
        ui->tableWidget_8->setItem(carNum,2,new QTableWidgetItem(uname));
        ui->tableWidget_8->setItem(carNum,3,new QTableWidgetItem(cnum));
        ui->tableWidget_8->setItem(carNum,4,new QTableWidgetItem(stime));
        ui->tableWidget_8->setItem(carNum,5,new QTableWidgetItem(ftime));
        ui->tableWidget_8->setItem(carNum,6,new QTableWidgetItem(cash));
        ui->tableWidget_8->setItem(carNum,7,new QTableWidgetItem(fine));
        ui->tableWidget_8->setItem(carNum,8,new QTableWidgetItem(csta));
        carNum++;
    }
}

void WorkerLogin::QueryRent()
{
    QString con = ui->lineEdit_8->text();
    if(ui->radioButton_6->isChecked())
    {//按照车辆编号查询输出
        if(con.isEmpty())
        {
            QMessageBox::information(this, "Tips", "请填充需要查询的车辆编号条件!", QMessageBox::Ok);
            return;
        }
        else
        {
            RentInfo_Show(1);
        }
    }
    else if(ui->radioButton_5->isChecked())
    {//按照请求查询输出
        RentInfo_Show(2);
    }
    else if(ui->radioButton_7->isChecked())
    {//按照客户名查询输出
        if(con.isEmpty())
        {
            QMessageBox::information(this, "Tips", "请填充需要查询的客户名条件!", QMessageBox::Ok);
            return;
        }
        else
        {
            RentInfo_Show(3);
        }
    }
    else if(ui->radioButton_8->isChecked())
    {//按照时间查询输出
        RentInfo_Show(4);
    }
    else
    {
        QMessageBox::information(this, "Tips", "请先选择查询方式!", QMessageBox::Ok);
        return;
    }
}

void WorkerLogin::DealRequest()
{
    QString tnum0;
    QString tnum1 = "";
    QString tnum2 = ui->lineEdit_order->text();
    if(ui->tableWidget_8->currentRow() != -1)
    {
        tnum1 = ui->tableWidget_8->item(ui->tableWidget_8->currentRow(),0)->text();
    }
    if(tnum2.isEmpty())
    {
        if(tnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何车辆!", QMessageBox::Ok);
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
    const QString temp = "select Uname,Ftm,allfee from RentInfo where Tnum='" + tnum0 + "'";
    query.exec(temp);
    if(query.next())
    {
        if(query.value(1).toString().isEmpty())
        {
            QMessageBox::information(this, "Tips", "该订单不是请求订单!", QMessageBox::Ok);
            return;
        }
    }
    QString csta = ui->comboBox->currentText();
    QString fine = ui->spinBox->text();
    QString uname = query.value(0).toString();
    float allfee = query.value(2).toFloat();
    if(fine != "0")
    {
        allfee += fine.toFloat();
    }
    if(csta == "B")
    {
        allfee *= 1.2;
    }
    else if(csta == "C")
    {
        allfee *= 1.5;
    }
    else if(csta == "D")
    {
        allfee *= 2.0;
    }
    //提交订单结束申请
    const QString temp2 = "update RentInfo set Wnum='" +  Logid + "',Fine=" + fine + ",Csta='" + csta + "',AllFee=" +\
                            QString::number(allfee,'f',2) + " where Tnum='" + tnum0 + "'";
    qDebug()<<temp2;
    if(query.exec(temp2))
    {
        //结束请求，扣除用户余额
        const QString temp3 = "select Acn from User where Uname='" + uname +"'";
        query.exec(temp3);
        if(query.next())
        {
            float fee2 = query.value(0).toFloat() - allfee;
            const QString temp4 = "update User set Acn=" + QString::number(fee2,'f',2) + " where Uname='" + uname + "'";
            if(query.exec(temp4))
            {
                QMessageBox::information(this, "Tips", "处理成功!", QMessageBox::Ok);
            }
        }
    }
    else
    {
        QMessageBox::information(this, "Tips", "处理失败!", QMessageBox::Ok);
    }
    RentInfo_Show();
}
