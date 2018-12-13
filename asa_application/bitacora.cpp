#include "bitacora.h"
#include "ui_bitacora.h"
#include <QDateTime>
#include <QLabel>
#include <QScroller>
#include <QScrollerProperties>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include "records.h"
#include "token_auth.h"
// rgb(0, 167, 250)

bitacora::bitacora(rutinas_mantenimiento *rutina, uint tab_ini, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bitacora)
{
    init_completed = false;

    ui->setupUi(this);
    rutina_ptr = rutina;

    QFont label_title_font("Typo Square Bold Demo",17,1);
    QFont ok_font("Typo Square Bold Demo",10,1);
    ui->key_OK->setFont(ok_font);

    ui->label_title->setFont(label_title_font);
    ui->label_title->setStyleSheet("Text-align:left;"
                                   "border:none;"
                                   "color:black;"
                                   "background-color:transparent;");
    ui->prof_label->setStyleSheet("color:white;");
    ui->prof_label->setText(get_user_name());
    selected_id = 0;
    selected_record = 0;
    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    ui->tabWidget->setCurrentIndex(tab_ini);

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    QSqlQuery q;
    if(q.prepare("SELECT MAX(log_date) FROM log"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                filtro_fecha_fin = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "on_clear_filters_clicked. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "on_clear_filters_clicked. Failed to prepare." << q.lastError();
    }

    if(q.prepare("SELECT MIN(log_date) FROM log"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                filtro_fecha_inicio = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "on_clear_filters_clicked. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "on_clear_filters_clicked. Failed to prepare." << q.lastError();
    }


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
    ui->label_filtro_record->setFont(font4);
    ui->label_filtro_record->setStyleSheet("background-color: transparent;"
                                         "color: rgb(0, 167, 250);");
    ui->label_mostrar_graficos->setFont(font4);
    ui->label_mostrar_graficos->setStyleSheet("background-color: transparent;"
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
    connect(ui->tableWidget_3, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected_registros(QTableWidgetItem*)));

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
//    release_lock();
//    this->close();
    ui->tabWidget->setCurrentIndex(2);
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

    titulos << tr("ID") << tr("Rutina") << tr("Periodo") << tr("Ultimo") << tr("Siguiente") << tr("Subsistema");
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

    titulos << tr("ID") << tr("Rutina") << tr("Fecha") << tr("ID") << tr("Pregunta") << tr("Valor") << tr("Usuario");
    ui->tableWidget_3->setColumnCount(titulos.size());
    ui->tableWidget_3->setHorizontalHeaderLabels(titulos);

    add_row_registro("SELECT * FROM log ORDER BY log_date DESC;", ui->tableWidget_3);
}

void bitacora::init_active_table()
{
    uint i;
    QString *temp_name;
    QDateTime *temp_date;
    QStringList titulos;

    titulos << tr("ID") << tr("Rutina") << tr("Periodo") << tr("Ultimo") << tr("Actual") << tr("Subsistema");
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
                temp_name = new QString(tr("Diario"));
                break;
            case RUTINA_SEMANA:
                temp_name = new QString(tr("Semanal"));
                break;
            case RUTINA_MES:
                temp_name = new QString(tr("Mensual"));
                break;
            case RUTINA_ANIO:
                temp_name = new QString(tr("Anual"));
                break;
            case SIN_RUTINA:
            default:
                temp_name = new QString(tr("Sin Rutina"));
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
                temp_name = new QString(tr("General"));
                break;
            case ORIGEN_REGULADOR:
                temp_name = new QString(tr("Regulador"));
                break;
            case ORIGEN_REACTOR:
                temp_name = new QString(tr("Reactor Biológico"));
                break;
            case ORIGEN_CLARIFICADOR:
                temp_name = new QString(tr("Clarificador"));
                break;
            case ORIGEN_CLORADOR:
                temp_name = new QString(tr("Clorador"));
                break;
            case ORIGEN_SECADO:
                temp_name = new QString(tr("Secado"));
                break;
            case ORIGEN_DIGESTOR:
                temp_name = new QString(tr("Digestor"));
                break;
            case ORIGEN_AFLUENTE:
                temp_name = new QString(tr("Afluente"));
                break;
            case ORIGEN_EFLUENTE:
                temp_name = new QString(tr("Efluente"));
                break;
            case ORIGEN_FILTRO:
                temp_name = new QString(tr("Filtro"));
                break;
            default:
                temp_name = new QString(tr("Otro"));
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

                // Reset table with all entries.
                // Registros
                ui->tableWidget->setRowCount(0);
                init_full_table();
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
        temp_name = new QString(tr("Diario"));
        break;
    case RUTINA_SEMANA:
        temp_name = new QString(tr("Semanal"));
        break;
    case RUTINA_MES:
        temp_name = new QString(tr("Mensual"));
        break;
    case RUTINA_ANIO:
        temp_name = new QString(tr("Anual"));
        break;
    case SIN_RUTINA:
    default:
        temp_name = new QString(tr("Sin Rutina"));
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
        temp_name = new QString(tr("General"));
        break;
    case ORIGEN_REGULADOR:
        temp_name = new QString(tr("Regulador"));
        break;
    case ORIGEN_REACTOR:
        temp_name = new QString(tr("Reactor Biológico"));
        break;
    case ORIGEN_CLARIFICADOR:
        temp_name = new QString(tr("Clarificador"));
        break;
    case ORIGEN_CLORADOR:
        temp_name = new QString(tr("Clorador"));
        break;
    case ORIGEN_SECADO:
        temp_name = new QString(tr("Secado"));
        break;
    case ORIGEN_DIGESTOR:
        temp_name = new QString(tr("Digestor"));
        break;
    case ORIGEN_AFLUENTE:
        temp_name = new QString(tr("Afluente"));
        break;
    case ORIGEN_EFLUENTE:
        temp_name = new QString(tr("Efluente"));
        break;
    case ORIGEN_FILTRO:
        temp_name = new QString(tr("Filtro"));
        break;
    default:
        temp_name = new QString(tr("Otro"));
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

    if(!q.exec()) qDebug() << "Failed to execute: add_row_registro()";

    //titulos << "ID" << "Rutina" << "Fecha" << "Pregunta" << "Valor";
    while (q.next())
    {
        table->insertRow(row);

        table->setItem(row,0, new QTableWidgetItem(q.value("rutina_id").toString()));
        table->setItem(row,1, new QTableWidgetItem(q.value("rutina_name").toString()));

        temp_date = new QDateTime(QDateTime::fromTime_t(q.value("log_date").toInt()));
        table->setItem(row,2, new QTableWidgetItem(temp_date->toString()));

        table->setItem(row,3, new QTableWidgetItem(q.value("record_id").toString()));
        table->setItem(row,4, new QTableWidgetItem(q.value("record_name").toString()));
        table->setItem(row,6, new QTableWidgetItem(q.value("user").toString()));

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
                qDebug() << "Failed to execute: add_row_registro() 2";
            }
            else
            {
                while (question_query.next())
                {
                    if("RESCHEDULE" == question_query.value("type").toString())
                    {
                        // This is a number (date), retrieve the actual number
                        QDateTime *temp_date;
                        temp_date = new QDateTime(QDateTime::fromTime_t(q.value("record_value").toInt()));
                        table->setItem(row,5, new QTableWidgetItem(temp_date->toString()));
                    }
                    if("COMPLETED" == question_query.value("type").toString())
                    {
                        // Set 0 for completed
                        table->setItem(row,5, new QTableWidgetItem("N/A"));
                    }
                    else if("NUMBER" == question_query.value("type").toString())
                    {
                        // This is a number, retrieve the actual number
                        table->setItem(row,5, new QTableWidgetItem(q.value("record_value").toString()));
                    }
                    else
                    {
                        // This is a option type, cross reference the name
                        if(1 == q.value("record_value").toInt())
                        {
                            table->setItem(row,5, new QTableWidgetItem(question_query.value("field_1").toString()));
                        }
                        else if(2 == q.value("record_value").toInt())
                        {
                            table->setItem(row,5, new QTableWidgetItem(question_query.value("field_2").toString()));
                        }
                        else if(3 == q.value("record_value").toInt())
                        {
                            table->setItem(row,5, new QTableWidgetItem(question_query.value("field_3").toString()));
                        }
                    }
                }
            }
        }



        row++;
        table->resizeRowsToContents();
        table->setColumnWidth(0, 35);
        table->setColumnWidth(1, 220);
        table->setColumnWidth(2, 120);
        table->setColumnWidth(3, 35);
        table->setColumnWidth(4, 180);
        table->setColumnWidth(5, 120);
        table->setColumnWidth(6, 65);
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
    ui->key_OK->setText(tr("Completado"));
//    qDebug() << "ID " << selected_id;
}

void bitacora::item_selected_all(QTableWidgetItem* item)
{
    QTableWidget *table = item->tableWidget();
    ui->label_3->setText(table->item(item->row(), 1)->text());
    selected_id = table->item(item->row(), 0)->text().toInt();
    qDebug() << "ID " << selected_id;
}

void bitacora::item_selected_registros(QTableWidgetItem* item)
{
    QTableWidget *table = item->tableWidget();
//    ui->label_2->setText(table->item(item->row(), 1)->text());
    selected_record = table->item(item->row(), 3)->text().toInt();
    qDebug() << "ID " << selected_record;
    if( (1 != table->item(item->row(), 3)->text().toInt()) &&
        (2 != table->item(item->row(), 3)->text().toInt()) )
    {
        ui->graph_button->show();
        ui->label_mostrar_graficos->show();
    }
    else
    {
        ui->graph_button->hide();
        ui->label_mostrar_graficos->hide();
    }
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

    qDebug() << "XXXX: date " << date;
    qDebug() << "XXXX: hora " << hora;

    *temp = temp->addSecs(60 * 60 * hora);
    reschedule_time = temp->toTime_t();
    qDebug() << "XXXX: temp " << *temp;
    qDebug() << "XXXX: reschedule_time " << reschedule_time;

    if(reschedule_time < MainWindow::time.toTime_t())
    {
        ui->label_2->setText(tr("Error: nueva fecha es menor a fecha actual"));
        ui->label_horas->setText("");
        ui->key_OK->setText(tr("Completado"));
        selected_id = 0;
        reschedule_time = 0;
    }
    else
    {
        ui->key_OK->setText(tr("Reagendar"));
        ui->label_2->setText(tr("SELECCIONAR UNA RUTINA DE LA LISTA"));
    }
    delete temp;
}

void bitacora::update_datetime(QDateTime datetime)
{

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
    uint items = 0;
    QStringList list_records;
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
                    qDebug() << "RESCH: " << reschedule_time;
                    rutina_ptr->reschedule_rutina(i, reschedule_time);

                    //update database
                    list_records.append("2"); /* #2 is reserved for reschedule */
                    rec_ptr = new records(tr("rutinas.db"),
                                          list_records,
                                          selected_id,
                                          rutina_ptr->get_current_time().toTime_t(),
                                          reschedule_time,
                                          this);
                    ui->label_horas->setText("");

                    // Update first two tables
                    update_table();

                    // When a routine is reschedule, update tab 3
                    ui->tableWidget_3->setRowCount(0);
                    init_registros_table();
                }
                else
                {
                    list_records = rutina_ptr->texto_ayuda(i).split(',');
                    // remove #2 from the list, it would cause to always report it.
                    for(items = 0; items < list_records.length(); items++)
                    {
                        if("2" == list_records.at(items))
                        {
                            list_records.removeAt(items);
                            break;
                        }
                    }

                    qDebug() << "SPLIT: " << list_records << "len: " << list_records.length();
                    if(list_records.length() > 0)
                    {
                        if(list_records.at(0) != "")
                        {
                            if(list_records.last() == "")
                            {
                                list_records.removeLast();
                            }

                            rec_ptr = new records(tr("rutinas.db"),
                                                  list_records,
                                                  selected_id,
                                                  rutina_ptr->get_current_time().toTime_t(),
                                                  reschedule_time,
                                                  this);

                            // Wait to be completed? release lock
                            connect(rec_ptr,SIGNAL(all_questions_ok(uint)),this,SLOT(activity_is_completed(uint)));
                        }
                        else
                        {
                            rutina_ptr->complete_rutina(i);
                        }
                    }
                    else
                    {
                        rutina_ptr->complete_rutina(i);
                    }
                }
                break;
            }
        }

    }

    ui->key_OK->setText(tr("Completado"));
    ui->label_2->setText(tr("SELECIONAR UNA RUTINA DE LA LISTA"));
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
        add_row_registro("SELECT * FROM log WHERE rutina_id = "+QString::number(selected_id)
                         + " ORDER BY log_date DESC", ui->tableWidget_3);
        ui->tabWidget->setCurrentIndex(2);
    }
}

void bitacora::on_clear_filters_clicked()
{
    QSqlQuery q;
    ui->tableWidget_3->setRowCount(0);
    add_row_registro("SELECT * FROM log ORDER BY log_date DESC", ui->tableWidget_3);
    ui->tabWidget->setCurrentIndex(3);

//    filtro_fecha_inicio = 0;
//    filtro_fecha_fin = 0;
    if(q.prepare("SELECT MAX(log_date) FROM log"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                filtro_fecha_fin = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "on_clear_filters_clicked. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "on_clear_filters_clicked. Failed to prepare." << q.lastError();
    }

    if(q.prepare("SELECT MIN(log_date) FROM log"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                filtro_fecha_inicio = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "on_clear_filters_clicked. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "on_clear_filters_clicked. Failed to prepare." << q.lastError();
    }
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
                         QString::number(filtro_fecha_fin) +
                         " ORDER BY log_date DESC", ui->tableWidget_3);
        ui->tabWidget->setCurrentIndex(2);
    }

}

void bitacora::on_filtro_record_clicked()
{
    // Delete all rows in registros table, and prepare new query
    if( 0 != selected_record)
    {
        ui->tableWidget_3->setRowCount(0);
        add_row_registro("SELECT * FROM log WHERE record_id = "+QString::number(selected_record) +
                         " ORDER BY log_date DESC", ui->tableWidget_3);
        ui->tabWidget->setCurrentIndex(2);
    }
}

void bitacora::on_graph_button_clicked()
{
    // Delete all rows in registros table, and prepare new query
    if( 0 != selected_record)
    {
        if(chart_window != NULL)
        {
            delete chart_window;
        }
        chart_window = new record_chart(selected_record, filtro_fecha_inicio, filtro_fecha_fin, this);
    }
}

void bitacora::on_top_menu_1_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void bitacora::on_top_menu_5_clicked()
{

}

void bitacora::activity_is_completed(uint id)
{
    uint i;
    qDebug() << "ACTIVITY COMPLETED " << id;
    for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
    {
        if(rutina_ptr->id(i) == id)
        {
            rutina_ptr->complete_rutina(i);

            // Update first two tables
            update_table();

            // When a routine is completed, update tab 3
            ui->tableWidget_3->setRowCount(0);
            init_registros_table();
            selected_id = 0;

            break;
        }
    }
}

void bitacora::on_tab1_to_bottom_clicked()
{
    ui->tableWidget_2->scrollToBottom();
}

void bitacora::on_tab1_to_top_clicked()
{
    ui->tableWidget_2->scrollToTop();
}

void bitacora::on_tab2_to_top_clicked()
{
    ui->tableWidget->scrollToTop();
}

void bitacora::on_tab2_to_bottom_clicked()
{
    ui->tableWidget->scrollToBottom();
}

void bitacora::on_tab3_to_top_clicked()
{
    ui->tableWidget_3->scrollToTop();
}

void bitacora::on_tab3_to_bottom_clicked()
{
    ui->tableWidget_3->scrollToBottom();
}

void bitacora::update_act_icon(uint num)
{
    if(num > 0)
    {
        ui->top_menu_1->setStyleSheet("background-color: transparent;"
                                      "background-image: url(:/iconos/screen800x600/iconos/Campana_amarillo.png);"
                                      "border: none;"
                                      "background-repeat: none;"
                                      "background-position: center;"
                                      );
        ui->num_of_act->setText(QString::number(num));
    }
    else
    {
        ui->top_menu_1->setStyleSheet("background-color: transparent;"
                                      "background-image: url(:/iconos/screen800x600/iconos/Campana.png);"
                                      "border: none;"
                                      "background-repeat: none;"
                                      "background-position: center;"
                                      );
        ui->num_of_act->setText("");
    }
}
