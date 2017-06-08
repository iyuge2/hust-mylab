#ifndef ADDCARINFO_H
#define ADDCARINFO_H

#include <QDialog>

namespace Ui {
class AddCarInfo;
}

class AddCarInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddCarInfo(QWidget *parent = 0,int op = 0,QString num = "");//op为0，将窗口设置成add模式，否则，num存放车牌号，为revise模式
    ~AddCarInfo();
private slots:
    void Ok();
    void Cancel();
private:
    Ui::AddCarInfo *ui;
};

#endif // ADDCARINFO_H
