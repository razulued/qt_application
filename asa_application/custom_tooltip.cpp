#include "custom_tooltip.h"
#include "parameters.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QSettings>

QPoint offset;


custom_tooltip::custom_tooltip(QWidget *frame, QList<int> list, QStringList names, QList<int> out_list, QStringList out_names, QWidget *mainwindow, QWidget *connect_to) : QWidget(frame)
{

    parent_window = mainwindow;
    parent_frame = frame;
    connect_here = connect_to;
//    parent_frame->setStyleSheet("color: rgb(0, 167, 250);"
//                                "border-style: solid;"
//                                "border-color: rgb(0, 167, 250);"
//                                "border-width: 1px;");
    parent_frame->setStyleSheet("border-image: url(:/iconos/images/Iconos/Globo_azul.png);"
                                "");

    layout = new QVBoxLayout(frame);
    layout->setAlignment(Qt::AlignTop);

    list_widget = new QListWidget();
    list_widget->clear();
    list_widget->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);"
                                    "border: none;"
                               "border-image: none;");
    connect(list_widget, SIGNAL (itemPressed(QListWidgetItem *)),this, SLOT (ListPressed()));
    connect(list_widget, SIGNAL (itemClicked(QListWidgetItem *)),this, SLOT (ListReleased()));


    DataList = list;
    NameList = names;

    OutDataList = out_list;
    OutNameList = out_names;

    item_is_pressed = false;

//    parent_frame->setGeometry(30, 30, parent_frame->x(), parent_frame->y());
////    QSettings settings("ASA_app", "tool_tip_geometry");
////        restoreGeometry(settings.value("geometry").toByteArray());

    init_data();
}

void custom_tooltip::init_data()
{
    QFont font_2("Typo Square Ligth Demo",12,1);
    list_widget->setFont(font_2);

    quint32 i, param_id;
    int items = 0;

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        if(true == getParamActiveShow(param_id))
        {
            list_widget->addItem(NameList[i] + ": " + getParamValue(param_id));
            items++;
        }
    }

    if(items>0)
    {
        list_widget->setMaximumWidth(list_widget->sizeHintForColumn(0) + 5);
        list_widget->setMaximumHeight(list_widget->sizeHintForRow(items-1)*items);
        list_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        layout->addWidget(list_widget);
        parent_frame->setLayout(layout);

        parent_frame->adjustSize();
        parent_frame->show();
    }
    else
    {
        parent_frame->hide();
    }
}

void custom_tooltip::update_data()
{
    QFont font_2("Typo Square Ligth Demo",12,1);
    quint32 i, param_id;
    int items = 0;

    list_widget->clear();
    list_widget->setFont(font_2);


    if(true == item_is_pressed)
    {
        parent_frame->move(mapTo(parent_window, mapFromGlobal(QCursor::pos()) - offset));
    }


    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        if(true == getParamActiveShow(param_id))
        {
            list_widget->addItem(NameList[i] + ": " + getParamValue(param_id));
            items++;
        }
    }

    if(items>0)
    {
        list_widget->setMaximumWidth(list_widget->sizeHintForColumn(0) + 5);
        list_widget->setMaximumHeight(list_widget->sizeHintForRow(items-1)*items);
        list_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        layout->addWidget(list_widget);
        parent_frame->adjustSize();
        parent_frame->show();
    }
    else
    {
        parent_frame->hide();
    }
}


void custom_tooltip::force_show()
{

    quint32 i, param_id;
    int items = 0;

    list_widget->clear();


    if(true == item_is_pressed)
    {
        parent_frame->move(mapTo(parent_window, mapFromGlobal(QCursor::pos()) - offset));
    }


    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        list_widget->addItem(NameList[i]  + ": " + getParamValue(param_id));
        items++;
    }

    if(items>0)
    {
        list_widget->setMaximumWidth(list_widget->sizeHintForColumn(0) + 5);
        list_widget->setMaximumHeight(list_widget->sizeHintForRow(items-1)*items);
        list_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        layout->addWidget(list_widget);
//        parent_frame->setLayout(layout);

        parent_frame->adjustSize();
        parent_frame->show();
    }
    else
    {
        parent_frame->hide();
    }
}

void custom_tooltip::force_hide()
{
    parent_frame->hide();
}

void custom_tooltip::ListPressed()
{
//    update_data();
//    qDebug() << "HOLA MUNDO";
//    QPoint offset = parent_window->mapFromGlobal(QCursor::pos());
//    QPoint p = parent_frame->mapFromGlobal(QCursor::pos());
//    qDebug() << offset;
//    parent_frame->move(mapTo(parent_window, event->pos() - offset));
    if(item_is_pressed == false)
    {
        item_is_pressed = true;
        qDebug() << "click true";
        offset = mapFromGlobal(QCursor::pos());
    }
    else
    {
        item_is_pressed = false;
        qDebug() << "click false";

        //Save tool tip position
//        QSettings settings("ASA_app", "tool_tip_geometry");
//        settings.setValue("geometry", saveGeometry());
    }

//    QCursor::setPos(p);
//    QMouseEvent *event = new QMouseEvent((QEvent)5,p,2,0,0);
//    custom_tooltip.mouseMoveEvent();
}

void custom_tooltip::ListReleased()
{
//    qDebug() << "Released";
}

void custom_tooltip::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
}

void custom_tooltip::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        parent_frame->move(mapTo(parent_window, event->pos() - offset));
    }
}
