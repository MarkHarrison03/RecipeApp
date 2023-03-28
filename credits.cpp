#include "credits.h"
#include "ui_credits.h"
bool longCurrently = false;
Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);


    union data dat = {42};
    ui->label_5->setText(QString::number(dat.integer));
    qDebug() << QChar::fromLatin1(sizeof(dat));
    QString s = ui->label_6->selectedText() + " " +  QString::number(sizeof(dat));
    ui->label_6->setText(s);
}

Credits::~Credits()
{
    delete ui;
}

void Credits::on_pushButton_clicked()
{
    union data dat = {42};
    if(longCurrently){

    ui->label_5->setText(QString::number(dat.integer));
    qDebug() << QChar::fromLatin1(sizeof(dat)) << "!";
    QString s = ui->label_6->selectedText() + " " +  QString::number(sizeof(dat.integer));
    ui->label_6->setText(s);
    ui->label_9->setText("Integer");
    longCurrently = false;
    }else{

        ui->label_5->setText(QString::number(dat.longNum));
        qDebug() << QChar::fromLatin1(sizeof(dat));
        QString s = ui->label_6->selectedText() + " " +  QString::number(sizeof(dat.longNum));
        ui->label_6->setText(s);
        ui->label_9->setText("Long Long");
    longCurrently = true;
    }

}

