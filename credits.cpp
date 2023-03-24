#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);
    QPixmap map(":/new/glasses/glass.png");
    ui->label_4->setPixmap(map);
    ui->label_4->setMask(map.mask());
    ui->label_4->show();


}

Credits::~Credits()
{
    delete ui;
}
