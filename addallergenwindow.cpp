#include "addallergenwindow.h"
#include <iostream>
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
    std::cout << "hello!";

}

void AddAllergenWindow::on_pushButton_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();
    if(!text.compare("Enter Allergen Name")){
        Allergen allergen;
        allergen.addAllergen(text.toStdString());
    }
}

