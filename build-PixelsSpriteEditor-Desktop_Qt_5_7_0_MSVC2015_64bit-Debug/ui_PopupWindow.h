/********************************************************************************
** Form generated from reading UI file 'PopupWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPWINDOW_H
#define UI_POPUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PopupWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *popupLabel;
    QPushButton *okButton;

    void setupUi(QDialog *PopupWindow)
    {
        if (PopupWindow->objectName().isEmpty())
            PopupWindow->setObjectName(QStringLiteral("PopupWindow"));
        PopupWindow->resize(414, 306);
        PopupWindow->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.482, y1:0.4375, x2:0.488, y2:0.994318, stop:0 rgba(35, 37, 37, 255), stop:1 rgba(51, 53, 53, 255));\n"
"color: rgb(239, 239, 239);"));
        gridLayout = new QGridLayout(PopupWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        popupLabel = new QLabel(PopupWindow);
        popupLabel->setObjectName(QStringLiteral("popupLabel"));
        popupLabel->setEnabled(true);
        popupLabel->setMinimumSize(QSize(390, 250));

        gridLayout->addWidget(popupLabel, 0, 0, 1, 1);

        okButton = new QPushButton(PopupWindow);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMinimumSize(QSize(100, 30));
        okButton->setMaximumSize(QSize(100, 30));
        okButton->setLayoutDirection(Qt::RightToLeft);
        okButton->setStyleSheet(QLatin1String("#okButton{\n"
"	border-radius: 8px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#okButton:hover{	\n"
"	background-color: rgb(108, 108, 108);\n"
"}"));

        gridLayout->addWidget(okButton, 2, 0, 1, 1);


        retranslateUi(PopupWindow);

        QMetaObject::connectSlotsByName(PopupWindow);
    } // setupUi

    void retranslateUi(QDialog *PopupWindow)
    {
        PopupWindow->setWindowTitle(QApplication::translate("PopupWindow", "Dialog", 0));
        popupLabel->setText(QApplication::translate("PopupWindow", "This text can be changed depending on the popup.", 0));
        okButton->setText(QApplication::translate("PopupWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class PopupWindow: public Ui_PopupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWINDOW_H
