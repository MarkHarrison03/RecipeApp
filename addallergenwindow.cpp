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

        bool vegetarian;
        if(ui->comboBox->currentText() == "Vegetarian"){
            vegetarian = true;
        }else{
            vegetarian = false;
        }
        Allergen *newAllergen = new Allergen(text.toStdString(), vegetarian);
        Allergen::addAllergen(newAllergen);
        emit allergensUpdated();
        qDebug("Hello!");

    }


    hide();
}

