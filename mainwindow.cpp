#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BINARY_ENCRYPT.h"
#include <QMessageBox>
#include <QLabel>
#include <QStackedWidget>
#include <QMessageBox>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
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

void MainWindow::on_BackStartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
