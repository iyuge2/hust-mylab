/********************************************************************************
** Form generated from reading UI file 'revisepass.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVISEPASS_H
#define UI_REVISEPASS_H

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

class Ui_RevisePass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_old;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_new;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_new2;
    QHBoxLayout *horizontalLayout;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *RevisePass)
    {
        if (RevisePass->objectName().isEmpty())
            RevisePass->setObjectName(QStringLiteral("RevisePass"));
        RevisePass->resize(261, 226);
        verticalLayout = new QVBoxLayout(RevisePass);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(RevisePass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_old = new QLineEdit(RevisePass);
        lineEdit_old->setObjectName(QStringLiteral("lineEdit_old"));
        lineEdit_old->setMaxLength(20);
        lineEdit_old->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_old);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(RevisePass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_new = new QLineEdit(RevisePass);
        lineEdit_new->setObjectName(QStringLiteral("lineEdit_new"));
        lineEdit_new->setMaxLength(20);
        lineEdit_new->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_new);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(RevisePass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_new2 = new QLineEdit(RevisePass);
        lineEdit_new2->setObjectName(QStringLiteral("lineEdit_new2"));
        lineEdit_new2->setMaxLength(20);
        lineEdit_new2->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEdit_new2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OkButton = new QPushButton(RevisePass);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout->addWidget(OkButton);

        CancelButton = new QPushButton(RevisePass);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RevisePass);

        QMetaObject::connectSlotsByName(RevisePass);
    } // setupUi

    void retranslateUi(QDialog *RevisePass)
    {
        RevisePass->setWindowTitle(QApplication::translate("RevisePass", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("RevisePass", "\345\216\237\345\257\206\347\240\201\357\274\232    ", Q_NULLPTR));
        label_2->setText(QApplication::translate("RevisePass", "\346\226\260\345\257\206\347\240\201\357\274\232    ", Q_NULLPTR));
        label_3->setText(QApplication::translate("RevisePass", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        OkButton->setText(QApplication::translate("RevisePass", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("RevisePass", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RevisePass: public Ui_RevisePass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVISEPASS_H
