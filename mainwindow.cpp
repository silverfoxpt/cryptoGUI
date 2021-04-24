#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BINARY_ENCRYPT.h"
#include <QMessageBox>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    std::string tmp = arg1.toUtf8().constData();

    std::string new2 = encryptBinary(tmp);
    QString qstr = QString::fromStdString(new2);
    ui->newLab->setText(qstr);
}
