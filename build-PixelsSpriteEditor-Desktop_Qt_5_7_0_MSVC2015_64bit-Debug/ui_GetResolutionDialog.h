/********************************************************************************
** Form generated from reading UI file 'GetResolutionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETRESOLUTIONDIALOG_H
#define UI_GETRESOLUTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GetResolutionDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *widthInputBox;
    QLineEdit *heightInputBox;
    QPushButton *okButton;
    QLabel *label_6;
    QPushButton *transparentBackgroundButton;
    QPushButton *whiteBackgroundButton;
    QPushButton *blackBackgroundButton;

    void setupUi(QDialog *GetResolutionDialog)
    {
        if (GetResolutionDialog->objectName().isEmpty())
            GetResolutionDialog->setObjectName(QStringLiteral("GetResolutionDialog"));
        GetResolutionDialog->resize(339, 255);
        GetResolutionDialog->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.482, y1:0.4375, x2:0.488, y2:0.994318, stop:0 rgba(35, 37, 37, 255), stop:1 rgba(51, 53, 53, 255));\n"
"color: rgb(239, 239, 239);"));
        label = new QLabel(GetResolutionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 321, 16));
        label_2 = new QLabel(GetResolutionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 80, 16, 16));
        label_3 = new QLabel(GetResolutionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 80, 60, 16));
        label_4 = new QLabel(GetResolutionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 41, 16));
        label_5 = new QLabel(GetResolutionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 60, 60, 16));
        widthInputBox = new QLineEdit(GetResolutionDialog);
        widthInputBox->setObjectName(QStringLiteral("widthInputBox"));
        widthInputBox->setGeometry(QRect(10, 80, 41, 21));
        heightInputBox = new QLineEdit(GetResolutionDialog);
        heightInputBox->setObjectName(QStringLiteral("heightInputBox"));
        heightInputBox->setGeometry(QRect(90, 80, 41, 21));
        heightInputBox->setReadOnly(true);
        okButton = new QPushButton(GetResolutionDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(230, 210, 71, 32));
        okButton->setStyleSheet(QLatin1String("#okButton{\n"
"	border-radius: 8px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#okButton:hover{	\n"
"	background-color: rgb(108, 108, 108);\n"
"}"));
        label_6 = new QLabel(GetResolutionDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 121, 16));
        transparentBackgroundButton = new QPushButton(GetResolutionDialog);
        transparentBackgroundButton->setObjectName(QStringLiteral("transparentBackgroundButton"));
        transparentBackgroundButton->setGeometry(QRect(10, 160, 61, 32));
        transparentBackgroundButton->setCheckable(true);
        transparentBackgroundButton->setChecked(true);
        whiteBackgroundButton = new QPushButton(GetResolutionDialog);
        whiteBackgroundButton->setObjectName(QStringLiteral("whiteBackgroundButton"));
        whiteBackgroundButton->setGeometry(QRect(90, 160, 61, 32));
        whiteBackgroundButton->setCheckable(true);
        blackBackgroundButton = new QPushButton(GetResolutionDialog);
        blackBackgroundButton->setObjectName(QStringLiteral("blackBackgroundButton"));
        blackBackgroundButton->setGeometry(QRect(170, 160, 61, 32));
        blackBackgroundButton->setCheckable(true);

        retranslateUi(GetResolutionDialog);

        QMetaObject::connectSlotsByName(GetResolutionDialog);
    } // setupUi

    void retranslateUi(QDialog *GetResolutionDialog)
    {
        GetResolutionDialog->setWindowTitle(QApplication::translate("GetResolutionDialog", "Welcome to the Pixels Sprite Editor", 0));
        label->setText(QApplication::translate("GetResolutionDialog", "Please enter your desired resolution for this project:", 0));
        label_2->setText(QApplication::translate("GetResolutionDialog", "X", 0));
        label_3->setText(QApplication::translate("GetResolutionDialog", "pixels", 0));
        label_4->setText(QApplication::translate("GetResolutionDialog", "Width", 0));
        label_5->setText(QApplication::translate("GetResolutionDialog", "Height", 0));
        widthInputBox->setText(QString());
        widthInputBox->setPlaceholderText(QApplication::translate("GetResolutionDialog", "128", 0));
        heightInputBox->setPlaceholderText(QApplication::translate("GetResolutionDialog", "128", 0));
        okButton->setText(QApplication::translate("GetResolutionDialog", "OK", 0));
        label_6->setText(QApplication::translate("GetResolutionDialog", "Background Color:", 0));
        transparentBackgroundButton->setText(QApplication::translate("GetResolutionDialog", "Transparent", 0));
        whiteBackgroundButton->setText(QApplication::translate("GetResolutionDialog", "White", 0));
        blackBackgroundButton->setText(QApplication::translate("GetResolutionDialog", "Black", 0));
    } // retranslateUi

};

namespace Ui {
    class GetResolutionDialog: public Ui_GetResolutionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETRESOLUTIONDIALOG_H
