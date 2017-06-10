#include "login.h"
#include "main.h"
#include <QApplication>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QStringList drivers = QSqlDatabase::drivers();
    //QSqlQuery       query;
    Login w;
    QSqlDatabase    dbconn;
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName("localhost");//主机名字
    dbconn.setDatabaseName("CarRentSys");//数据库名字
    if(dbconn.open("root", "960606saandsb!"))//用户名、密码，成功返回1
    {
        qDebug("成功链接数据库...");
        query = (QSqlQuery)dbconn;
        w.show();
    }
    else
    {
        qDebug("数据库连接失败！");
    }
    return app.exec();
}
