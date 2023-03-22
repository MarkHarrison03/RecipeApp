#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "CookBook.cpp"
#include "addallergenwindow.h"
#include "addingredientwindow.h"
#include "createrecipewindow.h"
#include <sstream>

int counter = 0;
Allergen allergen;
CookBook* cookbook = new CookBook();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->label_Ingredient->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum); //NB find out whatws happening here
    ui->label_Ingredient->setWordWrap(true);
    ui->titleLabel->setText(QString::fromStdString(cookbook->chickenCurry->name));
    ui->CaloriesLabel->setText("Calories :"  +QString::number(cookbook->chickenCurry->calories));
    std::string str;
    for(const auto &piece : allergen.getAllergens()){
        str += piece;
    }
    ui->label_Ingredients->setText(QString::fromStdString( str ));

};

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

    ui->titleLabel->setText(QString::fromStdString(cookbook->recipies[counter]->name));
    ui->CaloriesLabel->setText("Calories :"  + QString::number(cookbook->recipies[counter]->calories));


}
void MainWindow::updateAllergens(){

        std::string str;
        for(const auto &piece : allergen.getAllergens()){
            str += piece;
        }
        ui->label_Ingredients->setText(QString::fromStdString( str ));

}
void MainWindow::updateIngredients(){

    std::stringstream ss;
    std::string str;
    for( auto &piece : Ingredient::getListOfIngredients()){
        ss << "Name: " << piece->getName() << "\n" << "Calories:" << piece->getCalories() << "\n";
        if(piece->isVegetarian() == 1){
        ss << "Is vegetarian? Yes" "\n\n";
        }else{
            ss << "Is vegetarian? No" "\n\n";

        }
    }
    str = ss.str();
    ui->label_Ingredient->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_2_clicked()
{
    counter--;
    if (counter == -1){
        counter = 2;
    }

    ui->titleLabel->setText(QString::fromStdString(cookbook->recipies[counter]->name));
    ui->CaloriesLabel->setText("Calories :"  +QString::number(cookbook->recipies[counter]->calories));


}


void MainWindow::on_actionAllergen_triggered()
{
        AddAllergenWindow* windowAllergen = new AddAllergenWindow;
        connect(windowAllergen, SIGNAL(allergensUpdated()), this, SLOT(updateAllergens()));
        windowAllergen->show_window();
        qDebug() <<"TYo!";




}


void MainWindow::on_actionIngredient_triggered()
{
    addingredientwindow* windowIng = new addingredientwindow;
    connect(windowIng, SIGNAL(ingredientsUpdated()), this, SLOT(updateIngredients()));
    windowIng->show_window();
    qDebug()<<"HEY!";

}


void MainWindow::on_actionRecipe_triggered()
{
    CreateRecipeWindow* a = new CreateRecipeWindow;
    a->show_window();
}

