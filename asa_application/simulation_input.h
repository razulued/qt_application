#ifndef SIMULATION_INPUT_H
#define SIMULATION_INPUT_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class simulation_input;
}

class simulation_input : public QDialog
{
    Q_OBJECT

public:
    explicit simulation_input(QWidget *parent = 0);
    ~simulation_input();

    static QDateTime simDateTime;

private slots:
    void on_checkBox_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();
    void on_checkBox_6_clicked();
    void on_checkBox_7_clicked();
    void on_checkBox_8_clicked();

    void on_horizontalScrollBar_actionTriggered(int action);

    void on_lineEdit_editingFinished();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_horizontalScrollBar_2_actionTriggered(int action);

    void on_horizontalScrollBar_3_actionTriggered(int action);

    void on_horizontalScrollBar_4_actionTriggered(int action);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void add_seconds();

    void on_pushButton_4_clicked();

private:
    Ui::simulation_input *ui;
    bool time_running = false;
};

#endif // SIMULATION_INPUT_H
