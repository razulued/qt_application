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

void curve_chart::draw_chart(QList<float> seriesX, QList<float>seriesY, QString xname, QString yname, bool use_curve)
{
    //QSplineSeries or QLineSeries
    QLineSeries *seriesXY;
    if(use_curve)
    {
        seriesXY = new QSplineSeries;
    }
    else
    {
        seriesXY = new QLineSeries;
    }
    QLineSeries *dummy = new QLineSeries;
    QScatterSeries *scatter = new QScatterSeries;
    seriesXY->clear();

    for(int i = 0; i < seriesX.length(); i++)
    {
        seriesXY->append(seriesX.at(i),seriesY.at(i));
        scatter->append(seriesX.at(i),seriesY.at(i));
    }
    dummy->append(0,0);
    dummy->append(100,0);
    dummy->setBrush(QBrush(QColor(Qt::transparent)));
    scatter->setMarkerSize(6);
//    seriesXY->append(1.6, 1.4);
//    seriesXY->append(2.4, 3.5);
//    seriesXY->append(3.7, 2.5);
//    seriesXY->append(7, 4);
//    seriesXY->append(10, 2);
    ui->graphicsView->chart()->removeAllSeries();
    ui->graphicsView->chart()->addSeries(seriesXY);
    ui->graphicsView->chart()->addSeries(scatter);
    ui->graphicsView->chart()->addSeries(dummy);
    ui->graphicsView->chart()->legend()->hide();
    ui->graphicsView->chart()->createDefaultAxes();
    ui->graphicsView->chart()->axisX()->setLabelsColor(Qt::white);
    ui->graphicsView->chart()->axisY()->setLabelsColor(Qt::white);
    ui->graphicsView->chart()->axisX()->setTitleBrush(Qt::white);
    ui->graphicsView->chart()->axisX()->setTitleText(xname);
    ui->graphicsView->chart()->axisY()->setTitleBrush(Qt::white);
    ui->graphicsView->chart()->axisY()->setTitleText(yname);

    ui->graphicsView->resize(this->width()-30, this->height()-80);
}
