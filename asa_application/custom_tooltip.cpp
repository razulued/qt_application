#include "custom_tooltip.h"
#include "protocol/asa_protocol.h"
#include "parameters.h"
#include "multistatebutton.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QSettings>
#include <QDateTime>
#include <QTouchEvent>

#define HOLD_TIME (40)
QPoint offset;

custom_tooltip::custom_tooltip(QWidget *frame, configuration_id &conf_list, QWidget *parent) : QWidget(frame)
{

    parent_window = parent;

    parent_frame = frame;

    parent_frame->setObjectName(parent_window->objectName() + "_" + conf_list.group_name);
    parent_frame->setStyleSheet("#"+parent_frame->objectName()+"{border-image: url(:/iconos/images/Iconos/Globo_azul.png);}");

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

    item_is_pressed = false;

    DataList = conf_list.ids;
    NameList = conf_list.names;
    type = conf_list.type;
    file_name = parent->objectName() +"_"+conf_list.group_name;

    QString filename = "./tooltips/"+file_name;
    QFile myFile(filename);

    QDataStream in(&myFile);
    in.setVersion(QDataStream::Qt_5_7);

//    qDebug() << "TEXT:" << parent_window->objectName() << conf_list.group_name;
    QPoint pos = parent_frame->pos();
    if (!myFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not read the file:" << filename << "Error string:" << myFile.errorString();
//        // Re-try later
//        unknown_tool_pos.append(actual_tooltip_number);
//        QTimer::singleShot(3000, this, SLOT(retry_tool_pos()));
    }
    else
    {
        in >> pos;
        init_data();
        qDebug() << "tool: " << conf_list.group_name << "pos " << pos;
    }

    if(pos.x() != 0 && pos.y() != 0)
    {
        parent_frame->move(pos);
    }
    myFile.close();

}

void custom_tooltip::init_data()
{
    update_lock.lock();
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
    update_lock.unlock();
}

void custom_tooltip::update_tooltip()
{
    update_lock.lock();
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
        if(toolbar_active)
        {
            if((GetToolbarParameter() == (type -1))) // TODO: this is a patch because multistate button and conf have different enums
            {
                label = new QListWidgetItem(NameList[i] + ": " + getParamValue_and_units(param_id));

                list_widget->addItem(label);
                items++;
            }
        }
        else if(true == getParamActiveShow(param_id))
        {
            label = new QListWidgetItem(NameList[i] + ": " + getParamValue_and_units(param_id));

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
    update_lock.unlock();
}


void custom_tooltip::force_show(bool show)
{
    toolbar_active = show;
    this->update_tooltip();
}

void custom_tooltip::save_position()
{
    QString filename = "./tooltips/"+file_name;
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
