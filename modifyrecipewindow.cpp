#include "modifyrecipewindow.h"
#include "ui_modifyrecipewindow.h"
#include "allergen.h"
#include "IncorrectInputException.h"
#include <algorithm>
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
    ui->Name->setText(QString::fromStdString(a->name));
    ui->Category->setCurrentText(QString::fromStdString(a->category));
    ui->Steps->setPlainText(QString::fromStdString(a->steps));

    QWidget *container = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout(container);

    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);

    for(Ingredient* piece : Ingredient::getListOfIngredients()){
        qDebug() << QString::fromStdString(piece->getName());
        QCheckBox* checkBox = new QCheckBox(QString::fromStdString(piece->getName()));
        for(Ingredient * i : a->getListOfIngredients()){
            qDebug() << QString::fromStdString(i->getName()) << "FAUWONIFWA";
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
    std::stringstream stream(a->allergens);
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
        qDebug() << stringName.compare("Enter Recipe Name");
        if(stringName.compare("Enter Recipe Name") == 0){
            throw IncorrectInputException();
        }
    }catch(IncorrectInputException e){
        qDebug() << QString::fromStdString(e.what());

    }
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
    emit recipeModified(newRecipe);
    hide();
}

