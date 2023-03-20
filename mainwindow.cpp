#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "CookBook.cpp"
#include "addallergenwindow.h"

int counter = 0;
Allergen allergen;
CookBook* cookbook = new CookBook();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->titleLabel->setText(QString::fromStdString(cookbook->chickenCurry->name));
    ui->CaloriesLabel->setText("Calories :"  +QString::number(cookbook->chickenCurry->calories));
    std::string str(allergen.getAllergens().begin(), allergen.getAllergens().end());
    QString stringOfAllergens  = QString::fromStdString( str );
    ui->label_Ingredients->setText(stringOfAllergens);

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
        ui->titleLabel->setText("HEllo!!!");
        AddAllergenWindow *window = new AddAllergenWindow();
        connect(ui->actionAllergen, &QAction::triggered, window, &AddAllergenWindow::show_window);
}

