/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QLabel *label_ide;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *LoginButton;
    QPushButton *RegisterButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(265, 218);
        formLayout = new QFormLayout(Login);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(20);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Login);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaxLength(20);
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton = new QRadioButton(Login);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(Login);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton_4 = new QRadioButton(Login);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout_4->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(Login);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_4->addWidget(radioButton_3);


        verticalLayout->addLayout(horizontalLayout_4);

        label_ide = new QLabel(Login);
        label_ide->setObjectName(QStringLiteral("label_ide"));
        label_ide->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout->addWidget(label_ide);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LoginButton = new QPushButton(Login);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setMaximumSize(QSize(1677215, 16777215));

        horizontalLayout_5->addWidget(LoginButton);

        RegisterButton = new QPushButton(Login);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setMaximumSize(QSize(1677215, 16777215));

        horizontalLayout_5->addWidget(RegisterButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);

        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("Login", "UserName", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("Login", "PassWord", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Login", "\347\224\250\346\210\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Login", "\345\267\245\344\275\234\344\272\272\345\221\230", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("Login", "\346\270\270\345\256\242", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("Login", "\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        label_ide->setText(QString());
        LoginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        RegisterButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
