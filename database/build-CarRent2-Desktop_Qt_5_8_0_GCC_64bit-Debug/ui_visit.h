/********************************************************************************
** Form generated from reading UI file 'visit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISIT_H
#define UI_VISIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Visit
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BackButton;
    QPushButton *SlashButton;

    void setupUi(QDialog *Visit)
    {
        if (Visit->objectName().isEmpty())
            Visit->setObjectName(QStringLiteral("Visit"));
        Visit->resize(400, 300);
        verticalLayout = new QVBoxLayout(Visit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(Visit);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setColumnCount(8);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BackButton = new QPushButton(Visit);
        BackButton->setObjectName(QStringLiteral("BackButton"));

        horizontalLayout->addWidget(BackButton);

        SlashButton = new QPushButton(Visit);
        SlashButton->setObjectName(QStringLiteral("SlashButton"));

        horizontalLayout->addWidget(SlashButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Visit);

        QMetaObject::connectSlotsByName(Visit);
    } // setupUi

    void retranslateUi(QDialog *Visit)
    {
        Visit->setWindowTitle(QApplication::translate("Visit", "\346\270\270\345\256\242\346\250\241\345\274\217", Q_NULLPTR));
        BackButton->setText(QApplication::translate("Visit", "\350\277\224\345\233\236", Q_NULLPTR));
        SlashButton->setText(QApplication::translate("Visit", "\345\210\267\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Visit: public Ui_Visit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISIT_H
