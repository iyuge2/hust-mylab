/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserLogin
{
public:
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *RentButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *FOButton;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_10;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLabel *label_grade;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLabel *label_sex;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *label_age;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_account;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *label_credit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BasicButton;
    QPushButton *AccountButton;
    QPushButton *PassButton;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *SlashButton;
    QPushButton *ExitButton;

    void setupUi(QDialog *UserLogin)
    {
        if (UserLogin->objectName().isEmpty())
            UserLogin->setObjectName(QStringLiteral("UserLogin"));
        UserLogin->resize(698, 488);
        verticalLayout_8 = new QVBoxLayout(UserLogin);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tabWidget = new QTabWidget(UserLogin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        RentButton = new QPushButton(tab);
        RentButton->setObjectName(QStringLiteral("RentButton"));

        verticalLayout_2->addWidget(RentButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setMaxLength(9);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_6->addLayout(horizontalLayout);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_6->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 8)
            tableWidget_2->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->horizontalHeader()->setHighlightSections(false);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        FOButton = new QPushButton(tab_2);
        FOButton->setObjectName(QStringLiteral("FOButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FOButton->sizePolicy().hasHeightForWidth());
        FOButton->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(FOButton);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaxLength(9);

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_7->addWidget(label_10);


        horizontalLayout_12->addLayout(verticalLayout_7);


        verticalLayout->addLayout(horizontalLayout_12);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_11->addWidget(label);

        label_name = new QLabel(tab_3);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout_11->addWidget(label_name);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        label_grade = new QLabel(tab_3);
        label_grade->setObjectName(QStringLiteral("label_grade"));

        horizontalLayout_10->addWidget(label_grade);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_9->addWidget(label_3);

        label_sex = new QLabel(tab_3);
        label_sex->setObjectName(QStringLiteral("label_sex"));

        horizontalLayout_9->addWidget(label_sex);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        label_age = new QLabel(tab_3);
        label_age->setObjectName(QStringLiteral("label_age"));

        horizontalLayout_8->addWidget(label_age);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        label_account = new QLabel(tab_3);
        label_account->setObjectName(QStringLiteral("label_account"));

        horizontalLayout_7->addWidget(label_account);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        label_credit = new QLabel(tab_3);
        label_credit->setObjectName(QStringLiteral("label_credit"));

        horizontalLayout_6->addWidget(label_credit);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        BasicButton = new QPushButton(tab_3);
        BasicButton->setObjectName(QStringLiteral("BasicButton"));

        horizontalLayout_2->addWidget(BasicButton);

        AccountButton = new QPushButton(tab_3);
        AccountButton->setObjectName(QStringLiteral("AccountButton"));

        horizontalLayout_2->addWidget(AccountButton);

        PassButton = new QPushButton(tab_3);
        PassButton->setObjectName(QStringLiteral("PassButton"));

        horizontalLayout_2->addWidget(PassButton);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(tab_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMaximumSize(QSize(256, 100));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        verticalLayout_8->addWidget(tabWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        SlashButton = new QPushButton(UserLogin);
        SlashButton->setObjectName(QStringLiteral("SlashButton"));

        horizontalLayout_5->addWidget(SlashButton);

        ExitButton = new QPushButton(UserLogin);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ExitButton->sizePolicy().hasHeightForWidth());
        ExitButton->setSizePolicy(sizePolicy2);
        ExitButton->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_5->addWidget(ExitButton);


        verticalLayout_8->addLayout(horizontalLayout_5);


        retranslateUi(UserLogin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserLogin);
    } // setupUi

    void retranslateUi(QDialog *UserLogin)
    {
        UserLogin->setWindowTitle(QApplication::translate("UserLogin", "\347\224\250\346\210\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserLogin", "\345\223\201\347\211\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserLogin", "\351\242\234\350\211\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserLogin", "\350\275\246\350\276\206\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserLogin", "\350\264\255\345\205\245\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserLogin", "\346\211\200\351\234\200\346\212\274\351\207\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("UserLogin", "\347\247\237\351\207\221(/h)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("UserLogin", "\345\205\266\344\273\226", Q_NULLPTR));
        RentButton->setText(QApplication::translate("UserLogin", "\347\247\237\347\224\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserLogin", "\350\275\246\347\211\214\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("UserLogin", "C20140001", Q_NULLPTR));
        label_4->setText(QApplication::translate("UserLogin", "                              \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\350\275\246\350\276\206", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserLogin", "\347\247\237\350\275\246\347\225\214\351\235\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("UserLogin", "\350\256\242\345\215\225\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("UserLogin", "\350\256\242\345\215\225\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("UserLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("UserLogin", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("UserLogin", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("UserLogin", "\350\256\241\350\264\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("UserLogin", "\350\277\235\347\275\232\346\254\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("UserLogin", "\346\200\273\350\264\271\347\224\250", Q_NULLPTR));
        FOButton->setText(QApplication::translate("UserLogin", "\347\273\223\346\235\237\350\241\214\347\250\213", Q_NULLPTR));
        label_8->setText(QApplication::translate("UserLogin", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("UserLogin", "T******", Q_NULLPTR));
        label_10->setText(QApplication::translate("UserLogin", "                 \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\350\256\242\345\215\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserLogin", "\346\210\221\347\232\204\350\241\214\347\250\213", Q_NULLPTR));
        label->setText(QApplication::translate("UserLogin", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_name->setText(QString());
        label_9->setText(QApplication::translate("UserLogin", "\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        label_grade->setText(QString());
        label_3->setText(QApplication::translate("UserLogin", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_sex->setText(QString());
        label_5->setText(QApplication::translate("UserLogin", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_age->setText(QString());
        label_6->setText(QApplication::translate("UserLogin", "\350\264\246\346\210\267\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        label_account->setText(QString());
        label_7->setText(QApplication::translate("UserLogin", "\344\277\241\347\224\250\350\257\204\347\272\247\357\274\232", Q_NULLPTR));
        label_credit->setText(QString());
        BasicButton->setText(QApplication::translate("UserLogin", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        AccountButton->setText(QApplication::translate("UserLogin", "\350\264\246\346\210\267\345\205\205\345\200\274", Q_NULLPTR));
        PassButton->setText(QApplication::translate("UserLogin", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UserLogin", "\346\210\221\347\232\204\350\264\246\346\210\267", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("UserLogin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">      \350\257\246\346\203\205\350\257\267\350\247\201</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; text-decoration: underline;\">www.iyuge2.com</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("UserLogin", "\344\275\277\347\224\250\346\214\207\345\215\227", Q_NULLPTR));
        SlashButton->setText(QApplication::translate("UserLogin", "\345\210\267\346\226\260", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("UserLogin", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserLogin: public Ui_UserLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
