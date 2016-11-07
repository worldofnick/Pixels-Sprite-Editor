/********************************************************************************
** Form generated from reading UI file 'Preview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_H
#define UI_PREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Preview
{
public:
    QPushButton *closeButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QSlider *fpsSliderPreview;
    QLabel *label;
    QLabel *previewLabel;

    void setupUi(QDialog *Preview)
    {
        if (Preview->objectName().isEmpty())
            Preview->setObjectName(QStringLiteral("Preview"));
        Preview->resize(569, 474);
        Preview->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.482, y1:0.4375, x2:0.488, y2:0.994318, stop:0 rgba(35, 37, 37, 255), stop:1 rgba(51, 53, 53, 255));\n"
"color: rgb(239, 239, 239);"));
        closeButton = new QPushButton(Preview);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(460, 430, 101, 31));
        closeButton->setStyleSheet(QLatin1String("#closeButton{\n"
"	border-radius: 8px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#closeButton:hover{\n"
"background-color: rgb(108, 108, 108);\n"
"}"));
        zoomInButton = new QPushButton(Preview);
        zoomInButton->setObjectName(QStringLiteral("zoomInButton"));
        zoomInButton->setGeometry(QRect(100, 400, 51, 51));
        zoomInButton->setStyleSheet(QLatin1String("#zoomInButton{\n"
"	border-radius: 2px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#zoomInButton:hover{\n"
"background-color: rgb(108, 108, 108);\n"
"}"));
        zoomOutButton = new QPushButton(Preview);
        zoomOutButton->setObjectName(QStringLiteral("zoomOutButton"));
        zoomOutButton->setGeometry(QRect(250, 400, 51, 51));
        zoomOutButton->setStyleSheet(QLatin1String("#zoomOutButton{\n"
"	border-radius: 2px;\n"
"	border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"#zoomOutButton:hover{\n"
"background-color: rgb(108, 108, 108);\n"
"}"));
        fpsSliderPreview = new QSlider(Preview);
        fpsSliderPreview->setObjectName(QStringLiteral("fpsSliderPreview"));
        fpsSliderPreview->setGeometry(QRect(390, 100, 160, 22));
        fpsSliderPreview->setMaximum(32);
        fpsSliderPreview->setOrientation(Qt::Horizontal);
        fpsSliderPreview->setTickPosition(QSlider::TicksBelow);
        label = new QLabel(Preview);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 80, 101, 16));
        previewLabel = new QLabel(Preview);
        previewLabel->setObjectName(QStringLiteral("previewLabel"));
        previewLabel->setGeometry(QRect(20, 20, 361, 361));

        retranslateUi(Preview);

        closeButton->setDefault(true);


        QMetaObject::connectSlotsByName(Preview);
    } // setupUi

    void retranslateUi(QDialog *Preview)
    {
        Preview->setWindowTitle(QApplication::translate("Preview", "Sprite Preview", 0));
        closeButton->setText(QApplication::translate("Preview", "Close", 0));
        zoomInButton->setText(QApplication::translate("Preview", "-", 0));
        zoomOutButton->setText(QApplication::translate("Preview", "+", 0));
        label->setText(QApplication::translate("Preview", "Preview Speed", 0));
        previewLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Preview: public Ui_Preview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_H
