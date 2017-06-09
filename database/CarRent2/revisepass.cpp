#include "revisepass.h"
#include "ui_revisepass.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QDebug>

extern QSqlQuery query;
extern QString Logid;

RevisePass::RevisePass(QWidget *parent,int op) :
    QDialog(parent),Sop(op),
    ui(new Ui::RevisePass)
{
    ui->setupUi(this);

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
}

RevisePass::~RevisePass()
{
    delete ui;
}

void RevisePass::Ok()
{
    QString oldPass = ui->lineEdit_old->text();
    QString newPass = ui->lineEdit_new->text();
    QString newPass2 = ui->lineEdit_new2->text();
    if(oldPass.isEmpty() || newPass.isEmpty() || newPass2.isEmpty())
    {
        QMessageBox::information(this, "Tips", "请将信息填写完整！", QMessageBox::Ok);
        return;
    }
    if(newPass != newPass2)
    {
        QMessageBox::information(this, "Tips", "新密码输入不一致！", QMessageBox::Ok);
        return;
    }
    int flag = 0;
    const QString temp1 = "select Ucode from User where Uname='" + Logid + "'";
    const QString temp2 = "select Wcode from Worker where Wnum='" + Logid + "'";
    if(Sop)
    {
        if(query.exec(temp2))
        {
            flag = 1;
        }
    }
    else
    {
        if(query.exec(temp1))
        {
            flag = 1;
        }
    }
    if(flag)
    {
        query.next();
        if(query.value(0).toString() == oldPass)
        {
            int flag2 = 0;
            const QString temp1 = "update User set Ucode = '" + newPass + "' where Uname = '" + Logid + "'";
            const QString temp2 = "update Worker set Wcode = '" + newPass + "' where Wnum = '" + Logid + "'";
            if(Sop)
            {
                if(query.exec(temp2))
                {
                    flag2 = 1;
                }
            }
            else
            {
                if(query.exec(temp1))
                {
                    flag2 = 1;
                }
            }
            if(flag2)
            {
                QMessageBox::information(this, "Tips", "修改成功!", QMessageBox::Ok);
                Cancel();
            }
            else
            {
                QMessageBox::information(this, "Tips", "系统正忙，修改失败...!", QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::information(this, "Tips", "原密码错误!", QMessageBox::Ok);
        }
    }
}

void RevisePass::Cancel()
{
    this->close();
}
