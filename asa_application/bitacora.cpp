#include "bitacora.h"
#include "ui_bitacora.h"
#include <QDateTime>
#include <QLabel>
#include <QScroller>
#include <QScrollerProperties>

// rgb(0, 167, 250)

bitacora::bitacora(rutinas_mantenimiento *rutina, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bitacora)
{
    init_completed = false;

    ui->setupUi(this);
    rutina_ptr = rutina;

    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    QFont font0("Typo Square Bold Demo",20,1);
    QFont font1("Typo Square Italic Demo",14,1);
    QFont font2("Typo Square Italic Demo",12,1);
    QFont font3("Typo Square Bold Demo",16,1);

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

    ui->label_2->setFont(font3);
    ui->label_2->setAlignment(Qt::AlignCenter);

    ui->label_horas->setFont(font3);
    ui->label_horas->setAlignment(Qt::AlignRight);

//    ui->button_OK->setStyleSheet("border: 2px solid rgb(0, 167, 250);");
//    ui->button_STOP->setStyleSheet("border: 2px solid red;");
//    ui->button_Reschedule->setStyleSheet("border: 2px solid rgb(0, 167, 250);");

//    ui->tabWidget->setStyleSheet();

    init_tables();

//    connect(ui->tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected(QTableWidgetItem*)));
    connect(ui->tableWidget_2, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected(QTableWidgetItem*)));

    //Scroll
    QScroller *scroller = QScroller::scroller(ui->tableWidget);
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    ui->tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);

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
    ui->tableWidget_2->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    ui->tableWidget_2->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);

    QScrollerProperties properties_2 = QScroller::scroller(scroller_2)->scrollerProperties();
    QVariant overshootPolicy_2 = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties_2.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    properties_2.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy_2);
    scroller_2->setScrollerProperties(properties_2);
    //Scrolling Gesture
    scroller_2->grabGesture(ui->tableWidget_2,QScroller::LeftMouseButtonGesture);

    this->show();
}

bitacora::~bitacora()
{
    delete ui;
}

void bitacora::on_top_menu_3_clicked()
{
    this->close();
}
void bitacora::on_top_menu_2_clicked()
{
    this->close();
}

void bitacora::init_tables()
{

    init_full_table();
    init_active_table();

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

void bitacora::on_key_0_clicked() {insert_amount("0");}
void bitacora::on_key_1_clicked() {insert_amount("1");}
void bitacora::on_key_2_clicked() {insert_amount("2");}
void bitacora::on_key_3_clicked() {insert_amount("3");}
void bitacora::on_key_4_clicked() {insert_amount("4");}
void bitacora::on_key_5_clicked() {insert_amount("5");}
void bitacora::on_key_6_clicked() {insert_amount("6");}
void bitacora::on_key_7_clicked() {insert_amount("7");}
void bitacora::on_key_8_clicked() {insert_amount("8");}
void bitacora::on_key_9_clicked() {insert_amount("9");}

void bitacora::on_key_back_clicked()
{
    posponer_amount.chop(1);
    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
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
        ui->tableWidget->setColumnWidth(0, 45);
        ui->tableWidget->setColumnWidth(1, 450);
        ui->tableWidget->setColumnWidth(2, 90);
        ui->tableWidget->setColumnWidth(3, 120);
        ui->tableWidget->setColumnWidth(4, 120);
    }
}

void bitacora::update_full_table()
{
    QDateTime *temp_date;
    QString *temp_name;
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

void bitacora::init_active_table()
{
    uint i;
    QString *temp_name;
    QDateTime *temp_date;
    QStringList titulos;

    titulos << "ID" << "Rutina" << "Periodo" << "Ultimo" << "Actual" << "Origen";
    ui->tableWidget_2->setColumnCount(titulos.size());
    ui->tableWidget_2->setHorizontalHeaderLabels(titulos);

    ui->tableWidget_2->setColumnWidth(0, 45);
    ui->tableWidget_2->setColumnWidth(1, 450);
    ui->tableWidget_2->setColumnWidth(2, 90);
    ui->tableWidget_2->setColumnWidth(3, 120);
    ui->tableWidget_2->setColumnWidth(4, 120);

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
            default:
                temp_name = new QString("Otro");
                break;
            }
            ui->tableWidget_2->setItem(fila, ORIGEN, new QTableWidgetItem(*temp_name));

            fila++;
        }
    }

    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->setColumnWidth(0, 45);
    ui->tableWidget_2->setColumnWidth(1, 450);
    ui->tableWidget_2->setColumnWidth(2, 90);
    ui->tableWidget_2->setColumnWidth(3, 120);
    ui->tableWidget_2->setColumnWidth(4, 120);
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
            for(row = 0; row < ui->tableWidget_2->rowCount() ; row++)
            {
                if(ui->tableWidget_2->item(row,0)->text().toInt() == rutina_ptr->id(i))
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
            for(row = 0; row < ui->tableWidget_2->rowCount() ; row++)
            {
                if(ui->tableWidget_2->item(row,0)->text().toInt() == rutina_ptr->id(i))
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
    default:
        temp_name = new QString("Otro");
        break;
    }
    table->setItem(row, ORIGEN, new QTableWidgetItem(*temp_name));

    table->resizeRowsToContents();
    table->setColumnWidth(0, 45);
    table->setColumnWidth(1, 450);
    table->setColumnWidth(2, 90);
    table->setColumnWidth(3, 120);
    table->setColumnWidth(4, 120);
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

    qDebug() << "ID " << selected_id;
}

void bitacora::on_key_Reschedule_clicked()
{
    if(++add_base == BASE_LAST)
    {
        add_base = 0;
    }

    switch(add_base)
    {
    case BASE_SEC:
        posponer_amount_units = "s";
        base_mult = 1;
        break;
    case BASE_MIN:
        posponer_amount_units = "m";
        base_mult = 60;
        break;
    case BASE_HOUR:
        posponer_amount_units = "h";
        base_mult = 3600;
        break;
    case BASE_DAY:
        posponer_amount_units = "d";
        base_mult = 3600 * 24;
        break;
//    case BASE_MON:
//        ui->label_horas->setText("Meses:");
//        base_mult = 3600 * 24 * 30;
//        break;
    }

    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}

void bitacora::on_key_OK_clicked()
{
    uint i = 0;
    uint time = 0;

    time = posponer_amount.toInt();

    if(0 != selected_id)
    {
        qDebug() << "Button clicked ID: " << selected_id;
        for(i = 0; i < rutina_ptr->num_of_rutinas ; i++)
        {
            if(rutina_ptr->id(i) == selected_id)
            {
                qDebug() << "ID match at: " << i;

                if(time > 0)
                {
                    time = time * base_mult;
                    rutina_ptr->add_seconds_rutina(i, time);
                }
                else
                {
                    rutina_ptr->complete_rutina(i);
                }
            }
        }

//        for(i = 0; i < ui->tableWidget->rowCount() ; i++)
//        {
//            if(ui->tableWidget->item(i,0)->text().toInt() == selected_id)
//            {
//                ui->tableWidget->removeRow(i);
//                break;
//            }
//        }
    }

    ui->label_2->setText("SELECIONAR UNA RUTINA DE LA LISTA");
}

void bitacora::insert_amount(QString ins)
{
    posponer_amount += ins;

    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}


