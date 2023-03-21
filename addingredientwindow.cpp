#include "addingredientwindow.h"
#include "./ui_addingredientwindow.h"
#include <QDebug>
#include <QIntValidator>
#include "ingredient.h"

addingredientwindow::addingredientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingredientwindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,10000, this) );
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
    QString text = ui->plainTextEdit->toPlainText();
    QString calories = ui->lineEdit->text();
    int calInt = calories.toInt();
    if((QString::compare(text, "Enter Ingredient Name", Qt::CaseInsensitive) != 0)){
        Ingredient *ing = new Ingredient(text.toStdString(), calInt);
        Ingredient::addIngredient(ing);
        emit ingredientsUpdated();
        qDebug("Hello!");

    }


    hide();

}

