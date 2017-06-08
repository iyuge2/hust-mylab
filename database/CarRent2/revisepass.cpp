#include "revisepass.h"
#include "ui_revisepass.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QDebug>

extern QSqlQuery query;
extern QString Logid;

RevisePass::RevisePass(QWidget *parent) :
    QDialog(parent),
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
    const QString temp = "select Ucode from User where Uname='" + Logid + "'";
    if(query.exec(temp))
    {
        query.next();
        if(query.value(0).toString() == oldPass)
        {
            const QString temp = "update User set Ucode = '" + newPass + "' where Uname = '" + Logid + "'";
            if(query.exec(temp))
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
    else
    {
        qDebug("查询失败！");
    }
}

void RevisePass::Cancel()
{
    this->close();
//    parentWidget()->show();
}
