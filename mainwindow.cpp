#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QLabel>
#include <QStackedWidget>
#include <QMessageBox>
#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QObject>
#include <QTextEdit>
#include <QTextBrowser>
#include <QString>

#include <UTILITY_FUNCTIONS.h>
#include <MD5_HASH_MAIN.h>

char md5Help[50] = "MD5_HELP.txt";
char md5History[50] = "MD5_HISTORY.txt";

QComboBox *comboBoxType;
QComboBox *comboBoxName;

QTextEdit *inputField;
QTextBrowser *outputField;

bool firstTry = true;
std::map<std::string, int> encType;
std::map<std::string, int> hashType;

string curType = "Hash";
string curName = "MD5";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //QWidget *startMenu = ui->stackedWidget->findChild<QWidget *>("startMenu");
    encType["Hash"] = 1;
    encType["Translate"] = 2;

    hashType["MD5"] = 1;
    hashType["SHA-1"] = 2;

    inputField = ui->stackedWidget->findChild<QTextEdit *>("inputBox", Qt::FindChildrenRecursively);
    outputField = ui->stackedWidget->findChild<QTextBrowser *>("outputBox", Qt::FindChildrenRecursively);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    comboBoxName = ui->stackedWidget->findChild<QComboBox *>("nameComboBox", Qt::FindChildrenRecursively);
    comboBoxType = ui->stackedWidget->findChild<QComboBox *>("typeComboBox", Qt::FindChildrenRecursively);
    comboBoxType->addItem("Hash");
    comboBoxType->addItem("Translate");
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
    comboBoxType->clear();
    comboBoxName->clear();
}

void MainWindow::on_typeComboBox_currentTextChanged(const QString &arg1)
{
    //QMessageBox::warning(this, "Quit application", "Quit?", QMessageBox::Yes|QMessageBox::No);
    string txt = qStrToStr(arg1); curType = txt;
    //cerr << txt;
    switch(encType[txt])
    {
        case 1:
        {
            //cerr << txt;
            comboBoxName->addItem("MD5");
            comboBoxName->addItem("SHA-1");
            break;
        }
        default: comboBoxName->addItem("None");
    }
}

void MainWindow::on_nameComboBox_currentTextChanged(const QString &arg1)
{
    string txt = qStrToStr(arg1); curName = txt;
    //inputField->disconnect();
    switch(encType[curType])
    {
        case 1:
        {
            switch(hashType[txt])
            {
                case 1: outputField->setText(strToQStr(md5(qStrToStr(inputField->toPlainText())))); break;
                case 2: outputField->setText("Not implemented"); break;
                default: cerr << "ERROR";
            }
        }
    }
}

void MainWindow::on_inputBox_textChanged()
{
    outputField->setText(strToQStr(md5(qStrToStr(inputField->toPlainText()))));
}

void MainWindow::on_HelpButton_clicked()
{
    switch(encType[curType])
    {
        case 1:
        {
            switch(hashType[curName])
            {
                case 1:
                {
                    string x = textFileToStr(md5Help);
                    QMessageBox::information(this, "MD5 Help", strToQStr(x), QMessageBox::Ok);
                }
                break;
                case 2: outputField->setText("Not implemented"); break;
                default: cerr << "ERROR";
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    switch(encType[curType])
    {
        case 1:
        {
            switch(hashType[curName])
            {
                case 1:
                {
                    string x = textFileToStr(md5History);
                    QMessageBox::information(this, "MD5 History", strToQStr(x), QMessageBox::Ok);
                }
                break;
                case 2: outputField->setText("Not implemented"); break;
                default: cerr << "ERROR";
            }
        }
    }
}
