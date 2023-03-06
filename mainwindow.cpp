#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CookBook.cpp"
int counter = 0;
CookBook* cookbook = new CookBook();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QString::fromStdString(cookbook->chickenCurry->name));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    counter++;
    if (counter == 3){
        counter = 0;
    }

    ui->label->setText(QString::fromStdString(cookbook->recipies[counter]->name));

}


void MainWindow::on_pushButton_2_clicked()
{
    counter--;
    if (counter == -1){
        counter = 2;
    }

    ui->label->setText(QString::fromStdString(cookbook->recipies[counter]->name));

}

