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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StampSelector
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *stampBackFrame;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *stampScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *marioLabel;
    QLabel *sunLabel;
    QLabel *cloudLabel;
    QLabel *cowboyLabel;
    QLabel *squirtleLabel;
    QLabel *pokeballLabel;
    QLabel *ashLabel;
    QLabel *swordLabel;
    QLabel *pikachuLabel;
    QLabel *sunglassesLabel;

    void setupUi(QDialog *StampSelector)
    {
        if (StampSelector->objectName().isEmpty())
            StampSelector->setObjectName(QStringLiteral("StampSelector"));
        StampSelector->resize(160, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StampSelector->sizePolicy().hasHeightForWidth());
        StampSelector->setSizePolicy(sizePolicy);
        StampSelector->setMinimumSize(QSize(160, 500));
        StampSelector->setMaximumSize(QSize(160, 2000));
        StampSelector->setStyleSheet(QLatin1String("#StampSelector {\n"
"background-color: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(StampSelector);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stampBackFrame = new QFrame(StampSelector);
        stampBackFrame->setObjectName(QStringLiteral("stampBackFrame"));
        sizePolicy.setHeightForWidth(stampBackFrame->sizePolicy().hasHeightForWidth());
        stampBackFrame->setSizePolicy(sizePolicy);
        stampBackFrame->setMinimumSize(QSize(136, 476));
        stampBackFrame->setMaximumSize(QSize(136, 2000));
        stampBackFrame->setStyleSheet(QLatin1String("#stampBackFrame {\n"
"background-color: rgb(50, 51, 54, 170);\n"
"border: 0px solid rgb(252, 252, 252);\n"
"border-radius: 20px;\n"
"}"));
        stampBackFrame->setFrameShape(QFrame::StyledPanel);
        stampBackFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(stampBackFrame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stampScrollArea = new QScrollArea(stampBackFrame);
        stampScrollArea->setObjectName(QStringLiteral("stampScrollArea"));
        sizePolicy.setHeightForWidth(stampScrollArea->sizePolicy().hasHeightForWidth());
        stampScrollArea->setSizePolicy(sizePolicy);
        stampScrollArea->setMinimumSize(QSize(136, 576));
        stampScrollArea->setMaximumSize(QSize(136, 2000));
        stampScrollArea->setStyleSheet(QLatin1String("#stampScrollArea {\n"
"background-color: transparent;\n"
"}"));
        stampScrollArea->setFrameShape(QFrame::NoFrame);
        stampScrollArea->setFrameShadow(QFrame::Plain);
        stampScrollArea->setLineWidth(0);
        stampScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stampScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stampScrollArea->setWidgetResizable(true);
        stampScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 136, 1006));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("#scrollAreaWidgetContents {\n"
"background-color: transparent;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        marioLabel = new QLabel(scrollAreaWidgetContents);
        marioLabel->setObjectName(QStringLiteral("marioLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(marioLabel->sizePolicy().hasHeightForWidth());
        marioLabel->setSizePolicy(sizePolicy1);
        marioLabel->setMinimumSize(QSize(90, 90));
        marioLabel->setMaximumSize(QSize(90, 90));
        marioLabel->setStyleSheet(QLatin1String("#marioLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#marioLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));
        marioLabel->setFrameShape(QFrame::NoFrame);
        marioLabel->setLineWidth(0);
        marioLabel->setScaledContents(true);
        marioLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(marioLabel);

        sunLabel = new QLabel(scrollAreaWidgetContents);
        sunLabel->setObjectName(QStringLiteral("sunLabel"));
        sizePolicy1.setHeightForWidth(sunLabel->sizePolicy().hasHeightForWidth());
        sunLabel->setSizePolicy(sizePolicy1);
        sunLabel->setMinimumSize(QSize(90, 90));
        sunLabel->setMaximumSize(QSize(90, 90));
        sunLabel->setStyleSheet(QLatin1String("#sunLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"}\n"
"#sunLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"}"));
        sunLabel->setFrameShape(QFrame::NoFrame);
        sunLabel->setLineWidth(0);
        sunLabel->setScaledContents(true);
        sunLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(sunLabel);

        cloudLabel = new QLabel(scrollAreaWidgetContents);
        cloudLabel->setObjectName(QStringLiteral("cloudLabel"));
        sizePolicy1.setHeightForWidth(cloudLabel->sizePolicy().hasHeightForWidth());
        cloudLabel->setSizePolicy(sizePolicy1);
        cloudLabel->setMinimumSize(QSize(90, 90));
        cloudLabel->setMaximumSize(QSize(90, 90));
        cloudLabel->setStyleSheet(QLatin1String("#cloudLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"}\n"
"#cloudLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"}"));
        cloudLabel->setFrameShape(QFrame::NoFrame);
        cloudLabel->setLineWidth(0);
        cloudLabel->setScaledContents(true);
        cloudLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(cloudLabel);

        cowboyLabel = new QLabel(scrollAreaWidgetContents);
        cowboyLabel->setObjectName(QStringLiteral("cowboyLabel"));
        cowboyLabel->setMinimumSize(QSize(90, 90));
        cowboyLabel->setMaximumSize(QSize(90, 90));
        cowboyLabel->setStyleSheet(QLatin1String("#cowboyLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"}\n"
"#cowboyLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"}"));

        verticalLayout_2->addWidget(cowboyLabel);

        squirtleLabel = new QLabel(scrollAreaWidgetContents);
        squirtleLabel->setObjectName(QStringLiteral("squirtleLabel"));
        squirtleLabel->setMinimumSize(QSize(90, 90));
        squirtleLabel->setMaximumSize(QSize(90, 90));
        squirtleLabel->setStyleSheet(QLatin1String("#squirtleLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"}\n"
"#squirtleLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"}"));

        verticalLayout_2->addWidget(squirtleLabel);

        pokeballLabel = new QLabel(scrollAreaWidgetContents);
        pokeballLabel->setObjectName(QStringLiteral("pokeballLabel"));
        sizePolicy1.setHeightForWidth(pokeballLabel->sizePolicy().hasHeightForWidth());
        pokeballLabel->setSizePolicy(sizePolicy1);
        pokeballLabel->setMinimumSize(QSize(90, 90));
        pokeballLabel->setMaximumSize(QSize(90, 90));
        pokeballLabel->setStyleSheet(QLatin1String("#pokeballLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#pokeballLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));
        pokeballLabel->setFrameShape(QFrame::NoFrame);
        pokeballLabel->setLineWidth(0);
        pokeballLabel->setScaledContents(true);
        pokeballLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(pokeballLabel);

        ashLabel = new QLabel(scrollAreaWidgetContents);
        ashLabel->setObjectName(QStringLiteral("ashLabel"));
        ashLabel->setMinimumSize(QSize(90, 90));
        ashLabel->setMaximumSize(QSize(90, 90));
        ashLabel->setStyleSheet(QLatin1String("#ashLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#ashLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));

        verticalLayout_2->addWidget(ashLabel);

        swordLabel = new QLabel(scrollAreaWidgetContents);
        swordLabel->setObjectName(QStringLiteral("swordLabel"));
        sizePolicy1.setHeightForWidth(swordLabel->sizePolicy().hasHeightForWidth());
        swordLabel->setSizePolicy(sizePolicy1);
        swordLabel->setMinimumSize(QSize(90, 90));
        swordLabel->setMaximumSize(QSize(90, 90));
        swordLabel->setStyleSheet(QLatin1String("#swordLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#swordLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));
        swordLabel->setFrameShape(QFrame::NoFrame);
        swordLabel->setLineWidth(0);
        swordLabel->setScaledContents(true);
        swordLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(swordLabel);

        pikachuLabel = new QLabel(scrollAreaWidgetContents);
        pikachuLabel->setObjectName(QStringLiteral("pikachuLabel"));
        pikachuLabel->setMinimumSize(QSize(90, 90));
        pikachuLabel->setMaximumSize(QSize(90, 90));
        pikachuLabel->setStyleSheet(QLatin1String("#pikachuLabel {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#pikachuLabel:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));

        verticalLayout_2->addWidget(pikachuLabel);

        sunglassesLabel = new QLabel(scrollAreaWidgetContents);
        sunglassesLabel->setObjectName(QStringLiteral("sunglassesLabel"));
        sizePolicy1.setHeightForWidth(sunglassesLabel->sizePolicy().hasHeightForWidth());
        sunglassesLabel->setSizePolicy(sizePolicy1);
        sunglassesLabel->setMinimumSize(QSize(90, 90));
        sunglassesLabel->setMaximumSize(QSize(90, 90));
        sunglassesLabel->setStyleSheet(QLatin1String("#marioLabel_4 {\n"
"background-color: rgb(54,58,62,30);\n"
"border-radius: 10px;\n"
"background-repeat: none;\n"
"margin: 6px;\n"
"padding: 10px;\n"
"}\n"
"#marioLabel_4:hover\n"
"{\n"
"background-color: rgb(54,58,62,50);\n"
"border-radius: 10px;\n"
"border-top: -15px transparent;\n"
"border-bottom: -15px transparent;\n"
"border-right: -15px transparent;\n"
"border-left: -15px transparent;\n"
"margin: 2px;\n"
"padding: 0px;\n"
"}"));
        sunglassesLabel->setFrameShape(QFrame::NoFrame);
        sunglassesLabel->setLineWidth(0);
        sunglassesLabel->setScaledContents(true);
        sunglassesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(sunglassesLabel);

        stampScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(stampScrollArea);


        verticalLayout->addWidget(stampBackFrame);


        retranslateUi(StampSelector);

        QMetaObject::connectSlotsByName(StampSelector);
    } // setupUi

    void retranslateUi(QDialog *StampSelector)
    {
        StampSelector->setWindowTitle(QApplication::translate("StampSelector", "Dialog", 0));
        marioLabel->setText(QApplication::translate("StampSelector", "Mario", 0));
        sunLabel->setText(QApplication::translate("StampSelector", "Sun", 0));
        cloudLabel->setText(QApplication::translate("StampSelector", "Cloud", 0));
        cowboyLabel->setText(QApplication::translate("StampSelector", "Cowboy", 0));
        squirtleLabel->setText(QApplication::translate("StampSelector", "Squirtle", 0));
        pokeballLabel->setText(QApplication::translate("StampSelector", "Pokeball", 0));
        ashLabel->setText(QApplication::translate("StampSelector", "Ash", 0));
        swordLabel->setText(QApplication::translate("StampSelector", "Sword", 0));
        pikachuLabel->setText(QApplication::translate("StampSelector", "Pikachu", 0));
        sunglassesLabel->setText(QApplication::translate("StampSelector", "Sunglasses", 0));
    } // retranslateUi

};

namespace Ui {
    class StampSelector: public Ui_StampSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAMPSELECTOR_H
