/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QListWidget *listWidget;
    QSlider *playCourseSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *totalLabel;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(726, 601);
        Widget->setMinimumSize(QSize(726, 0));
        Widget->setMaximumSize(QSize(726, 16777215));
        Widget->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton,QListWidget\n"
"{\n"
"	border:none;\n"
"	backgroud:transparent;\n"
"}\n"
"QPushButton\n"
"{\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(37, 219, 222);\n"
"}\n"
"QListWidget:item:selected\n"
"{\n"
"background-color:rgb(128,128,0);\n"
"}"));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 530, 471, 64));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setStyleSheet(QString::fromUtf8("icon: url(:/File.png);"));
        pushButton->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("icon:url(:/Cycle.png)"));
        pushButton_2->setCheckable(false);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8("icon: url(:/Last.png);"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        pushButton_4->setStyleSheet(QString::fromUtf8("icon:url(:/Pause.png)"));
        pushButton_4->setCheckable(false);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(32, 32));
        pushButton_5->setMaximumSize(QSize(32, 32));
        pushButton_5->setStyleSheet(QString::fromUtf8("icon:url(:/Next.png)"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(32, 32));
        pushButton_6->setMaximumSize(QSize(32, 32));
        pushButton_6->setAcceptDrops(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("icon:url(:/Random.png)"));
        pushButton_6->setCheckable(false);

        horizontalLayout->addWidget(pushButton_6);

        pushButton->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_3->raise();
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 10, 711, 451));
        listWidget->setMinimumSize(QSize(711, 0));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/backg.jpg);\n"
"color:red;"));
        listWidget->setProperty("showDropIndicator", QVariant(true));
        playCourseSlider = new QSlider(Widget);
        playCourseSlider->setObjectName("playCourseSlider");
        playCourseSlider->setGeometry(QRect(20, 510, 691, 21));
        playCourseSlider->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 480, 711, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        curLabel = new QLabel(layoutWidget);
        curLabel->setObjectName("curLabel");

        horizontalLayout_2->addWidget(curLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        totalLabel = new QLabel(layoutWidget);
        totalLabel->setObjectName("totalLabel");

        horizontalLayout_2->addWidget(totalLabel);

        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(490, 550, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 550, 31, 20));
        QWidget::setTabOrder(listWidget, playCourseSlider);
        QWidget::setTabOrder(playCourseSlider, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_4);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
#if QT_CONFIG(tooltip)
        widget->setToolTip(QCoreApplication::translate("Widget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("Widget", "\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("Widget", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_2->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        pushButton_2->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_3->setStatusTip(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(statustip)
        pushButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("Widget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_5->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("Widget", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_6->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        pushButton_6->setText(QString());
        curLabel->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        totalLabel->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        label->setText(QCoreApplication::translate("Widget", "37", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
