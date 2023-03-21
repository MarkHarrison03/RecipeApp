#ifndef ADDINGREDIENTWINDOW_H
#define ADDINGREDIENTWINDOW_H

#include <QDialog>

namespace Ui {
class addingredientwindow;
}

class addingredientwindow : public QDialog
{
    Q_OBJECT

public:
     addingredientwindow(QWidget *parent = nullptr);
    ~addingredientwindow();
public slots:
     void show_window();
signals:
    void ingredientsUpdated();
private slots:
    void on_pushButton_clicked();

private:
    Ui::addingredientwindow *ui;
};

#endif // ADDINGREDIENTWINDOW_H
