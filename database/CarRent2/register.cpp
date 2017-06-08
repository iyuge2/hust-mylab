#include "register.h"
#include "login.h"
#include "ui_register.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlQuery>

extern QSqlQuery query;
extern QString Logid;

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
//    this->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
}

Register::~Register()
{
    delete ui;
}

void Register::Ok()
{
    QString name = ui->lineEdit->text();
    QString code= ui->lineEdit_3->text();
    QString sex = "";
    QString age = ui->spinBox->text();
    if(ui->radioButton->isChecked())
    {
        sex = "M";
    }
    else if(ui->radioButton_2->isChecked())
    {
        sex = "W";
    }
    if(name.isEmpty() || code.isEmpty() || age.isEmpty() || sex.isEmpty())
    {
        QMessageBox::information(this, "Tips", "请将信息填写完整！", QMessageBox::Ok);
        return;
    }
    const QString temp1 = "select Uname from User where Uname='" + name + "'";\
    query.exec(temp1);
    if(query.next())
    {
        QMessageBox::information(this, "Tips", "该用户名已被使用！", QMessageBox::Ok);
        return;
    }
    const QString temp2 = "insert into User values('" + name + "','" + code + "','" + sex + "'," +  age + ",'A',0,0)";
    if(query.exec(temp2))
    {
        QMessageBox::information(this, "Tips", "注册成功!", QMessageBox::Ok);
        Cancel();
    }
}

void Register::Cancel()
{
    this->close();
}
