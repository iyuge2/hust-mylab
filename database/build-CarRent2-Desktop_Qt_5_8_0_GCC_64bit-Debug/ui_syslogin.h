/********************************************************************************
** Form generated from reading UI file 'syslogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSLOGIN_H
#define UI_SYSLOGIN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_SysLogin
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *ACButton;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DCButton;
    QPushButton *RCButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_14;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *AWButton;
    QPushButton *DWButton;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_13;
    QPushButton *AddWageButton;
    QPushButton *PrizeButton;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_3;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *DUButton;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *tableWidget_4;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QFrame *line_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *radioButton_4;
    QHBoxLayout *horizontalLayout_9;
    QDateTimeEdit *TimeEdit1;
    QLabel *label_8;
    QDateTimeEdit *TimeEdit2;
    QPushButton *RentOkButton;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_11;
    QTableWidget *tableWidget_C;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QLabel *label_OrderCount;
    QLabel *label_12;
    QLabel *label_OrderFee;
    QFrame *line_9;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_14;
    QTableWidget *tableWidget_W;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLabel *label_WageAll;
    QLabel *label_20;
    QLabel *label_PrizeAll;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_25;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_21;
    QTableWidget *tableWidget_B;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QLabel *label_buycar;
    QFrame *line_11;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_23;
    QFrame *line_3;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_19;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *QueryMoneyButton;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_16;
    QLabel *label_in;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_17;
    QLabel *label_out;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_18;
    QLabel *label_left;
    QWidget *widget;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLabel *label_num;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
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
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLabel *label_Ide;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *pushButton_info;
    QPushButton *pushButton_pass;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SlashButton;
    QPushButton *ExitButton;

    void setupUi(QDialog *SysLogin)
    {
        if (SysLogin->objectName().isEmpty())
            SysLogin->setObjectName(QStringLiteral("SysLogin"));
        SysLogin->resize(774, 492);
        verticalLayout = new QVBoxLayout(SysLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(SysLogin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(tableWidget);

        line_10 = new QFrame(tab);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ACButton = new QPushButton(tab);
        ACButton->setObjectName(QStringLiteral("ACButton"));

        horizontalLayout_5->addWidget(ACButton);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        DCButton = new QPushButton(tab);
        DCButton->setObjectName(QStringLiteral("DCButton"));

        verticalLayout_2->addWidget(DCButton);

        RCButton = new QPushButton(tab);
        RCButton->setObjectName(QStringLiteral("RCButton"));

        verticalLayout_2->addWidget(RCButton);


        horizontalLayout_5->addLayout(verticalLayout_2);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(9);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_5->addLayout(horizontalLayout);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_5->addWidget(label_2);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_14 = new QVBoxLayout(tab_2);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->horizontalHeader()->setHighlightSections(false);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_14->addWidget(tableWidget_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        AWButton = new QPushButton(tab_2);
        AWButton->setObjectName(QStringLiteral("AWButton"));

        horizontalLayout_14->addWidget(AWButton);

        DWButton = new QPushButton(tab_2);
        DWButton->setObjectName(QStringLiteral("DWButton"));

        horizontalLayout_14->addWidget(DWButton);


        verticalLayout_3->addLayout(horizontalLayout_14);


        horizontalLayout_15->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaxLength(10);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        horizontalLayout_6->addWidget(label_4);

        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(100000);

        horizontalLayout_6->addWidget(spinBox);


        verticalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(verticalLayout_7);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        AddWageButton = new QPushButton(tab_2);
        AddWageButton->setObjectName(QStringLiteral("AddWageButton"));

        verticalLayout_13->addWidget(AddWageButton);

        PrizeButton = new QPushButton(tab_2);
        PrizeButton->setObjectName(QStringLiteral("PrizeButton"));

        verticalLayout_13->addWidget(PrizeButton);


        horizontalLayout_15->addLayout(verticalLayout_13);


        verticalLayout_14->addLayout(horizontalLayout_15);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidget_3 = new QTableWidget(tab_3);
        if (tableWidget_3->columnCount() < 6)
            tableWidget_3->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem21);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_3->horizontalHeader()->setHighlightSections(false);
        tableWidget_3->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidget_3);

        line_7 = new QFrame(tab_3);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DUButton = new QPushButton(tab_3);
        DUButton->setObjectName(QStringLiteral("DUButton"));

        horizontalLayout_3->addWidget(DUButton);

        line_8 = new QFrame(tab_3);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_8);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaxLength(10);

        horizontalLayout_7->addWidget(lineEdit_3);


        verticalLayout_8->addLayout(horizontalLayout_7);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));

        verticalLayout_8->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_8);


        verticalLayout_4->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_11 = new QVBoxLayout(tab_5);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        tableWidget_4 = new QTableWidget(tab_5);
        if (tableWidget_4->columnCount() < 10)
            tableWidget_4->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(7, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(8, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(9, __qtablewidgetitem31);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));
        tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_4->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_4->horizontalHeader()->setHighlightSections(false);
        tableWidget_4->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_11->addWidget(tableWidget_4);

        line_6 = new QFrame(tab_5);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        line_4 = new QFrame(tab_5);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_4);

        radioButton = new QRadioButton(tab_5);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_8->addWidget(radioButton);

        radioButton_2 = new QRadioButton(tab_5);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_8->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(tab_5);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_8->addWidget(radioButton_3);


        verticalLayout_9->addLayout(horizontalLayout_8);

        lineEdit_4 = new QLineEdit(tab_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaxLength(20);

        verticalLayout_9->addWidget(lineEdit_4);


        horizontalLayout_10->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        radioButton_4 = new QRadioButton(tab_5);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_10->addWidget(radioButton_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        TimeEdit1 = new QDateTimeEdit(tab_5);
        TimeEdit1->setObjectName(QStringLiteral("TimeEdit1"));
        TimeEdit1->setCalendarPopup(true);

        horizontalLayout_9->addWidget(TimeEdit1);

        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8, 0, Qt::AlignHCenter);

        TimeEdit2 = new QDateTimeEdit(tab_5);
        TimeEdit2->setObjectName(QStringLiteral("TimeEdit2"));
        TimeEdit2->setCalendarPopup(true);

        horizontalLayout_9->addWidget(TimeEdit2);


        verticalLayout_10->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_10);

        RentOkButton = new QPushButton(tab_5);
        RentOkButton->setObjectName(QStringLiteral("RentOkButton"));

        horizontalLayout_10->addWidget(RentOkButton);


        verticalLayout_11->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_19 = new QVBoxLayout(tab_4);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(239, 41, 41);"));

        verticalLayout_15->addWidget(label_11);

        tableWidget_C = new QTableWidget(tab_4);
        if (tableWidget_C->columnCount() < 3)
            tableWidget_C->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_C->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_C->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_C->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        tableWidget_C->setObjectName(QStringLiteral("tableWidget_C"));
        tableWidget_C->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_C->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_C->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_C->horizontalHeader()->setHighlightSections(false);
        tableWidget_C->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_15->addWidget(tableWidget_C);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_16->addWidget(label_13);

        label_OrderCount = new QLabel(tab_4);
        label_OrderCount->setObjectName(QStringLiteral("label_OrderCount"));

        horizontalLayout_16->addWidget(label_OrderCount);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_16->addWidget(label_12);

        label_OrderFee = new QLabel(tab_4);
        label_OrderFee->setObjectName(QStringLiteral("label_OrderFee"));

        horizontalLayout_16->addWidget(label_OrderFee);


        verticalLayout_15->addLayout(horizontalLayout_16);


        horizontalLayout_18->addLayout(verticalLayout_15);

        line_9 = new QFrame(tab_4);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_18->addWidget(line_9);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(239, 41, 41);"));

        verticalLayout_16->addWidget(label_14);

        tableWidget_W = new QTableWidget(tab_4);
        if (tableWidget_W->columnCount() < 4)
            tableWidget_W->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_W->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_W->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_W->setHorizontalHeaderItem(2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_W->setHorizontalHeaderItem(3, __qtablewidgetitem38);
        tableWidget_W->setObjectName(QStringLiteral("tableWidget_W"));
        tableWidget_W->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_W->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_W->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_W->horizontalHeader()->setHighlightSections(false);
        tableWidget_W->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_16->addWidget(tableWidget_W);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_17->addWidget(label_15);

        label_WageAll = new QLabel(tab_4);
        label_WageAll->setObjectName(QStringLiteral("label_WageAll"));

        horizontalLayout_17->addWidget(label_WageAll);

        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_17->addWidget(label_20);

        label_PrizeAll = new QLabel(tab_4);
        label_PrizeAll->setObjectName(QStringLiteral("label_PrizeAll"));

        horizontalLayout_17->addWidget(label_PrizeAll);


        verticalLayout_16->addLayout(horizontalLayout_17);


        horizontalLayout_18->addLayout(verticalLayout_16);


        verticalLayout_19->addLayout(horizontalLayout_18);

        line_5 = new QFrame(tab_4);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_19->addWidget(line_5);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setStyleSheet(QLatin1String("font: 20pt \"Ubuntu\";\n"
"color: rgb(239, 41, 41);"));

        verticalLayout_17->addWidget(label_21);

        tableWidget_B = new QTableWidget(tab_4);
        if (tableWidget_B->columnCount() < 3)
            tableWidget_B->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_B->setHorizontalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_B->setHorizontalHeaderItem(1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_B->setHorizontalHeaderItem(2, __qtablewidgetitem41);
        tableWidget_B->setObjectName(QStringLiteral("tableWidget_B"));
        tableWidget_B->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_B->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_B->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_B->horizontalHeader()->setHighlightSections(false);
        tableWidget_B->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_17->addWidget(tableWidget_B);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_24->addWidget(label_22);

        label_buycar = new QLabel(tab_4);
        label_buycar->setObjectName(QStringLiteral("label_buycar"));

        horizontalLayout_24->addWidget(label_buycar);


        verticalLayout_17->addLayout(horizontalLayout_24);


        horizontalLayout_25->addLayout(verticalLayout_17);

        line_11 = new QFrame(tab_4);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        horizontalLayout_25->addWidget(line_11);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        line_3 = new QFrame(tab_4);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_23->addWidget(line_3);

        dateTimeEdit = new QDateTimeEdit(tab_4);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setMaximumDate(QDate(2018, 6, 10));
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_23->addWidget(dateTimeEdit);

        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAcceptDrops(false);
        label_19->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_23->addWidget(label_19);

        dateTimeEdit_2 = new QDateTimeEdit(tab_4);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setMaximumDateTime(QDateTime(QDate(2018, 12, 31), QTime(23, 59, 59)));
        dateTimeEdit_2->setMaximumDate(QDate(2018, 12, 31));
        dateTimeEdit_2->setCalendarPopup(true);

        horizontalLayout_23->addWidget(dateTimeEdit_2);

        QueryMoneyButton = new QPushButton(tab_4);
        QueryMoneyButton->setObjectName(QStringLiteral("QueryMoneyButton"));

        horizontalLayout_23->addWidget(QueryMoneyButton);


        verticalLayout_18->addLayout(horizontalLayout_23);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_19->addWidget(label_16);

        label_in = new QLabel(tab_4);
        label_in->setObjectName(QStringLiteral("label_in"));

        horizontalLayout_19->addWidget(label_in);


        horizontalLayout_22->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_20->addWidget(label_17);

        label_out = new QLabel(tab_4);
        label_out->setObjectName(QStringLiteral("label_out"));

        horizontalLayout_20->addWidget(label_out);


        horizontalLayout_22->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_21->addWidget(label_18);

        label_left = new QLabel(tab_4);
        label_left->setObjectName(QStringLiteral("label_left"));

        horizontalLayout_21->addWidget(label_left);


        horizontalLayout_22->addLayout(horizontalLayout_21);


        verticalLayout_18->addLayout(horizontalLayout_22);


        horizontalLayout_25->addLayout(verticalLayout_18);

        horizontalLayout_25->setStretch(0, 2);
        horizontalLayout_25->setStretch(2, 1);

        verticalLayout_19->addLayout(horizontalLayout_25);

        tabWidget->addTab(tab_4, QString());
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_12 = new QVBoxLayout(widget);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_11->addWidget(label_7);

        label_num = new QLabel(widget);
        label_num->setObjectName(QStringLiteral("label_num"));

        horizontalLayout_11->addWidget(label_num);


        verticalLayout_12->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(label_9);

        label_name = new QLabel(widget);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout_12->addWidget(label_name);


        verticalLayout_12->addLayout(horizontalLayout_12);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_26->addWidget(label_23);

        label_sex = new QLabel(widget);
        label_sex->setObjectName(QStringLiteral("label_sex"));

        horizontalLayout_26->addWidget(label_sex);


        verticalLayout_12->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_27->addWidget(label_24);

        label_age = new QLabel(widget);
        label_age->setObjectName(QStringLiteral("label_age"));

        horizontalLayout_27->addWidget(label_age);


        verticalLayout_12->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_28->addWidget(label_26);

        label_Ctime = new QLabel(widget);
        label_Ctime->setObjectName(QStringLiteral("label_Ctime"));

        horizontalLayout_28->addWidget(label_Ctime);


        verticalLayout_12->addLayout(horizontalLayout_28);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(label_10);

        label_Ide = new QLabel(widget);
        label_Ide->setObjectName(QStringLiteral("label_Ide"));

        horizontalLayout_13->addWidget(label_Ide);


        verticalLayout_12->addLayout(horizontalLayout_13);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        pushButton_info = new QPushButton(widget);
        pushButton_info->setObjectName(QStringLiteral("pushButton_info"));

        horizontalLayout_30->addWidget(pushButton_info);

        pushButton_pass = new QPushButton(widget);
        pushButton_pass->setObjectName(QStringLiteral("pushButton_pass"));

        horizontalLayout_30->addWidget(pushButton_pass);


        verticalLayout_12->addLayout(horizontalLayout_30);

        tabWidget->addTab(widget, QString());

        verticalLayout->addWidget(tabWidget);

        line_2 = new QFrame(SysLogin);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        SlashButton = new QPushButton(SysLogin);
        SlashButton->setObjectName(QStringLiteral("SlashButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SlashButton->sizePolicy().hasHeightForWidth());
        SlashButton->setSizePolicy(sizePolicy);
        SlashButton->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(SlashButton);

        ExitButton = new QPushButton(SysLogin);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        sizePolicy.setHeightForWidth(ExitButton->sizePolicy().hasHeightForWidth());
        ExitButton->setSizePolicy(sizePolicy);
        ExitButton->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(ExitButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(SysLogin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SysLogin);
    } // setupUi

    void retranslateUi(QDialog *SysLogin)
    {
        SysLogin->setWindowTitle(QApplication::translate("SysLogin", "\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SysLogin", "\345\223\201\347\211\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SysLogin", "\351\242\234\350\211\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SysLogin", "\350\264\255\345\205\245\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SysLogin", "\350\264\255\345\205\245\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SysLogin", "\346\211\200\351\234\200\346\212\274\351\207\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("SysLogin", "\347\247\237\351\207\221(/h)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("SysLogin", "\345\205\266\344\273\226", Q_NULLPTR));
        ACButton->setText(QApplication::translate("SysLogin", "\345\242\236\345\212\240\350\275\246\350\276\206", Q_NULLPTR));
        DCButton->setText(QApplication::translate("SysLogin", "\345\210\240\351\231\244\350\275\246\350\276\206", Q_NULLPTR));
        RCButton->setText(QApplication::translate("SysLogin", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("SysLogin", "\350\275\246\347\211\214\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("SysLogin", "C20140001", Q_NULLPTR));
        label_2->setText(QApplication::translate("SysLogin", "                              \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\350\275\246\350\276\206", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SysLogin", "\350\275\246\350\276\206\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("SysLogin", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("SysLogin", "\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("SysLogin", "\346\200\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("SysLogin", "\345\271\264\351\276\204", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("SysLogin", "\344\270\232\345\212\241\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("SysLogin", "\345\205\245\350\201\214\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("SysLogin", "\345\237\272\346\234\254\345\267\245\350\265\204", Q_NULLPTR));
        AWButton->setText(QApplication::translate("SysLogin", "\345\242\236\345\212\240", Q_NULLPTR));
        DWButton->setText(QApplication::translate("SysLogin", "\345\210\240\351\231\244", Q_NULLPTR));
        label_3->setText(QApplication::translate("SysLogin", "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("SysLogin", "W201414700", Q_NULLPTR));
        label_4->setText(QApplication::translate("SysLogin", "\351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\345\221\230\345\267\245", Q_NULLPTR));
        AddWageButton->setText(QApplication::translate("SysLogin", "\346\224\271\345\267\245\350\265\204", Q_NULLPTR));
        PrizeButton->setText(QApplication::translate("SysLogin", "\345\217\221\345\245\226\351\207\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SysLogin", "\345\221\230\345\267\245\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("SysLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("SysLogin", "\346\200\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("SysLogin", "\345\271\264\351\276\204", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("SysLogin", "\344\277\241\347\224\250\350\257\204\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("SysLogin", "\350\264\246\346\210\267\344\275\231\351\242\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("SysLogin", "\345\205\266\344\273\226", Q_NULLPTR));
        DUButton->setText(QApplication::translate("SysLogin", "\345\210\240\351\231\244\345\256\242\346\210\267", Q_NULLPTR));
        label_5->setText(QApplication::translate("SysLogin", "\345\256\242\346\210\267\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEdit_3->setPlaceholderText(QApplication::translate("SysLogin", "username", Q_NULLPTR));
        label_6->setText(QApplication::translate("SysLogin", "                              \351\273\230\350\256\244\346\223\215\344\275\234\347\232\204\346\230\257\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\345\256\242\346\210\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SysLogin", "\345\256\242\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("SysLogin", "\344\272\244\346\230\223\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("SysLogin", "\345\221\230\345\267\245\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QApplication::translate("SysLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem26->setText(QApplication::translate("SysLogin", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem27->setText(QApplication::translate("SysLogin", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->horizontalHeaderItem(6);
        ___qtablewidgetitem28->setText(QApplication::translate("SysLogin", "\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_4->horizontalHeaderItem(7);
        ___qtablewidgetitem29->setText(QApplication::translate("SysLogin", "\350\277\235\347\275\232\346\254\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_4->horizontalHeaderItem(8);
        ___qtablewidgetitem30->setText(QApplication::translate("SysLogin", "\346\200\273\350\264\271\347\224\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_4->horizontalHeaderItem(9);
        ___qtablewidgetitem31->setText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\344\275\277\347\224\250\347\212\266\345\206\265\350\257\204\345\256\232\347\273\223\346\236\234", Q_NULLPTR));
        radioButton->setText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\347\274\226\345\217\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("SysLogin", "\345\221\230\345\267\245\347\274\226\345\217\267", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("SysLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        lineEdit_4->setPlaceholderText(QApplication::translate("SysLogin", "\350\275\246\350\276\206\347\274\226\345\217\267/\345\221\230\345\267\245\347\274\226\345\217\267/\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("SysLogin", "\347\247\237\350\275\246\346\227\266\351\227\264\346\256\265", Q_NULLPTR));
        TimeEdit1->setDisplayFormat(QApplication::translate("SysLogin", "yyyy/M/d hh:mm:ss", Q_NULLPTR));
        label_8->setText(QApplication::translate("SysLogin", "\357\275\236", Q_NULLPTR));
        TimeEdit2->setDisplayFormat(QApplication::translate("SysLogin", "yyyy/M/d hh:mm:ss", Q_NULLPTR));
        RentOkButton->setText(QApplication::translate("SysLogin", "\346\237\245\350\257\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("SysLogin", "\347\247\237\350\275\246\344\277\241\346\201\257", Q_NULLPTR));
        label_11->setText(QApplication::translate("SysLogin", "\347\247\237\350\275\246\350\264\242\345\212\241\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_C->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("SysLogin", "\350\256\242\345\215\225\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_C->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("SysLogin", "\350\256\242\345\215\225\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_C->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("SysLogin", "\350\256\242\345\215\225\351\207\221\351\242\235", Q_NULLPTR));
        label_13->setText(QApplication::translate("SysLogin", "\350\256\242\345\215\225\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
        label_OrderCount->setText(QString());
        label_12->setText(QApplication::translate("SysLogin", "\350\256\242\345\215\225\346\200\273\351\242\235(\357\277\245)\357\274\232", Q_NULLPTR));
        label_OrderFee->setText(QString());
        label_14->setText(QApplication::translate("SysLogin", "\345\221\230\345\267\245\345\267\245\350\265\204\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_W->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("SysLogin", "\345\221\230\345\267\245\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_W->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("SysLogin", "\345\237\272\346\234\254\345\267\245\350\265\204", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_W->horizontalHeaderItem(2);
        ___qtablewidgetitem37->setText(QApplication::translate("SysLogin", "\345\245\226\351\207\221", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_W->horizontalHeaderItem(3);
        ___qtablewidgetitem38->setText(QApplication::translate("SysLogin", "\346\200\273\345\267\245\350\265\204", Q_NULLPTR));
        label_15->setText(QApplication::translate("SysLogin", "\345\267\245\350\265\204\346\200\273\351\242\235(\357\277\245)\357\274\232", Q_NULLPTR));
        label_WageAll->setText(QString());
        label_20->setText(QApplication::translate("SysLogin", "\345\245\226\351\207\221\346\200\273\351\242\235(\357\277\245)\357\274\232", Q_NULLPTR));
        label_PrizeAll->setText(QString());
        label_21->setText(QApplication::translate("SysLogin", "\350\264\255\350\275\246\350\264\271\347\224\250\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_B->horizontalHeaderItem(0);
        ___qtablewidgetitem39->setText(QApplication::translate("SysLogin", "\350\275\246\347\211\214\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_B->horizontalHeaderItem(1);
        ___qtablewidgetitem40->setText(QApplication::translate("SysLogin", "\350\264\255\345\205\245\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_B->horizontalHeaderItem(2);
        ___qtablewidgetitem41->setText(QApplication::translate("SysLogin", "\350\264\255\345\205\245\350\264\271\347\224\250", Q_NULLPTR));
        label_22->setText(QApplication::translate("SysLogin", "\350\264\271\347\224\250\346\200\273\351\242\235(\357\277\245)\357\274\232", Q_NULLPTR));
        label_buycar->setText(QString());
        label_19->setText(QApplication::translate("SysLogin", "\357\275\236", Q_NULLPTR));
        QueryMoneyButton->setText(QApplication::translate("SysLogin", "\346\237\245\350\257\242", Q_NULLPTR));
        label_16->setText(QApplication::translate("SysLogin", "\346\224\266\345\205\245\346\200\273\351\242\235(\357\277\245):", Q_NULLPTR));
        label_in->setText(QString());
        label_17->setText(QApplication::translate("SysLogin", "\346\224\257\345\207\272\346\200\273\351\242\235(\357\277\245):", Q_NULLPTR));
        label_out->setText(QString());
        label_18->setText(QApplication::translate("SysLogin", "\347\273\223\344\275\231(\357\277\245):", Q_NULLPTR));
        label_left->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("SysLogin", "\350\264\242\345\212\241\346\212\245\350\241\250", Q_NULLPTR));
        label_7->setText(QApplication::translate("SysLogin", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_num->setText(QString());
        label_9->setText(QApplication::translate("SysLogin", " \345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_name->setText(QString());
        label_23->setText(QApplication::translate("SysLogin", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_sex->setText(QString());
        label_24->setText(QApplication::translate("SysLogin", "\345\271\264\351\276\204:", Q_NULLPTR));
        label_age->setText(QString());
        label_26->setText(QApplication::translate("SysLogin", "\345\205\245\350\201\214\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_Ctime->setText(QString());
        label_10->setText(QApplication::translate("SysLogin", "\350\272\253\344\273\275\357\274\232", Q_NULLPTR));
        label_Ide->setText(QString());
        pushButton_info->setText(QApplication::translate("SysLogin", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_pass->setText(QApplication::translate("SysLogin", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("SysLogin", "\346\210\221\347\232\204\344\270\273\351\241\265", Q_NULLPTR));
        SlashButton->setText(QApplication::translate("SysLogin", "\345\210\267\346\226\260", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("SysLogin", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysLogin: public Ui_SysLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSLOGIN_H
