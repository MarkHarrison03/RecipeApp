#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //static vector<Recipe *> listOfRecipies;

    friend class AddAllergenWindow;
    friend class deleterecipewindow;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Recipe*>getListOfRecipies();
public slots:


    void updateRecipies(Recipe *);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_actionAllergen_triggered();

//    void on_actionAllergen_triggered(bool checked);

    void on_actionIngredient_triggered();

    void on_actionRecipe_triggered();

    void on_actionCredits_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
