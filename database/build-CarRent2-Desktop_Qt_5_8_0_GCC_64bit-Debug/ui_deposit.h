/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Deposit
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_addmoney;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *Deposit)
    {
        if (Deposit->objectName().isEmpty())
            Deposit->setObjectName(QStringLiteral("Deposit"));
        Deposit->resize(266, 123);
        verticalLayout_2 = new QVBoxLayout(Deposit);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Deposit);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_addmoney = new QLineEdit(Deposit);
        lineEdit_addmoney->setObjectName(QStringLiteral("lineEdit_addmoney"));
        lineEdit_addmoney->setMaxLength(20);

        horizontalLayout->addWidget(lineEdit_addmoney);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        OkButton = new QPushButton(Deposit);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout_2->addWidget(OkButton);

        CancelButton = new QPushButton(Deposit);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Deposit);

        QMetaObject::connectSlotsByName(Deposit);
    } // setupUi

    void retranslateUi(QDialog *Deposit)
    {
        Deposit->setWindowTitle(QApplication::translate("Deposit", "\345\205\205\345\200\274", Q_NULLPTR));
        label->setText(QApplication::translate("Deposit", "\345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        OkButton->setText(QApplication::translate("Deposit", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("Deposit", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Deposit: public Ui_Deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
