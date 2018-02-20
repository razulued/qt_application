#include "custom_tooltip.h"
#include "parameters.h"
#include <QDebug>

custom_tooltip::custom_tooltip(QWidget *frame, QList<int> list)
{
    QFont font_2("Typo Square Ligth Demo",14,1);

    parent_frame = frame;
    parent_frame->setFont(font_2);
    parent_frame->setStyleSheet("color: rgb(0, 167, 250);"
                                "border-style: solid;"
                                "border-color: rgb(0, 167, 250);"
                                "border-width: 1px;");

    layout = new QVBoxLayout(frame);
    layout->setAlignment(Qt::AlignTop);

    list_widget = new QListWidget();
    list_widget->clear();
    list_widget->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);"
                                    "border: none");






    DataList = list;
    init_data();

//    //Setup Timer
//    timerHandler.setInterval(200);
//    connect(&timerHandler, SIGNAL(timeout()),this,SLOT(DataTimerUpdate()));
//    timerHandler.start();

}

void custom_tooltip::init_data()
{
    QLabel *label = new QLabel("");
    quint32 i, param_id;
    int items = 0;

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        if(true == getParamActiveShow(param_id))
        {
//            label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//            label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
            list_widget->addItem(getParamName(param_id) + ": " + getParamValue(param_id));
//            list_widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//            layout->addWidget(label);
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
    QLabel *label = new QLabel("");
    quint32 i, param_id;
    int items = 0;

    list_widget->clear();

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        if(true == getParamActiveShow(param_id))
        {
//            label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//            label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
            list_widget->addItem(getParamName(param_id) + ": " + getParamValue(param_id));
//            list_widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//            layout->addWidget(label);
            items++;
        }
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

void custom_tooltip::force_show()
{

    QLabel *label = new QLabel("");
    quint32 i, param_id;
    int items = 0;

    list_widget->clear();

    for(i = 0; i < (quint32)DataList.size(); i++)
    {
        param_id = DataList[i];

        list_widget->addItem(getParamName(param_id) + ": " + getParamValue(param_id));
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

void custom_tooltip::DataTimerUpdate()
{
//    update_data();
    qDebug() << "HOLA MUNDO";
}
