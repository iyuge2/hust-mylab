#include "login.h"
#include "ui_login.h"
#include "visit.h"
#include "userlogin.h"
#include "syslogin.h"
#include "workerlogin.h"
#include "register.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QRadioButton>
#include <QMessageBox>
#include <QDebug>

extern QSqlQuery query;
extern QString Logid;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->LoginButton,SIGNAL(clicked()),this,SLOT(logIn()));
    connect(ui->RegisterButton,SIGNAL(clicked()),this,SLOT(regIn()));
}

Login::~Login()
{
    delete ui;
}

void Login::logIn()
{
    QString user = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    int flag = 1;
    ui->label_ide->setText("");
    if(ui->radioButton->isChecked())//用户登录判断
    {
        const QString temp = "select Ucode from User where Uname='" + user + "'";
        if(query.exec(temp) && query.next())
        {
            if(query.value(0).toString() == pass)
            {
                flag = 0;
                Logid = user;
                UserLogin* userWin = new UserLogin(this);
                this->hide();
                userWin->exec();
                delete userWin;
            }
        }
    }
    else if(ui->radioButton_2->isChecked() || ui->radioButton_3->isChecked())
    {
        const QString temp = "select Wcode,Ide from Worker where Wnum='" + user + "'";
        qDebug()<<temp;
        if(query.exec(temp) && query.next())
        {
            if(query.value(0).toString() == pass)
            {
                flag = 0;
                Logid = user;
                if(query.value(1).toString() == "0")//员工登录
                {
                    WorkerLogin* workWin = new WorkerLogin(this);
                    this->hide();
                    workWin->exec();
                    delete workWin;
                }
                else//系统人员登录
                {
                    SysLogin* SysWin = new SysLogin(this);
                    this->hide();
                    SysWin->exec();
                    delete SysWin;
                }
            }
        }
    }
    else if(ui->radioButton_4->isChecked())
    {
        Visit* VisitWin = new Visit(this);
        this->hide();
        VisitWin->exec();
        delete VisitWin;
        flag = 0;
    }
    else//弹出提示窗口
    {
        ui->label_ide->setText("请选中您的身份特征!");
        flag = 0;
    }
    if(flag)\
    {
        QMessageBox::information(this, "Tips", "用户名或密码不存在!", QMessageBox::Ok);
    }
}

void Login::regIn()
{
    Register* RegWin = new Register(this);
    RegWin->exec();
    delete RegWin;
}
