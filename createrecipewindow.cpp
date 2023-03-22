#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "ingredient.h"
#include <QDebug>
CreateRecipeWindow::CreateRecipeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRecipeWindow)
{
    ui->setupUi(this);
    Ingredient a;
    QWidget *container = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout(container);
    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);

    for(Ingredient* piece : Ingredient::getListOfIngredients()){
        qDebug() << QString::fromStdString(piece->getName());
        QCheckBox* checkBox = new QCheckBox(QString::fromStdString(piece->getName()));
        layout->addWidget(checkBox);
    }

}

CreateRecipeWindow::~CreateRecipeWindow(){};


void CreateRecipeWindow::show_window(){
    show();
}
