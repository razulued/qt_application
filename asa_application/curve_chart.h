#ifndef CURVE_CHART_H
#define CURVE_CHART_H

#include <QWidget>
#include <QtGui/QResizeEvent>
#include <QtWidgets/QGraphicsScene>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>

namespace Ui {
class curve_chart;
}

class curve_chart : public QWidget
{
    Q_OBJECT

public:
    explicit curve_chart(QWidget *parent = 0);
    ~curve_chart();
    void draw_chart(QList<float> seriesX, QList<float> seriesY, QString xname, QString yname, bool use_curve, uint xscale);

private:
    Ui::curve_chart *ui;
};

#endif // CURVE_CHART_H
