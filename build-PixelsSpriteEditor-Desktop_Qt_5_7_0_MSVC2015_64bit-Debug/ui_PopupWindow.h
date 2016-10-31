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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PopupWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *popupLabel;

    void setupUi(QDialog *PopupWindow)
    {
        if (PopupWindow->objectName().isEmpty())
            PopupWindow->setObjectName(QStringLiteral("PopupWindow"));
        PopupWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(PopupWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        popupLabel = new QLabel(PopupWindow);
        popupLabel->setObjectName(QStringLiteral("popupLabel"));
        popupLabel->setGeometry(QRect(10, 10, 381, 221));

        retranslateUi(PopupWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), PopupWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PopupWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(PopupWindow);
    } // setupUi

    void retranslateUi(QDialog *PopupWindow)
    {
        PopupWindow->setWindowTitle(QApplication::translate("PopupWindow", "Dialog", 0));
        popupLabel->setText(QApplication::translate("PopupWindow", "This text can be changed depending on the popup.", 0));
    } // retranslateUi

};

namespace Ui {
    class PopupWindow: public Ui_PopupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWINDOW_H
