#ifndef RECORD_CHART_H
#define RECORD_CHART_H

#include <QDialog>

namespace Ui {
class record_chart;
}

class record_chart : public QDialog
{
    Q_OBJECT

public:
    explicit record_chart(QWidget *parent = 0);
    ~record_chart();

private:
    Ui::record_chart *ui;
};

#endif // RECORD_CHART_H
