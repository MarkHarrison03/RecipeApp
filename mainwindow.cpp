#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "addallergenwindow.h"
#include "addingredientwindow.h"
#include "createrecipewindow.h"
#include <sstream>
#include <vector>
#include "credits.h"
#include "allergen.h"
#include "global.h"
int counter = 0;
std::vector<Recipe*> listOfRecipies{};
bool baseRecipeRemoved = false;
void operator<<(Ui::MainWindow, Recipe*);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //blank recipe just to initialize vector;
    Ingredient* a = new Ingredient("Sample Ingredient", 0);
    QList<Ingredient*> ingList{a};
    Recipe* baseRecipe = new Recipe("Create a recipe to begin", "N/A", "N/A", 0, ingList, "N/A", false);
    listOfRecipies.push_back(baseRecipe);

    ui->setupUi(this);
    ui->gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
    ui->label_Ingredients->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum); //NB find out whatws happening here
//    ui->label_Ingredients->setWordWrap(true);
//    std::string str = "Ingredients: ";
//    for(const auto &piece : Ingredient::getListOfIngredients()){

//        str += piece->getName();
//        str += "\nCalories: ";
//        str += piece->getCalories();
//        str+= "\n";
//    }
//    ui->label_Ingredients->setText(QString::fromStdString( str ));
//    MainWindow::on_pushButton_clicked();
//    ui->label_steps->setText(QString::fromStdString(baseRecipe->steps));
       *ui << baseRecipe;
};

MainWindow::~MainWindow()
{
    delete ui;
}
void operator<< (Ui::MainWindow a, Recipe* b){
    a.titleLabel->setText(QString::fromStdString(b->name));
    a.AllergiesLabel->setText("Allergens : " + QString::fromStdString(b->allergens));

    std::string veggie = "";
    if(QString::number(b->isVegetarian()) == '1'){
        veggie = "Vegetarian";
    }else{
        veggie = "No Dietary Restriction";
    }
    a.DietLabel->setText("Dietary Restriction : " + QString::fromStdString(veggie));
    a.CategoryLabel->setText("Category : " + QString::fromStdString(b->category));
    a.TTCLabel->setText("Time to Cook (minutes) : " +QString::number(b->timeToCook));
    a.CaloriesLabel->setText("Calories :"  + QString::number(b->getCalories())); //overridden virtual function
    std::string ingList;
    for(Ingredient* i : b->listOfIngredients){
        ingList += i->getName();
        ingList += "\nCalories: ";
        ingList += std::to_string(i->getCalories()); //this getCalories is a virtual function that is overrideen by its derived class 5 lines up
        ingList += "\n\n";
    }

    a.label_Ingredients->setText("Ingredients: \n" + QString::fromStdString(ingList));
    a.label_steps->setText("Steps:\n " + QString::fromStdString(b->steps));

}

void MainWindow::on_pushButton_clicked()
{
    counter++;
    if (counter >= listOfRecipies.size()){
        qDebug() << "Pushbutton2 counter:" << counter;

        counter = 0;
    }
    Recipe* currentRecipe = listOfRecipies.at(counter);
    *ui << currentRecipe;
//    ui->titleLabel->setText(QString::fromStdString(currentRecipe->name));
//    ui->AllergiesLabel->setText("Allergens : " + QString::fromStdString(currentRecipe->allergens));
//    ui->DietLabel->setText("Dietary Restriction : " + QString::fromStdString(currentRecipe->isVegetarian()));
//    ui->CategoryLabel->setText("Category : " + QString::fromStdString(currentRecipe->category));
//    ui->TTCLabel->setText("Time to Cook (minutes) : " +QString::number(currentRecipe->timeToCook));
//    ui->CaloriesLabel->setText("Calories :"  + QString::number(currentRecipe->calories));
//    std::string a;
//    QList<Ingredient*> list = currentRecipe->listOfIngredients;
//    a << list;
//    ui->label_Ingredients->setText(currentRecipe->listOfIngredients);


}

//void MainWindow::updateAllergens(){

//        std::string str;
//        for(const auto &piece : allergen.getAllergens()){
//            str += piece;
//        }
//        ui->label_Ingredients->setText(QString::fromStdString( str ));

//}
std::vector<Recipe*> MainWindow::getListOfRecipies(){
    return listOfRecipies;
}



void MainWindow::updateRecipies(Recipe* a){
    if(baseRecipeRemoved == false){
        listOfRecipies.erase(listOfRecipies.begin());
        baseRecipeRemoved = true;
    }
    qDebug() << "YOOOOY!";
    listOfRecipies.push_back(a);
    qDebug() << QString::fromStdString(listOfRecipies.at(0)->name);
}
//void MainWindow::updateIngredients(){

//    std::stringstream ss;
//    std::string str;
//    for( auto &piece : Ingredient::getListOfIngredients()){
//        ss << "Name: " << piece->getName() << "\n" << "Calories:" << piece->getCalories() << "\n";
//        if(piece->isVegetarian() == 1){
//        ss << "Is vegetarian? Yes" "\n\n";
//        }else{
//            ss << "Is vegetarian? No" "\n\n";

//        }
//    }
//    str = ss.str();
//    ui->label_Ingredients->setText(QString::fromStdString(str));
//}
void MainWindow::on_pushButton_2_clicked()
{
    counter--;
    if (counter <= -1){
        counter = listOfRecipies.size() - 1;

        qDebug() << "Pushbutton2 counter:" << counter;
    }
    Recipe* currentRecipe = listOfRecipies.at(counter);
    *ui << currentRecipe;
    /*ui->titleLabel->setText(QString::fromStdString(currentRecipe->name));
    ui->AllergiesLabel->setText("Allergens : " + QString::fromStdString(currentRecipe->allergens));
    ui->DietLabel->setText("Dietary Restriction : " + QString::fromStdString(currentRecipe->isVegetarian()));
    ui->CategoryLabel->setText("Category : " + QString::fromStdString(currentRecipe->category));
    ui->TTCLabel->setText("Time to Cook (minutes) : " +QString::number(currentRecipe->timeToCook));
    ui->CaloriesLabel->setText("Calories :"  + QString::number(currentRecipe->calories));*/


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




void MainWindow::on_actionCredits_triggered()
{
    Credits *a = new Credits;
    a->show();

}

