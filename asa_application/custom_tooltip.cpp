#include "custom_tooltip.h"
#include "protocol/asa_protocol.h"
#include "parameters.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QSettings>
#include <QDateTime>
#include <QTouchEvent>

#define HOLD_TIME (40)
QPoint offset;

uint custom_tooltip::tooltip_number = 0;

custom_tooltip::custom_tooltip(QWidget *frame, configuration_id &conf_list, QWidget *mainwindow, uint type) : QWidget(frame)
{

    element_type = type;
    parent_window = mainwindow;

    parent_frame = frame;
//    parent_frame->setStyleSheet("color: rgb(0, 167, 250);"
//                                "border-style: solid;"
//                                "border-color: rgb(0, 167, 250);"
//                                "border-width: 1px;");
    parent_frame->setObjectName("MyCustomTooltip");
    parent_frame->setStyleSheet("#MyCustomTooltip{border-image: url(:/iconos/images/Iconos/Globo_azul.png);}");

    layout = new QVBoxLayout(frame);
    layout->setAlignment(Qt::AlignTop);

    list_widget = new QListWidget();
    list_widget->setFocusPolicy(Qt::NoFocus);
    list_widget->clear();
    list_widget->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);"
                                    "border: none;"
                               "border-image: none;"
                               "font-weight: bold;");

    connect(list_widget, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT (ListPressed()));

    DataList = conf_list.ids;
    NameList = conf_list.names;

    item_is_pressed = false;

//    parent_frame->setGeometry(30, 30, parent_frame->x(), parent_frame->y());
    tooltip_number++;
    actual_tooltip_number = tooltip_number;
    QString filename = "./tooltips/tool"+QString::number(actual_tooltip_number);
    QFile myFile(filename);

    QDataStream in(&myFile);
    in.setVersion(QDataStream::Qt_5_7);

    QPoint pos = parent_frame->pos();
    if (!myFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not read the file:" << filename << "Error string:" << myFile.errorString();
        // Re-try later
        unknown_tool_pos.append(actual_tooltip_number);
        QTimer::singleShot(3000, this, SLOT(retry_tool_pos()));
    }
    else
    {
        in >> pos;
        init_data();
        qDebug() << "tool: " << actual_tooltip_number <<"pos " << pos;
    }

    if(pos.x() != 0 && pos.y() != 0)
    {
        parent_frame->move(pos);
    }
    myFile.close();

}

void custom_tooltip::init_data()
{
    /*QFont font_2("Typo Square Ligth Demo",10,1);*/
    QFont font_2("Liberation Mono Bold",10,1);
    list_widget->setFont(font_2);
    QListWidgetItem *label;


    quint32 i, param_id;
    int items = 0;

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        if(true == getParamActiveShow(param_id))
        {
            label = new QListWidgetItem(NameList[i] + ": " + getParamValue_and_units(param_id));
//            label->setTextFormat(Qt::RichText);

            list_widget->addItem(label);
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

void custom_tooltip::update_tooltip()
{
//    QFont font_2("Ubuntu Bold",10,1);
    QFont font_2("Liberation Mono Bold",10,1);

    quint32 i, param_id;
    int items = 0;

    list_widget->clear();
    QListWidgetItem *label;

    if(last_position != parent_frame->pos())
    {
        save_position();
    }


    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];
//        if(true == getParamActiveShow(param_id))
        if(1)
        {
            label = new QListWidgetItem(NameList[i] + ": " + getParamValue_and_units(param_id));
//            label->setTextFormat(Qt::RichText);

            list_widget->addItem(label);
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


//    if(true == item_is_pressed)
//    {
//        parent_frame->move(mapTo(parent_window, mapFromGlobal(QCursor::pos()) - offset));

//        if(0 == item_pressed_counter)
//        {
//            item_is_pressed = false;
//            list_widget->setStyleSheet("background: transparent;"
//                                          "color: rgb(0, 167, 250);"
//                                            "border: none;"
//                                       "border-image: none;");

//            save_position();
//        }
//        else if(last_position == parent_frame->pos())
//        {
//            item_pressed_counter--;
//        }

//        last_position = parent_frame->pos();
//    }
    if(last_position != parent_frame->pos())
    {
        save_position();
    }

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        list_widget->addItem(NameList[i]  + ": " + getParamValue_and_units(param_id));
//        list_widget->item(i)->setFlags(Qt::ItemIsEnabled);
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
    if(false == parent_frame->isHidden())
    {
        parent_frame->hide();
    }
}

void custom_tooltip::save_position()
{
    QString filename = "./tooltips/tool"+QString::number(actual_tooltip_number);
    QFile myFile(filename);
    if (!myFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not write to file:" << filename << "Error string:" << myFile.errorString();
    }
    else
    {
        QDataStream out(&myFile);
        out.setVersion(QDataStream::Qt_5_7);
        out << parent_frame->pos();
    }
    myFile.close();
}

void custom_tooltip::ListPressed()
{
    if(number_of_clicks++ == 0)
    {
        QTimer::singleShot(500, this, SLOT(checkClick()));
    }
}

void custom_tooltip::checkClick()
{
    if(number_of_clicks >= 2)
    {
//        if(item_is_pressed == false)
//        {
//            item_is_pressed = true;
//            offset = mapFromGlobal(QCursor::pos());
//            list_widget->setStyleSheet("background: white;"
//                                          "color: rgb(0, 167, 250);"
//                                            "border: none;"
//                                       "border-image: none;");
//            item_pressed_counter = HOLD_TIME;
//        }
//        else
//        {
//            item_is_pressed = false;
//            list_widget->setStyleSheet("background: transparent;"
//                                          "color: rgb(0, 167, 250);"
//                                            "border: none;"
//                                       "border-image: none;");
//            item_pressed_counter = 0;

//            save_position();
//        }

        if(NULL != arrow_key_window)
        {
            delete arrow_key_window;
        }
        arrow_key_window = new arrowkeys(this->parent_frame, this->parent_window);

    }
    else
    {
        if(item_is_pressed == false)
        {
            //Emit signal for graph
//            if(graph_ptr->isHidden())
//            {
//                graph_ptr->show_graph(element_type);
//                graph_ptr->set_type(graph_origin);
//                graph_ptr->set_graph_span(0);
//            }
        }
        else
        {
            item_is_pressed = false;
            list_widget->setStyleSheet("background: transparent;"
                                          "color: rgb(0, 167, 250);"
                                            "border: none;"
                                       "border-image: none;");
            item_pressed_counter = 0;

            save_position();
        }
    }

    number_of_clicks = 0;
}

void custom_tooltip::retry_tool_pos()
{
    uint tooltip_num = unknown_tool_pos.takeLast();

    if (0 != tooltip_num)
    {
        QString filename = "./tooltips/tool"+QString::number(tooltip_num);
        QFile myFile(filename);

        QDataStream in(&myFile);
        in.setVersion(QDataStream::Qt_5_7);

        QPoint pos = parent_frame->pos();
        if (!myFile.open(QIODevice::ReadOnly))
        {
            qDebug() << "NEL NO SE PUDO";
        }
        else
        {
            in >> pos;
    //        init_data();
    //        qDebug() << "tool: " << actual_tooltip_number <<"pos " << pos;
        }

        if(pos.x() != 0 && pos.y() != 0)
        {
            parent_frame->move(pos);
        }
        myFile.close();
    }
}



//void custom_tooltip::mousePressEvent(QMouseEvent *event)
//{
//    offset = event->pos();
//}

//void custom_tooltip::mouseMoveEvent(QMouseEvent *event)
//{
//    if (event->buttons() & Qt::LeftButton)
//    {
//        parent_frame->move(mapTo(parent_window, event->pos() - offset));
//    }
//}
