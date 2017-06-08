#ifndef WORKERLOGIN_H
#define WORKERLOGIN_H

#include <QDialog>

namespace Ui {
class WorkerLogin;
}

class WorkerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerLogin(QWidget *parent = 0);
    ~WorkerLogin();

private:
    Ui::WorkerLogin *ui;
};

#endif // WORKERLOGIN_H
