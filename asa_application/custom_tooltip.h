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

class custom_tooltip: public QWidget
{
    Q_OBJECT

public:

    static QList<int> create_list()
    {
        QList<int> list;
        return list;
    }

    custom_tooltip(QWidget *frame, QList<int> list, QStringList names, QList<int> out_list, QStringList out_names, QWidget *mainwindow, QWidget *connect_to);

    void update_data();
    void init_data();
    void force_show();
    void force_hide();

private:
    QList<int> DataList;
    QStringList NameList;
    QList<int> OutDataList;
    QStringList OutNameList;

    QWidget *parent_frame;
    QWidget *parent_window;
    QWidget *connect_here;

    QLayout *layout;
    QListWidget *list_widget;

    bool item_is_pressed;

private slots:
    void ListPressed();
    void ListReleased();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // CUSTOM_TOOLTIP_H
