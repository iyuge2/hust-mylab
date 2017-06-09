#ifndef REVISEBASICINFO_H
#define REVISEBASICINFO_H

#include <QDialog>

namespace Ui {
class ReviseBasicInfo;
}

class ReviseBasicInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ReviseBasicInfo(QWidget *parent = 0,int op = 0);
    ~ReviseBasicInfo();
private slots:
    void Ok();
    void Cancel();
private:
    int Sop;//0--用户 1--员工
    Ui::ReviseBasicInfo *ui;
};

#endif // REVISEBASICINFO_H
