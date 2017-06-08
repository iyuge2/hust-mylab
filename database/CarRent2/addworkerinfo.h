#ifndef ADDWORKERINFO_H
#define ADDWORKERINFO_H

#include <QDialog>

namespace Ui {
class AddWorkerInfo;
}

class AddWorkerInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddWorkerInfo(QWidget *parent = 0);
    ~AddWorkerInfo();
private slots:
    void Ok();
    void Cancel();
private:
    Ui::AddWorkerInfo *ui;
};

#endif // ADDWORKERINFO_H
