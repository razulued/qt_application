#ifndef CUSTOM_TOOLTIP_H
#define CUSTOM_TOOLTIP_H
#include <QFrame>
#include <QLabel>
#include <QLayout>
#include <QList>
#include <QTimer>
#include <QListWidget>
#include <Qt>
#include <QMouseEvent>
#include <QPushButton>
#include <graphwindow.h>
#include "arrowkeys.h"

enum
{
    TYPE_ELECTRICOS,
    TYPE_FISICOS,
    TYPE_QUIMICOS
};

class custom_tooltip: public QWidget
{
    Q_OBJECT

public:

    static QList<int> create_list()
    {
        QList<int> list;
        return list;
    }

    custom_tooltip(QWidget *frame, QList<int> list, QStringList names, QList<int> out_list, QStringList out_names, QWidget *mainwindow, QPushButton *connect_to, uint type, graphwindow *graph);

    void update_data();
    void init_data();
    void force_show();
    void force_hide();

    static uint tooltip_number;
    uint actual_tooltip_number;
    QWidget *parent_window;
private:
    QList<int> DataList;
    QStringList NameList;
    QList<int> OutDataList;
    QStringList OutNameList;

    QWidget *parent_frame;
    QPushButton *connect_here;
    graphwindow *graph_ptr;

    QLayout *layout;
    QListWidget *list_widget;

    bool item_is_pressed;
    uint item_pressed_counter = 0;
    QPoint last_position;

    void save_position();

    uint number_of_clicks = 0;

    uint element_type = 0;

    arrowkeys *arrow_key_window = NULL;
private slots:
    void ListPressed();
    void checkClick();

protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

};

#endif // CUSTOM_TOOLTIP_H
