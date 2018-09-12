#include "bitacora.h"
#include "ui_bitacora.h"
#include <QDateTime>
#include <QLabel>
#include <QScroller>
#include <QScrollerProperties>
#include "mainwindow.h"
#include <QSqlQuery>
#include "records.h"

// rgb(0, 167, 250)

bitacora::bitacora(rutinas_mantenimiento *rutina, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bitacora)
{
    init_completed = false;

    ui->setupUi(this);
    rutina_ptr = rutina;

    selected_id = 0;
    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    QFont font0("Typo Square Bold Demo",18,1);
//    QFont font1("Typo Square Italic Demo",12,1);
//    QFont font2("Typo Square Italic Demo",10,1);
    QFont font3("Typo Square Bold Demo",14,1);
    QFont font4("Typo Square Bold Demo",10,1);
    QFont font5("Typo Square Bold Demo",8,1);

//    QFont font0("SquareSlab711 Lt BT",18,1);
    QFont font1("Square721 BT",12,1);
    QFont font2("Square721 BT",10,1);
//    QFont font3("SquareSlab711 Lt BT",14,1);
//    QFont font4("SquareSlab711 Lt BT",10,1);
//    QFont font5("SquareSlab711 Lt BT",8,1);

    ui->label->setFont(font0);

//    ui->tableWidget->setStyleSheet("color: white;"
//                                   "background-color: black;"
//                                   "gridline-color: rgb(0, 167, 250);");

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("color: rgb(0, 167, 250);;"
                                   "alternate-background-color: rgb(50, 50, 50);"
                                   "background-color: black;"
                                   "border-style: none;"
                                   "gridline-color: none;"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
    ui->tableWidget->horizontalHeader()->setFont(font1);
    ui->tableWidget->horizontalHeader()->setStyleSheet("border-style: none;"
                                                       "border-bottom: 1px solid #00a7fa;"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "border-right: 1px solid #00a7fa;"
                                                       "QHeaderView::section:vertical{"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "}"
                                                       "QHeaderView::section:horizontal{"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "}");
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setFont(font2);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setWordWrap(true);


    ui->tableWidget_2->setAlternatingRowColors(true);
    ui->tableWidget_2->setStyleSheet("color: rgb(0, 167, 250);;"
                                   "alternate-background-color: rgb(50, 50, 50);"
                                   "background-color: black;"
                                     "gridline-color: none;"
                                   "border-style: none;"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
//    ui->tableWidget_2->setStyleSheet("color: white;"
//                                   "background-color: black;"
//                                   "gridline-color: rgb(0, 167, 250);");
    ui->tableWidget_2->horizontalHeader()->setFont(font1);
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("border-style: none;"
                                                       "border-bottom: 1px solid #00a7fa;"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "border-right: 1px solid #00a7fa;"
                                                       "QHeaderView::section:vertical{"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "}"
                                                       "QHeaderView::section:horizontal{"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "}");
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->setFont(font2);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setWordWrap(true);

    // table 3
    ui->tableWidget_3->setAlternatingRowColors(true);
    ui->tableWidget_3->setStyleSheet("color: rgb(0, 167, 250);;"
                                   "alternate-background-color: rgb(50, 50, 50);"
                                   "background-color: black;"
                                     "gridline-color: none;"
                                   "border-style: none;"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
    ui->tableWidget_3->horizontalHeader()->setFont(font1);
    ui->tableWidget_3->horizontalHeader()->setStyleSheet("border-style: none;"
                                                       "border-bottom: 1px solid #00a7fa;"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "border-right: 1px solid #00a7fa;"
                                                       "QHeaderView::section:vertical{"
                                                       "border-left: 1px solid #00a7fa;"
                                                       "}"
                                                       "QHeaderView::section:horizontal{"
                                                       "border-top: 1px solid #00a7fa;"
                                                       "}");
    ui->tableWidget_3->verticalHeader()->setVisible(false);
    ui->tableWidget_3->setFont(font2);
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_3->setWordWrap(true);

    ui->label_quitar_filtros->setFont(font4);
    ui->label_quitar_filtros->setStyleSheet("background-color: transparent;"
                                         "color: rgb(0, 167, 250);");
    ui->label_filtro_fecha->setFont(font4);
    ui->label_filtro_fecha->setStyleSheet("background-color: transparent;"
                                         "color: rgb(0, 167, 250);");
    ui->label_2->setFont(font3);
    ui->label_2->setAlignment(Qt::AlignCenter);

    ui->label_horas->setFont(font4);
    ui->label_horas->setAlignment(Qt::AlignRight);

//    ui->button_OK->setStyleSheet("border: 2px solid rgb(0, 167, 250);");
//    ui->button_STOP->setStyleSheet("border: 2px solid red;");
//    ui->button_Reschedule->setStyleSheet("border: 2px solid rgb(0, 167, 250);");

//    ui->tabWidget->setStyleSheet();

    init_tables();

    connect(ui->tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected_all(QTableWidgetItem*)));
    connect(ui->tableWidget_2, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected(QTableWidgetItem*)));

    //Scroll
    QScroller *scroller = QScroller::scroller(ui->tableWidget);
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->tableWidget,QScroller::LeftMouseButtonGesture);

    //Scroll
    QScroller *scroller_2 = QScroller::scroller(ui->tableWidget_2);
    ui->tableWidget_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget_2->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties_2 = QScroller::scroller(scroller_2)->scrollerProperties();
    QVariant overshootPolicy_2 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_2.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    properties_2.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    //Scrolling Gesture
    scroller_2->grabGesture(ui->tableWidget_2,QScroller::LeftMouseButtonGesture);

    //Scroll
    QScroller *scroller_3 = QScroller::scroller(ui->tableWidget_3);
    ui->tableWidget_3->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget_3->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties_3 = QScroller::scroller(scroller_3)->scrollerProperties();
    QVariant overshootPolicy_3 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_3.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_3);
    scroller_3->setScrollerProperties(properties_3);
    properties_3.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy_3);
    scroller_3->setScrollerProperties(properties_3);
    //Scrolling Gesture
    scroller_3->grabGesture(ui->tableWidget_3,QScroller::LeftMouseButtonGesture);

    this->move(parent->pos());
//    this->show();
}

bitacora::~bitacora()
{
    delete ui;
}

void bitacora::on_top_menu_3_clicked()
{
    release_lock();
    this->close();
}
void bitacora::on_top_menu_2_clicked()
{
    release_lock();
    this->close();
}

void bitacora::init_tables()
{

    init_full_table();
    init_active_table();
    init_registros_table();

    init_completed = true;
}

void bitacora::update_table()
{
    if( true == init_completed)
    {
        update_full_table();
        update_active_table();
    }
}




void bitacora::init_full_table()
{
    QStringList titulos;

    titulos << "ID" << "Rutina" << "Periodo" << "Ultimo" << "Siguiente" << "Origen";
    ui->tableWidget->setColumnCount(titulos.size());
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    uint i;
    for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
    {

        add_row_rutina(i, i, ui->tableWidget);

        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->setColumnWidth(0, 35);
        ui->tableWidget->setColumnWidth(1, 350);
        ui->tableWidget->setColumnWidth(2, 70);
        ui->tableWidget->setColumnWidth(3, 90);
        ui->tableWidget->setColumnWidth(4, 90);
    }
}

void bitacora::update_full_table()
{
    QDateTime *temp_date;
//    qDebug() << "update_table";
    uint i;
    for(i = 0; i < rutina_ptr->num_of_rutinas; i++)
    {

        temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->last_event(i)));
        ui->tableWidget->setItem(i, LAST, new QTableWidgetItem(temp_date->toString()));

        temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->next_event(i)));
        ui->tableWidget->setItem(i, NEXT, new QTableWidgetItem(temp_date->toString()));

//        ui->tableWidget->resizeColumnsToContents();
    }
}

void bitacora::init_registros_table()
{
    QStringList titulos;

    titulos << "ID" << "Rutina" << "Fecha" << "Pregunta" << "Valor";
    ui->tableWidget_3->setColumnCount(titulos.size());
    ui->tableWidget_3->setHorizontalHeaderLabels(titulos);

    add_row_registro("SELECT * FROM log;", ui->tableWidget_3);
}

void bitacora::init_active_table()
{
    uint i;
    QString *temp_name;
    QDateTime *temp_date;
    QStringList titulos;

    titulos << "ID" << "Rutina" << "Periodo" << "Ultimo" << "Actual" << "Origen";
    ui->tableWidget_2->setColumnCount(titulos.size());
    ui->tableWidget_2->setHorizontalHeaderLabels(titulos);

    ui->tableWidget_2->setColumnWidth(0, 35);
    ui->tableWidget_2->setColumnWidth(1, 350);
    ui->tableWidget_2->setColumnWidth(2, 70);
    ui->tableWidget_2->setColumnWidth(3, 90);
    ui->tableWidget_2->setColumnWidth(4, 90);

    uint fila = 0;
    for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
    {
        if(0 == rutina_ptr->ready(i))
        {
            ui->tableWidget_2->insertRow(fila);

            ui->tableWidget_2->setItem(fila,ID, new QTableWidgetItem(QString::number(rutina_ptr->id(i))));

            ui->tableWidget_2->setItem(fila,NOMBRE, new QTableWidgetItem(rutina_ptr->nombre(i)));

            switch(rutina_ptr->periodo(i))
            {
            case RUTINA_DIA:
                temp_name = new QString("Diario");
                break;
            case RUTINA_SEMANA:
                temp_name = new QString("Semanal");
                break;
            case RUTINA_MES:
                temp_name = new QString("Mensual");
                break;
            case RUTINA_ANIO:
                temp_name = new QString("Anual");
                break;
            case SIN_RUTINA:
            default:
                temp_name = new QString("Sin Rutina");
                break;
            }
            ui->tableWidget_2->setItem(fila, PERIODO, new QTableWidgetItem(*temp_name));

            temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->last_event(i)));
            ui->tableWidget_2->setItem(fila, LAST, new QTableWidgetItem(temp_date->toString()));

            temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->next_event(i)));
            ui->tableWidget_2->setItem(fila, NEXT, new QTableWidgetItem(temp_date->toString()));

            switch(rutina_ptr->origen(i))
            {
            case ORIGEN_GENERAL:
                temp_name = new QString("General");
                break;
            case ORIGEN_REGULADOR:
                temp_name = new QString("Regulador");
                break;
            case ORIGEN_REACTOR:
                temp_name = new QString("Reactor Biológico");
                break;
            case ORIGEN_CLARIFICADOR:
                temp_name = new QString("Clarificador");
                break;
            case ORIGEN_CLORADOR:
                temp_name = new QString("Clorador");
                break;
            case ORIGEN_SECADO:
                temp_name = new QString("Secado");
                break;
            case ORIGEN_DIGESTOR:
                temp_name = new QString("Digestor");
                break;
            case ORIGEN_AFLUENTE:
                temp_name = new QString("Afluente");
                break;
            case ORIGEN_EFLUENTE:
                temp_name = new QString("Efluente");
                break;
            case ORIGEN_FILTRO:
                temp_name = new QString("Filtro");
                break;
            default:
                temp_name = new QString("Otro");
                break;
            }
            ui->tableWidget_2->setItem(fila, ORIGEN, new QTableWidgetItem(*temp_name));

            fila++;
        }
    }

    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->setColumnWidth(0, 35);
    ui->tableWidget_2->setColumnWidth(1, 350);
    ui->tableWidget_2->setColumnWidth(2, 70);
    ui->tableWidget_2->setColumnWidth(3, 90);
    ui->tableWidget_2->setColumnWidth(4, 90);
}

void bitacora::update_active_table()
{
    uint i = 0, row = 0;
    bool item_found = false;

    //Add new elements to the table
    for(i = 0; i < rutina_ptr->num_of_rutinas; i++)
    {
        if(0 == rutina_ptr->ready(i))
        {
            for(row = 0; row < (uint)ui->tableWidget_2->rowCount() ; row++)
            {
                if((uint)ui->tableWidget_2->item(row,0)->text().toInt() == rutina_ptr->id(i))
                {
                    item_found = true;
                    break;
                }
            }
            if(!item_found)
            {
                add_row_rutina(ui->tableWidget_2->rowCount(), i, ui->tableWidget_2);
            }
        }
        item_found = false;
    }


    // Remove elelents
    for(i = 0; i < rutina_ptr->num_of_rutinas; i++)
    {
        if(1 == rutina_ptr->ready(i))
        {
            for(row = 0; row < (uint)ui->tableWidget_2->rowCount() ; row++)
            {
                if((uint)ui->tableWidget_2->item(row,0)->text().toInt() == rutina_ptr->id(i))
                {
                    item_found = true;
                    break;
                }
            }

            if(item_found)
            {
                delete_row(row, ui->tableWidget_2);
            }
        }
        item_found = false;
    }
}

void bitacora::add_row_rutina(uint row, uint rutina, QTableWidget *table)
{
    QString *temp_name;
    QDateTime *temp_date;

    table->insertRow(row);

    table->setItem(row,ID, new QTableWidgetItem(QString::number(rutina_ptr->id(rutina))));

    table->setItem(row,NOMBRE, new QTableWidgetItem(rutina_ptr->nombre(rutina)));

    switch(rutina_ptr->periodo(rutina))
    {
    case RUTINA_DIA:
        temp_name = new QString("Diario");
        break;
    case RUTINA_SEMANA:
        temp_name = new QString("Semanal");
        break;
    case RUTINA_MES:
        temp_name = new QString("Mensual");
        break;
    case RUTINA_ANIO:
        temp_name = new QString("Anual");
        break;
    case SIN_RUTINA:
    default:
        temp_name = new QString("Sin Rutina");
        break;
    }
    table->setItem(row, PERIODO, new QTableWidgetItem(*temp_name));

    temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->last_event(rutina)));
    table->setItem(row, LAST, new QTableWidgetItem(temp_date->toString()));

    temp_date = new QDateTime(QDateTime::fromTime_t(rutina_ptr->next_event(rutina)));
    table->setItem(row, NEXT, new QTableWidgetItem(temp_date->toString()));

    switch(rutina_ptr->origen(rutina))
    {
    case ORIGEN_GENERAL:
        temp_name = new QString("General");
        break;
    case ORIGEN_REGULADOR:
        temp_name = new QString("Regulador");
        break;
    case ORIGEN_REACTOR:
        temp_name = new QString("Reactor Biológico");
        break;
    case ORIGEN_CLARIFICADOR:
        temp_name = new QString("Clarificador");
        break;
    case ORIGEN_CLORADOR:
        temp_name = new QString("Clorador");
        break;
    case ORIGEN_SECADO:
        temp_name = new QString("Secado");
        break;
    case ORIGEN_DIGESTOR:
        temp_name = new QString("Digestor");
        break;
    case ORIGEN_AFLUENTE:
        temp_name = new QString("Afluente");
        break;
    case ORIGEN_EFLUENTE:
        temp_name = new QString("Efluente");
        break;
    case ORIGEN_FILTRO:
        temp_name = new QString("Filtro");
        break;
    default:
        temp_name = new QString("Otro");
        break;
    }
    table->setItem(row, ORIGEN, new QTableWidgetItem(*temp_name));

    table->resizeRowsToContents();
    table->setColumnWidth(0, 35);
    table->setColumnWidth(1, 350);
    table->setColumnWidth(2, 70);
    table->setColumnWidth(3, 90);
    table->setColumnWidth(4, 90);
}

void bitacora::add_row_registro(QString sql_query, QTableWidget *table)
{
    QSqlQuery q;
    QSqlQuery question_query;

    uint row = 0;
    uint question_id;
    QDateTime *temp_date;

    qDebug() << "QUERY: " << sql_query;

    if(!q.prepare(sql_query)) qDebug() << "Failed to prepare";

//    q.bindValue(":id_found",rutina_def_table[i].id);
    if(!q.exec()) qDebug() << "Failed to execute";

    //titulos << "ID" << "Rutina" << "Fecha" << "Pregunta" << "Valor";
    while (q.next())
    {
        table->insertRow(row);

        table->setItem(row,0, new QTableWidgetItem(q.value("rutina_id").toString()));
        table->setItem(row,1, new QTableWidgetItem(q.value("rutina_name").toString()));

        temp_date = new QDateTime(QDateTime::fromTime_t(q.value("log_date").toInt()));
        table->setItem(row,2, new QTableWidgetItem(temp_date->toString()));

        table->setItem(row,3, new QTableWidgetItem(q.value("record_name").toString()));

        //get question type
        question_id = q.value("record_id").toInt();
        if(!question_query.prepare("SELECT * FROM records WHERE id = :id_found"))
        {
            qDebug() << "Failed to prepare";
        }
        else
        {
            question_query.bindValue(":id_found",question_id);
            if(!question_query.exec())
            {
                qDebug() << "Failed to execute";
            }
            else
            {
                while (question_query.next())
                {
                    if("NUMBER" == question_query.value("type").toString())
                    {
                        // This is a number, retrieve the actual number
                        table->setItem(row,4, new QTableWidgetItem(q.value("record_value").toString()));
                    }
                    else
                    {
                        // This is a option type, cross reference the name
                        if(1 == q.value("record_value").toInt())
                        {
                            table->setItem(row,4, new QTableWidgetItem(question_query.value("field_1").toString()));
                        }
                        else if(2 == q.value("record_value").toInt())
                        {
                            table->setItem(row,4, new QTableWidgetItem(question_query.value("field_2").toString()));
                        }
                        else if(3 == q.value("record_value").toInt())
                        {
                            table->setItem(row,4, new QTableWidgetItem(question_query.value("field_3").toString()));
                        }
                    }
                }
            }
        }



        row++;
        table->resizeRowsToContents();
        table->setColumnWidth(0, 35);
        table->setColumnWidth(1, 300);
        table->setColumnWidth(2, 120);
        table->setColumnWidth(3, 200);
        table->setColumnWidth(4, 70);
    }
}

void bitacora::delete_row(uint row, QTableWidget *table)
{
    table->removeRow(row);
}

void bitacora::item_selected(QTableWidgetItem* item)
{
    QTableWidget *table = item->tableWidget();
    ui->label_2->setText(table->item(item->row(), 1)->text());
    selected_id = table->item(item->row(), 0)->text().toInt();
    reschedule_time = 0;
    ui->label_horas->setText("");
//    qDebug() << "ID " << selected_id;
}

void bitacora::item_selected_all(QTableWidgetItem* item)
{
    QTableWidget *table = item->tableWidget();
    ui->label_3->setText(table->item(item->row(), 1)->text());
    selected_id = table->item(item->row(), 0)->text().toInt();
    qDebug() << "ID " << selected_id;
}

void bitacora::on_key_Reschedule_clicked()
{
    uint i = 0;
    uint periodo;
    if(NULL != calendar_window)
    {
        delete calendar_window;
    }

    for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
    {
        if(rutina_ptr->id(i) == selected_id)
        {
            periodo = rutina_ptr->periodo(i);
            break;
        }
    }
    calendar_window = new calendar(MainWindow::time, periodo, this);
    connect(calendar_window, SIGNAL(send_calendar_date(uint,QDate)), this, SLOT(receive_date(uint,QDate)));
}

void bitacora::receive_date(uint hora, QDate date)
{
    QDateTime *temp = new QDateTime(date);
    ui->label_horas->setText(date.toString("yyyy-MM-dd") + " " + QString::number(hora) + ":00");

    *temp = temp->addSecs(60 * 60 * hora);
    reschedule_time = temp->toTime_t();
    delete temp;
}

void bitacora::update_datetime(QDateTime datetime)
{
    qDebug() << datetime;
    uint i = 0;
    reschedule_time = datetime.toTime_t();
    if(0 != selected_id)
    {
        for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
        {
            if(rutina_ptr->id(i) == selected_id)
            {
                qDebug() << "ID match at: " << i;

                if(reschedule_time > 0)
                {
                    rutina_ptr->reschedule_rutina(i, reschedule_time);
                    rutina_ptr->update_rutina(i);
                }
                break;
            }
        }
    }
}

void bitacora::on_key_OK_clicked()
{
    uint i = 0;
    QStringList list_records;
    uint record_idx = 0;
    QString record_ID;
    records *rec_ptr;

    if(0 != selected_id)
    {
//        qDebug() << "Button clicked ID: " << selected_id;
        for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
        {
            if(rutina_ptr->id(i) == selected_id)
            {
                qDebug() << "ID match at: " << i;

                if(reschedule_time > 0)
                {
                    rutina_ptr->reschedule_rutina(i, reschedule_time);
                }
                else
                {
                    rutina_ptr->complete_rutina(i);
                    list_records = rutina_ptr->texto_ayuda(i).split(',');
//                    qDebug() << "SPLIT: " << list_records << "len: " << list_records.length();
                    if(list_records.length() > 0)
                    {
                        for(record_idx = 0; record_idx < (uint)list_records.length(); record_idx++)
                        {
                            record_ID = list_records.at(record_idx);
                            if(record_ID != "")
                            {
                                rec_ptr = new records("rutinas.db", record_ID.toInt(),
                                                      selected_id,
                                                      rutina_ptr->get_current_time().toTime_t(),
                                                      this);
                            }
                        }
                    }
                }
                break;
            }
        }

    }

    ui->label_2->setText("SELECIONAR UNA RUTINA DE LA LISTA");
}



void bitacora::on_key_Reschedule_2_clicked()
{
    uint i = 0;
    uint periodo;
    if(NULL != calendar_window)
    {
        delete calendar_window;
    }

    for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
    {
        if(rutina_ptr->id(i) == selected_id)
        {
            periodo = rutina_ptr->periodo(i);
            break;
        }
    }
    calendar_window = new calendar(MainWindow::time, 0, this);
    connect(calendar_window, SIGNAL(send_calendar_datetime(QDateTime)), this, SLOT(update_datetime(QDateTime)));
}

void bitacora::on_log_button_clicked()
{
    // Delete all rows in registros table, and prepare new query
    if( 0 != selected_id)
    {
        ui->tableWidget_3->setRowCount(0);
        add_row_registro("SELECT * FROM log WHERE rutina_id = "+QString::number(selected_id), ui->tableWidget_3);
        ui->tabWidget->setCurrentIndex(2);
    }
}

void bitacora::on_clear_filters_clicked()
{
    ui->tableWidget_3->setRowCount(0);
    add_row_registro("SELECT * FROM log", ui->tableWidget_3);
    ui->tabWidget->setCurrentIndex(3);

    filtro_fecha_inicio = 0;
    filtro_fecha_fin = 0;

}



void bitacora::on_filtro_fecha_clicked()
{
    if(calendario_window != NULL)
    {
        delete calendario_window;
    }

    calendario_window = new calendario_filtro(this);
    connect(calendario_window, SIGNAL(send_fechas(uint,uint)),
            this, SLOT(filtro_fecha_received(uint,uint)));

}

void bitacora::filtro_fecha_received(uint ini, uint end)
{
    filtro_fecha_inicio = ini;
    filtro_fecha_fin = end;
    // Delete all rows in registros table, and prepare new query
    if( 0 != filtro_fecha_fin &&
            0 != filtro_fecha_inicio &&
            filtro_fecha_fin > filtro_fecha_inicio)
    {
        ui->tableWidget_3->setRowCount(0);
        //SELECT * FROM log WHERE log_date BETWEEN 1537106400 and 1537279200
        add_row_registro("SELECT * FROM log WHERE log_date BETWEEN "+
                         QString::number(filtro_fecha_inicio) +
                         " and "+
                         QString::number(filtro_fecha_fin), ui->tableWidget_3);
        ui->tabWidget->setCurrentIndex(2);
    }

}
