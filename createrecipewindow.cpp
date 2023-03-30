#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "ingredient.h"
#include "IncorrectInputException.h"
#include "global.h"
#include <QValidator>
#include "recipe.h"
#include "allergen.h"
//advanced preprocessor directive
#ifndef TTCLIMIT
#define TTCLimit 9
#endif

using namespace staticAllergens;
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
    std::string categories[5] = {"Breakfast", "Lunch", "Dinner","Snack", "Dessert"};

    for(int i = 0; i < 5; i++){
    //arrays and array pointer arithmetic
    ui->Category->addItem(QString::fromStdString(*(categories + i)));

}
    for(Ingredient* piece : Ingredient::getListOfIngredients()){
        QCheckBox* checkBox = new QCheckBox(QString::fromStdString(piece->getName()));
        layout->addWidget(checkBox);
    }
    QWidget *containerAllergens = new QWidget;
    QVBoxLayout * layoutAllergens = new QVBoxLayout(containerAllergens);
    ui->scrollArea_2->setWidget(containerAllergens);
    ui->scrollArea_2->setWidgetResizable(true);

    for(Allergen* a : Allergen::getListOfAllergens()){


        QCheckBox* checkBoxAllergen = new QCheckBox(QString::fromStdString(a->getName()));
        layoutAllergens->addWidget(checkBoxAllergen);
    }

}

CreateRecipeWindow::~CreateRecipeWindow(){};


void CreateRecipeWindow::show_window(){
    show();

}
void CreateRecipeWindow::on_pushButton_clicked()
{
    QString stringName(ui->Name->toPlainText());
    std::string name = stringName.toStdString();
   try{
        if(stringName.compare("Enter Recipe Name") == 0){
            throw IncorrectInputException();
        }
    }catch(IncorrectInputException e){

    }
    QString steps(ui->Steps->toPlainText());
    std::string stepsString = steps.toStdString();
    QString TTC(ui->TimeToCookLabel->text());
    struct s{
    unsigned int TTCBitStruct : TTCLimit;
    };
    //bitstruct to ensure that
    //ttc cant exceed 512
    s structTTC;

    structTTC.TTCBitStruct = TTC.toInt();

    QList<Ingredient *> ingredients;
    QList<QCheckBox *> checkboxes = ui->scrollArea->findChildren<QCheckBox *>();

    for(QCheckBox * box : checkboxes){
        if(box->isChecked()){
            std::string ingName = box->text().toStdString();
            for(Ingredient * a : Ingredient::getListOfIngredients()){
                if(a->getName() == ingName){
                    ingredients.append(a);
                }
            }
        }
    }

    QString listOfAllergensString = "";
    QList<QCheckBox *>   checkboxAllergen = ui->scrollArea_2->findChildren<QCheckBox *>();
    for(QCheckBox * box: checkboxAllergen){
        if(box->isChecked()){
            listOfAllergensString += box->text();
            listOfAllergensString += " ";
        }
    }
    QString restriction = ui->Restrictions->currentText();
    bool vegetarian = false;
    if(restriction.compare("Vegetarian")){
        vegetarian = true;
    }
    std::string category = ui->Category->currentText().toStdString();

    Recipe* newRecipe = new Recipe(name, category, stepsString, structTTC.TTCBitStruct, ingredients, listOfAllergensString.toStdString(), vegetarian);
   listOfRecipies.push_back(newRecipe);
    emit recipeAdded(newRecipe);
    hide();
}


void CreateRecipeWindow::on_TimeToCook_sliderMoved(int position)
{
    QString num = QString::number(ui->TimeToCook->value()) ;
    ui->TimeToCookLabel->setText(num);
}

void CreateRecipeWindow::setUi(Recipe* a){
    ui->Name->setText(QString::fromStdString(a->getName()));
    ui->Steps->setPlainText(QString::fromStdString(a->getSteps()));

}


