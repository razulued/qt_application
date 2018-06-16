#ifndef MOTORES_H
#define MOTORES_H

#include <QDialog>
#include "configuration.h"
#include <QVBoxLayout>
#include "login_dialog.h"
#include <QCheckBox>
namespace Ui {
class motores;
}

class motores : public QDialog
{
    Q_OBJECT

public:
    explicit motores(QWidget *parent = 0);
    ~motores();
    void update_motors();
private slots:
    void on_asa_logo_clicked();
    void out_checkBoxStateChanged(int);
    void background_clicked();
    void checkActivity();
    void on_pushButton_clicked();
    void checkStop();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

private:
    Ui::motores *ui;
    void module_init(configuration_id *conf, QGridLayout *layout);
    bool has_activity = false;
    login_dialog *login_d = NULL;
    uint number_of_motors = 0;
    uint motor_index = 0;
    QCheckBox* controls_ptr[20];
    void module_update(configuration_id *conf);
    bool stop_pressed = false;
    void read_op_mode();
    void set_op_mode(uint mode, uint what_element);
};

#endif // MOTORES_H
