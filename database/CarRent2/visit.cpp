#include "visit.h"
#include "ui_visit.h"
#include "login.h"
#include <QStringList>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtSql/QSqlQuery>
#include <QTableWidgetItem>

extern QSqlQuery query;
extern int Winflag;

Visit::Visit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visit)
{
    ui->setupUi(this);
    QStringList header;
    header<<tr("车辆编号")<<tr("品牌")<<tr("颜色")<<tr("车辆状态")<<tr("购入费用")<<tr("所需押金")<<tr("租金(/h)")<<tr("其他");
    ui->tableWidget->setHorizontalHeaderLabels(header);

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    QHBoxLayout *Hlayout = new QHBoxLayout;
//    Hlayout->addWidget(ui->pushButton);
//    Hlayout->addWidget(ui->pushButton_2);
//    mainLayout->addWidget(ui->tableWidget);
//    mainLayout->addLayout(Hlayout);
//    setLayout(mainLayout);

    CarInfo_Show();
    connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(CarInfo_Show()));
    connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(back()));
}

Visit::~Visit()
{
    delete ui;
}

void Visit::CarInfo_Show()
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

void Visit::back()
{
    this->close();
    parentWidget()->show();
}
