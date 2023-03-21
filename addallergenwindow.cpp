#include "addallergenwindow.h"
#include <iostream>
#include <QDebug>
#include <QString>
#include "allergen.h"
#include "./ui_addallergenwindow.h"

AddAllergenWindow::AddAllergenWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAllergenWindow)
{
    ui->setupUi(this);
}

AddAllergenWindow::~AddAllergenWindow()
{
    delete ui;
}

void AddAllergenWindow::show_window(){

    show();

}

void AddAllergenWindow::on_pushButton_clicked()
{

    QString text = ui->plainTextEdit->toPlainText();

    if((QString::compare(text, "Enter Allergen Name", Qt::CaseInsensitive) != 0)){
        Allergen allergen;
        allergen.addAllergen(text.toStdString());
        emit allergensUpdated();
        qDebug("Hello!");

    }


    hide();
}

