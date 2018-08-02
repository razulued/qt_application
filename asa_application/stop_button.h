#ifndef STOP_BUTTON_H
#define STOP_BUTTON_H

#include <QDialog>

namespace Ui {
class stop_button;
}

class stop_button : public QDialog
{
    Q_OBJECT

public:
    explicit stop_button(QWidget *parent = 0);
    ~stop_button();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void checkStop();
private:
    Ui::stop_button *ui;
    bool stop_pressed = false;
};

#endif // STOP_BUTTON_H
