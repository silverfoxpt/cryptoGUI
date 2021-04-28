#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BINARY_ENCRYPT.h"
#include <QMessageBox>
#include <QLabel>
#include <QStackedWidget>
#include <QMessageBox>
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



void MainWindow::on_Start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Quit application", "Quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}
