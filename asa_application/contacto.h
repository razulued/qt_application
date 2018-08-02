#ifndef CONTACTO_H
#define CONTACTO_H

#include <QDialog>
#include "settings.h"
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

    void on_top_menu_5_clicked();

private:
    Ui::contacto *ui;
    uint sequence = 0;

    settings *settingswindow = NULL;

signals:
    void close_app();
    void release_lock();
};

#endif // CONTACTO_H
