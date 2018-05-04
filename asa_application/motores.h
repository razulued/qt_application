#ifndef MOTORES_H
#define MOTORES_H

#include <QDialog>
#include "configuration.h"
#include <QVBoxLayout>

namespace Ui {
class motores;
}

class motores : public QDialog
{
    Q_OBJECT

public:
    explicit motores(QWidget *parent = 0);
    ~motores();

private slots:
    void on_asa_logo_clicked();
    void out_checkBoxStateChanged(int);
    void background_clicked();

private:
    Ui::motores *ui;
    void module_init(configuration_id *conf, QVBoxLayout *layout);
};

#endif // MOTORES_H
