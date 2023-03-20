#include "addallergenwindow.h"
#include "./ui_addallergenwindow.h"

AddAllergenWindow::AddAllergenWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAllergenWindow)
{
    ui->setupUi(this);
}

AddAllergenWindow::~AddAllergenWindow()
{
    delete ui;
}

void AddAllergenWindow::show_window(){
    show();

}
