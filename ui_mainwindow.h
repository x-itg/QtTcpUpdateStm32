/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_13;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_19;
    QTextEdit *serEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *recChooseFile;
    QLineEdit *recFilePath;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *ListenButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_24;
    QLineEdit *hostIPNum;
    QLabel *label_20;
    QLineEdit *serPort;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ClientconnectServer;
    QPushButton *disClientconnectServer;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QPushButton *CannelUpdate;
    QFrame *line_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_21;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QLineEdit *serIPNum;
    QLabel *label_16;
    QLineEdit *serPortNum;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *GetNewFile;
    QPushButton *ChooseFile;
    QLineEdit *FilePath;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_18;
    QProgressBar *progressBar;
    QPushButton *UpdateCode;
    QLineEdit *recFilePath_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1580, 770);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 60, 150, 19));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(14);
        label_13->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 1571, 761));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_3 = new QFrame(horizontalLayoutWidget_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_19 = new QLabel(horizontalLayoutWidget_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(12);
        label_19->setFont(font1);

        verticalLayout_6->addWidget(label_19);

        serEdit = new QTextEdit(horizontalLayoutWidget_3);
        serEdit->setObjectName(QStringLiteral("serEdit"));
        serEdit->setEnabled(true);

        verticalLayout_6->addWidget(serEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        recChooseFile = new QPushButton(horizontalLayoutWidget_3);
        recChooseFile->setObjectName(QStringLiteral("recChooseFile"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(10);
        recChooseFile->setFont(font2);

        horizontalLayout_6->addWidget(recChooseFile);

        recFilePath = new QLineEdit(horizontalLayoutWidget_3);
        recFilePath->setObjectName(QStringLiteral("recFilePath"));
        recFilePath->setFont(font1);

        horizontalLayout_6->addWidget(recFilePath);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ListenButton = new QPushButton(horizontalLayoutWidget_3);
        ListenButton->setObjectName(QStringLiteral("ListenButton"));

        horizontalLayout_8->addWidget(ListenButton);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_24 = new QLabel(horizontalLayoutWidget_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        horizontalLayout->addWidget(label_24);

        hostIPNum = new QLineEdit(horizontalLayoutWidget_3);
        hostIPNum->setObjectName(QStringLiteral("hostIPNum"));
        hostIPNum->setEnabled(false);
        hostIPNum->setFont(font1);

        horizontalLayout->addWidget(hostIPNum);

        label_20 = new QLabel(horizontalLayoutWidget_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        horizontalLayout->addWidget(label_20);

        serPort = new QLineEdit(horizontalLayoutWidget_3);
        serPort->setObjectName(QStringLiteral("serPort"));
        serPort->setEnabled(true);
        serPort->setFont(font1);

        horizontalLayout->addWidget(serPort);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ClientconnectServer = new QPushButton(horizontalLayoutWidget_3);
        ClientconnectServer->setObjectName(QStringLiteral("ClientconnectServer"));
        ClientconnectServer->setFont(font1);

        verticalLayout_3->addWidget(ClientconnectServer);

        disClientconnectServer = new QPushButton(horizontalLayoutWidget_3);
        disClientconnectServer->setObjectName(QStringLiteral("disClientconnectServer"));
        disClientconnectServer->setEnabled(true);
        disClientconnectServer->setFont(font1);

        verticalLayout_3->addWidget(disClientconnectServer);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton = new QPushButton(horizontalLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(12);
        font3.setUnderline(false);
        pushButton->setFont(font3);

        verticalLayout_5->addWidget(pushButton);

        CannelUpdate = new QPushButton(horizontalLayoutWidget_3);
        CannelUpdate->setObjectName(QStringLiteral("CannelUpdate"));
        CannelUpdate->setFont(font3);

        verticalLayout_5->addWidget(CannelUpdate);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_6);

        line_5 = new QFrame(horizontalLayoutWidget_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_21 = new QLabel(horizontalLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        verticalLayout->addWidget(label_21);

        textEdit = new QTextEdit(horizontalLayoutWidget_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_17 = new QLabel(horizontalLayoutWidget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_3->addWidget(label_17);

        serIPNum = new QLineEdit(horizontalLayoutWidget_3);
        serIPNum->setObjectName(QStringLiteral("serIPNum"));
        serIPNum->setEnabled(true);
        serIPNum->setFont(font1);

        horizontalLayout_3->addWidget(serIPNum);

        label_16 = new QLabel(horizontalLayoutWidget_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_3->addWidget(label_16);

        serPortNum = new QLineEdit(horizontalLayoutWidget_3);
        serPortNum->setObjectName(QStringLiteral("serPortNum"));
        serPortNum->setEnabled(false);
        serPortNum->setFont(font1);

        horizontalLayout_3->addWidget(serPortNum);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        GetNewFile = new QPushButton(horizontalLayoutWidget_3);
        GetNewFile->setObjectName(QStringLiteral("GetNewFile"));
        GetNewFile->setFont(font2);

        horizontalLayout_2->addWidget(GetNewFile);

        ChooseFile = new QPushButton(horizontalLayoutWidget_3);
        ChooseFile->setObjectName(QStringLiteral("ChooseFile"));
        ChooseFile->setFont(font2);

        horizontalLayout_2->addWidget(ChooseFile);

        FilePath = new QLineEdit(horizontalLayoutWidget_3);
        FilePath->setObjectName(QStringLiteral("FilePath"));
        FilePath->setFont(font1);

        horizontalLayout_2->addWidget(FilePath);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_18 = new QLabel(horizontalLayoutWidget_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);

        horizontalLayout_7->addWidget(label_18);

        progressBar = new QProgressBar(horizontalLayoutWidget_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_7->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_7);

        UpdateCode = new QPushButton(horizontalLayoutWidget_3);
        UpdateCode->setObjectName(QStringLiteral("UpdateCode"));
        QFont font4;
        font4.setFamily(QStringLiteral("Agency FB"));
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setUnderline(true);
        font4.setWeight(50);
        UpdateCode->setFont(font4);

        verticalLayout->addWidget(UpdateCode);


        horizontalLayout_4->addLayout(verticalLayout);

        recFilePath_2 = new QLineEdit(centralWidget);
        recFilePath_2->setObjectName(QStringLiteral("recFilePath_2"));
        recFilePath_2->setGeometry(QRect(710, 740, 664, 24));
        recFilePath_2->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_13->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "Local interaction information:", 0));
        recChooseFile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\350\267\257\345\276\204\n"
"Save File Path", 0));
        recFilePath->setText(QApplication::translate("MainWindow", "D:/rec.bin", 0));
        ListenButton->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\347\233\221\345\220\254\n"
"Listen", 0));
        label_24->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260IP\345\234\260\345\235\200:\n"
"Host IP Address", 0));
        label_20->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\n"
"PORT:", 0));
        ClientconnectServer->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245TCP\346\234\215\345\212\241\345\231\250\n"
"Connect TCP Server", 0));
        disClientconnectServer->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200TCP\350\277\236\346\216\245\n"
"Disconnect TCP", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\345\215\207\347\272\247\346\250\241\345\274\217\n"
"Enter Bootloader", 0));
        CannelUpdate->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\345\215\207\347\272\247\346\250\241\345\274\217\n"
"ESC Bootloader", 0));
        label_21->setText(QApplication::translate("MainWindow", "Device interaction information:", 0));
        label_17->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207IP\345\234\260\345\235\200:\n"
"Device IP Address", 0));
        label_16->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\n"
"PORT:", 0));
        GetNewFile->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\234\200\346\226\260\346\226\207\344\273\266\n"
"Get New Bin File", 0));
        ChooseFile->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\n"
"File Choose", 0));
        FilePath->setText(QApplication::translate("MainWindow", "D:/5G_VER_D2AS.bin", 0));
        label_18->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\350\277\233\345\272\246\n"
"Upgrade Progress:", 0));
        UpdateCode->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\345\215\207\347\272\247\n"
"Confirm the upgrade", 0));
        recFilePath_2->setText(QApplication::translate("MainWindow", "D:/rec.bin", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
