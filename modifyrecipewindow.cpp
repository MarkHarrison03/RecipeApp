#include "modifyrecipewindow.h"
#include "ui_modifyrecipewindow.h"
#include "allergen.h"
#include "IncorrectInputException.h"
#include <algorithm>
#ifndef TTCLimit
#define TTCLimit 9
#endif
ModifyRecipeWindow::ModifyRecipeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyRecipeWindow)
{
    ui->setupUi(this);

}

ModifyRecipeWindow::~ModifyRecipeWindow()
{
    delete ui;
}


void ModifyRecipeWindow::setup(Recipe* a){
    show();
    ui->Name->setText(QString::fromStdString(a->getName()));
    ui->Category->setCurrentText(QString::fromStdString(a->getCategory()));
    ui->Steps->setPlainText(QString::fromStdString(a->getSteps()));

    QWidget *container = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout(container);

    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);

    for(Ingredient* piece : Ingredient::getListOfIngredients()){
        QCheckBox* checkBox = new QCheckBox(QString::fromStdString(piece->getName()));
        for(Ingredient * i : a->getListOfIngredients()){
            if(QString::fromStdString(i->getName()).compare( checkBox->text()) == 0){
                checkBox->setChecked(true);
            }
        }
       layout->addWidget(checkBox);
    }

    QWidget *containerAllergens = new QWidget;
    QVBoxLayout * layoutAllergens = new QVBoxLayout(containerAllergens);
    ui->scrollArea_2->setWidget(containerAllergens);
    ui->scrollArea_2->setWidgetResizable(true);
    std::vector<std::string> allergenVector;
    std::stringstream stream(a->getAllergens());
    std::string currentString;
    while(std::getline(stream, currentString, ' ')){
        allergenVector.push_back(currentString);
    }
    for(Allergen* al : Allergen::getListOfAllergens()){


        QCheckBox* checkBoxAllergen = new QCheckBox(QString::fromStdString(al->getName()));

        if(std::find(allergenVector.begin(), allergenVector.end(), al->getName() ) != allergenVector.end()){
            checkBoxAllergen->setChecked(true);
        }

        layoutAllergens->addWidget(checkBoxAllergen);
    }


}

void ModifyRecipeWindow::on_pushButton_clicked()
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
    int ttcInt = TTC.toInt() ;
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

    struct s{
    unsigned int TTCBitStruct : TTCLimit;
    };
    //bitstruct to ensure that
    //ttc cant exceed 512
    s structTTC;

    structTTC.TTCBitStruct = TTC.toInt();
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
    if(restriction.compare("Vegetarian") == 0){
        vegetarian = true;
    }
    std::string category = ui->Category->currentText().toStdString();

    Recipe* newRecipe = new Recipe(name, category, stepsString, ttcInt, ingredients, listOfAllergensString.toStdString(), vegetarian);
    emit recipeModified(newRecipe);
    hide();
}


void ModifyRecipeWindow::on_TimeToCook_actionTriggered(int action)
{
    QString num = QString::number(ui->TimeToCook->value()) ;
    ui->TimeToCookLabel->setText(num);
}

