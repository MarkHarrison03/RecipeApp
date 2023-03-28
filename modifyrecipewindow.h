#ifndef MODIFYRECIPEWINDOW_H
#define MODIFYRECIPEWINDOW_H

#include <QDialog>
#include "recipe.h"

namespace Ui {
class ModifyRecipeWindow;
}

class ModifyRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyRecipeWindow(QWidget *parent = nullptr);
    ~ModifyRecipeWindow();
    void setup(Recipe*a );

private slots:
    void on_pushButton_clicked();

    void on_TimeToCook_actionTriggered(int action);

private:
    Ui::ModifyRecipeWindow *ui;

signals:
    void recipeModified(Recipe*);
};

#endif // MODIFYRECIPEWINDOW_H
