#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>
#include "recipe.h"

namespace Ui {
class CreateRecipeWindow;
}

class CreateRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRecipeWindow(QWidget *parent = nullptr);
    ~CreateRecipeWindow();
    void show_window();
private slots:
    void on_pushButton_clicked();
signals:
    void recipeAdded(Recipe*);

private:
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
