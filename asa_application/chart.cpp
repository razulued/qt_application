/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QBrush>
#include <QLinearGradient>

Chart::Chart(QList<float> values, uint ticks, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(0),
    m_y(0)
{
    qsrand((uint) QTime::currentTime().msec());

//    QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
//    m_timer.setInterval(1000);

    m_series = new QSplineSeries(this);
    QPen line_color(QColor::fromRgb(0, 167, 250,180));
    line_color.setWidth(5);
    m_series->setPen(line_color);
    m_series->append(m_x, m_y);


    addSeries(m_series);
    createDefaultAxes();

    setAxisX(m_axis, m_series);
    m_axis->setTickCount(11);

    yMax = 10;
    yMin = 0;
    axisX()->setRange(0, ticks);
    axisY()->setRange(yMin, yMax);

    connect(m_series, &QSplineSeries::pointAdded, [=](int index){
           qreal y = m_series->at(index).y();

           if(y< yMin || y > yMax)
           {
               if(y < yMin)
                   yMin = y;
               if(y> yMax)
                   yMax = y;
//               axisY()->setRange(yMin-20, yMax+20);
//               qDebug() << "Ymax: " << yMax << "Ymin: " << yMin;
               axisY()->setRange(roundDown(yMin,10,10), roundUp(yMax,10,10));
               axisY()->setRange(0, roundUp(yMax,10,10));
           }

       });


    // Customize chart background
//    QLinearGradient backgroundGradient;
//    backgroundGradient.setStart(QPointF(0, 0));
//    backgroundGradient.setFinalStop(QPointF(0, 1));
//    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
//    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
//    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    QColor backcolor(Qt::black);
    QBrush backgroundcolor(backcolor);
    this->setBackgroundBrush(backgroundcolor);
    this->axisX()->setLabelsColor(Qt::white);
    this->axisY()->setLabelsColor(Qt::white);
    this->setTitleBrush(Qt::white);

    uint i = 0;
    for(i = 0; i < values.length(); i++)
    {
        m_series->append(i, values.at(i));
    }
}

Chart::~Chart()
{

}

void Chart::handleTimeout()
{
//    qDebug() << "plotArea().width()" << plotArea().width();
    qreal x = plotArea().width() / (m_axis->tickCount() - 1);
//    qDebug() << "m_axis->max():" << m_axis->max() <<  "m_axis->min(): " << m_axis->min() << "m_axis->tickCount():" << m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
//    qDebug() << "x: " << x << "y: " << y;
    m_x += 1;//y;
    m_y = qrand() % 100 - 30;
    m_series->append(m_x, m_y);

    if((m_x - m_axis->min()) >= 10)
    {
        scroll(x, 0);
    }
    if (m_x == 100)
        m_timer.stop();
}

qreal Chart::roundUp(qreal actual, qreal base, qreal gap)
{
    qreal ret = 0;
//    ret = (((int)actual / base) + 1) * base;
    ret = (qRound(actual / base) + 1) * base;
    ret +=gap;
//    qDebug() << "UP: " << ret;
    return ret;
}

qreal Chart::roundDown(qreal actual, qreal base, qreal gap)
{
    qreal ret = 0;

//    ret = (((int)actual / base) - 1) * base;
    ret = (qRound(actual / base) - 1) * base;
    ret -=gap;
//    qDebug() << "DN: " << ret;

    return ret;
}
