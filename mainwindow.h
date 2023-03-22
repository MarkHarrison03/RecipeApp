#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class AddAllergenWindow;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateAllergens();
    void updateIngredients();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionAllergen_triggered();

//    void on_actionAllergen_triggered(bool checked);

    void on_actionIngredient_triggered();

    void on_actionRecipe_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
