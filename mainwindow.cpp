#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "CookBook.cpp"
#include "addallergenwindow.h"
#include "addingredientwindow.h"
#include "createrecipewindow.h"
#include <sstream>
#include <vector>
std::vector<Recipe*> listOfRecipies;
int counter = 0;
Allergen allergen;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //blank recipe just to initialize vector;
    Ingredient* a = new Ingredient("Sample Ingredient", 400);
    QList<Ingredient*> ingList{a};
    Recipe* baseRecipe = new Recipe("Create a recipe to begin", "N/A", "N/A", 0, 0, ingList, "N/A", false);
    listOfRecipies.push_back(baseRecipe);

    ui->setupUi(this);
    ui->gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->label_Ingredient->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum); //NB find out whatws happening here
    ui->label_Ingredient->setWordWrap(true);
    std::string str;
    for(const auto &piece : allergen.getAllergens()){
        str += piece;
    }
    ui->label_Ingredients->setText(QString::fromStdString( str ));
    MainWindow::on_pushButton_clicked();

};

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    counter++;
    if (counter >= listOfRecipies.size()){
        qDebug() << "Pushbutton2 counter:" << counter;

        counter = 0;
    }
    Recipe* currentRecipe = listOfRecipies.at(counter);
    ui->titleLabel->setText(QString::fromStdString(currentRecipe->name));
    ui->AllergiesLabel->setText("Allergens : " + QString::fromStdString(currentRecipe->allergens));
    ui->DietLabel->setText("Dietary Restriction : " + QString::fromStdString(currentRecipe->isVegetarian()));
    ui->CategoryLabel->setText("Category : " + QString::fromStdString(currentRecipe->category));
    ui->TTCLabel->setText("Time to Cook (minutes) : " +QString::number(currentRecipe->timeToCook));
    ui->CaloriesLabel->setText("Calories :"  + QString::number(currentRecipe->calories));



}

void MainWindow::updateAllergens(){

        std::string str;
        for(const auto &piece : allergen.getAllergens()){
            str += piece;
        }
        ui->label_Ingredients->setText(QString::fromStdString( str ));

}
void MainWindow::updateRecipies(Recipe* a){
    qDebug() << "YOOOOY!";
    listOfRecipies.push_back(a);
    qDebug() << QString::fromStdString(listOfRecipies.at(0)->name);
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
    if (counter <= -1){
        counter = listOfRecipies.size() - 1;

        qDebug() << "Pushbutton2 counter:" << counter;
    }
    Recipe* currentRecipe = listOfRecipies.at(counter);
    ui->titleLabel->setText(QString::fromStdString(currentRecipe->name));
    ui->CaloriesLabel->setText("Calories :"  +QString::number(currentRecipe->calories));


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
    connect(a, SIGNAL(recipeAdded(Recipe*)), this, SLOT(updateRecipies(Recipe*)));

    a->show_window();
}

