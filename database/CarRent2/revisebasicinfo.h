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
    explicit ReviseBasicInfo(QWidget *parent = 0);
    ~ReviseBasicInfo();
private slots:
    void Ok();
    void Cancel();
private:
    Ui::ReviseBasicInfo *ui;
};

#endif // REVISEBASICINFO_H
