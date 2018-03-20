/********************************************************************************
** Form generated from reading UI file 'workerlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERLOGIN_H
#define UI_WORKERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkerLogin
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_5;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *ACButton_3;
    QVBoxLayout *verticalLayout_13;
    QPushButton *DCButton_2;
    QPushButton *RCButton_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_7;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *DUButton_2;
    QFrame *line_14;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_8;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_7;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *TimeEdit1_2;
    QLabel *label_3;
    QDateTimeEdit *TimeEdit2_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_8;
    QPushButton *RentOkButton_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_order;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QSpinBox *spinBox;
    QPushButton *DealButton;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *label_num;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_23;
    QLabel *label_sex;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_24;
    QLabel *label_age;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_26;
    QLabel *label_Ctime;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_25;
    QLabel *label_tnum;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_27;
    QLabel *label_Ide;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_8;
    QLabel *label_wage;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *pushButton_info;
    QPushButton *pushButton_pass;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *SlashButton;
    QPushButton *ExitButton;

    void setupUi(QDialog *WorkerLogin)
    {
        if (WorkerLogin->objectName().isEmpty())
            WorkerLogin->setObjectName(QStringLiteral("WorkerLogin"));
        WorkerLogin->resize(774, 465);
        verticalLayout = new QVBoxLayout(WorkerLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(WorkerLogin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_5 = new QVBoxLayout(tab_6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidget_5 = new QTableWidget(tab_6);
        if (tableWidget_5->columnCount() < 8)
            tableWidget_5->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_5->setObjectName(QStringLiteral("tableWidget_5"));
        tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_5->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_5->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_5->horizontalHeader()->setHighlightSections(false);
        tableWidget_5->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableWidget_5);

        line_11 = new QFrame(tab_6);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_11);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        ACButton_3 = new QPushButton(tab_6);
        ACButton_3->setObjectName(QStringLiteral("ACButton_3"));

        horizontalLayout_11->addWidget(ACButton_3);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        DCButton_2 = new QPushButton(tab_6);
        DCButton_2->setObjectName(QStringLiteral("DCButton_2"));

        verticalLayout_13->addWidget(DCButton_2);

        RCButton_2 = new QPushButton(tab_6);
        RCButton_2->setObjectName(QStringLiteral("RCButton_2"));

        verticalLayout_13->addWidget(RCButton_2);


        horizontalLayout_11->addLayout(verticalLayout_13);

        line_2 = new QFrame(tab_6);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_11->addWidget(line_2);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(tab_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lineEdit_5 = new QLineEdit(tab_6);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMaxLength(9);

        horizontalLayout_4->addWidget(lineEdit_5);


        verticalLayout_14->addLayout(horizontalLayout_4);

        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_14->addWidget(label_9);


        horizontalLayout_11->addLayout(verticalLayout_14);


        verticalLayout_5->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        verticalLayout_6 = new QVBoxLayout(tab_8);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidget_7 = new QTableWidget(tab_8);
        if (tableWidget_7->columnCount() < 6)
            tableWidget_7->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        tableWidget_7->setObjectName(QStringLiteral("tableWidget_7"));
        tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_7->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_7->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_7->horizontalHeader()->setHighlightSections(false);
        tableWidget_7->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(tableWidget_7);

        line_13 = new QFrame(tab_8);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        DUButton_2 = new QPushButton(tab_8);
        DUButton_2->setObjectName(QStringLiteral("DUButton_2"));

        horizontalLayout_14->addWidget(DUButton_2);

        line_14 = new QFrame(tab_8);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        horizontalLayout_14->addWidget(line_14);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_12 = new QLabel(tab_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_15->addWidget(label_12);

        lineEdit_7 = new QLineEdit(tab_8);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setMaxLength(10);

        horizontalLayout_15->addWidget(lineEdit_7);


        verticalLayout_18->addLayout(horizontalLayout_15);

        label_13 = new QLabel(tab_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_18->addWidget(label_13);


        horizontalLayout_14->addLayout(verticalLayout_18);


        verticalLayout_6->addLayout(horizontalLayout_14);

        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        verticalLayout_4 = new QVBoxLayout(tab_9);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidget_8 = new QTableWidget(tab_9);
        if (tableWidget_8->columnCount() < 10)
            tableWidget_8->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(7, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(8, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(9, __qtablewidgetitem23);
        tableWidget_8->setObjectName(QStringLiteral("tableWidget_8"));
        tableWidget_8->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_8->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_8->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_8->horizontalHeader()->setHighlightSections(false);
        tableWidget_8->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidget_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        radioButton_8 = new QRadioButton(tab_9);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        horizontalLayout_17->addWidget(radioButton_8);

        radioButton_6 = new QRadioButton(tab_9);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        horizontalLayout_17->addWidget(radioButton_6);

        radioButton_5 = new QRadioButton(tab_9);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        horizontalLayout_17->addWidget(radioButton_5);

        radioButton_7 = new QRadioButton(tab_9);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        horizontalLayout_17->addWidget(radioButton_7);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        TimeEdit1_2 = new QDateTimeEdit(tab_9);
        TimeEdit1_2->setObjectName(QStringLiteral("TimeEdit1_2"));
        TimeEdit1_2->setCalendarPopup(true);

        horizontalLayout_3->addWidget(TimeEdit1_2);

        label_3 = new QLabel(tab_9);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        TimeEdit2_2 = new QDateTimeEdit(tab_9);
        TimeEdit2_2->setObjectName(QStringLiteral("TimeEdit2_2"));
        TimeEdit2_2->setCalendarPopup(true);

        horizontalLayout_3->addWidget(TimeEdit2_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit_8 = new QLineEdit(tab_9);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMaxLength(20);

        horizontalLayout_5->addWidget(lineEdit_8);

        RentOkButton_2 = new QPushButton(tab_9);
        RentOkButton_2->setObjectName(QStringLiteral("RentOkButton_2"));

        horizontalLayout_5->addWidget(RentOkButton_2);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(tab_9);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_order = new QLineEdit(tab_9);
        lineEdit_order->setObjectName(QStringLiteral("lineEdit_order"));
        lineEdit_order->setMaxLength(12);

        horizontalLayout->addWidget(lineEdit_order);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(tab_9);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(tab_9);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_4 = new QLabel(tab_9);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinBox = new QSpinBox(tab_9);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(100000);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        DealButton = new QPushButton(tab_9);
        DealButton->setObjectName(QStringLiteral("DealButton"));

        verticalLayout_3->addWidget(DealButton);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_9, QString());
        widget_2 = new QWidget();
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_8 = new QVBoxLayout(widget_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_5);

        label_num = new QLabel(widget_2);
        label_num->setObjectName(QStringLiteral("label_num"));

        horizontalLayout_7->addWidget(label_num);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(label_6);

        label_name = new QLabel(widget_2);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout_8->addWidget(label_name);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_26->addWidget(label_23);

        label_sex = new QLabel(widget_2);
        label_sex->setObjectName(QStringLiteral("label_sex"));

        horizontalLayout_26->addWidget(label_sex);


        verticalLayout_8->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_24 = new QLabel(widget_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_27->addWidget(label_24);

        label_age = new QLabel(widget_2);
        label_age->setObjectName(QStringLiteral("label_age"));

        horizontalLayout_27->addWidget(label_age);


        verticalLayout_8->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_26 = new QLabel(widget_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_28->addWidget(label_26);

        label_Ctime = new QLabel(widget_2);
        label_Ctime->setObjectName(QStringLiteral("label_Ctime"));

        horizontalLayout_28->addWidget(label_Ctime);


        verticalLayout_8->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_25 = new QLabel(widget_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_29->addWidget(label_25);

        label_tnum = new QLabel(widget_2);
        label_tnum->setObjectName(QStringLiteral("label_tnum"));

        horizontalLayout_29->addWidget(label_tnum);


        verticalLayout_8->addLayout(horizontalLayout_29);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        label_27 = new QLabel(widget_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_31->addWidget(label_27);

        label_Ide = new QLabel(widget_2);
        label_Ide->setObjectName(QStringLiteral("label_Ide"));

        horizontalLayout_31->addWidget(label_Ide);


        verticalLayout_8->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_32->addWidget(label_8);

        label_wage = new QLabel(widget_2);
        label_wage->setObjectName(QStringLiteral("label_wage"));

        horizontalLayout_32->addWidget(label_wage);


        verticalLayout_8->addLayout(horizontalLayout_32);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        pushButton_info = new QPushButton(widget_2);
        pushButton_info->setObjectName(QStringLiteral("pushButton_info"));

        horizontalLayout_30->addWidget(pushButton_info);

        pushButton_pass = new QPushButton(widget_2);
        pushButton_pass->setObjectName(QStringLiteral("pushButton_pass"));

        horizontalLayout_30->addWidget(pushButton_pass);


        verticalLayout_8->addLayout(horizontalLayout_30);

        tabWidget->addTab(widget_2, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        SlashButton = new QPushButton(WorkerLogin);
        SlashButton->setObjectName(QStringLiteral("SlashButton"));

        horizontalLayout_19->addWidget(SlashButton);

        ExitButton = new QPushButton(WorkerLogin);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));

        horizontalLayout_19->addWidget(ExitButton);


        verticalLayout->addLayout(horizontalLayout_19);


        retranslateUi(WorkerLogin);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(WorkerLogin);
    } // setupUi

    void retranslateUi(QDialog *WorkerLogin)
    {
        WorkerLogin->setWindowTitle(QApplication::translate("WorkerLogin", "\345\221\230\345\267\245", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("WorkerLogin", "\345\223\201\347\211\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("WorkerLogin", "\351\242\234\350\211\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("WorkerLogin", "\350\264\255\345\205\245\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("WorkerLogin", "\346\211\200\351\234\200\346\212\274\351\207\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_5->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("WorkerLogin", "\347\247\237\351\207\221(/h)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_5->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("WorkerLogin", "\345\205\266\344\273\226", Q_NULLPTR));
        ACButton_3->setText(QApplication::translate("WorkerLogin", "\345\242\236\345\212\240\350\275\246\350\276\206", Q_NULLPTR));
        DCButton_2->setText(QApplication::translate("WorkerLogin", "\345\210\240\351\231\244\350\275\246\350\276\206", Q_NULLPTR));
        RCButton_2->setText(QApplication::translate("WorkerLogin", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("WorkerLogin", "\350\275\246\347\211\214\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_5->setPlaceholderText(QApplication::translate("WorkerLogin", "C20140001", Q_NULLPTR));
        label_9->setText(QApplication::translate("WorkerLogin", "                              \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\350\275\246\350\276\206", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("WorkerLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("WorkerLogin", "\346\200\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_7->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("WorkerLogin", "\345\271\264\351\276\204", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_7->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("WorkerLogin", "\344\277\241\347\224\250\350\257\204\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_7->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("WorkerLogin", "\350\264\246\346\210\267\344\275\231\351\242\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_7->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("WorkerLogin", "\345\205\266\344\273\226", Q_NULLPTR));
        DUButton_2->setText(QApplication::translate("WorkerLogin", "\345\210\240\351\231\244\345\256\242\346\210\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("WorkerLogin", "\345\256\242\346\210\267\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEdit_7->setPlaceholderText(QApplication::translate("WorkerLogin", "username", Q_NULLPTR));
        label_13->setText(QApplication::translate("WorkerLogin", "                              \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\345\256\242\346\210\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("WorkerLogin", "\345\256\242\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_8->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("WorkerLogin", "\350\256\242\345\215\225\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_8->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("WorkerLogin", "\345\221\230\345\267\245\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_8->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("WorkerLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_8->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_8->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("WorkerLogin", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_8->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("WorkerLogin", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_8->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("WorkerLogin", "\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_8->horizontalHeaderItem(7);
        ___qtablewidgetitem21->setText(QApplication::translate("WorkerLogin", "\350\277\235\347\275\232\346\254\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_8->horizontalHeaderItem(8);
        ___qtablewidgetitem22->setText(QApplication::translate("WorkerLogin", "\346\200\273\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_8->horizontalHeaderItem(9);
        ___qtablewidgetitem23->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\344\275\277\347\224\250\346\203\205\345\206\265\350\257\204\345\256\232", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("WorkerLogin", "\347\247\237\350\275\246\346\227\266\351\227\264\346\256\265", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("WorkerLogin", "\345\217\252\347\234\213\350\257\267\346\261\202", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("WorkerLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        TimeEdit1_2->setDisplayFormat(QApplication::translate("WorkerLogin", "yyyy/M/d hh:mm:ss", Q_NULLPTR));
        label_3->setText(QApplication::translate("WorkerLogin", "\357\275\236", Q_NULLPTR));
        TimeEdit2_2->setDisplayFormat(QApplication::translate("WorkerLogin", "yyyy/M/d hh:mm:ss", Q_NULLPTR));
        lineEdit_8->setPlaceholderText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\274\226\345\217\267/\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        RentOkButton_2->setText(QApplication::translate("WorkerLogin", "\346\237\245\350\257\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("WorkerLogin", "\350\256\242\345\215\225\347\274\226\345\217\267:", Q_NULLPTR));
        lineEdit_order->setPlaceholderText(QApplication::translate("WorkerLogin", "T\303\227\303\227\303\227\303\227\303\227", Q_NULLPTR));
        label->setText(QApplication::translate("WorkerLogin", "\350\275\246\350\276\206\347\212\266\345\206\265:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("WorkerLogin", "A", Q_NULLPTR)
         << QApplication::translate("WorkerLogin", "B", Q_NULLPTR)
         << QApplication::translate("WorkerLogin", "C", Q_NULLPTR)
         << QApplication::translate("WorkerLogin", "D", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("WorkerLogin", "\350\277\235\347\275\232\346\254\276\357\274\232", Q_NULLPTR));
        DealButton->setText(QApplication::translate("WorkerLogin", "\345\244\204\347\220\206\350\257\267\346\261\202", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("WorkerLogin", "\347\247\237\350\275\246\344\277\241\346\201\257", Q_NULLPTR));
        label_5->setText(QApplication::translate("WorkerLogin", "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_num->setText(QString());
        label_6->setText(QApplication::translate("WorkerLogin", "\345\221\230\345\267\245\345\220\215\357\274\232", Q_NULLPTR));
        label_name->setText(QString());
        label_23->setText(QApplication::translate("WorkerLogin", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_sex->setText(QString());
        label_24->setText(QApplication::translate("WorkerLogin", "\345\271\264\351\276\204:", Q_NULLPTR));
        label_age->setText(QString());
        label_26->setText(QApplication::translate("WorkerLogin", "\345\205\245\350\201\214\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_Ctime->setText(QString());
        label_25->setText(QApplication::translate("WorkerLogin", "\346\211\200\345\256\214\346\210\220\344\272\244\346\230\223\346\225\260\357\274\232", Q_NULLPTR));
        label_tnum->setText(QString());
        label_27->setText(QApplication::translate("WorkerLogin", "\350\272\253\344\273\275\357\274\232", Q_NULLPTR));
        label_Ide->setText(QString());
        label_8->setText(QApplication::translate("WorkerLogin", "\345\237\272\346\234\254\345\267\245\350\265\204(/\346\234\210):", Q_NULLPTR));
        label_wage->setText(QString());
        pushButton_info->setText(QApplication::translate("WorkerLogin", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_pass->setText(QApplication::translate("WorkerLogin", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(widget_2), QApplication::translate("WorkerLogin", "\346\210\221\347\232\204\344\270\273\351\241\265", Q_NULLPTR));
        SlashButton->setText(QApplication::translate("WorkerLogin", "\345\210\267\346\226\260", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("WorkerLogin", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorkerLogin: public Ui_WorkerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERLOGIN_H
