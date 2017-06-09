#include "addcarinfo.h"
#include "ui_addcarinfo.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QButtonGroup>
#include <QString>

extern QSqlQuery query;
extern QString Logid;

AddCarInfo::AddCarInfo(QWidget *parent,int op,QString num) :
    QDialog(parent),AddOrRev(op),CarNum(""),
    ui(new Ui::AddCarInfo)
{
    ui->setupUi(this);
    ui->comboBox->addItem("兰博基尼");
    ui->comboBox->addItem("比亚迪");
    ui->comboBox->addItem("大众");
    ui->comboBox->addItem("丰田");
    ui->comboBox->addItem("悍马");
    ui->comboBox->addItem("奔驰");
    ui->comboBox_2->addItem("红色");
    ui->comboBox_2->addItem("白色");
    ui->comboBox_2->addItem("黑色");
    ui->comboBox_2->addItem("黄色");
    ui->comboBox_2->addItem("蓝色");
    ui->comboBox_2->addItem("绿色");
    //将单选框进行分组
    QButtonGroup* grp1 = new QButtonGroup(this);
    grp1->addButton(ui->radioButton);
    grp1->addButton(ui->radioButton_2);
    QButtonGroup* grp2 = new QButtonGroup(this);
    grp2->addButton(ui->radioButton_3);
    grp2->addButton(ui->radioButton_4);
    grp2->addButton(ui->radioButton_5);
    if(op == 0)
    {
        ui->radioButton_3->setChecked(1);
        ui->radioButton_3->setEnabled(0);
        ui->radioButton_4->setEnabled(0);
        ui->radioButton_5->setEnabled(0);
    }
    else
    {
        const QString temp = "select * from CarInfo where Cnum='" + num + "'";
        query.exec(temp);
        if(query.next())
        {
            CarNum = query.value(0).toString();
            QString brand = query.value(1).toString();
            QString color = query.value(2).toString();
            QString sta = query.value(3).toString();
            QString fee = query.value(4).toString();
            QString btime = query.value(5).toString();
            QString cash = query.value(6).toString();
            QString ree = query.value(7).toString();
            QString vip = query.value(8).toString();

            ui->lineEdit_cnum->setText(CarNum);
            ui->lineEdit_fee->setText(fee);
            ui->lineEdit_ree->setText(ree);
            ui->lineEdit_time->setText(btime);
            ui->lineEdit_cash->setText(cash);
            ui->comboBox->setCurrentText(brand);
            ui->comboBox_2->setCurrentText(color);
            if(sta == "A")//设置只有当车辆处于空闲状态时才能更改车辆编号
            {
                ui->radioButton_3->setChecked(1);
            }
            else if(sta == "B")
            {
                ui->lineEdit_cnum->setEnabled(0);
                ui->radioButton_5->setChecked(1);
            }
            else
            {
                ui->lineEdit_cnum->setEnabled(0);
                ui->radioButton_4->setChecked(1);
            }
            if(vip == "Y")
            {
                ui->radioButton->setChecked(1);
            }
            else
            {
                ui->radioButton_2->setChecked(1);
            }
        }
    }

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
}

AddCarInfo::~AddCarInfo()
{
    delete ui;
}

void AddCarInfo::Ok()
{
    QString cnum = ui->lineEdit_cnum->text();
    QString fee = ui->lineEdit_fee->text();
    QString time = ui->lineEdit_time->text();
    QString brand = ui->comboBox->currentText();
    QString color = ui->comboBox_2->currentText();
    QString cash = ui->lineEdit_cash->text();
    QString ree = ui->lineEdit_ree->text();
    QString vip = "";
    QString sta = "";
    if(ui->radioButton->isChecked())
    {
        vip = "Y";
    }
    else if(ui->radioButton_2->isChecked())
    {
        vip = "N";
    }
    if(ui->radioButton_3->isChecked())
    {
        sta = "A";
    }
    else if(ui->radioButton_4->isChecked())
    {
        sta = "C";
    }
    else if(ui->radioButton_5->isChecked())
    {
        sta = "B";
    }
    if(cnum.isEmpty() || fee.isEmpty() || time.isEmpty() || brand.isEmpty() || cash.isEmpty() ||\
            color.isEmpty() || ree.isEmpty() || vip.isEmpty() || sta.isEmpty())
    {
        QMessageBox::information(this, "Tips", "请将信息填写完整！", QMessageBox::Ok);
        return;
    }
    if(AddOrRev)
    {//执行update
        if(CarNum != cnum)
        {
            const QString temp = "select Cnum from CarInfo where Cnum='" + cnum + "'";
            query.exec(temp);
            if(query.next())//查找成功，车牌编号已存在
            {
                QMessageBox::information(this, "Tips", "该车牌编号已存在!", QMessageBox::Ok);
                return;
            }
        }
        const QString temp2 = "update CarInfo set Cnum='" + cnum + "',Brand='" + brand + "',Color='" + color + "',Sta='" + sta + \
                "',Fee=" + fee + ",Btime='" + time + "',Cash=" + cash + ",Ree=" + ree + ",Vip='" + vip + "' where Cnum='" + CarNum + "'";
        if(query.exec(temp2))
        {
            QMessageBox::information(this, "Tips", "OK!", QMessageBox::Ok);
            Cancel();
        }
        else
        {
            QMessageBox::information(this, "Tips", "Oh~no!", QMessageBox::Ok);
        }
    }
    else
    {//执行insert
        const QString temp = "select Cnum from CarInfo where Cnum='" + cnum + "'";
        query.exec(temp);
        if(query.next())//查找成功，车牌编号已存在
        {
            QMessageBox::information(this, "Tips", "该车牌编号已存在!", QMessageBox::Ok);
            return;
        }
        const QString temp2 = "insert into CarInfo values('" + cnum + "','" + brand + "','" + color + "','" + sta + "'," + fee + ",'" +\
                                time + "'," + cash + "," + ree + ",'" + vip + "')";
        if(query.exec(temp2))
        {
            QMessageBox::information(this, "Tips", "OK!", QMessageBox::Ok);
            Cancel();
        }
        else
        {
            QMessageBox::information(this, "Tips", "Oh~no!", QMessageBox::Ok);
        }
    }

}

void AddCarInfo::Cancel()
{
    this->close();
}
