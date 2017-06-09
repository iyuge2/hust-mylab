#include "syslogin.h"
#include "ui_syslogin.h"
#include "addworkerinfo.h"
#include "addcarinfo.h"
#include "revisebasicinfo.h"
#include "revisepass.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QDateTimeEdit>

extern QSqlQuery query;
extern QString Logid;

SysLogin::SysLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SysLogin)
{
    ui->setupUi(this);

    //第一个Tab界面
    QStringList header;
    header<<tr("车辆编号")<<tr("品牌")<<tr("颜色")<<tr("车辆状态")<<tr("购入费用")<<tr("所需押金")<<tr("租金(/h)")<<tr("其他");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //第二个Tab界面
    header<<tr("姓名")<<tr("编号")<<tr("性别")<<tr("年龄")<<tr("业务量")<<tr("入职时间")<<tr("基本工资");
    ui->tableWidget_2->setHorizontalHeaderLabels(header);

    //第三个界面
    header<<tr("用户名")<<tr("性别")<<tr("年龄")<<tr("信用评级")<<tr("账户余额")<<tr("其他");
    ui->tableWidget_3->setHorizontalHeaderLabels(header);

    //第四个界面
    header<<tr("交易编号")<<tr("员工编号")<<tr("用户名")<<tr("车辆编号")<<tr("开始时间")<<tr("结束时间")<<tr("费用")<<tr("违罚款")<<tr("总费用");
    ui->tableWidget_4->setHorizontalHeaderLabels(header);

    CarInfo_Show();
    WorkerInfo_Show();
    UserInfo_Show();
    BasicShow();

    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(Exit()));
    connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(select()));

    connect(ui->ACButton,SIGNAL(clicked()),this,SLOT(AddCar()));
    connect(ui->DCButton,SIGNAL(clicked()),this,SLOT(DelCar()));
    connect(ui->RCButton,SIGNAL(clicked()),this,SLOT(RevCar()));

    connect(ui->AWButton,SIGNAL(clicked()),this,SLOT(AddWorker()));
    connect(ui->DWButton,SIGNAL(clicked()),this,SLOT(DelWorker()));
    connect(ui->AddWageButton,SIGNAL(clicked()),this,SLOT(AddWage()));
    connect(ui->PrizeButton,SIGNAL(clicked()),this,SLOT(GivePrize()));

    connect(ui->DUButton,SIGNAL(clicked()),this,SLOT(DelUser()));

    connect(ui->RentOkButton,SIGNAL(clicked()),this,SLOT(QueryRent()));

    connect(ui->QueryMoneyButton,SIGNAL(clicked()),this,SLOT(QueryMoney()));

    connect(ui->pushButton_info,SIGNAL(clicked()),this,SLOT(ChangeBasic()));
    connect(ui->pushButton_pass,SIGNAL(clicked()),this,SLOT(ChangePass()));
}

SysLogin::~SysLogin()
{
    delete ui;
}

void SysLogin::Exit()
{
    this->close();
    parentWidget()->show();
}

void SysLogin::select()
{
    if(ui->tabWidget->currentIndex() == 0)
    {
        CarInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {
        WorkerInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {
        UserInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 3)
    {
        RentInfo_Show();
    }
    else if(ui->tabWidget->currentIndex() == 4)
    {
        QueryMoney();
    }
    else if(ui->tabWidget->currentIndex() == 5)
    {
        BasicShow();
    }
}

void SysLogin::CarInfo_Show()
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

void SysLogin::WorkerInfo_Show()
{
    int carNum = 0;
    ui->tableWidget_2->clearContents();
    query.exec("select * from Worker");
    while(query.next() && (query.value(7).toString() == "0"))//不显示系统管理员的信息
    {
        ui->tableWidget_2->setRowCount(carNum+1);
        QString wname = query.value(0).toString();
        QString wnum = query.value(1).toString();
        QString sex = (query.value(3).toString() == 'M') ? "男" : "女";
        QString age = query.value(4).toString();
        QString tnum = query.value(5).toString();
        QString ctime = query.value(6).toString();
        QString wage = query.value(8).toString();
        ui->tableWidget_2->setItem(carNum,0,new QTableWidgetItem(wname));
        ui->tableWidget_2->setItem(carNum,1,new QTableWidgetItem(wnum));
        ui->tableWidget_2->setItem(carNum,2,new QTableWidgetItem(sex));
        ui->tableWidget_2->setItem(carNum,3,new QTableWidgetItem(age));
        ui->tableWidget_2->setItem(carNum,4,new QTableWidgetItem(tnum));
        ui->tableWidget_2->setItem(carNum,5,new QTableWidgetItem(ctime));
        ui->tableWidget_2->setItem(carNum,6,new QTableWidgetItem(wage));
        carNum++;
    }
}

void SysLogin::AddCar()
{
    AddCarInfo* AcWin = new AddCarInfo(this);
    AcWin->exec();
    delete AcWin;
    CarInfo_Show();
}

void SysLogin::DelCar()
{
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

void SysLogin::RevCar()
{//只有处于空闲状态的车可以修改编号信息
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

void SysLogin::AddWorker()
{
    AddWorkerInfo* AwWin = new AddWorkerInfo(this);
    AwWin->exec();
    delete AwWin;
    WorkerInfo_Show();
}

void SysLogin::DelWorker()
{
    QString wnum0;
    QString wnum1 = "";
    QString wnum2 = ui->lineEdit_2->text();
    if(ui->tableWidget_2->currentRow() != -1)
    {
        wnum1 = ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),1)->text();
    }
    if(wnum2.isEmpty())
    {
        if(wnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何员工!", QMessageBox::Ok);
            return;
        }
        else
        {
            wnum0 = wnum1;
        }
    }
    else
    {
        wnum0 = wnum2;
    }
    const QString temp1 = "select Wnum from Worker where Wnum='" + wnum0 + "'";
    query.exec(temp1);
    if(!query.next())
    {
        QMessageBox::information(this, "Tips", "不存在该员工!", QMessageBox::Ok);
        return;
    }
    if(QMessageBox::question(this,"question","确定删除此员工吗?",QMessageBox::Yes|QMessageBox::No))
    {
        const QString temp2 = "delete from Worker where Wnum='" + wnum0 + "'";
        if(query.exec(temp2))
        {
            QMessageBox::information(this, "Tips", "删除成功!", QMessageBox::Ok);
            WorkerInfo_Show();
        }
        else
        {
            QMessageBox::information(this, "Tips", "删除失败!", QMessageBox::Ok);
        }
    }
}

void SysLogin::AddWage()
{
    QString wage = ui->spinBox->text();
    QString wnum0;
    QString wnum1 = "";
    QString wnum2 = ui->lineEdit_2->text();
    if(ui->tableWidget_2->currentRow() != -1)
    {
        wnum1 = ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),1)->text();
    }
    if(wnum2.isEmpty())
    {
        if(wnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何员工!", QMessageBox::Ok);
            return;
        }
        else
        {
            wnum0 = wnum1;
        }
    }
    else
    {
        wnum0 = wnum2;
    }
    const QString temp = "update Worker set Bsal=" + wage + " where Wnum='" + wnum0 + "'";
    if(query.exec(temp))
    {
        QMessageBox::information(this, "Tips", "改工资成功!", QMessageBox::Ok);
        return;
    }
    else
    {
        QMessageBox::information(this, "Tips", "改工资失败!", QMessageBox::Ok);
    }
}

void SysLogin::GivePrize()
{
    QString prize = ui->spinBox->text();
    QString wnum0;
    QString wnum1 = "";
    QString wnum2 = ui->lineEdit_2->text();
    if(ui->tableWidget_2->currentRow() != -1)
    {
        wnum1 = ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),1)->text();
    }
    if(wnum2.isEmpty())
    {
        if(wnum1.isEmpty())
        {
            QMessageBox::information(this, "Tips", "当前未选中任何员工!", QMessageBox::Ok);
            return;
        }
        else
        {
            wnum0 = wnum1;
        }
    }
    else
    {
        wnum0 = wnum2;
    }
    const QString temp1 = "update WorkerSal set Prise=" + prize + " where Wnum='" + wnum0 + "'";
    if(query.exec(temp1))
    {
        QMessageBox::information(this, "Tips", "发奖金成功!", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Tips", "发奖金失败!", QMessageBox::Ok);
    }
}

void SysLogin::UserInfo_Show()
{
    int carNum = 0;
    ui->tableWidget_3->clearContents();
    query.exec("select * from User");
    while(query.next())
    {
        ui->tableWidget_3->setRowCount(carNum+1);
        QString uname = query.value(0).toString();
        QString sex = (query.value(2).toString() == 'M') ? "男" : "女";
        QString age = query.value(3).toString();
        QString cre = query.value(4).toString();
        QString acn = query.value(5).toString();
        QString ide = (query.value(6).toFloat() < 1000) ? "普通会员" : "黄金会员";
        ui->tableWidget_3->setItem(carNum,0,new QTableWidgetItem(uname));
        ui->tableWidget_3->setItem(carNum,1,new QTableWidgetItem(sex));
        ui->tableWidget_3->setItem(carNum,2,new QTableWidgetItem(age));
        ui->tableWidget_3->setItem(carNum,3,new QTableWidgetItem(cre));
        ui->tableWidget_3->setItem(carNum,4,new QTableWidgetItem(acn));
        ui->tableWidget_3->setItem(carNum,5,new QTableWidgetItem(ide));
        carNum++;
    }
}

void SysLogin::DelUser()
{
    QString uname0;
    QString uname1 = "";
    QString uname2 = ui->lineEdit_3->text();
    if(ui->tableWidget_3->currentRow() != -1)
    {
        uname1 = ui->tableWidget_3->item(ui->tableWidget_3->currentRow(),0)->text();
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

void SysLogin::RentInfo_Show(int op)
{
    int carNum = 0;
    ui->tableWidget_4->clearContents();
    query.exec("select * from RentInfo");
    while(query.next())
    {
        if(op == 1)
        {
            if(query.value(3).toString() != ui->lineEdit_4->text())
            {
                continue;
            }
        }
        else if(op == 2)
        {
            if(query.value(1).toString() != ui->lineEdit_4->text())
            {
                continue;
            }
        }
        else if(op == 3)
        {
            if(query.value(2).toString() != ui->lineEdit_4->text())
            {
                continue;
            }
        }
        else if(op == 4)
        {
            int s = QDateTime::fromString(query.value(4).toString()).toTime_t();
            int s1 = QDateTime::fromString(ui->TimeEdit1->text()).toTime_t();
            int s2 = QDateTime::fromString(ui->TimeEdit2->text()).toTime_t();
            if(s < s1 || s > s2)
            {
                continue;
            }
        }
        ui->tableWidget_4->setRowCount(carNum+1);
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
        ui->tableWidget_4->setItem(carNum,0,new QTableWidgetItem(tnum));
        ui->tableWidget_4->setItem(carNum,1,new QTableWidgetItem(wnum));
        ui->tableWidget_4->setItem(carNum,2,new QTableWidgetItem(uname));
        ui->tableWidget_4->setItem(carNum,3,new QTableWidgetItem(cnum));
        ui->tableWidget_4->setItem(carNum,4,new QTableWidgetItem(stime));
        ui->tableWidget_4->setItem(carNum,5,new QTableWidgetItem(ftime));
        ui->tableWidget_4->setItem(carNum,6,new QTableWidgetItem(cash));
        ui->tableWidget_4->setItem(carNum,7,new QTableWidgetItem(fine));
        ui->tableWidget_4->setItem(carNum,8,new QTableWidgetItem(csta));
        carNum++;
    }
}

void SysLogin::QueryRent()
{
    QString con = ui->lineEdit_4->text();
    if(ui->radioButton->isChecked())
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
    else if(ui->radioButton_2->isChecked())
    {//按照员工编号查询输出
        if(con.isEmpty())
        {
            QMessageBox::information(this, "Tips", "请填充需要查询的员工编号条件!", QMessageBox::Ok);
            return;
        }
        else
        {
            RentInfo_Show(2);
        }
    }
    else if(ui->radioButton_3->isChecked())
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
    else if(ui->radioButton_4->isChecked())
    {//按照时间查询输出
        RentInfo_Show(4);
    }
    else
    {
        QMessageBox::information(this, "Tips", "请先选择查询方式!", QMessageBox::Ok);
        return;
    }
}

void SysLogin::QueryMoney()
{
    QDateTime stime = ui->dateTimeEdit->dateTime();
    QDateTime ftime = ui->dateTimeEdit->dateTime();
    if(stime.isNull() || ftime.isNull())
    {
        QMessageBox::information(this, "Tips", "请选择查询时间!", QMessageBox::Ok);
        return;
    }
    //填充订单金额表
    float cashAll = 0;
    int carNum = 0;
    ui->tableWidget_C->clearContents();
    const QString temp = "select Tnum,Ftm,Cash from RentInfo";
    query.exec(temp);
    while(query.next())
    {
        ui->tableWidget_C->setRowCount(carNum+1);
        QString tnum = query.value(0).toString();
        QDateTime time = query.value(1).toDateTime();
        QString cash = query.value(2).toString();
        if(time >= stime && time <= ftime)
        {
            ui->tableWidget_C->setItem(carNum,0,new QTableWidgetItem(tnum));
            ui->tableWidget_C->setItem(carNum,1,new QTableWidgetItem(time.toString()));
            ui->tableWidget_C->setItem(carNum,2,new QTableWidgetItem(cash));
            cashAll += cash.toFloat();
        }
        carNum += 1;
    }
    ui->label_OrderCount->setText(QString::number(carNum));
    ui->label_OrderFee->setText(QString::number(cashAll,'f',2));
    ui->label_in->setText(QString::number(cashAll,'f',2));
    //填充员工工资表
    float wageAll = 0,prizeAll = 0;
    carNum = 0;
    ui->tableWidget_W->clearContents();
    int monthNum = (ftime.toTime_t() - stime.toTime_t()) / (3600 * 24 * 30);//计算出所查询的总月数，便于计算员工基本工资
    const QString temp2 = "select Wnum,BSal,Ide from Worker";
    query.exec(temp2);
    while(query.next() && (query.value(2).toString() != "1"))//排除Boss
    {
        QString wnum = query.value(0).toString();
        float bwage = query.value(1).toFloat();
        QSqlQuery query2 = query;
        float prize = 0;
        const QString temp3 = "select Prize,Gtime from WorkSal where Wnum='" + wnum + "'";
        query2.exec(temp3);
        while(query2.next())//查询员工奖金总额
        {
            QDateTime gtime = query2.value(1).toDateTime();
            if(gtime >= stime && gtime <= ftime)
            {
                prize += query2.value(0).toFloat();
            }
        }
        bwage *= monthNum;
        prizeAll += prize;
        wageAll += bwage;
        ui->tableWidget_W->setRowCount(carNum+1);
        ui->tableWidget_W->setItem(carNum,0,new QTableWidgetItem(wnum));
        ui->tableWidget_W->setItem(carNum,1,new QTableWidgetItem(QString::number(bwage,'f',2)));
        ui->tableWidget_W->setItem(carNum,2,new QTableWidgetItem(prize));
        prize += bwage;
        ui->tableWidget_W->setItem(carNum,3,new QTableWidgetItem(QString::number(prize,'f',2)));
        carNum += 1;
    }
    ui->label_WageAll->setText(QString::number(wageAll,'f',2));
    ui->label_PrizeAll->setText(QString::number(prizeAll,'f',2));
    float out = wageAll + prizeAll;
    float left = cashAll - out;
    ui->label_out->setText(QString::number(out,'f',2));
    ui->label_left->setText(QString::number(left,'f',2));
}

void SysLogin::BasicShow()
{
    const QString temp = "select Wnum,Wname,Sex,Age,Ctime,Ide from Worker where Wnum='" + Logid + "'";
    query.exec(temp);
    if(query.next())
    {
        ui->label_num->setText(query.value(0).toString());
        ui->label_name->setText(query.value(1).toString());
        ui->label_sex->setText((query.value(2).toString()=="M") ? "先生" : "女士");
        ui->label_age->setText(query.value(3).toString());
        ui->label_Ctime->setText(query.value(4).toString());
        ui->label_Ide->setText((query.value(5).toString() == "1") ? "Boss" : "普通员工");
    }
    else
    {
        QMessageBox::information(this, "Tips", "个人信息读取错误！", QMessageBox::Ok);
    }
}

void SysLogin::ChangeBasic()
{
    ReviseBasicInfo* w = new ReviseBasicInfo(this);
    w->exec();
    delete w;
    BasicShow();
}

void SysLogin::ChangePass()
{
    RevisePass* w = new RevisePass(this);
    w->exec();
    delete w;
}
