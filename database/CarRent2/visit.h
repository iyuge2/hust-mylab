#ifndef VISIT_H
#define VISIT_H

#include <QDialog>

namespace Ui {
class Visit;
}

class Visit : public QDialog
{
    Q_OBJECT

public:
    explicit Visit(QWidget *parent = 0);
    ~Visit();
private slots:
        void CarInfo_Show();
        void back();
private:
    Ui::Visit *ui;
};

#endif // VISIT_H
