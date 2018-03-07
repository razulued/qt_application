#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QFile>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

    void sync_regulador_IDs(void);


private slots:
    void on_settings_accepted();
    void on_settings_rejected();

    void on_buttonBox_accepted();


    void on_key_0_clicked();
    void on_key_1_clicked();
    void on_key_2_clicked();
    void on_key_3_clicked();
    void on_key_4_clicked();
    void on_key_5_clicked();
    void on_key_6_clicked();
    void on_key_7_clicked();
    void on_key_8_clicked();
    void on_key_9_clicked();

    void on_key_Q_clicked();
    void on_key_W_clicked();
    void on_key_E_clicked();
    void on_key_R_clicked();
    void on_key_T_clicked();
    void on_key_Y_clicked();
    void on_key_U_clicked();
    void on_key_I_clicked();
    void on_key_O_clicked();
    void on_key_P_clicked();
    void on_key_A_clicked();
    void on_key_S_clicked();
    void on_key_D_clicked();
    void on_key_F_clicked();
    void on_key_G_clicked();
    void on_key_H_clicked();
    void on_key_J_clicked();
    void on_key_K_clicked();
    void on_key_L_clicked();
    void on_key_Z_clicked();
    void on_key_X_clicked();
    void on_key_C_clicked();
    void on_key_V_clicked();
    void on_key_B_clicked();
    void on_key_N_clicked();
    void on_key_M_clicked();

    void on_key_up_clicked();
    void on_key_down_clicked();
    void on_key_left_clicked();
    void on_key_right_clicked();

    void on_key_guion_clicked();
    void on_key_equal_clicked();
    void on_key_space_clicked();
    void on_key_back_clicked();
    void on_key_enter_clicked();


private:
    Ui::settings *ui;
    QFile *config_file;

};

void saveSettings(const QString &group, const QString &key, const QVariant &value);
#endif // SETTINGS_H
