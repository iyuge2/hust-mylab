/********************************************************************************
** Form generated from reading UI file 'addcarinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARINFO_H
#define UI_ADDCARINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCarInfo
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_cnum;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEdit_fee;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_time;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_cash;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_ree;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *AddCarInfo)
    {
        if (AddCarInfo->objectName().isEmpty())
            AddCarInfo->setObjectName(QStringLiteral("AddCarInfo"));
        AddCarInfo->resize(304, 353);
        layoutWidget = new QWidget(AddCarInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 292, 340));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_cnum = new QLineEdit(layoutWidget);
        lineEdit_cnum->setObjectName(QStringLiteral("lineEdit_cnum"));
        lineEdit_cnum->setMaxLength(9);

        horizontalLayout->addWidget(lineEdit_cnum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEdit_fee = new QLineEdit(layoutWidget);
        lineEdit_fee->setObjectName(QStringLiteral("lineEdit_fee"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_fee->sizePolicy().hasHeightForWidth());
        lineEdit_fee->setSizePolicy(sizePolicy);
        lineEdit_fee->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_fee->setMaxLength(12);

        horizontalLayout_7->addWidget(lineEdit_fee);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_time = new QLineEdit(layoutWidget);
        lineEdit_time->setObjectName(QStringLiteral("lineEdit_time"));
        lineEdit_time->setMaxLength(19);

        horizontalLayout_6->addWidget(lineEdit_time);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);
        comboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_cash = new QLineEdit(layoutWidget);
        lineEdit_cash->setObjectName(QStringLiteral("lineEdit_cash"));
        lineEdit_cash->setMaxLength(12);

        horizontalLayout_4->addWidget(lineEdit_cash);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lineEdit_ree = new QLineEdit(layoutWidget);
        lineEdit_ree->setObjectName(QStringLiteral("lineEdit_ree"));
        lineEdit_ree->setMaxLength(12);

        horizontalLayout_3->addWidget(lineEdit_ree);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_9->addWidget(label_3);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEditable(true);
        comboBox_2->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_9->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_10->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout_10->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(layoutWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        horizontalLayout_10->addWidget(radioButton_5);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        OkButton = new QPushButton(layoutWidget);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout_8->addWidget(OkButton);

        CancelButton = new QPushButton(layoutWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_8->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(AddCarInfo);

        QMetaObject::connectSlotsByName(AddCarInfo);
    } // setupUi

    void retranslateUi(QDialog *AddCarInfo)
    {
        AddCarInfo->setWindowTitle(QApplication::translate("AddCarInfo", "\345\242\236\345\212\240\350\275\246\350\276\206", Q_NULLPTR));
        label->setText(QApplication::translate("AddCarInfo", "    \350\275\246\347\211\214\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_cnum->setText(QString());
        lineEdit_cnum->setPlaceholderText(QApplication::translate("AddCarInfo", "C20140001", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddCarInfo", "\350\264\255\345\205\245\350\264\271\347\224\250\357\274\232", Q_NULLPTR));
        lineEdit_fee->setPlaceholderText(QApplication::translate("AddCarInfo", "20000", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddCarInfo", "\350\264\255\345\205\245\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        lineEdit_time->setText(QString());
        lineEdit_time->setPlaceholderText(QApplication::translate("AddCarInfo", "2017-01-01 12:00:00", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddCarInfo", "        \345\223\201\347\211\214\357\274\232", Q_NULLPTR));
        comboBox->setCurrentText(QApplication::translate("AddCarInfo", "\345\245\224\351\251\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddCarInfo", "\346\211\200\351\234\200\346\212\274\351\207\221\357\274\232", Q_NULLPTR));
        lineEdit_cash->setText(QString());
        lineEdit_cash->setPlaceholderText(QApplication::translate("AddCarInfo", "1000", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddCarInfo", "  \347\247\237\351\207\221(/h)\357\274\232", Q_NULLPTR));
        lineEdit_ree->setText(QString());
        lineEdit_ree->setPlaceholderText(QApplication::translate("AddCarInfo", "1000", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddCarInfo", "        \351\242\234\350\211\262\357\274\232", Q_NULLPTR));
        comboBox_2->setCurrentText(QApplication::translate("AddCarInfo", "\347\272\242\350\211\262", Q_NULLPTR));
        label_8->setText(QApplication::translate("AddCarInfo", " VIP\344\270\223\344\272\253\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("AddCarInfo", "\346\230\257", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("AddCarInfo", "\345\220\246", Q_NULLPTR));
        label_9->setText(QApplication::translate("AddCarInfo", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("AddCarInfo", "\347\251\272\351\227\262", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("AddCarInfo", "\347\273\264\344\277\256\344\270\255", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("AddCarInfo", "\344\275\277\347\224\250\344\270\255", Q_NULLPTR));
        OkButton->setText(QApplication::translate("AddCarInfo", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("AddCarInfo", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddCarInfo: public Ui_AddCarInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARINFO_H
