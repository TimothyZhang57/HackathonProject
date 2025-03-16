/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QComboBox *KeyboardLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QComboBox *Resolution;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *Username;
    QLabel *label_6;
    QRadioButton *Hardware;
    QRadioButton *Simulated;
    QLineEdit *Password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 0, 241, 41));
        KeyboardLayout = new QComboBox(centralwidget);
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->addItem(QString());
        KeyboardLayout->setObjectName("KeyboardLayout");
        KeyboardLayout->setGeometry(QRect(120, 120, 241, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 110, 101, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 230, 80, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 150, 71, 41));
        Resolution = new QComboBox(centralwidget);
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->setObjectName("Resolution");
        Resolution->setGeometry(QRect(120, 160, 241, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 40, 101, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 70, 71, 41));
        Username = new QLineEdit(centralwidget);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(120, 50, 113, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 180, 71, 41));
        Hardware = new QRadioButton(centralwidget);
        Hardware->setObjectName("Hardware");
        Hardware->setGeometry(QRect(120, 190, 91, 22));
        Simulated = new QRadioButton(centralwidget);
        Simulated->setObjectName("Simulated");
        Simulated->setGeometry(QRect(230, 190, 91, 22));
        Password = new QLineEdit(centralwidget);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(120, 80, 113, 24));
        Password->setEchoMode(QLineEdit::EchoMode::Password);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Raspberry Pi QNX Quick Setup Wizard", nullptr));
        KeyboardLayout->setItemText(0, QCoreApplication::translate("MainWindow", "Czech", nullptr));
        KeyboardLayout->setItemText(1, QCoreApplication::translate("MainWindow", "Danish", nullptr));
        KeyboardLayout->setItemText(2, QCoreApplication::translate("MainWindow", "German", nullptr));
        KeyboardLayout->setItemText(3, QCoreApplication::translate("MainWindow", "English (Canadian)", nullptr));
        KeyboardLayout->setItemText(4, QCoreApplication::translate("MainWindow", "English (Canadian) (Dvorak)", nullptr));
        KeyboardLayout->setItemText(5, QCoreApplication::translate("MainWindow", "English (British)", nullptr));
        KeyboardLayout->setItemText(6, QCoreApplication::translate("MainWindow", "English (United States)", nullptr));
        KeyboardLayout->setItemText(7, QCoreApplication::translate("MainWindow", "English (United States) (Dvoark)", nullptr));
        KeyboardLayout->setItemText(8, QCoreApplication::translate("MainWindow", "Spanish", nullptr));
        KeyboardLayout->setItemText(9, QCoreApplication::translate("MainWindow", "French (Belgian)", nullptr));
        KeyboardLayout->setItemText(10, QCoreApplication::translate("MainWindow", "French (Canadian)", nullptr));
        KeyboardLayout->setItemText(11, QCoreApplication::translate("MainWindow", "French (Swiss)", nullptr));
        KeyboardLayout->setItemText(12, QCoreApplication::translate("MainWindow", "French (France)", nullptr));
        KeyboardLayout->setItemText(13, QCoreApplication::translate("MainWindow", "Croatian", nullptr));
        KeyboardLayout->setItemText(14, QCoreApplication::translate("MainWindow", "Italian", nullptr));
        KeyboardLayout->setItemText(15, QCoreApplication::translate("MainWindow", "Japanese", nullptr));
        KeyboardLayout->setItemText(16, QCoreApplication::translate("MainWindow", "Dutch", nullptr));
        KeyboardLayout->setItemText(17, QCoreApplication::translate("MainWindow", "Norwegian", nullptr));
        KeyboardLayout->setItemText(18, QCoreApplication::translate("MainWindow", "Polish", nullptr));
        KeyboardLayout->setItemText(19, QCoreApplication::translate("MainWindow", "Portuguese", nullptr));
        KeyboardLayout->setItemText(20, QCoreApplication::translate("MainWindow", "Northern Sami", nullptr));
        KeyboardLayout->setItemText(21, QCoreApplication::translate("MainWindow", "Slovak", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Keyboard Layout", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
        Resolution->setItemText(0, QCoreApplication::translate("MainWindow", "640x480", nullptr));
        Resolution->setItemText(1, QCoreApplication::translate("MainWindow", "1024x768", nullptr));
        Resolution->setItemText(2, QCoreApplication::translate("MainWindow", "1280x720", nullptr));
        Resolution->setItemText(3, QCoreApplication::translate("MainWindow", "1280x1024", nullptr));
        Resolution->setItemText(4, QCoreApplication::translate("MainWindow", "1440x900", nullptr));
        Resolution->setItemText(5, QCoreApplication::translate("MainWindow", "1600x1200", nullptr));
        Resolution->setItemText(6, QCoreApplication::translate("MainWindow", "1920x1080", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        Hardware->setText(QCoreApplication::translate("MainWindow", "Hardware", nullptr));
        Simulated->setText(QCoreApplication::translate("MainWindow", "Simulated", nullptr));
        Password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
