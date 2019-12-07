#ifndef ANALISYS_FULL_TABLE_H
#define ANALISYS_FULL_TABLE_H

#include <QWidget>
#include <QList>

namespace Ui {
class analisys_full_table;
}

class analisys_full_table : public QWidget
{
    Q_OBJECT

public:
    explicit analisys_full_table(QList<QList<float>> master_data, QWidget *parent = 0);
    ~analisys_full_table();

private:
    Ui::analisys_full_table *ui;

private slots:
    void background_clicked();
};

#endif // ANALISYS_FULL_TABLE_H
