#ifndef CONTACTO_H
#define CONTACTO_H

#include <QDialog>

namespace Ui {
class contacto;
}

class contacto : public QDialog
{
    Q_OBJECT

public:
    explicit contacto(QWidget *parent = 0);
    ~contacto();

private slots:
    void background_clicked();
    void on_push_cancelar_clicked();

    void on_push_cancelar_2_clicked();

    void on_push_cancelar_3_clicked();

    void on_push_cancelar_4_clicked();

    void on_close_clicked();

private:
    Ui::contacto *ui;
    uint sequence = 0;

signals:
    void close_app();
};

#endif // CONTACTO_H
