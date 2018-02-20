#ifndef CUSTOM_TOOLTIP_H
#define CUSTOM_TOOLTIP_H
#include <QFrame>
#include <QLabel>
#include <QLayout>
#include <QList>
#include <QTimer>
#include <QListWidget>
class custom_tooltip: public QObject
{
    Q_OBJECT

public:

    static QList<int> create_list()
    {
        QList<int> list;
        return list;
    }

    custom_tooltip(QWidget *frame, QList<int> list);

    void update_data();
    void init_data();
    void force_show();
    void force_hide();

private:
    QTimer timerHandler;
    QList<int> DataList;
    QWidget *parent_frame;
    QLayout *layout;
    QListWidget *list_widget;

private slots:
    void DataTimerUpdate();
};

#endif // CUSTOM_TOOLTIP_H
