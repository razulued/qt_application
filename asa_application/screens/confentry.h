#ifndef CONFENTRY_H
#define CONFENTRY_H

#include <QDialog>
#include <QLineEdit>
#include <QString>
namespace Ui {
class confentry;
}

class confentry : public QDialog
{
    Q_OBJECT

public:
    explicit confentry(QWidget *parent = 0);
    ~confentry();

    void set_Values(QStringList values);

    QStringList get_AllValues();

private slots:
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

    void on_key_equal_clicked();
    void on_key_space_clicked();
    void on_key_back_clicked();
    void on_key_enter_clicked();
    void on_key_L_corchete_clicked();
    void on_key_R_corchete_clicked();
    void on_key_comma_clicked();
    void on_key_dot_clicked();
    void on_key_slash_clicked();
    void on_key_minus_clicked();
    void on_key_plus_clicked();

    void keyboard_handler(QString key);
    void on_closeButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::confentry *ui;

    QString get_Name();
    QString get_ID();
    QString get_Type();
    QString get_Units();
};

#endif // CONFENTRY_H
