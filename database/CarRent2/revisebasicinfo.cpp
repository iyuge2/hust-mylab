#include "revisebasicinfo.h"
#include "ui_revisebasicinfo.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>

extern QSqlQuery query;
extern QString Logid;
ReviseBasicInfo::ReviseBasicInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReviseBasicInfo)
{
    ui->setupUi(this);

    const QString temp = "select Uname,Sex,Age from User where Uname='" + Logid + "'";
    if(query.exec(temp))
    {
        query.next();
        //填充用户修改区
        ui->lineEdit_name->setText(query.value(0).toString());
        if(query.value(1).toString() == "M")
        {
            ui->radioButton_M->setChecked(1);
        }
        else
        {
            ui->radioButton_W->setChecked(1);
        }
        ui->spinBox->setValue(query.value(2).toInt());
    }

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));

}

ReviseBasicInfo::~ReviseBasicInfo()
{
    delete ui;
}

void ReviseBasicInfo::Ok()
{
    QString Tname = ui->lineEdit_name->text();
    if(Tname.isEmpty())
    {
        QMessageBox::information(this, "Tips", "用户名不能为空!", QMessageBox::Ok);
        return;
    }
    else if(Tname != Logid)
    {
        query.exec("select Uname from User");
        while(query.next())
        {
            if(Tname == query.value(0).toString())
            {
                QMessageBox::information(this, "Tips", "该用户名已存在!", QMessageBox::Ok);
                return;
            }
        }
    }
    QString sex;
    if(ui->radioButton_M->isChecked())
    {
        sex = "M";
    }
    else if(ui->radioButton_W->isChecked())
    {
        sex = "W";
    }
    QString age = ui->spinBox->text();
    const QString temp = "update User set Sex = '" + sex + "',age = " + age + ",Uname = '" + Tname + \
            "' where Uname = '" + Logid + "'";
    if(!query.exec(temp))
    {
        QMessageBox::information(this, "Tips", "系统正忙，修改失败...!", QMessageBox::Ok);
    }
    else
    {
        Logid = Tname;
        QMessageBox::information(this, "Tips", "修改成功!", QMessageBox::Ok);
        Cancel();
    }
}

void ReviseBasicInfo::Cancel()
{
    this->close();
}
