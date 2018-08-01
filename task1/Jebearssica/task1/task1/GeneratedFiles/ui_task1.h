/********************************************************************************
** Form generated from reading UI file 'task1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_H
#define UI_TASK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task1Class
{
public:
    QWidget *centralWidget;
    QToolBox *toolBox;
    QWidget *Button1;
    QWidget *Button2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *task1Class)
    {
        if (task1Class->objectName().isEmpty())
            task1Class->setObjectName(QStringLiteral("task1Class"));
        task1Class->resize(600, 400);
        centralWidget = new QWidget(task1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 40, 85, 145));
        Button1 = new QWidget();
        Button1->setObjectName(QStringLiteral("Button1"));
        Button1->setGeometry(QRect(0, 0, 85, 85));
        toolBox->addItem(Button1, QStringLiteral("Page 1"));
        Button2 = new QWidget();
        Button2->setObjectName(QStringLiteral("Button2"));
        Button2->setGeometry(QRect(0, 0, 85, 85));
        toolBox->addItem(Button2, QStringLiteral("Page 2"));
        task1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(task1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        task1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(task1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        task1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(task1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        task1Class->setStatusBar(statusBar);

        retranslateUi(task1Class);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(task1Class);
    } // setupUi

    void retranslateUi(QMainWindow *task1Class)
    {
        task1Class->setWindowTitle(QApplication::translate("task1Class", "task1", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(Button1), QApplication::translate("task1Class", "Page 1", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(Button2), QApplication::translate("task1Class", "Page 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class task1Class: public Ui_task1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_H
