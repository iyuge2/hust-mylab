#ifndef REVISEPASS_H
#define REVISEPASS_H

#include <QDialog>

namespace Ui {
class RevisePass;
}

class RevisePass : public QDialog
{
    Q_OBJECT

public:
    explicit RevisePass(QWidget *parent = 0);
    ~RevisePass();
private slots:
    void Ok();
    void Cancel();
private:
    Ui::RevisePass *ui;
};

#endif // REVISEPASS_H
