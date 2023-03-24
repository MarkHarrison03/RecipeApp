#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "ingredient.h"
#include <QDebug>
#include "mainwindow.h"
#include <QValidator>
#include "recipe.h"
#include "allergen.h"

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

    for(Ingredient* piece : Ingredient::getListOfIngredients()){
        qDebug() << QString::fromStdString(piece->getName());
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
    QString steps(ui->Steps->toPlainText());
    std::string stepsString = steps.toStdString();
    QString TTC(ui->TimeToCookLabel->text());
    int ttcInt = TTC.toInt();
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
    Recipe* newRecipe = new Recipe(name, category, stepsString, ttcInt, ingredients, listOfAllergensString.toStdString(), vegetarian);
    emit recipeAdded(newRecipe);
    hide();
}


void CreateRecipeWindow::on_TimeToCook_sliderMoved(int position)
{
    QString num = QString::number(ui->TimeToCook->value()) ;
    ui->TimeToCookLabel->setText(num);
}

