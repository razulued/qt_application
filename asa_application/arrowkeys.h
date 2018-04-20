#ifndef ARROWKEYS_H
#define ARROWKEYS_H

#include <QDialog>

namespace Ui {
class arrowkeys;
}

class arrowkeys : public QDialog
{
    Q_OBJECT

public:
    explicit arrowkeys(QWidget *frame, QWidget *main_window);
    ~arrowkeys();

private:
    Ui::arrowkeys *ui;
    QWidget *frame_to_move;

private slots:
    void background_clicked();
    void on_key_up_clicked();
    void on_key_down_clicked();
    void on_key_left_clicked();
    void on_key_rigth_clicked();
};

#endif // ARROWKEYS_H
