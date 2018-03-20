/********************************************************************************
** Form generated from reading UI file 'revisebasicinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVISEBASICINFO_H
#define UI_REVISEBASICINFO_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReviseBasicInfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QRadioButton *radioButton_M;
    QRadioButton *radioButton_W;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *ReviseBasicInfo)
    {
        if (ReviseBasicInfo->objectName().isEmpty())
            ReviseBasicInfo->setObjectName(QStringLiteral("ReviseBasicInfo"));
        ReviseBasicInfo->resize(300, 215);
        verticalLayout_2 = new QVBoxLayout(ReviseBasicInfo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ReviseBasicInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(ReviseBasicInfo);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setMaxLength(20);

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(ReviseBasicInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        radioButton_M = new QRadioButton(ReviseBasicInfo);
        radioButton_M->setObjectName(QStringLiteral("radioButton_M"));

        horizontalLayout_2->addWidget(radioButton_M);

        radioButton_W = new QRadioButton(ReviseBasicInfo);
        radioButton_W->setObjectName(QStringLiteral("radioButton_W"));

        horizontalLayout_2->addWidget(radioButton_W);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 160, -1);
        label_3 = new QLabel(ReviseBasicInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox = new QSpinBox(ReviseBasicInfo);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_3->addWidget(spinBox);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        OkButton = new QPushButton(ReviseBasicInfo);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout_4->addWidget(OkButton);

        CancelButton = new QPushButton(ReviseBasicInfo);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_4->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ReviseBasicInfo);

        QMetaObject::connectSlotsByName(ReviseBasicInfo);
    } // setupUi

    void retranslateUi(QDialog *ReviseBasicInfo)
    {
        ReviseBasicInfo->setWindowTitle(QApplication::translate("ReviseBasicInfo", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("ReviseBasicInfo", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit_name->setPlaceholderText(QApplication::translate("ReviseBasicInfo", "UserName", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReviseBasicInfo", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        radioButton_M->setText(QApplication::translate("ReviseBasicInfo", "\347\224\267", Q_NULLPTR));
        radioButton_W->setText(QApplication::translate("ReviseBasicInfo", "\345\245\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReviseBasicInfo", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        OkButton->setText(QApplication::translate("ReviseBasicInfo", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("ReviseBasicInfo", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReviseBasicInfo: public Ui_ReviseBasicInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVISEBASICINFO_H
