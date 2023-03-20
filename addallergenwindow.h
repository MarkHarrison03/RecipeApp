#ifndef ADDALLERGENWINDOW_H
#define ADDALLERGENWINDOW_H

#include <QDialog>

namespace Ui {
class AddAllergenWindow;
}

class AddAllergenWindow : public QDialog
{
    Q_OBJECT

public:
     AddAllergenWindow(QWidget *parent = nullptr);
    ~AddAllergenWindow();

public slots:
    void show_window();

private:
    Ui::AddAllergenWindow *ui;
};

#endif // ADDALLERGENWINDOW_H
