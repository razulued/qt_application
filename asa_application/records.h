#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QString>
#include <QSqlDatabase>
#include <QMutex>

namespace Ui {
class records;
}

enum{
    NO_TYPE_SELECTED,
    TYPE_NUMERIC,
    TYPE_CHOICE,
    TYPE_COMPLETED,
    TYPE_RESCHEDULE
};

typedef struct
{
    uint log__rutina_id;
    uint log__date;
    QString log__rutina_text;
    uint log__record_id;
    QString log__record_text;
    float log__record_value;
}log_type;

class records : public QDialog
{
    Q_OBJECT

public:
    explicit records(const QString &path, QStringList list_records, uint from_id, uint time, QWidget *parent = 0);
    ~records();

private:
    Ui::records *ui;
    QSqlDatabase m_db;
    QString db_path;
    void load_to_temp(uint id);
    uint current_type = NO_TYPE_SELECTED;
    uint main_id;
    uint actual_time;
    QStringList question_list;

    void format_everything();
    void input_numeric(QString name, QString units);
    void input_choice(QString name, QString opt_1, QString opt_2, QString opt_3);

    QList<log_type> log_queue;
    log_type temp_log;

    void save_records_to_log();
    uint get_current_question_id();
    void input_completed_reschedule();
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
    void on_pushButton_clicked();

    void out_RadioButtonChanged(int opt);
    void on_pushButton_2_clicked();
    void background_clicked();
    void run_after();
signals:
    void all_questions_ok(uint id);
};

#endif // RECORDS_H
