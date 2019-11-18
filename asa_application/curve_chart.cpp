#include "curve_chart.h"
#include "ui_curve_chart.h"

curve_chart::curve_chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::curve_chart)
{
    ui->setupUi(this);
    this->setGeometry(parent->geometry());
    ui->graphicsView->chart()->setBackgroundBrush(QBrush(QColor(Qt::transparent)));
}

curve_chart::~curve_chart()
{
    delete ui;
}

void curve_chart::draw_chart(QList<float> seriesX, QList<float>seriesY)
{
    QSplineSeries *seriesXY = new QSplineSeries;
    seriesXY->clear();

    for(int i = 0; i < seriesX.length(); i++)
    {
        seriesXY->append(seriesX.at(i),seriesY.at(i));
    }
//    seriesXY->append(1.6, 1.4);
//    seriesXY->append(2.4, 3.5);
//    seriesXY->append(3.7, 2.5);
//    seriesXY->append(7, 4);
//    seriesXY->append(10, 2);
    ui->graphicsView->chart()->removeAllSeries();
    ui->graphicsView->chart()->addSeries(seriesXY);
    ui->graphicsView->chart()->legend()->hide();
    ui->graphicsView->chart()->createDefaultAxes();
    ui->graphicsView->chart()->axisX()->setLabelsColor(Qt::white);
    ui->graphicsView->chart()->axisY()->setLabelsColor(Qt::white);

    ui->graphicsView->resize(this->width()-30, this->height()-80);
}
