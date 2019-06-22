#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>
#include <QFileDialog>
#include <QFileDevice>
#include <QFile>
#include <QMessageBox>
#include <QtEvents>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QList>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_selExeFileBtn_clicked();
    void on_cmdOutPut();
    void on_readerror();
    void on_openPakgDirBtn_clicked();

private:
    Ui::Dialog* ui;
    QProcess* initMkpakg;
    QString* fileName;
};

#endif // DIALOG_H
