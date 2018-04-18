#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QGraphicsScene>
#include "statistics.h"
#include <QList>
#include <QBrush>
#include <QDebug>

#define VAL_SEPARATION (ui->graphicsView->width()/10)

enum
{
    TYPE_ELECTRICOS,
    TYPE_FISICOS,
    TYPE_QUIMICOS
};



graphwindow::graphwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
    parent_window = parent;

    QLinearGradient gradient(0,0,ui->graphicsView->width(),ui->graphicsView->height());
//    gradient.setColorAt(0, QColor::fromRgbF(0, 0, 0, 127));
    gradient.setColorAt(0, QColor::fromRgb(0, 167, 250,180));
//    gradient.setColorAt(0.7, QColor::fromRgb(0, 167, 250,255));
    gradient.setColorAt(1, QColor::fromRgb(255, 255, 255,255));
    QBrush brush(gradient);
//    QBrush brush(Qt::LinearGradientPattern);
    pen.setBrush(brush);
//        QColor line_color;
//        line_color.setRgb(0, 167, 250,150);
//        pen.setColor(line_color);
    pen.setWidth(5);


//    QColor line_color;
//    line_color.setRgb(0, 167, 250,150);

//    pen.setColor(line_color);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setWidth(3);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    this->setStyleSheet("background-color:black;");
}

graphwindow::~graphwindow()
{
    delete ui;
}

void graphwindow::show_graph(uint element_type)
{
    switch(element_type)
    {
    case TYPE_ELECTRICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PE_bar.png);");
        break;
    case TYPE_FISICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PF_bar.png);");

        break;
    case TYPE_QUIMICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PQ_bar.png);");

        break;

    }

    this->move(parent_window->pos());
    this->show();
}

void graphwindow::update_graph()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
//    scene->setSceneRect(0,0,100,100);
    QList<int>values = get_list_from_param(0x3001);
    int i, num_of_values;
    QPolygon pol;
    QPoint point;

    num_of_values = values.length();
//    for(i = 0; i < (values.length() - 1); i++)
    for(i = 0; i < (values.length()); i++)
    {
//        scene->addLine(i*VAL_SEPARATION(num_of_values), values.at(i),(i+1)*VAL_SEPARATION(num_of_values), values.at(i+1), pen);
        point.setX(i*VAL_SEPARATION);
        point.setY(values.at(i));
        pol.append(point);
    }


//    QRadialGradient gradient2(center,10,center);
    QRadialGradient gradient2(QPointF((i-1)*VAL_SEPARATION,values.at(i-1)),20);
//    QBrush brush(Qt::LinearGradientPattern);
    gradient2.setColorAt(0, QColor::fromRgb(255, 255, 255,255));
    gradient2.setColorAt(1, QColor::fromRgb(0, 0, 0,0));
    QBrush brush(gradient2);
    pen2.setBrush(brush);

    pen2.setWidth(10);

    QPainterPath path;
    path.addPolygon(pol);
    scene->addEllipse((i-1)*VAL_SEPARATION,values.at(i-1)-5,10, 10,pen2);
    scene->addPath(path, pen);

    ui->graphicsView->setScene(scene);

}

void graphwindow::on_top_menu_3_clicked()
{
    this->close();
}
