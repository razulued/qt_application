#include "calendar.h"
#include "ui_calendar.h"
#include "clickeablelabel.h"
#include <QScroller>
#include <QScrollerProperties>
#include <QDebug>

calendar::calendar(QDateTime datetime, uint periodo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendar)
{
    ui->setupUi(this);

    this->setObjectName("Calendar");
    this->setStyleSheet("#Calendar{background-color: black;"
                        "border: none;}");

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QFont font("Typo Square Bold Italic Demo",12,1);
    QFont font_2("Typo Square Bold Italic Demo",14,1);
    ui->label->setFont(font_2);
    ui->label->setStyleSheet("color: black;"
                              "background-color: transparent;");

    ui->listWidget->setFont(font);
    ui->listWidget->setStyleSheet("background-color: black;"
                                  "color: white;");
    //Scroll
    QScroller *scroller = QScroller::scroller(ui->listWidget);
    ui->listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->listWidget->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->listWidget,QScroller::LeftMouseButtonGesture);


    // Add hours to list widget
    ui->listWidget->addItem("00:00");
    ui->listWidget->addItem("01:00");
    ui->listWidget->addItem("02:00");
    ui->listWidget->addItem("03:00");
    ui->listWidget->addItem("04:00");
    ui->listWidget->addItem("05:00");
    ui->listWidget->addItem("06:00");
    ui->listWidget->addItem("07:00");
    ui->listWidget->addItem("08:00");
    ui->listWidget->addItem("09:00");
    ui->listWidget->addItem("10:00");
    ui->listWidget->addItem("11:00");
    ui->listWidget->addItem("12:00");
    ui->listWidget->addItem("13:00");
    ui->listWidget->addItem("14:00");
    ui->listWidget->addItem("15:00");
    ui->listWidget->addItem("16:00");
    ui->listWidget->addItem("17:00");
    ui->listWidget->addItem("18:00");
    ui->listWidget->addItem("19:00");
    ui->listWidget->addItem("20:00");
    ui->listWidget->addItem("21:00");
    ui->listWidget->addItem("22:00");
    ui->listWidget->addItem("23:00");

    ui->listWidget->item(9)->setSelected(true);

    ui->calendarWidget->setCurrentPage(datetime.date().year(), datetime.date().month());
    ui->calendarWidget->setSelectedDate(datetime.date());
    ui->calendarWidget->setStyleSheet("background-color: white;"
                                      "color: black");

    if(periodo == 1)
    {
        ui->calendarWidget->setEnabled(false);
    }

    this->move(parent->pos());
    this->show();}

calendar::~calendar()
{
    delete ui;
}

void calendar::background_clicked()
{
    this->close();
}

void calendar::on_push_aceptar_clicked()
{
//    qDebug() << "hora " << ui->listWidget->row(ui->listWidget->selectedItems().at(0)) << "date " << ui->calendarWidget->selectedDate();
    send_calendar_date(ui->listWidget->row(ui->listWidget->selectedItems().at(0)), ui->calendarWidget->selectedDate());

    //Build date time
    QDateTime datetime;

    datetime.setDate(ui->calendarWidget->selectedDate());
    QTime time(ui->listWidget->row(ui->listWidget->selectedItems().at(0)),0,0);
    datetime.setTime(time);
    send_calendar_datetime(datetime);

    this->close();
}

void calendar::on_push_cancelar_clicked()
{
    this->close();
}
