/********************************************************************************
** Form generated from reading UI file 'StampSelector.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAMPSELECTOR_H
#define UI_STAMPSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StampSelector
{
public:
    QPushButton *selectButton;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QRadioButton *sunButton;
    QRadioButton *marioButton;
    QLabel *label_3;
    QRadioButton *cloudButton;
    QLabel *label_4;

    void setupUi(QDialog *StampSelector)
    {
        if (StampSelector->objectName().isEmpty())
            StampSelector->setObjectName(QStringLiteral("StampSelector"));
        StampSelector->resize(334, 440);
        StampSelector->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.482, y1:0.4375, x2:0.488, y2:0.994318, stop:0 rgba(35, 37, 37, 255), stop:1 rgba(51, 53, 53, 255));\n"
"color: rgb(239, 239, 239);"));
        selectButton = new QPushButton(StampSelector);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(60, 380, 100, 51));
        selectButton->setStyleSheet(QLatin1String("#selectButton{\n"
"	border-radius: 8px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#selectButton:hover{	\n"
"	background-color: rgb(181, 183, 183);\n"
"}"));
        label = new QLabel(StampSelector);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 51, 31));
        gridLayoutWidget = new QWidget(StampSelector);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 151, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(64, 64));
        label_2->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        sunButton = new QRadioButton(gridLayoutWidget);
        sunButton->setObjectName(QStringLiteral("sunButton"));
        sunButton->setChecked(false);

        gridLayout->addWidget(sunButton, 1, 0, 1, 1);

        marioButton = new QRadioButton(gridLayoutWidget);
        marioButton->setObjectName(QStringLiteral("marioButton"));
        marioButton->setChecked(true);

        gridLayout->addWidget(marioButton, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(64, 64));
        label_3->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        cloudButton = new QRadioButton(gridLayoutWidget);
        cloudButton->setObjectName(QStringLiteral("cloudButton"));
        cloudButton->setChecked(false);

        gridLayout->addWidget(cloudButton, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(64, 64));
        label_4->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_4, 2, 1, 1, 1);


        retranslateUi(StampSelector);

        QMetaObject::connectSlotsByName(StampSelector);
    } // setupUi

    void retranslateUi(QDialog *StampSelector)
    {
        StampSelector->setWindowTitle(QApplication::translate("StampSelector", "Dialog", 0));
        selectButton->setText(QApplication::translate("StampSelector", "SELECT", 0));
        label->setText(QApplication::translate("StampSelector", "Stamps:", 0));
        label_2->setText(QApplication::translate("StampSelector", "Mario", 0));
        sunButton->setText(QString());
        marioButton->setText(QString());
        label_3->setText(QApplication::translate("StampSelector", "Sun", 0));
        cloudButton->setText(QString());
        label_4->setText(QApplication::translate("StampSelector", "Cloud", 0));
    } // retranslateUi

};

namespace Ui {
    class StampSelector: public Ui_StampSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAMPSELECTOR_H
