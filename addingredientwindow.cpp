#include "addingredientwindow.h"
#include "./ui_addingredientwindow.h"
#include <QDebug>
#include <QIntValidator>
#include "allergen.h"
#include "ingredient.h"
#include <QButtonGroup>
using namespace staticAllergens;

addingredientwindow::addingredientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingredientwindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,10000, this) );
    ui->plainTextEdit->setFixedHeight(35);
    QWidget* central = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(central);



}


void addingredientwindow::show_window(){
    qDebug() << "UP!";
    show();
}

addingredientwindow::~addingredientwindow()
{
    delete ui;
}

void addingredientwindow::on_pushButton_clicked()
{

    bool vegetarian;
    if(ui->radioButton->isChecked()){
        vegetarian = false;
    }else if(ui->radioButton_2->isChecked()){
        vegetarian = true;
    }

    QString text = ui->plainTextEdit->toPlainText();
    QString calories = ui->lineEdit->text();
    int calInt = calories.toInt();
    if((QString::compare(text, "Enter Ingredient Name", Qt::CaseInsensitive) != 0)){
        Ingredient *ing = new Ingredient(text.toStdString(), calInt);
        Ingredient::addIngredient(ing);
        ing->setIsVegetarian(vegetarian);
        emit ingredientsUpdated();
        qDebug("Hello!");

    }


    hide();

}

