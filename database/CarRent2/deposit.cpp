#include "deposit.h"
#include "ui_deposit.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QString>

extern QSqlQuery query;
extern QString Logid;

Deposit::Deposit(QWidget *parent,float old) :
    QDialog(parent),oldMoney(old),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(Ok()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));

}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::Ok()
{
    QString Money = ui->lineEdit_addmoney->text();
    if(Money.isEmpty())
    {
        QMessageBox::information(this, "Tips", "充值金额不能为空!", QMessageBox::Ok);
        return;
    }
    float tm = Money.toFloat() + oldMoney;
    Money = QString::number(tm);
    const QString temp = "update User set Acn = " + Money + " where Uname = '" + Logid + "'";
    if(!query.exec(temp))
    {
        QMessageBox::information(this, "Tips", "系统正忙，修改失败...!", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Tips", "充值成功!", QMessageBox::Ok);
        Cancel();
    }
}

void Deposit::Cancel()
{
    this->close();
}
