#include "donut_chart.h"
#include "ui_donut_chart.h"


#include <QtCore/QDebug>
//#include "parameters.h"



donut_chart::donut_chart(QString name, float value, float max, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::donut_chart)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: transparent;"
                        "border: none");

    ui->graphicsView->setGeometry(this->geometry());
    ui->valuelabel->move(this->rect().center()- ui->valuelabel->rect().center());
    ui->valuelabel->move(ui->valuelabel->x(),ui->valuelabel->y()-10);


    ui->valuelabel->setStyleSheet("background-color: transparent;"
                                  "color: rgb(146,205,186);");
    ui->valuelabel->setText(QString::number(value,'f',2));

    ui->namelabel->setStyleSheet(ui->valuelabel->styleSheet());
    ui->namelabel->setText(name);
//    ui->namelabel->adjustSize();
    ui->namelabel->move(this->rect().center()- ui->valuelabel->rect().center());
    ui->namelabel->move(ui->namelabel->x(),ui->namelabel->y()+90);

    max_value = max;

    color1.setRgb(0, 163, 176);
    color2.setRgb(12, 201, 100);
//    qDebug() << "PARAM" << getParamValue(0x1234).toFloat();
//![1]
    series = new QPieSeries();
    series->setHoleSize(0.75);
    series->setPieSize(1);

    series->append("Caudal",  value);
    series->append("None", max_value - series->slices().at(0)->value());

    //    series->slices().at(0)->setBrush(QBrush(QColor(82, 191, 227,150)));
    series->slices().at(0)->setBorderColor(QColor(Qt::transparent));
    series->slices().at(0)->setBorderColor(QColor(Qt::transparent));


    series->slices().at(1)->setBrush(QBrush(QColor(48,81,105)));
    series->slices().at(1)->setBorderColor(QColor(Qt::transparent));
//![1]

//![2]
//    QChart *donut_chart = new QChart;
//    donut_chart->addSeries(series);
//    donut_chart->legend()->hide();
//    donut_chart->setMargins(QMargins(0,0,0,0));
//    donut_chart->setBackgroundBrush(QBrush(Qt::transparent));
//    donut_chart->setBackgroundRoundness(0);
//    donut_chart->setAnimationOptions(QChart::AllAnimations);

//    QConicalGradient gradient(ui->valuelabel->geometry().center(), 0);
//    gradient.setColorAt(0.0, Qt::red);
////    gradient.setColorAt(0.5, Qt::green);
//    gradient.setColorAt(1.0, Qt::blue);
//    series->slices().at(0)->setBrush(QBrush(gradient));

//![2]
    ui->graphicsView->chart()->addSeries(series);
    ui->graphicsView->chart()->legend()->hide();
//qDebug()<<"Size" <<  ui->graphicsView->chart()->size();
    ui->graphicsView->chart()->setMargins(QMargins(0,0,20,20));
//    ui->graphicsView->chart()->resize(180,180);
    ui->graphicsView->chart()->setBackgroundBrush(QBrush(Qt::transparent));
    ui->graphicsView->chart()->setAnimationOptions(QChart::AllAnimations);
//    ui->graphicsView->chart()->setPos(parent->geometry().center());
//    ui->graphicsView->setStyleSheet("border: none");
    //    ui->graphicsView->setChart(donut_chart);

    //    QChartView *chartView = new QChartView(this);
//    chartView->setRenderHint(QPainter::Antialiasing);
//    chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
//    chartView->chart()->addSeries(series);
//    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
//    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
//    chartView->chart()->legend()->setFont(QFont("Arial", 7));


//    QString getParamValue_base_units(unsigned int id);
//    QString getParamValue(unsigned int id);
}

donut_chart::~donut_chart()
{
    delete ui;
}

void donut_chart::set_value()
{

}

QColor donut_chart::get_color(int value)
{
    int r = rect_eq_y((color2.red() - color1.red()), value, color1.red());
    int g = rect_eq_y((color2.green() - color1.green()), value, color1.green());
    int b = rect_eq_y((color2.blue() - color1.blue()), value, color1.blue());

    if(r >= color2.red() || r < 0){
        r = color2.red();
    }
    if(g >= color2.green() || g < 0){
        g = color2.green();
    }
    if(b >= color2.blue() || b < 0){
        b = color2.blue();
    }
    return QColor(r,g,b);
}

int donut_chart::rect_eq_y(double m, double x, double b)
{
    double value =  (m/max_value * x) + b;
    return value;
}

void donut_chart::update_data(float value)
{

    series->slices().at(0)->setValue(value);
    if(value >= max_value)
    {
        series->slices().at(1)->setValue(0);
    }
    else
    {
        series->slices().at(1)->setValue(max_value - value);
    }
    series->slices().at(0)->setBrush(QBrush(get_color((int)value)));
    ui->valuelabel->setText(QString::number(value,'f',2));
//    qDebug() << "Slice val: " << value;
}

void donut_chart::mousePressEvent(QMouseEvent *e)
{
    clicked();
}
