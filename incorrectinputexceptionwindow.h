#ifndef INCORRECTINPUTEXCEPTIONWINDOW_H
#define INCORRECTINPUTEXCEPTIONWINDOW_H

#include <QDialog>

namespace Ui {
class IncorrectInputExceptionWindow;
}

class IncorrectInputExceptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IncorrectInputExceptionWindow(QWidget *parent = nullptr);
    ~IncorrectInputExceptionWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IncorrectInputExceptionWindow *ui;
};

#endif // INCORRECTINPUTEXCEPTIONWINDOW_H
