/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *playB;
    QPushButton *pauseB;
    QPushButton *stopB;
    QPushButton *muteB;
    QPushButton *openB;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *memoryBar;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QProgressBar *progress;
    QSlider *volumeBar;
    QListWidget *songsLIst;
    QListWidget *artistList;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(745, 440);
        playB = new QPushButton(Widget);
        playB->setObjectName(QString::fromUtf8("playB"));
        playB->setGeometry(QRect(550, 330, 89, 25));
        pauseB = new QPushButton(Widget);
        pauseB->setObjectName(QString::fromUtf8("pauseB"));
        pauseB->setGeometry(QRect(650, 330, 89, 25));
        stopB = new QPushButton(Widget);
        stopB->setObjectName(QString::fromUtf8("stopB"));
        stopB->setGeometry(QRect(550, 360, 89, 25));
        muteB = new QPushButton(Widget);
        muteB->setObjectName(QString::fromUtf8("muteB"));
        muteB->setGeometry(QRect(650, 360, 89, 25));
        openB = new QPushButton(Widget);
        openB->setObjectName(QString::fromUtf8("openB"));
        openB->setGeometry(QRect(20, 20, 89, 25));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 10, 261, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Uroob"));
        font.setPointSize(32);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(560, 390, 168, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        memoryBar = new QProgressBar(layoutWidget);
        memoryBar->setObjectName(QString::fromUtf8("memoryBar"));
        memoryBar->setValue(0);

        horizontalLayout->addWidget(memoryBar);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 370, 521, 48));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        progress = new QProgressBar(layoutWidget1);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(0);

        verticalLayout->addWidget(progress);

        volumeBar = new QSlider(layoutWidget1);
        volumeBar->setObjectName(QString::fromUtf8("volumeBar"));
        volumeBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(volumeBar);

        songsLIst = new QListWidget(Widget);
        songsLIst->setObjectName(QString::fromUtf8("songsLIst"));
        songsLIst->setGeometry(QRect(150, 50, 581, 271));
        artistList = new QListWidget(Widget);
        artistList->setObjectName(QString::fromUtf8("artistList"));
        artistList->setGeometry(QRect(10, 50, 121, 301));
        QWidget::setTabOrder(playB, pauseB);
        QWidget::setTabOrder(pauseB, stopB);
        QWidget::setTabOrder(stopB, openB);
        QWidget::setTabOrder(openB, muteB);
        QWidget::setTabOrder(muteB, volumeBar);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "ODYSSEY RADIO", nullptr));
        playB->setText(QCoreApplication::translate("Widget", "PLAY", nullptr));
        pauseB->setText(QCoreApplication::translate("Widget", "PAUSE", nullptr));
        stopB->setText(QCoreApplication::translate("Widget", "STOP", nullptr));
        muteB->setText(QCoreApplication::translate("Widget", "MUTE", nullptr));
        openB->setText(QCoreApplication::translate("Widget", "OPEN", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "ODYSSEY RADIO", nullptr));
        label->setText(QCoreApplication::translate("Widget", "MEMORY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
