#ifndef SIMULATION_INPUT_H
#define SIMULATION_INPUT_H

#include <QDialog>

namespace Ui {
class simulation_input;
}

class simulation_input : public QDialog
{
    Q_OBJECT

public:
    explicit simulation_input(QWidget *parent = 0);
    ~simulation_input();

private slots:
    void on_checkBox_clicked();

    void on_horizontalScrollBar_actionTriggered(int action);

    void on_lineEdit_editingFinished();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_horizontalScrollBar_2_actionTriggered(int action);

    void on_horizontalScrollBar_3_actionTriggered(int action);

    void on_horizontalScrollBar_4_actionTriggered(int action);

private:
    Ui::simulation_input *ui;
};

#endif // SIMULATION_INPUT_H
