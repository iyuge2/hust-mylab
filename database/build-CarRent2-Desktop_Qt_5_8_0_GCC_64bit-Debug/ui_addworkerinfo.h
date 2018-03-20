/********************************************************************************
** Form generated from reading UI file 'addworkerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORKERINFO_H
#define UI_ADDWORKERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddWorkerInfo
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit_wname;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_wnum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *AddWorkerInfo)
    {
        if (AddWorkerInfo->objectName().isEmpty())
            AddWorkerInfo->setObjectName(QStringLiteral("AddWorkerInfo"));
        AddWorkerInfo->resize(300, 338);
        verticalLayout = new QVBoxLayout(AddWorkerInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(AddWorkerInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        lineEdit_wname = new QLineEdit(AddWorkerInfo);
        lineEdit_wname->setObjectName(QStringLiteral("lineEdit_wname"));

        horizontalLayout_5->addWidget(lineEdit_wname);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(AddWorkerInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_wnum = new QLineEdit(AddWorkerInfo);
        lineEdit_wnum->setObjectName(QStringLiteral("lineEdit_wnum"));

        horizontalLayout_4->addWidget(lineEdit_wnum);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(AddWorkerInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinBox = new QSpinBox(AddWorkerInfo);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(AddWorkerInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        radioButton = new QRadioButton(AddWorkerInfo);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(AddWorkerInfo);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(AddWorkerInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        dateTimeEdit = new QDateTimeEdit(AddWorkerInfo);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(AddWorkerInfo);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        spinBox_2 = new QSpinBox(AddWorkerInfo);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(100000);

        horizontalLayout_7->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        OkButton = new QPushButton(AddWorkerInfo);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout_6->addWidget(OkButton);

        CancelButton = new QPushButton(AddWorkerInfo);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_6->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(AddWorkerInfo);

        QMetaObject::connectSlotsByName(AddWorkerInfo);
    } // setupUi

    void retranslateUi(QDialog *AddWorkerInfo)
    {
        AddWorkerInfo->setWindowTitle(QApplication::translate("AddWorkerInfo", "\345\242\236\345\212\240\345\221\230\345\267\245", Q_NULLPTR));
        label->setText(QApplication::translate("AddWorkerInfo", "       \345\247\223\345\220\215\357\274\232 ", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddWorkerInfo", "\345\267\245\344\275\234\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddWorkerInfo", "        \345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddWorkerInfo", "        \346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("AddWorkerInfo", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("AddWorkerInfo", "\345\245\263", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddWorkerInfo", "\345\205\245\350\201\214\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("AddWorkerInfo", "yyyy/M/d hh:mm:ss", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddWorkerInfo", "\346\234\210\345\237\272\346\234\254\345\267\245\350\265\204(\357\277\245/\346\234\210):", Q_NULLPTR));
        OkButton->setText(QApplication::translate("AddWorkerInfo", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("AddWorkerInfo", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddWorkerInfo: public Ui_AddWorkerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORKERINFO_H
