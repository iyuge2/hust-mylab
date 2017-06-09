#include "addworkerinfo.h"
#include "ui_addworkerinfo.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QButtonGroup>
#include <QString>
#include <QDebug>

extern QSqlQuery query;
extern QString Logid;

AddWorkerInfo::AddWorkerInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWorkerInfo)
{
    ui->setupUi(this);

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
}

AddWorkerInfo::~AddWorkerInfo()
{
    delete ui;
}

void AddWorkerInfo::Ok()
{
    QString name = ui->lineEdit_wname->text();
    QString num = ui->lineEdit_wnum->text();
    QString age = ui->spinBox->text();
    QString sex = "";
    QString time = ui->dateTimeEdit->text();
    QString wage = ui->spinBox_2->text();
    if(ui->radioButton->isChecked())
    {
        sex = "M";
    }
    else if(ui->radioButton_2->isChecked())
    {
        sex = "W";
    }

    if(name.isEmpty() || num.isEmpty() || age.isEmpty() || sex.isEmpty() || time.isEmpty())
    {
        QMessageBox::information(this, "Tips", "请将信息填写完整！", QMessageBox::Ok);
        return;
    }
    const QString temp = "select Wnum from Worker where Wnum='" + num + "'";
    query.exec(temp);
    if(query.next())//查找成功，员工编号已存在
    {
        QMessageBox::information(this, "Tips", "该员工编号已存在!", QMessageBox::Ok);
        return;
    }
    const QString temp2 = "insert into Worker values('" + name + "','" + num + "','123456','" + sex + "'," + age + ",0,'" +\
                        time + "','0'," + wage + ")";
    qDebug()<<temp2;
    if(query.exec(temp2))
    {
        QMessageBox::information(this, "Tips", "OK!该员工登录初始密码为123456", QMessageBox::Ok);
        Cancel();
    }
    else
    {
        QMessageBox::information(this, "Tips", "Opp~增加员工失败!", QMessageBox::Ok);
    }
}

void AddWorkerInfo::Cancel()
{
    this->close();
}
