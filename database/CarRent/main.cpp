#include "mainwindow.h"
#include <QApplication>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QPluginLoader>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

     QStringList drivers = QSqlDatabase::drivers();
     qDebug() << drivers;
     QSqlDatabase    dbconn;
     QSqlQuery       query;
     dbconn = QSqlDatabase::addDatabase("QMYSQL");
     dbconn.setHostName("localhost");//主机名字
     dbconn.setDatabaseName("MyGoods");//数据库名字
     dbconn.open("root", "960606saandsb!");//用户名、密码，成功返回1
     query = (QSqlQuery)dbconn;
     query.exec("select * from SALE");
     while(query.next())
     {
         int id = query.value(0).toInt();
         QString name = query.value(1).toString();
         qDebug() << QString::number(id) + " : "+ name;
     }
    return a.exec();
}
