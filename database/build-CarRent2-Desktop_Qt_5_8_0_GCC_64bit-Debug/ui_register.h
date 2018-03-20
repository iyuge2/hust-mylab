/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(271, 300);
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit = new QLineEdit(Register);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(20);

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Register);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaxLength(20);
        lineEdit_3->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(Register);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        radioButton = new QRadioButton(Register);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_5->addWidget(radioButton);

        radioButton_2 = new QRadioButton(Register);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_5->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OkButton = new QPushButton(Register);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout->addWidget(OkButton);

        CancelButton = new QPushButton(Register);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit->setText(QString());
        label_3->setText(QApplication::translate("Register", "    \345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_3->setPlaceholderText(QApplication::translate("Register", "\344\270\215\350\266\205\350\277\20720\344\275\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "    \345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "    \346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Register", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Register", "\345\245\263", Q_NULLPTR));
        OkButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("Register", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
