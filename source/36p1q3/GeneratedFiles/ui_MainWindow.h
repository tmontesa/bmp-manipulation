/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "widgetcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *btnQuit;
    QPushButton *btnFile;
    QLabel *lblFilename;
    QPushButton *btnEffectRed;
    QPushButton *btnEffectBlue;
    QPushButton *btnEffectGreen;
    QPushButton *btnEffectBright;
    QPushButton *btnEffectGreyscale;
    QPushButton *btnEffectDither;
    QLabel *lblInfo;
    QPushButton *btnEffectRGB;
    WidgetCanvas *Canvas;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(491, 542);
        MainWindowClass->setMinimumSize(QSize(491, 541));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnQuit = new QPushButton(centralWidget);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setGeometry(QRect(430, 10, 51, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        btnQuit->setFont(font);
        btnQuit->setLayoutDirection(Qt::RightToLeft);
        btnFile = new QPushButton(centralWidget);
        btnFile->setObjectName(QStringLiteral("btnFile"));
        btnFile->setGeometry(QRect(310, 10, 51, 31));
        btnFile->setFont(font);
        btnFile->setFlat(false);
        lblFilename = new QLabel(centralWidget);
        lblFilename->setObjectName(QStringLiteral("lblFilename"));
        lblFilename->setGeometry(QRect(10, 10, 291, 16));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        lblFilename->setFont(font1);
        lblFilename->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        btnEffectRed = new QPushButton(centralWidget);
        btnEffectRed->setObjectName(QStringLiteral("btnEffectRed"));
        btnEffectRed->setGeometry(QRect(10, 50, 71, 23));
        btnEffectBlue = new QPushButton(centralWidget);
        btnEffectBlue->setObjectName(QStringLiteral("btnEffectBlue"));
        btnEffectBlue->setGeometry(QRect(170, 50, 71, 23));
        btnEffectGreen = new QPushButton(centralWidget);
        btnEffectGreen->setObjectName(QStringLiteral("btnEffectGreen"));
        btnEffectGreen->setGeometry(QRect(90, 50, 71, 23));
        btnEffectBright = new QPushButton(centralWidget);
        btnEffectBright->setObjectName(QStringLiteral("btnEffectBright"));
        btnEffectBright->setGeometry(QRect(250, 50, 71, 23));
        btnEffectGreyscale = new QPushButton(centralWidget);
        btnEffectGreyscale->setObjectName(QStringLiteral("btnEffectGreyscale"));
        btnEffectGreyscale->setGeometry(QRect(330, 50, 71, 23));
        btnEffectDither = new QPushButton(centralWidget);
        btnEffectDither->setObjectName(QStringLiteral("btnEffectDither"));
        btnEffectDither->setGeometry(QRect(410, 50, 71, 23));
        lblInfo = new QLabel(centralWidget);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(10, 20, 291, 21));
        lblInfo->setLayoutDirection(Qt::LeftToRight);
        lblInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnEffectRGB = new QPushButton(centralWidget);
        btnEffectRGB->setObjectName(QStringLiteral("btnEffectRGB"));
        btnEffectRGB->setGeometry(QRect(370, 10, 51, 31));
        btnEffectRGB->setFont(font);
        btnEffectRGB->setFlat(false);
        Canvas = new WidgetCanvas(centralWidget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(10, 80, 2048, 2048));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);
        Canvas->setMinimumSize(QSize(0, 0));
        Canvas->setMaximumSize(QSize(2048, 2048));
        MainWindowClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(btnQuit, btnEffectRed);
        QWidget::setTabOrder(btnEffectRed, btnEffectBlue);
        QWidget::setTabOrder(btnEffectBlue, btnEffectGreen);
        QWidget::setTabOrder(btnEffectGreen, btnEffectBright);
        QWidget::setTabOrder(btnEffectBright, btnEffectGreyscale);
        QWidget::setTabOrder(btnEffectGreyscale, btnEffectDither);
        QWidget::setTabOrder(btnEffectDither, btnEffectRGB);
        QWidget::setTabOrder(btnEffectRGB, btnFile);

        retranslateUi(MainWindowClass);
        QObject::connect(btnQuit, SIGNAL(released()), MainWindowClass, SLOT(close()));
        QObject::connect(btnFile, SIGNAL(released()), MainWindowClass, SLOT(GetFile()));
        QObject::connect(MainWindowClass, SIGNAL(OpenFile(QString)), lblFilename, SLOT(setText(QString)));
        QObject::connect(MainWindowClass, SIGNAL(PassInfo(QString)), lblInfo, SLOT(setText(QString)));
        QObject::connect(MainWindowClass, SIGNAL(StreamPixels(QString,int,int)), Canvas, SLOT(GetPixelstream(QString,int,int)));
        QObject::connect(btnEffectRed, SIGNAL(released()), Canvas, SLOT(SetEffectRed()));
        QObject::connect(btnEffectRGB, SIGNAL(released()), Canvas, SLOT(SetEffectRGB()));
        QObject::connect(btnEffectGreen, SIGNAL(released()), Canvas, SLOT(SetEffectGreen()));
        QObject::connect(btnEffectBlue, SIGNAL(released()), Canvas, SLOT(SetEffectBlue()));
        QObject::connect(btnEffectGreyscale, SIGNAL(released()), Canvas, SLOT(SetEffectGreyscale()));
        QObject::connect(btnEffectBright, SIGNAL(released()), Canvas, SLOT(SetEffectBright()));
        QObject::connect(btnEffectDither, SIGNAL(released()), Canvas, SLOT(SetEffectDither()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "365 Project 1 Task 3 (tmontesa)", nullptr));
        btnQuit->setText(QApplication::translate("MainWindowClass", "Quit", nullptr));
        btnFile->setText(QApplication::translate("MainWindowClass", "File", nullptr));
        lblFilename->setText(QApplication::translate("MainWindowClass", "No file selected.", nullptr));
        btnEffectRed->setText(QApplication::translate("MainWindowClass", "Red", nullptr));
        btnEffectBlue->setText(QApplication::translate("MainWindowClass", "Blue", nullptr));
        btnEffectGreen->setText(QApplication::translate("MainWindowClass", "Green", nullptr));
        btnEffectBright->setText(QApplication::translate("MainWindowClass", "1.5x Bright", nullptr));
        btnEffectGreyscale->setText(QApplication::translate("MainWindowClass", "Greyscale", nullptr));
        btnEffectDither->setText(QApplication::translate("MainWindowClass", "Dither", nullptr));
        lblInfo->setText(QApplication::translate("MainWindowClass", "0 x 0 image (0-bit)", nullptr));
        btnEffectRGB->setText(QApplication::translate("MainWindowClass", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
