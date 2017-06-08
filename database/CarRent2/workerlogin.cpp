#include "workerlogin.h"
#include "ui_workerlogin.h"

WorkerLogin::WorkerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerLogin)
{
    ui->setupUi(this);
}

WorkerLogin::~WorkerLogin()
{
    delete ui;
}
