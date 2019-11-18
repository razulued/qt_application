#ifndef DONUT_CHART_H
#define DONUT_CHART_H

#include <QWidget>
#include <QColor>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class donut_chart;
}

class donut_chart : public QWidget
{
    Q_OBJECT

public:
    explicit donut_chart(float value, float max, QWidget *parent = 0);
    ~donut_chart();
    void set_value();

private:
    Ui::donut_chart *ui;
    QPieSeries *series;
    float max_value;
    QColor color1;
    QColor color2;
    QColor get_color(int value);
    int rect_eq_y(double m, double x, double b);
public slots:
    void update_data(float value);
protected:
    void mousePressEvent(QMouseEvent *e);
signals:
    void clicked();
};

#endif // DONUT_CHART_H
