#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete fileName;
    delete ui;
}

void Dialog::on_selExeFileBtn_clicked()
{
    //选择.exe文件
    fileName = new QString(QFileDialog::getOpenFileName(this, "请选择要打包项目的exe文件",
                                                        "", "exe可执行文件(*.exe)"));

    if (*fileName == "") return;

    ui->pakFileNameBox->clear();
    ui->pakFileNameBox->setText(*fileName);

    // QString initMkPakgCmd("C:\\Windows\\System32\\cmd.exe /A /Q /K D:\\Qt\5.12.3\\mingw73_32\\bin\\qtenv2.bat");
    QString cmd(QString("windeployqt ") + *fileName);

    ui->openPakgDirBtn->setEnabled(false);

    //    if (QFileInfo::exists(initMkPakgCmd))
    //    {
    initMkpakg = new QProcess(this);

    connect(initMkpakg , SIGNAL(readyReadStandardOutput()) , this, SLOT(on_cmdOutPut()));
    connect(initMkpakg , SIGNAL(readyReadStandardError()) , this, SLOT(on_readerror()));

    //initMkpakg->start(initMkPakgCmd);
    initMkpakg->start(cmd);
    //    }
}

void Dialog::on_cmdOutPut()
{
    initMkpakg->waitForStarted();
    initMkpakg->waitForFinished();
    ui->cmdOutptEdit->clear();
    ui->cmdOutptEdit->appendPlainText(initMkpakg->readAllStandardOutput().data());
    ui->openPakgDirBtn->setEnabled(true);
    QMessageBox::information(this, "提示", "打包完成！！！", QMessageBox::Ok, QMessageBox::NoButton);
}

void Dialog::on_readerror()
{
    initMkpakg->waitForStarted();
    initMkpakg->waitForFinished();
    ui->cmdOutptEdit->clear();

    if (strncmp(initMkpakg->readAllStandardError().data(),"",  static_cast<size_t>(initMkpakg->readAllStandardError().count())))
    {
        ui->cmdOutptEdit->appendPlainText(initMkpakg->readAllStandardError().data());
        ui->openPakgDirBtn->setEnabled(true);
        QMessageBox::warning(this, "提示", "打包失败！！！", QMessageBox::Ok, QMessageBox::NoButton);
    }
}

void Dialog::on_openPakgDirBtn_clicked()
{
    if (QFileInfo::exists(*fileName))
    {
        QDir dir(*fileName);
        dir.cdUp();
        QString dirPath = dir.path();
        QDesktopServices::openUrl(QUrl(dirPath, QUrl::TolerantMode));
        ui->openPakgDirBtn->setEnabled(true);
    }
}
