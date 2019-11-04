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
#include "screens/graphwindow.h"
#include "arrowkeys.h"
#include "configuration/configuration.h"
#include <QMutex>

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

    custom_tooltip(QWidget *frame, configuration_id &conf_list, QWidget *parent);

    void init_data();

    QWidget *parent_window;
private:
    QList<int> DataList;
    QStringList NameList;
    QList<int> OutDataList;
    QStringList OutNameList;

    QWidget *parent_frame;
    QPushButton *connect_here;

    QLayout *layout;
    QListWidget *list_widget;

    bool item_is_pressed;
    uint item_pressed_counter = 0;
    QPoint last_position;

    void save_position();

    uint number_of_clicks = 0;

    arrowkeys *arrow_key_window = NULL;
    QString graph_origin;

    QList<int> unknown_tool_pos;

    QString file_name;

    bool toolbar_active = false;
    elemnt_type type;

    QMutex update_lock;
private slots:
    void ListPressed();
    void checkClick();
    void retry_tool_pos();

public slots:
    void update_tooltip();
    void force_show(bool show);

protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

};

#endif // CUSTOM_TOOLTIP_H
