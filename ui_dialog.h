/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *cmdOutptEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *pakFileNameBox;
    QPushButton *selExeFileBtn;
    QPushButton *openPakgDirBtn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(490, 160);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 471, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cmdOutptEdit = new QPlainTextEdit(gridLayoutWidget);
        cmdOutptEdit->setObjectName(QString::fromUtf8("cmdOutptEdit"));
        cmdOutptEdit->setReadOnly(true);

        gridLayout->addWidget(cmdOutptEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pakFileNameBox = new QLineEdit(gridLayoutWidget);
        pakFileNameBox->setObjectName(QString::fromUtf8("pakFileNameBox"));

        horizontalLayout->addWidget(pakFileNameBox);

        selExeFileBtn = new QPushButton(gridLayoutWidget);
        selExeFileBtn->setObjectName(QString::fromUtf8("selExeFileBtn"));

        horizontalLayout->addWidget(selExeFileBtn);

        openPakgDirBtn = new QPushButton(gridLayoutWidget);
        openPakgDirBtn->setObjectName(QString::fromUtf8("openPakgDirBtn"));
        openPakgDirBtn->setEnabled(false);

        horizontalLayout->addWidget(openPakgDirBtn);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "V.C.\346\211\223\345\214\205\345\267\245\345\205\267", nullptr));
        selExeFileBtn->setText(QApplication::translate("Dialog", "\346\211\223\345\214\205\357\274\201", nullptr));
        openPakgDirBtn->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
