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

class custom_tooltip: public QWidget
{
    Q_OBJECT

public:

    static QList<int> create_list()
    {
        QList<int> list;
        return list;
    }

    custom_tooltip(QWidget *frame, QList<int> list, QStringList names, QList<int> out_list, QStringList out_names, QWidget *mainwindow, QPushButton *connect_to);

    void update_data();
    void init_data();
    void force_show();
    void force_hide();

    static uint tooltip_number;
    uint actual_tooltip_number;
private:
    QList<int> DataList;
    QStringList NameList;
    QList<int> OutDataList;
    QStringList OutNameList;

    QWidget *parent_frame;
    QWidget *parent_window;
    QPushButton *connect_here;

    QLayout *layout;
    QListWidget *list_widget;

    bool item_is_pressed;
    uint item_pressed_counter = 0;
    QPoint last_position;

    void save_position();

    uint number_of_clicks = 0;

private slots:
    void ListPressed();
    void checkClick();

protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

};

#endif // CUSTOM_TOOLTIP_H
