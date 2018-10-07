#include "record_chart.h"
#include "ui_record_chart.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>

#include "clickeablelabel.h"
#include <QSqlQuery>
#include <QSqlError>

QT_CHARTS_USE_NAMESPACE


record_chart::record_chart(uint record_id, uint inicio, uint final, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::record_chart)
{
    ui->setupUi(this);

    rec_id = record_id;
    last_inicio = inicio;
    last_final = final;

    choice_field_1_text = "";
    choice_field_2_text = "";
    choice_field_3_text = "";

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    QFont font("Typo Square Bold Demo",14,1);
    QFont font_2("Typo Square Bold Demo",10,1);

    ui->label->setFont(font);
    ui->label_2->setFont(font_2);
    ui->label_3->setFont(font_2);
    ui->label_4->setFont(font_2);
    ui->label_5->setFont(font_2);
    ui->label_6->setFont(font_2);
    ui->label_7->setFont(font_2);
    ui->radioButton->setFont(font_2);
    ui->radioButton_2->setFont(font_2);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    //Obtain question type (choice, numeric)
    QSqlQuery q;
    if(!q.prepare("SELECT * FROM records WHERE id = " + QString::number(record_id)))
    {
        qDebug() << "Failed to prepare: record_chart";
        qDebug() << q.lastError();
    }
    else
    {
        if(!q.exec())
        {
            qDebug() << "Failed to execute: record_chart";
            qDebug() << q.lastError();
        }
        else
        {
            while(q.next())
            {
                type = q.value("type").toString();

                if("CHOICE" == type)
                {
                    choice_field_1_text = q.value("field_1").toString();
                    choice_field_2_text = q.value("field_2").toString();
                    choice_field_3_text = q.value("field_3").toString();
                }
                else if("NUMBER" == type)
                {
                    number_field_1_text = q.value("field_1").toString();
                }
            }
        }
    }

    if("CHOICE" == type)
    {
        update_pie_chart(rec_id, inicio, final);
    }
    else if("NUMBER" == type)
    {
        ui->radioButton_2->setChecked(true);
        update_bar_chart(rec_id, inicio, final);
    }

    this->move(parent->pos());
    this->show();
}

record_chart::~record_chart()
{
    delete ui;
}

void record_chart::update_pie_chart(uint id, uint fecha_inicio, uint fecha_fin)
{
    QString rutina_name;
    QString record_name;
    uint field_1_counter = 0;
    uint field_2_counter = 0;
    uint field_3_counter = 0;

    ui->label_7->setText("");
    ui->groupBox->hide();

    QPieSeries *series = new QPieSeries();

    QSqlQuery q;
    if(!q.prepare("SELECT * FROM log WHERE record_id = " +QString::number(id)
                  +" AND log_date BETWEEN " + QString::number(fecha_inicio) + " and " + QString::number(fecha_fin)))
    {
        qDebug() << "Failed to prepare: update_pie_chart";
        qDebug() << q.lastError();
    }
    else
    {
        if(!q.exec())
        {
            qDebug() << "Failed to execute: record_chart";
            qDebug() << q.lastError();
        }
        else
        {
            while(q.next())
            {
                rutina_name = q.value("rutina_name").toString();
                record_name = q.value("record_name").toString();

                //Choices have only 3 options (1, 2, 3) count occurrences
                if(1 == q.value("record_value").toInt())
                {
                    field_1_counter++;
                }
                else if(2 == q.value("record_value").toInt())
                {
                    field_2_counter++;
                }
                else if(3 == q.value("record_value").toInt())
                {
                    field_3_counter++;
                }
            }
        }
    }

    // Get the string value for the choices (1,2,3)
    if(field_1_counter != 0)
    {
        series->append(choice_field_1_text, field_1_counter);
    }
    if(field_2_counter != 0)
    {
        series->append(choice_field_2_text, field_2_counter);
    }
    if(field_3_counter != 0)
    {
        series->append(choice_field_3_text, field_3_counter);
    }


    uint i = 0;
    QPieSlice *slice;
    for(i = 0; i < (uint)series->count(); i++)
    {
        slice = series->slices().at(i);
        slice->setLabel(slice->label() + " (" + QString::number(slice->value()) + ")");
        slice->setLabelVisible();
    }
//    slice->setExploded();
//    slice->setLabelVisible();
//    slice->setPen(QPen(Qt::darkGreen, 2));
//    slice->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record_name);
    chart->legend()->hide();
//    chart->legend()->setAlignment(Qt::AlignRight);

    //If We find any data
    if((field_1_counter + field_2_counter + field_3_counter) > 0)
    {
        ui->label->setText(rutina_name);
    }
    else
    {
        ui->label_7->setText("NO HAY REGISTROS");
    }
    ui->label_3->setText(QDateTime::fromTime_t(fecha_inicio).toString());
    ui->label_5->setText(QDateTime::fromTime_t(fecha_fin).toString());
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void record_chart::update_bar_chart(uint id, uint fecha_inicio, uint fecha_fin)
{
    QString rutina_name;
    QString record_name;
    QDate date;
    QDate last_date;
    uint bar_count = 0;

    QList <qreal> bar_values;
    QStringList bar_names;

    ui->label_7->setText("");
    ui->groupBox->show();

    QSqlQuery q;
    if(!q.prepare("SELECT * FROM log WHERE record_id = " +QString::number(id)
                  +" AND log_date BETWEEN " + QString::number(fecha_inicio) + " and " + QString::number(fecha_fin)
                  +" ORDER BY log_date ASC"))
    {
        qDebug() << "Failed to prepare: update_bar_chart";
        qDebug() << q.lastError();
        qDebug() << q.lastQuery();
    }
    else
    {
        if(!q.exec())
        {
            qDebug() << "Failed to execute: update_bar_chart";
            qDebug() << q.lastError();
        }
        else
        {
            while(q.next())
            {
                rutina_name = q.value("rutina_name").toString();
                record_name = q.value("record_name").toString();

                // If group by months
                if(ui->radioButton_2->isChecked())
                {
                    date = QDateTime::fromTime_t(q.value("log_date").toInt()).date();
                    if(date.month() != last_date.month())
                    {
                        // Increment bar count cause this is a new bar
                        bar_count++;

                        // Add initial value and name to the bar struct
                        bar_values.append(q.value("record_value").toReal());
                        bar_names.append(QString::number(date.month()) + "/" + QString::number(date.year()));
                        last_date = date;
                    }
                    else
                    {
                        // Same month, just add value to same index in list
                        bar_values.last() += q.value("record_value").toReal();
                    }
                }
                else
                {
                    // Group by days
                    date = QDateTime::fromTime_t(q.value("log_date").toInt()).date();
                    if((date.month() != last_date.month())
                            || (date.day() != last_date.day()))
                    {
                        // Increment bar count cause this is a new bar
                        bar_count++;

                        // Add initial value and name to the bar struct
                        bar_values.append(q.value("record_value").toReal());
                        bar_names.append(QString::number(date.day())
                                         + "/" + QString::number(date.month())
                                         + "/" + QString::number(date.year()));
                        last_date = date;
                    }
                    else
                    {
                        // Same day, just add value to same index in list
                        bar_values.last() += q.value("record_value").toReal();
                    }
                }
            }
        }
    }

    QBarSet *set = new QBarSet(number_field_1_text);
    set->append(bar_values);

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(record_name);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(bar_names);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //If We find any data
    if(bar_count > 0)
    {
        ui->label->setText(rutina_name);
    }
    else
    {
        ui->label_7->setText("NO HAY REGISTROS");
    }
    ui->label_3->setText(QDateTime::fromTime_t(fecha_inicio).toString());
    ui->label_5->setText(QDateTime::fromTime_t(fecha_fin).toString());
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void record_chart::background_clicked()
{
    this->close();
}

void record_chart::on_filtro_fecha_clicked()
{
    if(calendario_window != NULL)
    {
        delete calendario_window;
    }

    calendario_window = new calendario_filtro(this);
    connect(calendario_window, SIGNAL(send_fechas(uint,uint)),
            this, SLOT(filtro_fecha_received(uint,uint)));
}

void record_chart::filtro_fecha_received(uint ini, uint end)
{
    last_inicio = ini;
    last_final = end;
    if("CHOICE" == type)
    {
        update_pie_chart(rec_id, ini, end);
    }
    else if("NUMBER" == type)
    {
        update_bar_chart(rec_id, ini, end);
    }
}

void record_chart::on_radioButton_toggled(bool checked)
{
    update_bar_chart(rec_id, last_inicio, last_final);
}
