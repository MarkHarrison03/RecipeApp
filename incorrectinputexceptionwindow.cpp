#include "incorrectinputexceptionwindow.h"
#include "ui_incorrectinputexceptionwindow.h"

IncorrectInputExceptionWindow::IncorrectInputExceptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncorrectInputExceptionWindow)
{
    ui->setupUi(this);
}

IncorrectInputExceptionWindow::~IncorrectInputExceptionWindow()
{
    delete ui;
}

void IncorrectInputExceptionWindow::on_pushButton_clicked()
{
    hide();
}

