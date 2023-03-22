#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>

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
private:
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
